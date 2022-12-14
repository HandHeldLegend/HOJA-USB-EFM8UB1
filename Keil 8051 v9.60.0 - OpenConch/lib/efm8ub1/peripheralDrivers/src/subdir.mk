################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/src/usb_0.c 

OBJS += \
./lib/efm8ub1/peripheralDrivers/src/usb_0.OBJ 


# Each subdirectory must supply rules for building sources it contributes
lib/efm8ub1/peripheralDrivers/src/usb_0.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/src/usb_0.c lib/efm8ub1/peripheralDrivers/src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

lib/efm8ub1/peripheralDrivers/src/usb_0.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h


