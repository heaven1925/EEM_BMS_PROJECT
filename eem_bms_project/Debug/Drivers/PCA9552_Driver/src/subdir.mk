################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/PCA9552_Driver/src/_Pca9552_Led_Driver.c 

OBJS += \
./Drivers/PCA9552_Driver/src/_Pca9552_Led_Driver.o 

C_DEPS += \
./Drivers/PCA9552_Driver/src/_Pca9552_Led_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/PCA9552_Driver/src/%.o Drivers/PCA9552_Driver/src/%.su: ../Drivers/PCA9552_Driver/src/%.c Drivers/PCA9552_Driver/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/application/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/AdcModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/BalanceModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/CANModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/Drivers/EEMProtocol/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/Drivers/PCA9552_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Drivers-2f-PCA9552_Driver-2f-src

clean-Drivers-2f-PCA9552_Driver-2f-src:
	-$(RM) ./Drivers/PCA9552_Driver/src/_Pca9552_Led_Driver.d ./Drivers/PCA9552_Driver/src/_Pca9552_Led_Driver.o ./Drivers/PCA9552_Driver/src/_Pca9552_Led_Driver.su

.PHONY: clean-Drivers-2f-PCA9552_Driver-2f-src

