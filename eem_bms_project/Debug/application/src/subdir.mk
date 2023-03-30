################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../application/src/app.c \
../application/src/debug.c 

OBJS += \
./application/src/app.o \
./application/src/debug.o 

C_DEPS += \
./application/src/app.d \
./application/src/debug.d 


# Each subdirectory must supply rules for building sources it contributes
application/src/%.o application/src/%.su: ../application/src/%.c application/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/application/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/AdcModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/BalanceModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/CANModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/Drivers/EEMProtocol/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/Drivers/PCA9552_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-application-2f-src

clean-application-2f-src:
	-$(RM) ./application/src/app.d ./application/src/app.o ./application/src/app.su ./application/src/debug.d ./application/src/debug.o ./application/src/debug.su

.PHONY: clean-application-2f-src

