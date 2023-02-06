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

typedef enum
{
  GAMEPAD_STATUS_IDLE,
  GAMEPAD_STATUS_INITIALIZED,
} Gamepad_System_Status_TypeDef;

typedef enum
{
  USB_STATUS_NOBUS,
  USB_STATUS_BUSOK,
} USB_System_Status_TypeDef;

typedef enum
{
  USB_SUBCORE_IDLE    = 0,
  USB_SUBCORE_DINPUT  = 1,
  USB_SUBCORE_NS      = 2,
  USB_SUBCORE_XINPUT  = 3,
  USB_SUBCORE_GCINPUT = 4,
  USB_SUBCORE_MAX,
} Gamepad_USB_Subcore_TypeDef;

// Variables for system tracking
extern Gamepad_USB_Subcore_TypeDef gamepadSubcore;
extern Gamepad_System_Status_TypeDef gamepadStatus;
extern USB_System_Status_TypeDef usbStatus;
extern bool gamepadRumble;

void gamepadStop();

void gamepadCmd();

void gamepadCheckStatus();

void gamepadModeSet(I2C_Command_Setmode_TypeDef cmd);

void gamepadUSBModeSet(Gamepad_USB_Subcore_TypeDef coreType);

void gamepadInput();

void gamepadConfigInput();

void gamepadConfigOutput();

void gamepadReturnCmd(I2C_Return_Command_TypeDef ret_cmd);

#endif /* INC_GAMEPAD_H_ */
