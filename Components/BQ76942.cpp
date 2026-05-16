/**
 * @file    BQ76942.cpp
 * @brief   STM32 HAL driver for the TI BQ76942 battery monitor.
 */
#include "BQ76942.hpp"

volatile bool BQ76942::_alertInterruptPending = false;

BQ76942::BQ76942(I2C_HandleTypeDef *hi2c, std::uint8_t address7bit)
    : BQ76942(hi2c, Config{}, address7bit)
{
}

BQ76942::BQ76942(I2C_HandleTypeDef *hi2c, Config config, std::uint8_t address7bit)
    : _hi2c(hi2c),
      _config(config),
      _deviceAddress(static_cast<std::uint16_t>(address7bit << 1U))
{
    if (_config.cellCount > MAX_CELL_COUNT)
    {
        _config.cellCount = MAX_CELL_COUNT;
    }
}

BQ76942::Status BQ76942::IsConnected() const
{
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    return HAL_I2C_IsDeviceReady(_hi2c, _deviceAddress, 2, I2C_TIMEOUT_MS) == HAL_OK
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

BQ76942::Status BQ76942::ReadCellVoltage(std::uint8_t cellIndex, std::uint16_t &millivolts) const
{
    if (cellIndex >= _config.cellCount || cellIndex >= MAX_CELL_COUNT)
    {
        return Status::ERR_INVALID_ARG;
    }

    const std::uint8_t registerAddress =
        static_cast<std::uint8_t>(CELL_1_VOLTAGE + (cellIndex * 2U));
    return ReadU16(static_cast<Register>(registerAddress), millivolts);
}

BQ76942::Status BQ76942::ReadStackVoltage(std::uint16_t &userVolts) const
{
    return ReadU16(STACK_VOLTAGE, userVolts);
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
    return HAL_GPIO_ReadPin(ALERT_GPIO_Port, ALERT_Pin) == GPIO_PIN_SET;
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
    if (_hi2c == nullptr)
    {
        return Status::ERR_INVALID_ARG;
    }

    return HAL_I2C_Mem_Read(_hi2c,
                            _deviceAddress,
                            static_cast<std::uint16_t>(reg),
                            I2C_MEMADD_SIZE_8BIT,
                            &value,
                            sizeof(value),
                            I2C_TIMEOUT_MS) == HAL_OK
               ? Status::OK
               : Status::ERR_I2C;
}

extern "C" void BQ76942_NotifyAlertInterrupt(void)
{
    BQ76942::NotifyAlertInterrupt();
}

BQ76942::Status BQ76942::ReadU16(Register reg, std::uint16_t &value) const
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
                         I2C_TIMEOUT_MS) != HAL_OK)
    {
        return Status::ERR_I2C;
    }

    value = static_cast<std::uint16_t>(raw[0] | (static_cast<std::uint16_t>(raw[1]) << 8U));
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

    std::uint8_t raw[2]{
        static_cast<std::uint8_t>(value & 0xFFU),
        static_cast<std::uint8_t>((value >> 8U) & 0xFFU)};

    return HAL_I2C_Mem_Write(_hi2c,
                             _deviceAddress,
                             static_cast<std::uint16_t>(reg),
                             I2C_MEMADD_SIZE_8BIT,
                             raw,
                             sizeof(raw),
                             I2C_TIMEOUT_MS) == HAL_OK
               ? Status::OK
               : Status::ERR_I2C;
}
