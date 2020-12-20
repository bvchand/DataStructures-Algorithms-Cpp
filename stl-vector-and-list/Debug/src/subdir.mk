################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Node.cpp \
../src/SortedList.cpp \
../src/SortedVector.cpp \
../src/TImer.cpp \
../src/TestDriver.cpp \
../src/TestSuite.cpp 

OBJS += \
./src/Node.o \
./src/SortedList.o \
./src/SortedVector.o \
./src/TImer.o \
./src/TestDriver.o \
./src/TestSuite.o 

CPP_DEPS += \
./src/Node.d \
./src/SortedList.d \
./src/SortedVector.d \
./src/TImer.d \
./src/TestDriver.d \
./src/TestSuite.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++0x -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


