/*
 * xinput_desc.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */


#include "xinput_legacy_desc.h"

UTF16LE_PACKED_STATIC_CONST_STRING_DESC( xinput_prod_descriptor[], XINPUT_PROD_STRING, XINPUT_PROD_SIZE);

// Xinput Device Description
extern SI_SEGMENT_VARIABLE(xinput_device_descriptor[],
                    const USB_DeviceDescriptor_TypeDef,
                    SI_SEG_CODE) =
{
  USB_DEVICE_DESCSIZE,             // bLength
  USB_DEVICE_DESCRIPTOR,           // bLength
  htole16(0x0110),                 // bcdUSB
  0xFF,                            // bDeviceClass
  0xFF,                            // bDeviceSubClass
  0xFF,                            // bDeviceProtocol
  64,                              // bMaxPacketSize
  XINPUT_VENDOR_ID,                   // idVendor
  XINPUT_PROD_ID,                  // idProduct
  htole16(0x0572),                 // bcdDevice
  1,                               // iManufacturer
  2,                               // iProduct
  0,                               // iSerialNumber
  1,                               // bNumConfigurations
};

// Xinput Config Description
extern SI_SEGMENT_VARIABLE(xinput_config_descriptor[],
                    const uint8_t,
                    SI_SEG_CODE) =
{
    0x09,        // bLength
    0x02,        // bDescriptorType (Configuration)
    0x30, 0x00,  // wTotalLength 48
    0x01,        // bNumInterfaces 1
    0x01,        // bConfigurationValue
    0x00,        // iConfiguration (String Index)
    0x80,        // bmAttributes
    0xFA,        // bMaxPower 500mA

    0x09,        // bLength
    0x04,        // bDescriptorType (Interface)
    0x00,        // bInterfaceNumber 0
    0x00,        // bAlternateSetting
    0x02,        // bNumEndpoints 2
    0xFF,        // bInterfaceClass
    0x5D,        // bInterfaceSubClass
    0x01,        // bInterfaceProtocol
    0x00,        // iInterface (String Index)

    0x10,        // bLength
    0x21,        // bDescriptorType (HID)
    0x10, 0x01,  // bcdHID 1.10
    0x01,        // bCountryCode
    0x24,        // bNumDescriptors
    0x81,        // bDescriptorType[0] (Unknown 0x81)
    0x14, 0x03,  // wDescriptorLength[0] 788
    0x00,        // bDescriptorType[1] (Unknown 0x00)
    0x03, 0x13,  // wDescriptorLength[1] 4867
    0x02,        // bDescriptorType[2] (Unknown 0x02)
    0x00, 0x03,  // wDescriptorLength[2] 768
    0x00,        // bDescriptorType[3] (Unknown 0x00)

    0x07,        // bLength
    0x05,        // bDescriptorType (Endpoint)
    0x81,        // bEndpointAddress (IN/D2H)
    0x03,        // bmAttributes (Interrupt)
    0x20, 0x00,  // wMaxPacketSize 32
    0x01,        // bInterval 4 (unit depends on device speed)

    0x07,        // bLength
    0x05,        // bDescriptorType (Endpoint)
    0x02,        // bEndpointAddress (OUT/H2D)
    0x03,        // bmAttributes (Interrupt)
    0x20, 0x00,  // wMaxPacketSize 32
    0x08,        // bInterval 8 (unit depends on device speed)
};

SI_SEGMENT_VARIABLE_SEGMENT_POINTER(xinput_UsbStringTable_USEnglish[], static const USB_StringDescriptor_TypeDef, SI_SEG_GENERIC, const SI_SEG_CODE) =
{
  (SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_CODE))global_lang_descriptor,
  global_mfr_descriptor,
  xinput_prod_descriptor,
  global_serial_descriptor
};

// xinput initialization Struct
extern SI_SEGMENT_VARIABLE(xinput_init_struct,
                    const USBD_Init_TypeDef,
                    SI_SEG_CODE) =
{
  (SI_VARIABLE_SEGMENT_POINTER(, USB_DeviceDescriptor_TypeDef, SI_SEG_GENERIC))xinput_device_descriptor,              // deviceDescriptor
  (SI_VARIABLE_SEGMENT_POINTER(, USB_ConfigurationDescriptor_TypeDef, SI_SEG_GENERIC))xinput_config_descriptor,       // configDescriptor
  (SI_VARIABLE_SEGMENT_POINTER(, USB_StringTable_TypeDef, SI_SEG_GENERIC))xinput_UsbStringTable_USEnglish,   // stringDescriptors
  sizeof(xinput_UsbStringTable_USEnglish) / sizeof(xinput_UsbStringTable_USEnglish[0])                            // numberOfStrings
};
