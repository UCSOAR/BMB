/**
 * @file    BQ76942.cpp
 * @brief   STM32 HAL driver for the TI BQ76942 battery monitor.
 */
#include "BQ76942.hpp"
#include "cmsis_os.h"

volatile bool BQ76942::_alertInterruptPending = false;

BQ76942::BQ76942(I2C_HandleTypeDef *hi2c, std::uint8_t address7bit)
    : BQ76942(hi2c, Config{}, address7bit)
{
}

BQ76942::BQ76942(I2C_HandleTypeDef *hi2c, Config config, std::uint8_t address7bit)
    : _hi2c(hi2c),
      _config(config),
      _deviceAddress(static_cast<std::uint16_t>(address7bit))
{
    if (_config.cellCount > MAX_CELL_COUNT)
    {
        _config.cellCount = MAX_CELL_COUNT;
    }
}

BQ76942::Status BQ76942::SendSubcommand(std::uint16_t subcmd) const
{
	std::uint8_t cmd[4]{};

	std::uint8_t data1 = static_cast<std::uint8_t>(subcmd & 0xFFU);
	std::uint8_t data2 = static_cast<std::uint8_t>((subcmd >> 8U) & 0xFFU);

	std::uint8_t crc1_buffer[3] = {
		static_cast<std::uint8_t>(_deviceAddress),
		SUBCMD_ADDR,
		data1
	};
	std::uint8_t crc2_buffer[1] = { data2 };

	cmd[0] = data1;
	cmd[1] = ComputeCRC8(crc1_buffer, 3);
	cmd[2] = data2;
	cmd[3] = ComputeCRC8(crc2_buffer, 1);

	if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_ADDR,
						  I2C_MEMADD_SIZE_8BIT, cmd, sizeof(cmd),
						  I2C_TIMEOUT_MS) != HAL_OK)
	{
		return Status::ERR_I2C;
	}
	return Status::OK;
}

BQ76942::Status BQ76942::ReadFETStatus(std::uint8_t& fet_status) const
{
    Status write_status = SendSubcommand(SUBCMD_FET_STATUS);
    if (write_status != Status::OK)
    {
        return write_status;
    }

    // Wait for the BQ76942 to load data into the 0x40 buffer
    osDelay(2);

    return ReadU8(static_cast<Register>(SUBCMD_BUFFER), fet_status);
}

BQ76942::Status BQ76942::IsConnected() const
{
	if(HAL_I2C_IsDeviceReady(_hi2c, _deviceAddress, 2, I2C_TIMEOUT_MS) == HAL_OK){
	        return ReadDeviceID();
	    }

	return Status::ERR_I2C;
}

BQ76942::Status BQ76942::ReadMeasurements(Measurements &measurements) const
{
    for (std::uint8_t cell = 0; cell < _config.cellCount; ++cell)
    {
        Status status = ReadCellVoltage(cell, measurements.cellVoltage_mV[cell]);
        if (status != Status::OK)
        {
            return status;
        }
    }

    Status status = ReadStackVoltage(measurements.stackVoltage_userV);
    if (status != Status::OK)
    {
        return status;
    }

    return ReadCurrent(measurements.current_userA);
}

BQ76942::Status BQ76942::ReadCellVoltage(std::uint8_t cellIndex, std::int16_t &millivolts) const
{
    if (cellIndex >= _config.cellCount || cellIndex >= MAX_CELL_COUNT)
    {
        return Status::ERR_INVALID_ARG;
    }

    const std::uint8_t registerAddress =
        static_cast<std::uint8_t>(CELL_1_VOLTAGE + (cellIndex * 2U));
    return ReadI16(static_cast<Register>(registerAddress), millivolts);
}

std::uint8_t BQ76942::ComputeCRC8(const std::uint8_t* data, size_t length) const {
    std::uint8_t crc = 0x00;
    for (size_t i = 0; i < length; ++i) {
        crc ^= data[i];
        for (std::uint8_t j = 0; j < 8; ++j) {
            if (crc & 0x80) {
                crc = static_cast<std::uint8_t>((crc << 1) ^ 0x07);
            } else {
                crc <<= 1;
            }
        }
    }
    return crc;
}

BQ76942::Status BQ76942::ReadStackVoltage(std::int16_t &userVolts) const
{
    return ReadI16(STACK_VOLTAGE, userVolts);
}

BQ76942::Status BQ76942::ReadCurrent(std::int16_t &userAmps) const
{
    return ReadI16(CC2_CURRENT, userAmps);
}

BQ76942::Status BQ76942::ReadAlarmStatus(std::uint16_t &alarmStatus) const
{
    return ReadU16(ALARM_STATUS, alarmStatus);
}

BQ76942::Status BQ76942::ClearAlarmStatus(std::uint16_t alarmMask) const
{
    return WriteU16(ALARM_STATUS, alarmMask);
}

BQ76942::Status BQ76942::ReadSafetyStatus(SafetyStatus &status) const
{
    Status readStatus = ReadU8(SAFETY_STATUS_A, status.a);
    if (readStatus != Status::OK)
    {
        return readStatus;
    }

    readStatus = ReadU8(SAFETY_STATUS_B, status.b);
    if (readStatus != Status::OK)
    {
        return readStatus;
    }

    return ReadU8(SAFETY_STATUS_C, status.c);
}

bool BQ76942::IsAlertAsserted() const
{
    return HAL_GPIO_ReadPin(ALERT_GPIO_Port, ALERT_Pin) == GPIO_PIN_RESET; // todo: check this CHANGED FROM SET TO RESET as active low
}

void BQ76942::NotifyAlertInterrupt()
{
    _alertInterruptPending = true;
}

bool BQ76942::ConsumeAlertInterrupt()
{
    const bool wasPending = _alertInterruptPending;
    _alertInterruptPending = false;
    return wasPending;
}

const BQ76942::Config &BQ76942::GetConfig() const
{
    return _config;
}

BQ76942::Status BQ76942::ReadU8(Register reg, std::uint8_t &value) const
{
    std::uint8_t raw[2]{};
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    if (HAL_I2C_Mem_Read(_hi2c,
                         _deviceAddress,
                         static_cast<std::uint16_t>(reg),
                         I2C_MEMADD_SIZE_8BIT,
                         raw,
                         sizeof(raw),
                         I2C_TIMEOUT_MS) == HAL_OK)
    {
        value = raw[0];
        return Status::OK;
    }

    return Status::ERR_I2C;
}

extern "C" void BQ76942_NotifyAlertInterrupt(void)
{
    BQ76942::NotifyAlertInterrupt();
}

BQ76942::Status BQ76942::ReadU16(Register reg, std::uint16_t &value) const
{
    std::uint8_t raw[4]{};
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    if (HAL_I2C_Mem_Read(_hi2c, _deviceAddress, static_cast<std::uint16_t>(reg), I2C_MEMADD_SIZE_8BIT, raw, sizeof(raw), I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }

    value = static_cast<std::uint16_t>(raw[0] | (static_cast<std::uint16_t>(raw[2]) << 8U));
    return Status::OK;
}

BQ76942::Status BQ76942::ReadI16(Register reg, std::int16_t &value) const
{
    std::uint16_t raw = 0;
    Status status = ReadU16(reg, raw);
    if (status != Status::OK)
    {
        return status;
    }

    value = static_cast<std::int16_t>(raw);
    return Status::OK;
}

BQ76942::Status BQ76942::WriteU16(Register reg, std::uint16_t value) const
{
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    std::uint8_t data1 = static_cast<std::uint8_t>(value & 0xFFU);
    std::uint8_t data2 = static_cast<std::uint8_t>((value >> 8U) & 0xFFU);

    std::uint8_t crc1_buffer[3] = {
        static_cast<std::uint8_t>(_deviceAddress),
        static_cast<std::uint8_t>(reg),
        data1
    };
    std::uint8_t crc2_buffer[1] = { data2 };

    std::uint8_t cmd[4];
    cmd[0] = data1;
    cmd[1] = ComputeCRC8(crc1_buffer, 3);
    cmd[2] = data2;
    cmd[3] = ComputeCRC8(crc2_buffer, 1);

    return HAL_I2C_Mem_Write(_hi2c,
                             _deviceAddress,
                             static_cast<std::uint16_t>(reg),
                             I2C_MEMADD_SIZE_8BIT,
                             cmd,
                             sizeof(cmd),
                             I2C_TIMEOUT_MS) == HAL_OK
               ? Status::OK
               : Status::ERR_I2C;
}

BQ76942::Status BQ76942::ReadDeviceID() const
{
	// payload 4 bytes: Data1, CRC1, Data2, CRC2
	std::uint8_t cmd[4]{};

	std::uint8_t data1 = static_cast<std::uint8_t>(SUBCMD_DEVICE_NUMBER & 0xFFU);
	std::uint8_t data2 = static_cast<std::uint8_t>((SUBCMD_DEVICE_NUMBER >> 8U) & 0xFFU);

	std::uint8_t crc1_buffer[3] = {
		static_cast<std::uint8_t>(_deviceAddress),
		SUBCMD_ADDR,
		data1
	};

	std::uint8_t crc2_buffer[1] = { data2 };

	cmd[0] = data1;
	cmd[1] = ComputeCRC8(crc1_buffer, 3);
	cmd[2] = data2;
	cmd[3] = ComputeCRC8(crc2_buffer, 1);

	if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_ADDR,
						  I2C_MEMADD_SIZE_8BIT, cmd, sizeof(cmd),
						  I2C_TIMEOUT_MS) != HAL_OK)
	{
		return Status::ERR_I2C;
	}

    osDelay(2);

    std::uint8_t raw[4]{};
	if (HAL_I2C_Mem_Read(_hi2c, _deviceAddress, SUBCMD_BUFFER, I2C_MEMADD_SIZE_8BIT, raw, sizeof(raw), I2C_TIMEOUT_MS) != HAL_OK)
	{
		return Status::ERR_I2C;
	}
	const std::uint16_t id =
		static_cast<std::uint16_t>(raw[0] | (static_cast<std::uint16_t>(raw[2]) << 8U));

	return (id == DEVICE_ID) ? Status::OK : Status::ERR_INVALID_ARG;

}
