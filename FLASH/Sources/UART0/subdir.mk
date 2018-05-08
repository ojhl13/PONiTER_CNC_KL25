################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/UART0/UART.c" \

C_SRCS += \
../Sources/UART0/UART.c \

OBJS += \
./Sources/UART0/UART.o \

C_DEPS += \
./Sources/UART0/UART.d \

OBJS_QUOTED += \
"./Sources/UART0/UART.o" \

C_DEPS_QUOTED += \
"./Sources/UART0/UART.d" \

OBJS_OS_FORMAT += \
./Sources/UART0/UART.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/UART0/UART.o: ../Sources/UART0/UART.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/UART0/UART.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/UART0/UART.o"
	@echo 'Finished building: $<'
	@echo ' '


