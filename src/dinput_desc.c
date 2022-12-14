/*
 * dinput_desc.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#include "dinput_desc.h"

UTF16LE_PACKED_STATIC_CONST_STRING_DESC( dinput_prod_descriptor[], DINPUT_PROD_STRING, DINPUT_PROD_SIZE);

// Generic Gamepad HID descriptor
extern SI_SEGMENT_VARIABLE(dinput_hid_descriptor[DINPUT_HID_SIZE],
                    const uint8_t,
                    SI_SEG_CODE) =
{
    0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
    0x09, 0x05,        // Usage (Game Pad)
    0xA1, 0x01,        // Collection (Application)

    0x15, 0x00,        //   Logical Minimum (0)
    0x25, 0x01,        //   Logical Maximum (1)
    0x35, 0x00,        //   Physical Minimum (0)
    0x45, 0x01,        //   Physical Maximum (1)
    0x75, 0x01,        //   Report Size (1)
    0x95, 0x0E,        //   Report Count (14)
    0x05, 0x09,        //   Usage Page (Button)
    0x19, 0x01,        //   Usage Minimum (0x01)
    0x29, 0x0E,        //   Usage Maximum (0x0E)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

    0x95, 0x02,        //   Report Count (2)
    0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)

    0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
    0x25, 0x07,        //   Logical Maximum (7)
    0x46, 0x3B, 0x01,  //   Physical Maximum (315)
    0x75, 0x04,        //   Report Size (4)
    0x95, 0x01,        //   Report Count (1)
    0x65, 0x14,        //   Unit (System: English Rotation, Length: Centimeter)
    0x09, 0x39,        //   Usage (Hat switch)
    0x81, 0x42,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
    0x65, 0x00,        //   Unit (None)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)

    0x26, 0xFF, 0x00,  //   Logical Maximum (255)
    0x46, 0xFF, 0x00,  //   Physical Maximum (255)
    0x09, 0x30,        //   Usage (X)
    0x09, 0x31,        //   Usage (Y)
    0x09, 0x32,        //   Usage (Z)
    0x09, 0x35,        //   Usage (Rz)

    // EXPERIMENTAL ADDITIONS
    0x09, 0x33,
    0x09, 0x34,

    0x75, 0x08,        //   Report Size (8)
    0x95, 0x06,        //   Report Count (6)
    0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

    0x75, 0x08,        //   Report Size (8)
    0x95, 0x01,        //   Report Count (1)
    0x81, 0x01,        //   Input (Const,Array,Abs,No Wrap,Linear,Preferred State,No Null Position)
    0x05, 0x0C,        //   Usage Page (Consumer)

    0x09, 0x00,        //   Usage (Unassigned)
    0x15, 0x80,        //   Logical Minimum (-128)
    0x25, 0x7F,        //   Logical Maximum (127)
    0x75, 0x08,        //   Report Size (8)
    0x95, 0x40,        //   Report Count (64)
    0xB1, 0x02,        //   Feature (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)

    0xC0,              // End Collection
    // 94 bytes
};

// Dinput Device Description
extern SI_SEGMENT_VARIABLE(dinput_device_descriptor[],
                    const USB_DeviceDescriptor_TypeDef,
                    SI_SEG_CODE) =
{
  USB_DEVICE_DESCSIZE,             // bLength
  USB_DEVICE_DESCRIPTOR,           // bLength
  htole16(0x0110),                 // bcdUSB
  0,                               // bDeviceClass
  0,                               // bDeviceSubClass
  0,                               // bDeviceProtocol
  64,                              // bMaxPacketSize
  NSPRO_VENDOR_ID,                   // idVendor
  NSPRO_PROD_ID,                  // idProduct
  htole16(0x0100),                 // bcdDevice
  1,                               // iManufacturer
  2,                               // iProduct
  0,                               // iSerialNumber
  1,                               // bNumConfigurations
};

// Dinput Config Description
extern SI_SEGMENT_VARIABLE(dinput_config_descriptor[],
                    const uint8_t,
                    SI_SEG_CODE) =
{
  USB_CONFIG_DESCSIZE,             // bLength
  USB_CONFIG_DESCRIPTOR,           // bLength
  0x22,                            // wTotalLength(LSB)
  0x00,                            // wTotalLength(MSB)
  1,                               // bNumInterfaces
  1,                               // bConfigurationValue
  0,                               // iConfiguration

  CONFIG_DESC_BM_RESERVED_D7,     // bmAttrib: usb powered,

  CONFIG_DESC_MAXPOWER_mA(500),    // bMaxPower: 500 mA

  //Interface 0 Descriptor
  USB_INTERFACE_DESCSIZE,          // bLength
  USB_INTERFACE_DESCRIPTOR,        // bDescriptorType
  0,                               // bInterfaceNumber
  0,                               // bAlternateSetting
  1,                               // bNumEndpoints
  3,                               // bInterfaceClass: HID (Human Interface Device)
  0,                               // bInterfaceSubClass
  0,                               // bInterfaceProtocol
  0,                               // iInterface

  //HID Descriptor
  USB_HID_DESCSIZE,                // bLength
  USB_HID_DESCRIPTOR,              // bLength
  0x11,                            // bcdHID (LSB)
  0x01,                            // bcdHID (MSB)
  0,                               // bCountryCode
  1,                               // bNumDescriptors
  USB_HID_REPORT_DESCRIPTOR,       // bDescriptorType
  sizeof( dinput_hid_descriptor ),     // wDescriptorLength(LSB)
  sizeof( dinput_hid_descriptor ) >> 8,    // wDescriptorLength(MSB)

  //Endpoint 1 IN Descriptor
  USB_ENDPOINT_DESCSIZE,           // bLength
  USB_ENDPOINT_DESCRIPTOR,         // bDescriptorType
  0x81,                            // bEndpointAddress
  USB_EPTYPE_INTR,                 // bAttrib
  0x40,                            // wMaxPacketSize (LSB)
  0x00,                            // wMaxPacketSize (MSB)
  0x02,                            // bInterval (2ms)
};

SI_SEGMENT_VARIABLE_SEGMENT_POINTER(dinput_UsbStringTable_USEnglish[], static const USB_StringDescriptor_TypeDef, SI_SEG_GENERIC, const SI_SEG_CODE) =
{
  (SI_VARIABLE_SEGMENT_POINTER(, uint8_t, SI_SEG_CODE))global_lang_descriptor,
  global_mfr_descriptor,
  dinput_prod_descriptor,
  global_serial_descriptor
};

// dinput initialization Struct
extern SI_SEGMENT_VARIABLE(dinput_init_struct,
                    const USBD_Init_TypeDef,
                    SI_SEG_CODE) =
{
  (SI_VARIABLE_SEGMENT_POINTER(, USB_DeviceDescriptor_TypeDef, SI_SEG_GENERIC))dinput_device_descriptor,              // deviceDescriptor
  (SI_VARIABLE_SEGMENT_POINTER(, USB_ConfigurationDescriptor_TypeDef, SI_SEG_GENERIC))dinput_config_descriptor,       // configDescriptor
  (SI_VARIABLE_SEGMENT_POINTER(, USB_StringTable_TypeDef, SI_SEG_GENERIC))dinput_UsbStringTable_USEnglish,   // stringDescriptors
  sizeof(dinput_UsbStringTable_USEnglish) / sizeof(dinput_UsbStringTable_USEnglish[0])                            // numberOfStrings
};
