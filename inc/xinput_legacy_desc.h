/*
 * xinput_legacy_desc.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Mitch
 */

#ifndef INC_XINPUT_LEGACY_DESC_H_
#define INC_XINPUT_LEGACY_DESC_H_

#include "usb_includes.h"

// XInput defines
#define XINPUT_VENDOR_ID  htole16( 0x045E )
#define XINPUT_PROD_ID    htole16( 0x028E )

#define XINPUT_PROD_STRING   'X','I',' ','W','i','r','e','d','\0'
#define XINPUT_PROD_SIZE     9

// Xinput externs
extern SI_SEGMENT_VARIABLE(xinput_config_descriptor[], const uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE(xinput_init_struct, const USBD_Init_TypeDef, SI_SEG_CODE);

#endif /* INC_XINPUT_LEGACY_DESC_H_ */
