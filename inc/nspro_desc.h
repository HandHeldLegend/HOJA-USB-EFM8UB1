/*
 * nspro_desc.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#ifndef INC_NSPRO_DESC_H_
#define INC_NSPRO_DESC_H_

#include "usb_includes.h"

// Nintendo Switch Pro defines
#define NSPRO_VENDOR_ID  htole16( 0x20D6 )
#define NSPRO_PROD_ID    htole16( 0xA713 )

#define NSPRO_PROD_STRING   'N','S',' ','W','i','r','e','d','\0'
#define NSPRO_PROD_SIZE     9

#define NSPRO_HID_SIZE      94

// Nintendo Switch externs
extern SI_SEGMENT_VARIABLE(nspro_hid_descriptor[NSPRO_HID_SIZE], const uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE(nspro_config_descriptor[], const uint8_t, SI_SEG_CODE);
extern SI_SEGMENT_VARIABLE(nspro_init_struct, const USBD_Init_TypeDef, SI_SEG_CODE);

#endif /* INC_NSPRO_DESC_H_ */
