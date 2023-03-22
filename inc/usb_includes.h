/*
 * usb_includes.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */
#ifndef INC_USB_INCLUDES_H_
#define INC_USB_INCLUDES_H_

#include <SI_EFM8UB1_Register_Enums.h>
#include "InitDevice.h"
#include <si_toolchain.h>
#include <endian.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <efm8_usb.h>

#include "idle.h"
#include "smb_0.h"

#include "i2cbridge.h"

#include "gamepad.h"
#include "input_utils.h"

#include "descriptors.h"
#include "dinput_desc.h"
#include "nspro_desc.h"
#include "xinput_legacy_desc.h"

#include "nspro.h"
#include "dinput.h"
#include "xinput_legacy.h"

#endif /* INC_USB_INCLUDES_H_ */
