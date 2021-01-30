################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../test/gtest_main.cpp \
../test/test_score.cpp 

OBJS += \
./test/gtest_main.o \
./test/test_score.o 

CPP_DEPS += \
./test/gtest_main.d \
./test/test_score.d 


# Each subdirectory must supply rules for building sources it contributes
test/%.o: ../test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -I"/Users/adaye/eclipse-workspace/bowling_unit_test2/include" -I"/Users/adaye/eclipse-workspace/bowling_unit_test2/gtest_src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


