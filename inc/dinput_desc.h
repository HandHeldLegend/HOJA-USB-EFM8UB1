/*
 * dinput_desc.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#ifndef DINPUT_DESC_H_
#define DINPUT_DESC_H_

#include "usb_includes.h"

// DInput defines
#define DINPUT_VENDOR_ID  htole16( 0x20D6 )
#define DINPUT_PROD_ID    htole16( 0xA713 )

#define DINPUT_PROD_STRING   'D','I',' ','W','i','r','e','d','\0'
#define DINPUT_PROD_SIZE     9

#define DINPUT_HID_SIZE      125

// Dinput externs
extern SI_SEGMENT_VARIABLE(dinput_hid_descriptor[DINPUT_HID_SIZE], const uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE(dinput_config_descriptor[], const uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE(dinput_init_struct, const USBD_Init_TypeDef, SI_SEG_CODE);

#endif /* DINPUT_DESC_H_ */
