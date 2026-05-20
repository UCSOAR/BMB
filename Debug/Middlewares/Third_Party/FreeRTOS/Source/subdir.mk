################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (13.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Middlewares/Third_Party/FreeRTOS/Source/croutine.c \
../Middlewares/Third_Party/FreeRTOS/Source/event_groups.c \
../Middlewares/Third_Party/FreeRTOS/Source/list.c \
../Middlewares/Third_Party/FreeRTOS/Source/queue.c \
../Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.c \
../Middlewares/Third_Party/FreeRTOS/Source/tasks.c \
../Middlewares/Third_Party/FreeRTOS/Source/timers.c 

C_DEPS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.d \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.d \
./Middlewares/Third_Party/FreeRTOS/Source/list.d \
./Middlewares/Third_Party/FreeRTOS/Source/queue.d \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.d \
./Middlewares/Third_Party/FreeRTOS/Source/timers.d 

OBJS += \
./Middlewares/Third_Party/FreeRTOS/Source/croutine.o \
./Middlewares/Third_Party/FreeRTOS/Source/event_groups.o \
./Middlewares/Third_Party/FreeRTOS/Source/list.o \
./Middlewares/Third_Party/FreeRTOS/Source/queue.o \
./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o \
./Middlewares/Third_Party/FreeRTOS/Source/tasks.o \
./Middlewares/Third_Party/FreeRTOS/Source/timers.o 


# Each subdirectory must supply rules for building sources it contributes
Middlewares/Third_Party/FreeRTOS/Source/%.o Middlewares/Third_Party/FreeRTOS/Source/%.su Middlewares/Third_Party/FreeRTOS/Source/%.cyclo: ../Middlewares/Third_Party/FreeRTOS/Source/%.c Middlewares/Third_Party/FreeRTOS/Source/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu17 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32G491xx -c -I../Core/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc -I../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../Middlewares/Third_Party/FreeRTOS/Source/include -I../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../Drivers/CMSIS/Include -I"C:/cygwin64/home/spiro/SOAR/BMB/Drivers/STM32G4xx_HAL_Driver" -I../../Core/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc -I../../Drivers/STM32G4xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM4F -I../../Drivers/CMSIS/Device/ST/STM32G4xx/Include -I../../Drivers/CMSIS/Include -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SysCore" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SysCore/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Core/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Core" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Drivers" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Drivers/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Components/DataBroker/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarOS/Libraries/embedded-template-library/include" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/SoarDebug/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/Core/Src" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/Communication" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/GPS" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/IMU32" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/LSM6DSODriver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MAX7456" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MMC5983MA_SPI" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MS5607Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MS5611Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/MX66L1G45GMI" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/NAU7802" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/TMUX1104 Driver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/W25NDriver" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications/CanAutoNode" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarDrivers/FDCanG4" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications/CanAutoNode/Targets" -I"C:/cygwin64/home/spiro/SOAR/BMB/Components/Communication/Inc" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications/CanAutoNode/LogTypes" -I"C:/cygwin64/home/spiro/SOAR/BMB/SoarCommunications" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source:
	-$(RM) ./Middlewares/Third_Party/FreeRTOS/Source/croutine.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/croutine.d ./Middlewares/Third_Party/FreeRTOS/Source/croutine.o ./Middlewares/Third_Party/FreeRTOS/Source/croutine.su ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.d ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.o ./Middlewares/Third_Party/FreeRTOS/Source/event_groups.su ./Middlewares/Third_Party/FreeRTOS/Source/list.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/list.d ./Middlewares/Third_Party/FreeRTOS/Source/list.o ./Middlewares/Third_Party/FreeRTOS/Source/list.su ./Middlewares/Third_Party/FreeRTOS/Source/queue.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/queue.d ./Middlewares/Third_Party/FreeRTOS/Source/queue.o ./Middlewares/Third_Party/FreeRTOS/Source/queue.su ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.d ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.o ./Middlewares/Third_Party/FreeRTOS/Source/stream_buffer.su ./Middlewares/Third_Party/FreeRTOS/Source/tasks.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/tasks.d ./Middlewares/Third_Party/FreeRTOS/Source/tasks.o ./Middlewares/Third_Party/FreeRTOS/Source/tasks.su ./Middlewares/Third_Party/FreeRTOS/Source/timers.cyclo ./Middlewares/Third_Party/FreeRTOS/Source/timers.d ./Middlewares/Third_Party/FreeRTOS/Source/timers.o ./Middlewares/Third_Party/FreeRTOS/Source/timers.su

.PHONY: clean-Middlewares-2f-Third_Party-2f-FreeRTOS-2f-Source

