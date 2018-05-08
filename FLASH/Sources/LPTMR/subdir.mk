################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../../makefile.local

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS_QUOTED += \
"../Sources/LPTMR/LPTMR.c" \

C_SRCS += \
../Sources/LPTMR/LPTMR.c \

OBJS += \
./Sources/LPTMR/LPTMR.o \

C_DEPS += \
./Sources/LPTMR/LPTMR.d \

OBJS_QUOTED += \
"./Sources/LPTMR/LPTMR.o" \

C_DEPS_QUOTED += \
"./Sources/LPTMR/LPTMR.d" \

OBJS_OS_FORMAT += \
./Sources/LPTMR/LPTMR.o \


# Each subdirectory must supply rules for building sources it contributes
Sources/LPTMR/LPTMR.o: ../Sources/LPTMR/LPTMR.c
	@echo 'Building file: $<'
	@echo 'Executing target #6 $<'
	@echo 'Invoking: ARM Ltd Windows GCC C Compiler'
	"$(ARMSourceryDirEnv)/arm-none-eabi-gcc" "$<" @"Sources/LPTMR/LPTMR.args" -MMD -MP -MF"$(@:%.o=%.d)" -o"Sources/LPTMR/LPTMR.o"
	@echo 'Finished building: $<'
	@echo ' '


