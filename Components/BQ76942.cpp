/**
 * @file    BQ76942.cpp
 * @brief   STM32 HAL driver for the TI BQ76942 battery monitor.
 */
#include "BQ76942.hpp"
#include "cmsis_os.h"

volatile bool BQ76942::_alertInterruptPending = false;

BQ76942::BQ76942(I2C_HandleTypeDef *hi2c, std::uint8_t address8bit)
    : BQ76942(hi2c, Config{}, address8bit)
{
}

BQ76942::BQ76942(I2C_HandleTypeDef *hi2c, Config config, std::uint8_t address8bit)
    : _hi2c(hi2c),
      _config(config),
      _deviceAddress(static_cast<std::uint16_t>(address8bit))
{
    if (_config.cellCount > MAX_CELL_COUNT)
    {
        _config.cellCount = MAX_CELL_COUNT;
    }
}

BQ76942::Status BQ76942::SendSubcommand(std::uint16_t subcmd) const
{
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

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
    return ReadU8(FET_STATUS, fet_status);
}

/**
 * @brief Send the 0x0097 FET_CONTROL subcommand (only applies when FET_EN = 1).
 * @param fet_mask Bitmask per TRM Section 12.5.6:
 *                 bit 0 = DSG_OFF, bit 1 = PDSG_OFF, bit 2 = CHG_OFF, bit 3 = PCHG_OFF
 *                 (1 = force FET off, 0 = allow FET on).
 */
BQ76942::Status BQ76942::SendFETControl(std::uint8_t fet_mask) const
{
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    // Step 1: write subcommand 0x0097 to 0x3E/0x3F
    const Status subStatus = SendSubcommand(SUBCMD_FET_CONTROL);
    if (subStatus != Status::OK)
    {
        return subStatus;
    }

    // Step 2: write 1-byte payload to 0x40 transfer buffer
    const std::uint8_t crc_buf[3] = {
        static_cast<std::uint8_t>(_deviceAddress),
        SUBCMD_BUFFER,
        fet_mask
    };
    std::uint8_t buffer_cmd[2] = {
        fet_mask,
        ComputeCRC8(crc_buf, 3U)
    };
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_BUFFER,
                          I2C_MEMADD_SIZE_8BIT, buffer_cmd, sizeof(buffer_cmd),
                          I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }

    // Step 3: commit with checksum (0x60) and length = 1 + 4 = 5 (0x61) written together
    const std::uint8_t sub_lo = static_cast<std::uint8_t>(SUBCMD_FET_CONTROL & 0xFFU);
    const std::uint8_t sub_hi = static_cast<std::uint8_t>((SUBCMD_FET_CONTROL >> 8U) & 0xFFU);
    const std::uint8_t chk = static_cast<std::uint8_t>(~(sub_lo + sub_hi + fet_mask));
    const std::uint8_t len = 5U;

    const std::uint8_t crc_chk[3] = {
        static_cast<std::uint8_t>(_deviceAddress),
        0x60U,
        chk
    };
    std::uint8_t commit_cmd[4] = {
        chk, ComputeCRC8(crc_chk, 3U),
        len, ComputeCRC8(&len, 1U)
    };
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, 0x60U,
                          I2C_MEMADD_SIZE_8BIT, commit_cmd, sizeof(commit_cmd),
                          I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }

    return Status::OK;
}

BQ76942::Status BQ76942::IsConnected() const
{
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    return (HAL_I2C_IsDeviceReady(_hi2c, _deviceAddress, 2, I2C_TIMEOUT_MS) == HAL_OK)
               ? Status::OK
               : Status::ERR_I2C;
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

    Status writeStatus = Status::OK;

    std::uint8_t crc_a1[3] = { static_cast<std::uint8_t>(_deviceAddress), SUBCMD_ADDR, addr_lo };
    std::uint8_t cmd_addr[4] = { addr_lo, ComputeCRC8(crc_a1, 3U), addr_hi, ComputeCRC8(&addr_hi, 1U) };
    if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_ADDR,
                          I2C_MEMADD_SIZE_8BIT, cmd_addr, 4U, I2C_TIMEOUT_MS) != HAL_OK)
    {
        writeStatus = Status::ERR_I2C;
    }

    if (writeStatus == Status::OK)
    {
        std::uint8_t crc_d0[3] = { static_cast<std::uint8_t>(_deviceAddress), SUBCMD_BUFFER, val_lo };
        std::uint8_t buf[4] = { val_lo, ComputeCRC8(crc_d0, 3U), val_hi, ComputeCRC8(&val_hi, 1U) };
        if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, SUBCMD_BUFFER,
                              I2C_MEMADD_SIZE_8BIT, buf, 4U, I2C_TIMEOUT_MS) != HAL_OK)
        {
            writeStatus = Status::ERR_I2C;
        }
    }

    if (writeStatus == Status::OK)
    {
        const std::uint8_t chk = static_cast<std::uint8_t>(~(addr_lo + addr_hi + val_lo + val_hi));
        const std::uint8_t len = 6U;
        std::uint8_t crc_chk[3] = { static_cast<std::uint8_t>(_deviceAddress), 0x60U, chk };
        std::uint8_t cmd_commit[4] = { chk, ComputeCRC8(crc_chk, 3U), len, ComputeCRC8(&len, 1U) };
        if (HAL_I2C_Mem_Write(_hi2c, _deviceAddress, 0x60U,
                              I2C_MEMADD_SIZE_8BIT, cmd_commit, 4U, I2C_TIMEOUT_MS) != HAL_OK)
        {
            writeStatus = Status::ERR_I2C;
        }
    }

    osDelay(2U);
    if (SendSubcommand(SUBCMD_EXIT_CFGUPDATE) != Status::OK)
    {
        return Status::ERR_I2C;
    }

    // Wait for CONFIG_UPDATE mode to exit (~1 ms per TRM Table 9-2) before sending follow-up commands
    bool exitedCfgUpdate = false;
    for (int attempt = 0; attempt < 10; ++attempt)
    {
        osDelay(2U);
        if (ReadU16(BATTERY_STATUS, batStatus) == Status::OK && ((batStatus & 0x0001U) == 0U))
        {
            exitedCfgUpdate = true;
            break;
        }
    }

    if (writeStatus != Status::OK) { return writeStatus; }
    return exitedCfgUpdate ? Status::OK : Status::ERR_I2C;
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

BQ76942::Status BQ76942::ReadBatteryStatus(std::uint16_t &batStatus) const
{
    return ReadU16(BATTERY_STATUS, batStatus);
}

BQ76942::Status BQ76942::ReadManufacturingStatus(std::uint16_t &mfgStatus) const
{
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    const Status writeStatus = SendSubcommand(SUBCMD_MANUFACTURING_STATUS);
    if (writeStatus != Status::OK)
    {
        return writeStatus;
    }

    osDelay(SUBCMD_DELAY_MS);

    std::uint8_t raw[4]{};
    if (HAL_I2C_Mem_Read(_hi2c, _deviceAddress, SUBCMD_BUFFER,
                         I2C_MEMADD_SIZE_8BIT, raw, sizeof(raw),
                         I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }

    mfgStatus = static_cast<std::uint16_t>(raw[0] | (static_cast<std::uint16_t>(raw[2]) << 8U));
    return Status::OK;
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
    // Active-low requires Settings:Configuration:ALERT Pin Config (0x92FC) to have PIN_FXN = 0b10 and OPT[5] = 1
    return HAL_GPIO_ReadPin(ALERT_GPIO_Port, ALERT_Pin) == GPIO_PIN_RESET;
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
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    const Status writeStatus = SendSubcommand(SUBCMD_DEVICE_NUMBER);
    if (writeStatus != Status::OK)
    {
        return writeStatus;
    }

    osDelay(SUBCMD_DELAY_MS);

    std::uint8_t raw[4]{};
    if (HAL_I2C_Mem_Read(_hi2c, _deviceAddress, SUBCMD_BUFFER, I2C_MEMADD_SIZE_8BIT, raw, sizeof(raw), I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }
    const std::uint16_t id =
        static_cast<std::uint16_t>(raw[0] | (static_cast<std::uint16_t>(raw[2]) << 8U));

    return (id == DEVICE_ID) ? Status::OK : Status::ERR_INVALID_ARG;
}
