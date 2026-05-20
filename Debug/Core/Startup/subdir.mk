################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../Core/Startup/startup_stm32g491mesx.s 

S_DEPS += \
./Core/Startup/startup_stm32g491mesx.d 

OBJS += \
./Core/Startup/startup_stm32g491mesx.o 


# Each subdirectory must supply rules for building sources it contributes
Core/Startup/%.o: ../Core/Startup/%.s Core/Startup/subdir.mk
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/cygwin64/home/spiro/SOAR/BMB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SysCore" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SysCore/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Core/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Core" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Drivers" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Drivers/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Components/DataBroker/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Libraries/embedded-template-library/include" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SoarDebug/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Core/Src" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/Communication" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/GPS" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/IMU32" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/LSM6DSODriver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MAX7456" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MMC5983MA_SPI" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MS5607Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MS5611Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MX66L1G45GMI" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/NAU7802" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/TMUX1104 Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/W25NDriver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications/CanAutoNode" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/FDCanG4" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications/CanAutoNode/Targets" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/Communication/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications/CanAutoNode/LogTypes" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g491mesx.d ./Core/Startup/startup_stm32g491mesx.o

.PHONY: clean-Core-2f-Startup

