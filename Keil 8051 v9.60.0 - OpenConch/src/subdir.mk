################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
A51_UPPER_SRCS += \
C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/SILABS_STARTUP.A51 

C_SRCS += \
../src/EFM8UB10F16G-B-QFN28_main.c \
../src/InitDevice.c \
../src/callback.c \
../src/descriptors.c \
../src/dinput.c \
../src/dinput_desc.c \
../src/gamepad.c \
../src/i2cbridge.c \
../src/idle.c \
../src/input_utils.c \
../src/nspro.c \
../src/nspro_desc.c \
../src/usb_includes.c \
../src/xinput_.c \
../src/xinput_desc.c 

OBJS += \
./src/EFM8UB10F16G-B-QFN28_main.OBJ \
./src/InitDevice.OBJ \
./src/SILABS_STARTUP.OBJ \
./src/callback.OBJ \
./src/descriptors.OBJ \
./src/dinput.OBJ \
./src/dinput_desc.OBJ \
./src/gamepad.OBJ \
./src/i2cbridge.OBJ \
./src/idle.OBJ \
./src/input_utils.OBJ \
./src/nspro.OBJ \
./src/nspro_desc.OBJ \
./src/usb_includes.OBJ \
./src/xinput_.OBJ \
./src/xinput_desc.OBJ 


# Each subdirectory must supply rules for building sources it contributes
src/%.OBJ: ../src/%.c src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Compiler'
	C51 "@$(patsubst %.OBJ,%.__i,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/EFM8UB10F16G-B-QFN28_main.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/InitDevice.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/SILABS_STARTUP.OBJ: C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/SILABS_STARTUP.A51 src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: Keil 8051 Assembler'
	AX51 "@$(patsubst %.OBJ,%.__ia,$@)" || $(RC)
	@echo 'Finished building: $<'
	@echo ' '

src/callback.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/descriptors.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/dinput.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/dinput_desc.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/gamepad.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/i2cbridge.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h

src/idle.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h

src/input_utils.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/nspro.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/nspro_desc.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/usb_includes.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/xinput_.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h

src/xinput_desc.OBJ: C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/usb_includes.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Register_Enums.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/InitDevice.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/si_toolchain.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/endian.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDLIB.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STRING.H C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDIO.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Lib/efm8_usb/inc/efm8_usb.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/xinput_.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/idle.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/smb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/i2cbridge.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/gamepad.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/input_utils.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/descriptors.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro_desc.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/nspro.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/dinput.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/inc/SI_EFM8UB1_Defs.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdint.h C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/shared/si8051Base/stdbool.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/config/usbconfig.h C:/SiliconLabs/SimplicityStudio/v5/developer/toolchains/keil_8051/9.60/INC/STDDEF.H C:/SiliconLabs/SimplicityStudio/v5/developer/sdks/8051/v4.2.4/Device/EFM8UB1/peripheral_driver/inc/usb_0.h C:/Users/Mitch/SimplicityStudio/v5_workspace/HOJA-USB-EFM8UB1/inc/EFM8UB1_I2C_Slave.h


