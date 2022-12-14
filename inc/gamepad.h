/*
 * gamepad.h
 *
 *  Created on: Sep 10, 2022
 *      Author: Mitch
 */

#ifndef INC_GAMEPAD_H_
#define INC_GAMEPAD_H_

// Includes for HHL Gamepad
#include "usb_includes.h"

extern bool sendReport;

// Defines for i2c custom protocol information
#define I2C_SLAVE_ADDR    0x45

#define I2C_CMD_CHECK     0x00
#define I2C_CMD_SYSTEM    0x01
#define I2C_CMD_INPUT     0x02
#define I2C_CMD_USBCHANGE 0x03

typedef enum
{
  SYSTEM_SET_STARTUSB = 0,
  SYSTEM_SET_STOPUSB  = 1,
  SYSTEM_SET_SLEEPUSB = 2,
  SYSTEM_SET_RESETUSB = 3,

} Gamepad_System_Set_TypeDef;

typedef enum
{
  GAMEPAD_STATUS_READY = 0,
  GAMEPAD_STATUS_NOCONNECT = 1,
} Gamepad_System_Status_TypeDef;

typedef enum
{
  USB_SUBCORE_DINPUT  = 0,
  USB_SUBCORE_NS      = 1,
  USB_SUBCORE_XINPUT  = 2,
  USB_SUBCORE_GCINPUT = 3,
} Gamepad_USB_Subcore_TypeDef;

// Variables for system tracking
extern Gamepad_USB_Subcore_TypeDef gamepadSubcore;
extern Gamepad_System_Status_TypeDef gamepadStatus;

void gamepadCmd();

void gamepadCheckReady();

void gamepadSysSet(Gamepad_System_Set_TypeDef setting);

void gamepadInput();

I2C_Response_Messsage_TypeDef gamepadSetSubcore(Gamepad_USB_Subcore_TypeDef mode);


#endif /* INC_GAMEPAD_H_ */
