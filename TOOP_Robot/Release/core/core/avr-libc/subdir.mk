################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/cores/emoro_core/avr-libc/malloc.c \
/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/cores/emoro_core/avr-libc/realloc.c 

C_DEPS += \
./core/core/avr-libc/malloc.c.d \
./core/core/avr-libc/realloc.c.d 

AR_OBJ += \
./core/core/avr-libc/malloc.c.o \
./core/core/avr-libc/realloc.c.o 


# Each subdirectory must supply rules for building sources it contributes
core/core/avr-libc/malloc.c.o: /home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/cores/emoro_core/avr-libc/malloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_EMORO_2560 -DARDUINO_ARCH_AVR     -I"/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/cores/emoro_core" -I"/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/variants/emoro_variants" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '

core/core/avr-libc/realloc.c.o: /home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/cores/emoro_core/avr-libc/realloc.c
	@echo 'Building file: $<'
	@echo 'Starting C compile'
	"/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-gcc" -c -g -Os -w -std=gnu11 -ffunction-sections -fdata-sections -MMD -mmcu=atmega2560 -DF_CPU=16000000L -DARDUINO=10812 -DARDUINO_AVR_EMORO_2560 -DARDUINO_ARCH_AVR     -I"/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/cores/emoro_core" -I"/home/joshua/eclipse/cpp-2022-09/eclipse/arduinoPlugin/packages/emoro/hardware/avr/3.2.2/variants/emoro_variants" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -D__IN_ECLIPSE__=1 "$<"   -o "$@"
	@echo 'Finished building: $<'
	@echo ' '


