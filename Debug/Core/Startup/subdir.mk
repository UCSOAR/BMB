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
	arm-none-eabi-gcc -mcpu=cortex-m4 -g3 -DDEBUG -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/cygwin64/home/spiro/SOAR/BMB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SysCore" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SysCore/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/LoggingModule" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/LoggingModule/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/Flash/Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/Flash/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SoarDebug/Inc" -x assembler-with-cpp -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@" "$<"

clean: clean-Core-2f-Startup

clean-Core-2f-Startup:
	-$(RM) ./Core/Startup/startup_stm32g491mesx.d ./Core/Startup/startup_stm32g491mesx.o

.PHONY: clean-Core-2f-Startup

