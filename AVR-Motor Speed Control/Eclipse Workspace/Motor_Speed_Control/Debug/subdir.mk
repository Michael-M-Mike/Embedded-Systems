################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../external_interrupts.c \
../lcd.c \
../main.c \
../motor_driver.c \
../timer.c 

OBJS += \
./adc.o \
./external_interrupts.o \
./lcd.o \
./main.o \
./motor_driver.o \
./timer.o 

C_DEPS += \
./adc.d \
./external_interrupts.d \
./lcd.d \
./main.d \
./motor_driver.d \
./timer.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


