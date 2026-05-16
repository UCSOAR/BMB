/**
 * @file    BQ76942.hpp
 * @brief   Lightweight STM32 HAL driver for the TI BQ76942 battery monitor.
 */
#ifndef BQ76942_HPP
#define BQ76942_HPP

#include <cstdint>

extern "C"
{
#include "main.h"
}

class BQ76942
{
public:
    static constexpr std::uint8_t MAX_CELL_COUNT = 10;
    static constexpr std::uint8_t DEFAULT_7BIT_ADDRESS = 0x08;
    static constexpr std::uint16_t DEFAULT_CHARGE_VOLTAGE_LIMIT_MV = 20000;
    static constexpr std::uint16_t DEFAULT_CHARGE_CURRENT_LIMIT_MA = 1500;

    enum class Status : std::uint8_t
    {
        OK = 0,
        ERR_INVALID_ARG,
        ERR_I2C
    };

    struct Config
    {
        std::uint8_t cellCount = MAX_CELL_COUNT;
        std::uint16_t chargeVoltageLimit_mV = DEFAULT_CHARGE_VOLTAGE_LIMIT_MV;
        std::uint16_t chargeCurrentLimit_mA = DEFAULT_CHARGE_CURRENT_LIMIT_MA;
    };

    struct Measurements
    {
        std::uint16_t cellVoltage_mV[MAX_CELL_COUNT]{};
        std::uint16_t stackVoltage_userV = 0;
        std::int16_t current_userA = 0;
    };

    struct SafetyStatus
    {
        std::uint8_t a = 0;
        std::uint8_t b = 0;
        std::uint8_t c = 0;
    };

    explicit BQ76942(I2C_HandleTypeDef *hi2c,
                     std::uint8_t address7bit = DEFAULT_7BIT_ADDRESS);
    BQ76942(I2C_HandleTypeDef *hi2c,
            Config config,
            std::uint8_t address7bit = DEFAULT_7BIT_ADDRESS);

    Status IsConnected() const;
    Status ReadMeasurements(Measurements &measurements) const;
    Status ReadCellVoltage(std::uint8_t cellIndex, std::uint16_t &millivolts) const;
    Status ReadStackVoltage(std::uint16_t &userVolts) const;
    Status ReadCurrent(std::int16_t &userAmps) const;
    Status ReadAlarmStatus(std::uint16_t &alarmStatus) const;
    Status ClearAlarmStatus(std::uint16_t alarmMask) const;
    Status ReadSafetyStatus(SafetyStatus &status) const;
    bool IsAlertAsserted() const;
    static void NotifyAlertInterrupt();
    static bool ConsumeAlertInterrupt();

    const Config &GetConfig() const;

private:
    static constexpr std::uint16_t I2C_TIMEOUT_MS = 100;

    enum Register : std::uint8_t
    {
        CONTROL_STATUS = 0x00,
        SAFETY_STATUS_A = 0x03,
        SAFETY_STATUS_B = 0x05,
        SAFETY_STATUS_C = 0x07,
        CELL_1_VOLTAGE = 0x14,
        STACK_VOLTAGE = 0x34,
        CC2_CURRENT = 0x3A,
        ALARM_STATUS = 0x62
    };

    Status ReadU8(Register reg, std::uint8_t &value) const;
    Status ReadU16(Register reg, std::uint16_t &value) const;
    Status ReadI16(Register reg, std::int16_t &value) const;
    Status WriteU16(Register reg, std::uint16_t value) const;

    I2C_HandleTypeDef *_hi2c;
    Config _config;
    std::uint16_t _deviceAddress;
    static volatile bool _alertInterruptPending;
};

#endif // BQ76942_HPP
