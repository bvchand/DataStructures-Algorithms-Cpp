################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/DataRandom.cpp \
../src/Element.cpp \
../src/InsertionSort.cpp \
../src/LinkedList.cpp \
../src/ListSorter.cpp \
../src/MergeSort.cpp \
../src/QuickSortOptimal.cpp \
../src/QuickSortSuboptimal.cpp \
../src/QuickSorter.cpp \
../src/SelectionSort.cpp \
../src/ShellSortOptimal.cpp \
../src/ShellSortSuboptimal.cpp \
../src/SortTests.cpp \
../src/Sorter.cpp \
../src/VectorSorter.cpp 

OBJS += \
./src/DataRandom.o \
./src/Element.o \
./src/InsertionSort.o \
./src/LinkedList.o \
./src/ListSorter.o \
./src/MergeSort.o \
./src/QuickSortOptimal.o \
./src/QuickSortSuboptimal.o \
./src/QuickSorter.o \
./src/SelectionSort.o \
./src/ShellSortOptimal.o \
./src/ShellSortSuboptimal.o \
./src/SortTests.o \
./src/Sorter.o \
./src/VectorSorter.o 

CPP_DEPS += \
./src/DataRandom.d \
./src/Element.d \
./src/InsertionSort.d \
./src/LinkedList.d \
./src/ListSorter.d \
./src/MergeSort.d \
./src/QuickSortOptimal.d \
./src/QuickSortSuboptimal.d \
./src/QuickSorter.d \
./src/SelectionSort.d \
./src/ShellSortOptimal.d \
./src/ShellSortSuboptimal.d \
./src/SortTests.d \
./src/Sorter.d \
./src/VectorSorter.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


