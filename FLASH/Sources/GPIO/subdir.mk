################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/GPIO/GPIO.c" \

C_SRCS += \
../Sources/GPIO/GPIO.c \

OBJS += \
./Sources/GPIO/GPIO.o \

C_DEPS += \
./Sources/GPIO/GPIO.d \

OBJS_QUOTED += \
"./Sources/GPIO/GPIO.o" \

C_DEPS_QUOTED += \
"./Sources/GPIO/GPIO.d" \

OBJS_OS_FORMAT += \
./Sources/GPIO/GPIO.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/GPIO/GPIO.o: ../Sources/GPIO/GPIO.c
	@echo 'Building file: $<'
	@echo 'Executing target #7 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/GPIO/GPIO.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/GPIO/GPIO.o"
	@echo 'Finished building: $<'
	@echo ' '


