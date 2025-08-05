################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Driver/Src/debug_handler.c \
../Driver/Src/get_register_data.c \
../Driver/Src/gpio.c \
../Driver/Src/memory_dump.c \
../Driver/Src/peripheral_clock.c \
../Driver/Src/uart.c 

OBJS += \
./Driver/Src/debug_handler.o \
./Driver/Src/get_register_data.o \
./Driver/Src/gpio.o \
./Driver/Src/memory_dump.o \
./Driver/Src/peripheral_clock.o \
./Driver/Src/uart.o 

C_DEPS += \
./Driver/Src/debug_handler.d \
./Driver/Src/get_register_data.d \
./Driver/Src/gpio.d \
./Driver/Src/memory_dump.d \
./Driver/Src/peripheral_clock.d \
./Driver/Src/uart.d 


# Each subdirectory must supply rules for building sources it contributes
Driver/Src/%.o Driver/Src/%.su Driver/Src/%.cyclo: ../Driver/Src/%.c Driver/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DSTM32F407G_DISC1 -DSTM32F4 -DSTM32F407VGTx -c -I../Inc -I"E:/Embedded_Engineer_Projects/UART_Mini_Debugger/UART_MINI_DEBUGGER/Driver/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Driver-2f-Src

clean-Driver-2f-Src:
	-$(RM) ./Driver/Src/debug_handler.cyclo ./Driver/Src/debug_handler.d ./Driver/Src/debug_handler.o ./Driver/Src/debug_handler.su ./Driver/Src/get_register_data.cyclo ./Driver/Src/get_register_data.d ./Driver/Src/get_register_data.o ./Driver/Src/get_register_data.su ./Driver/Src/gpio.cyclo ./Driver/Src/gpio.d ./Driver/Src/gpio.o ./Driver/Src/gpio.su ./Driver/Src/memory_dump.cyclo ./Driver/Src/memory_dump.d ./Driver/Src/memory_dump.o ./Driver/Src/memory_dump.su ./Driver/Src/peripheral_clock.cyclo ./Driver/Src/peripheral_clock.d ./Driver/Src/peripheral_clock.o ./Driver/Src/peripheral_clock.su ./Driver/Src/uart.cyclo ./Driver/Src/uart.d ./Driver/Src/uart.o ./Driver/Src/uart.su

.PHONY: clean-Driver-2f-Src

