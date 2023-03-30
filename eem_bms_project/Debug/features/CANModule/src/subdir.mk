################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../features/CANModule/src/canModule.c 

OBJS += \
./features/CANModule/src/canModule.o 

C_DEPS += \
./features/CANModule/src/canModule.d 


# Each subdirectory must supply rules for building sources it contributes
features/CANModule/src/%.o features/CANModule/src/%.su: ../features/CANModule/src/%.c features/CANModule/src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32F446xx -c -I../Core/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc -I../Drivers/STM32F4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32F4xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/application/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/AdcModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/BalanceModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/features/CANModule/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/Drivers/EEMProtocol/inc" -I"C:/Users/AtakanErtekin/Desktop/Elektromobil WorkSpace/EEM_BMS_PROJECT/eem_bms_project/Drivers/PCA9552_Driver/inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-features-2f-CANModule-2f-src

clean-features-2f-CANModule-2f-src:
	-$(RM) ./features/CANModule/src/canModule.d ./features/CANModule/src/canModule.o ./features/CANModule/src/canModule.su

.PHONY: clean-features-2f-CANModule-2f-src

