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

BQ76942::Status BQ76942::SendFETControl(std::uint8_t fet_mask) const
{
    std::uint8_t buffer_cmd[2];
    std::uint8_t crc_buf[3] = {
        static_cast<std::uint8_t>(_deviceAddress),
        SUBCMD_BUFFER,
        fet_mask
    };

    buffer_cmd[0] = fet_mask;
    buffer_cmd[1] = ComputeCRC8(crc_buf, 3);

    // Write 8-bit payload to 0x40 buffer
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_BUFFER, I2C_MEMADD_SIZE_8BIT, buffer_cmd, sizeof(buffer_cmd), I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }

    // Trigger the FET_CONTROL subcommand
    return SendSubcommand(SUBCMD_FET_CONTROL);
}

BQ76942::Status BQ76942::IsConnected() const
{
	if(HAL_I2C_IsDeviceReady(_hi2c, _deviceAddress, 2, I2C_TIMEOUT_MS) == HAL_OK){
	        return ReadDeviceID();
	    }

	return Status::ERR_I2C;
}

BQ76942::Status BQ76942::WriteCCGain(float gain) const
{
    if (_hi2c == nullptr) { return Status::ERR_INVALID_ARG; }

    const std::uint16_t addr = DATA_MEM_CC_GAIN;
    const std::uint8_t  addr_lo = static_cast<std::uint8_t>(addr & 0xFFU);
    const std::uint8_t  addr_hi = static_cast<std::uint8_t>((addr >> 8U) & 0xFFU);

    // Reinterpret float bytes without memcpy
    const std::uint32_t bits = *reinterpret_cast<const std::uint32_t*>(&gain);
    const std::uint8_t flt[4] = {
        static_cast<std::uint8_t>(bits        & 0xFFU),
        static_cast<std::uint8_t>((bits >> 8U) & 0xFFU),
        static_cast<std::uint8_t>((bits >>16U) & 0xFFU),
        static_cast<std::uint8_t>((bits >>24U) & 0xFFU)
    };

    // Step 1: write DM address to 0x3E
    {
        std::uint8_t crc1[3] = { static_cast<std::uint8_t>(_deviceAddress), SUBCMD_ADDR, addr_lo };
        std::uint8_t crc2[1] = { addr_hi };
        std::uint8_t cmd[4]  = { addr_lo, ComputeCRC8(crc1, 3U), addr_hi, ComputeCRC8(crc2, 1U) };
        if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_ADDR,
                              I2C_MEMADD_SIZE_8BIT, cmd, 4U, I2C_TIMEOUT_MS) != HAL_OK)
            return Status::ERR_I2C;
    }

    // Step 2: write 4 float bytes to 0x40 — [d0,crc0, d1,crc1, d2,crc2, d3,crc3]
    {
        std::uint8_t crc0[3] = { static_cast<std::uint8_t>(_deviceAddress), SUBCMD_BUFFER, flt[0] };
        std::uint8_t buf[8]  = {
            flt[0], ComputeCRC8(crc0, 3U),
            flt[1], ComputeCRC8(&flt[1], 1U),
            flt[2], ComputeCRC8(&flt[2], 1U),
            flt[3], ComputeCRC8(&flt[3], 1U)
        };
        if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_BUFFER,
                              I2C_MEMADD_SIZE_8BIT, buf, 8U, I2C_TIMEOUT_MS) != HAL_OK)
            return Status::ERR_I2C;
    }

    // Step 3: commit — simple-sum checksum (NOT CRC8) + length to 0x60/0x61
    {
        const std::uint8_t s = static_cast<std::uint8_t>(
            addr_lo + addr_hi + flt[0] + flt[1] + flt[2] + flt[3]);
        const std::uint8_t chk = static_cast<std::uint8_t>(~s);
        const std::uint8_t len = 6U;
        std::uint8_t crc_chk[3] = { static_cast<std::uint8_t>(_deviceAddress), 0x60U, chk };
        std::uint8_t crc_len[1] = { len };
        std::uint8_t cmd[4] = { chk, ComputeCRC8(crc_chk, 3U), len, ComputeCRC8(crc_len, 1U) };
        if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, 0x60U,
                              I2C_MEMADD_SIZE_8BIT, cmd, 4U, I2C_TIMEOUT_MS) != HAL_OK)
            return Status::ERR_I2C;
    }

    osDelay(5U);
    return Status::OK;
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

//BQ76942::Status BQ76942::ReadCellVoltage(std::uint8_t cellIndex, std::int16_t &millivolts) const
//{
//    if (cellIndex >= _config.cellCount || cellIndex >= MAX_CELL_COUNT)
//    {
//        return Status::ERR_INVALID_ARG;
//    }
//
//    const std::uint8_t registerAddress =
//        static_cast<std::uint8_t>(CELL_1_VOLTAGE + (cellIndex * 2U));
//    return ReadI16(static_cast<Register>(registerAddress), millivolts);
//}

BQ76942::Status BQ76942::ReadCellVoltage(std::uint8_t cellIndex, std::int16_t &millivolts) const
{
    if (cellIndex >= _config.cellCount || cellIndex >= MAX_CELL_COUNT)
    {
        return Status::ERR_INVALID_ARG;
    }

    // For a 4S pack wired to VC0..VC3 and VC10 (VC4..VC9 shorted to VC3),
    // physical Cell 4 is measured on the Cell 10 channel (0x26).
    const std::uint8_t registerAddress =
        (_config.cellCount == 4U && cellIndex == 3U)
            ? static_cast<std::uint8_t>(CELL_10_VOLTAGE)
            : static_cast<std::uint8_t>(CELL_1_VOLTAGE + (cellIndex * 2U));

    return ReadI16(static_cast<Register>(registerAddress), millivolts);
}

BQ76942::Status BQ76942::DisableSleepMode() const
{
    return SendSubcommand(SUBCMD_SLEEP_DISABLE);
}

BQ76942::Status BQ76942::ConfigureVcellMode(std::uint16_t vcellMask) const
{
    if (_hi2c == nullptr) { return Status::ERR_INVALID_ARG; }

    if (SendSubcommand(SUBCMD_SET_CFGUPDATE) != Status::OK)
        return Status::ERR_I2C;

    std::uint16_t batStatus = 0;
    bool inCfgUpdate = false;
    for (int attempt = 0; attempt < 10; ++attempt)
    {
        osDelay(2U);
        if (ReadU16(BATTERY_STATUS, batStatus) == Status::OK && (batStatus & 0x0001U))
        {
            inCfgUpdate = true;
            break;
        }
    }
    if (!inCfgUpdate) { return Status::ERR_I2C; }

    const std::uint8_t addr_lo = static_cast<std::uint8_t>(DATA_MEM_VCELL_MODE & 0xFFU);
    const std::uint8_t addr_hi = static_cast<std::uint8_t>((DATA_MEM_VCELL_MODE >> 8U) & 0xFFU);
    const std::uint8_t val_lo  = static_cast<std::uint8_t>(vcellMask & 0xFFU);
    const std::uint8_t val_hi  = static_cast<std::uint8_t>((vcellMask >> 8U) & 0xFFU);

    std::uint8_t crc_a1[3] = { static_cast<std::uint8_t>(_deviceAddress), SUBCMD_ADDR, addr_lo };
    std::uint8_t cmd_addr[4] = { addr_lo, ComputeCRC8(crc_a1, 3U), addr_hi, ComputeCRC8(&addr_hi, 1U) };
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_ADDR,
                          I2C_MEMADD_SIZE_8BIT, cmd_addr, 4U, I2C_TIMEOUT_MS) != HAL_OK)
        return Status::ERR_I2C;

    std::uint8_t crc_d0[3] = { static_cast<std::uint8_t>(_deviceAddress), SUBCMD_BUFFER, val_lo };
    std::uint8_t buf[4] = { val_lo, ComputeCRC8(crc_d0, 3U), val_hi, ComputeCRC8(&val_hi, 1U) };
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_BUFFER,
                          I2C_MEMADD_SIZE_8BIT, buf, 4U, I2C_TIMEOUT_MS) != HAL_OK)
        return Status::ERR_I2C;

    const std::uint8_t chk = static_cast<std::uint8_t>(~(addr_lo + addr_hi + val_lo + val_hi));
    const std::uint8_t len = 6U;
    std::uint8_t crc_chk[3] = { static_cast<std::uint8_t>(_deviceAddress), 0x60U, chk };
    std::uint8_t cmd_commit[4] = { chk, ComputeCRC8(crc_chk, 3U), len, ComputeCRC8(&len, 1U) };
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, 0x60U,
                          I2C_MEMADD_SIZE_8BIT, cmd_commit, 4U, I2C_TIMEOUT_MS) != HAL_OK)
        return Status::ERR_I2C;

    osDelay(2U);
    return SendSubcommand(SUBCMD_EXIT_CFGUPDATE);
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

BQ76942::Status BQ76942::ToggleAutonomousFETs() const
{
    return SendSubcommand(SUBCMD_FET_ENABLE);
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
