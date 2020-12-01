################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../airline.c \
../airport.c \
../airport_manager.c \
../date.c \
../flight.c \
../functions.c \
../main.c 

OBJS += \
./airline.o \
./airport.o \
./airport_manager.o \
./date.o \
./flight.o \
./functions.o \
./main.o 

C_DEPS += \
./airline.d \
./airport.d \
./airport_manager.d \
./date.d \
./flight.d \
./functions.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


