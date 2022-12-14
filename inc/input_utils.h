/*
 * input_utils.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#ifndef INC_INPUT_UTILS_H_
#define INC_INPUT_UTILS_H_

#include "usb_includes.h"

typedef enum
{
  DPAD_TYPE_DINPUT,
  DPAD_TYPE_XINPUT
} Input_Hat_Type;

typedef enum
{
  HAT_TOP          = 0x00,
  HAT_TOP_RIGHT    = 0x01,
  HAT_RIGHT        = 0x02,
  HAT_BOTTOM_RIGHT = 0x03,
  HAT_BOTTOM       = 0x04,
  HAT_BOTTOM_LEFT  = 0x05,
  HAT_LEFT         = 0x06,
  HAT_TOP_LEFT     = 0x07,
  HAT_CENTER       = 0x08,
} DInput_Hat_Dir_Type;

typedef enum
{
  XI_HAT_TOP          = 0x01,
  XI_HAT_TOP_RIGHT    = 0x02,
  XI_HAT_RIGHT        = 0x03,
  XI_HAT_BOTTOM_RIGHT = 0x04,
  XI_HAT_BOTTOM       = 0x05,
  XI_HAT_BOTTOM_LEFT  = 0x06,
  XI_HAT_LEFT         = 0x07,
  XI_HAT_TOP_LEFT     = 0x08,
  XI_HAT_CENTER       = 0x00,
} XInput_Hat_Dir_Type;

uint8_t getHatDir(Input_Hat_Type type, uint8_t leftRight, uint8_t upDown);

#endif /* INC_INPUT_UTILS_H_ */
