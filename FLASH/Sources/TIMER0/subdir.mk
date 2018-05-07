################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/TIMER0/TIMER.c" \

C_SRCS += \
../Sources/TIMER0/TIMER.c \

OBJS += \
./Sources/TIMER0/TIMER.o \

C_DEPS += \
./Sources/TIMER0/TIMER.d \

OBJS_QUOTED += \
"./Sources/TIMER0/TIMER.o" \

C_DEPS_QUOTED += \
"./Sources/TIMER0/TIMER.d" \

OBJS_OS_FORMAT += \
./Sources/TIMER0/TIMER.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/TIMER0/TIMER.o: ../Sources/TIMER0/TIMER.c
	@echo 'Building file: $<'
	@echo 'Executing target #4 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/TIMER0/TIMER.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/TIMER0/TIMER.o"
	@echo 'Finished building: $<'
	@echo ' '


