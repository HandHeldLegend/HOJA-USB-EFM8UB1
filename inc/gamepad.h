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

// Variables for system tracking
extern usb_subcore_t gamepadSubcore;
extern ui2c_gamepad_status_t gamepadStatus;
extern ui2c_usb_status_t usbStatus;

extern bool sendReport;

extern bool gpRumble;
extern bool gpConfigRequest;
extern bool gpConfigWrite;
extern uint8_t gpConfigData[8];

void gamepadStop();

void gamepadCmd();

void gamepadCheckStatus();

void gamepadModeSet(ui2c_setmode_t cmd);

void gamepadUSBModeSet(usb_subcore_t coreType);

void gamepadInput();

void gamepadConfigInput();

void gamepadConfigOutput();

void gamepadReturnCmd();

#endif /* INC_GAMEPAD_H_ */
