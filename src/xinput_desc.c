/*
 * xinput_desc.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */


#include "xinput_desc.h"

UTF16LE_PACKED_STATIC_CONST_STRING_DESC( xinput_prod_descriptor[], XINPUT_PROD_STRING, XINPUT_PROD_SIZE);

// XinputHID descriptor
extern SI_SEGMENT_VARIABLE(xinput_hid_descriptor[XINPUT_HID_SIZE],
                    const uint8_t,
                    SI_SEG_CODE) =
{
        0x05, 0x01,        // Usage Page (Generic Desktop Ctrls)
        0x09, 0x05,        // Usage (Game Pad)
        0xA1, 0x01,        // Collection (Application)

        // Byte 0
        0x85, 0x01,        //   Report ID (1)

        // Bytes 1, 2, 3, 4 for left stick X and Y
        0x09, 0x01,        //   Usage (Pointer)
        0xA1, 0x00,        //   Collection (Physical)
        0x09, 0x30,        //     Usage (X)
        0x09, 0x31,        //     Usage (Y)
        0x15, 0x00,        //     Logical Minimum (0)
        0x27, 0xFF, 0xFF, 0x00, 0x00,  //     Logical Maximum (65534)
        0x95, 0x02,        //     Report Count (2)
        0x75, 0x10,        //     Report Size (16)
        0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0xC0,              //   End Collection

        // Bytes 4, 5, 6, 7 for right stick X and Y
        0x09, 0x01,        //   Usage (Pointer)
        0xA1, 0x00,        //   Collection (Physical)
        0x09, 0x33,        //     Usage (Rx)
        0x09, 0x34,        //     Usage (Ry)
        0x15, 0x00,        //     Logical Minimum (0)
        0x27, 0xFF, 0xFF, 0x00, 0x00,  //     Logical Maximum (65534)
        0x95, 0x02,        //     Report Count (2)
        0x75, 0x10,        //     Report Size (16)
        0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0xC0,              //   End Collection

        // Bytes 8, 9 for left analog trigger
        0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
        0x09, 0x32,        //   Usage (Z)
        0x15, 0x00,        //   Logical Minimum (0)
        0x26, 0xFF, 0x03,  //   Logical Maximum (1023)
        0x95, 0x01,        //   Report Count (1)
        0x75, 0x0A,        //   Report Size (10)
        0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0x15, 0x00,        //   Logical Minimum (0)
        0x25, 0x00,        //   Logical Maximum (0)
        0x75, 0x06,        //   Report Size (6)
        0x95, 0x01,        //   Report Count (1)
        0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

        // Bytes 10, 11 for right analog trigger
        0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
        0x09, 0x35,        //   Usage (Rz)
        0x15, 0x00,        //   Logical Minimum (0)
        0x26, 0xFF, 0x03,  //   Logical Maximum (1023)
        0x95, 0x01,        //   Report Count (1)
        0x75, 0x0A,        //   Report Size (10)
        0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0x15, 0x00,        //   Logical Minimum (0)
        0x25, 0x00,        //   Logical Maximum (0)
        0x75, 0x06,        //   Report Size (6)
        0x95, 0x01,        //   Report Count (1)
        0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

        // Byte 12 for Hat switch for dpad
        0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
        0x09, 0x39,        //   Usage (Hat switch)
        0x15, 0x01,        //   Logical Minimum (1)
        0x25, 0x08,        //   Logical Maximum (8)
        0x35, 0x00,        //   Physical Minimum (0)
        0x46, 0x3B, 0x01,  //   Physical Maximum (315)
        0x66, 0x14, 0x00,  //   Unit (System: English Rotation, Length: Centimeter)
        0x75, 0x04,        //   Report Size (4)
        0x95, 0x01,        //   Report Count (1)
        0x81, 0x03,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,Null State)
        0x75, 0x04,        //   Report Size (4)
        0x95, 0x01,        //   Report Count (1)
        0x15, 0x00,        //   Logical Minimum (0)
        0x25, 0x00,        //   Logical Maximum (0)
        0x35, 0x00,        //   Physical Minimum (0)
        0x45, 0x00,        //   Physical Maximum (0)
        0x65, 0x00,        //   Unit (None)
        0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

        // Bytes 13 and 14 for buttons_1
        0x05, 0x09,        //   Usage Page (Button)
        0x19, 0x01,        //   Usage Minimum (0x01)
        0x29, 0x0A,        //   Usage Maximum (0x0A)
        0x15, 0x00,        //   Logical Minimum (0)
        0x25, 0x01,        //   Logical Maximum (1)
        0x75, 0x01,        //   Report Size (1)
        0x95, 0x0A,        //   Report Count (10)
        0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0x15, 0x00,        //   Logical Minimum (0)
        0x25, 0x00,        //   Logical Maximum (0)
        0x75, 0x06,        //   Report Size (6)
        0x95, 0x01,        //   Report Count (1)
        0x81, 0x03,        //   Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)

        0x05, 0x01,        //   Usage Page (Generic Desktop Ctrls)
        0x09, 0x80,        //   Usage (Sys Control)
        0x85, 0x02,        //   Report ID (2)
        0xA1, 0x00,        //   Collection (Physical)
        0x09, 0x85,        //     Usage (Sys Main Menu)
        0x15, 0x00,        //     Logical Minimum (0)
        0x25, 0x01,        //     Logical Maximum (1)
        0x95, 0x01,        //     Report Count (1)
        0x75, 0x01,        //     Report Size (1)
        0x81, 0x02,        //     Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0x15, 0x00,        //     Logical Minimum (0)
        0x25, 0x00,        //     Logical Maximum (0)
        0x75, 0x07,        //     Report Size (7)
        0x95, 0x01,        //     Report Count (1)
        0x81, 0x03,        //     Input (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0xC0,              //   End Collection

        0x05, 0x0F,        //   Usage Page (PID Page)
        0x09, 0x21,        //   Usage (0x21)

        0x85, 0x03,        //   Report ID (3)

        0xA1, 0x02,        //   Collection (Logical)
        0x09, 0x97,        //     Usage (0x97)
        0x15, 0x00,        //     Logical Minimum (0)
        0x25, 0x01,        //     Logical Maximum (1)
        0x75, 0x04,        //     Report Size (4)
        0x95, 0x01,        //     Report Count (1)
        0x91, 0x02,        //     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
        0x15, 0x00,        //     Logical Minimum (0)
        0x25, 0x00,        //     Logical Maximum (0)
        0x75, 0x04,        //     Report Size (4)
        0x95, 0x01,        //     Report Count (1)
        0x91, 0x03,        //     Output (Const,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
        0x09, 0x70,        //     Usage (0x70)
        0x15, 0x00,        //     Logical Minimum (0)
        0x25, 0x64,        //     Logical Maximum (100)
        0x75, 0x08,        //     Report Size (8)
        0x95, 0x04,        //     Report Count (4)
        0x91, 0x02,        //     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
        0x09, 0x50,        //     Usage (0x50)
        0x66, 0x01, 0x10,  //     Unit (System: SI Linear, Time: Seconds)
        0x55, 0x0E,        //     Unit Exponent (-2)
        0x15, 0x00,        //     Logical Minimum (0)
        0x26, 0xFF, 0x00,  //     Logical Maximum (255)
        0x75, 0x08,        //     Report Size (8)
        0x95, 0x01,        //     Report Count (1)
        0x91, 0x02,        //     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
        0x09, 0xA7,        //     Usage (0xA7)
        0x15, 0x00,        //     Logical Minimum (0)
        0x26, 0xFF, 0x00,  //     Logical Maximum (255)
        0x75, 0x08,        //     Report Size (8)
        0x95, 0x01,        //     Report Count (1)
        0x91, 0x02,        //     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
        0x65, 0x00,        //     Unit (None)
        0x55, 0x00,        //     Unit Exponent (0)
        0x09, 0x7C,        //     Usage (0x7C)
        0x15, 0x00,        //     Logical Minimum (0)
        0x26, 0xFF, 0x00,  //     Logical Maximum (255)
        0x75, 0x08,        //     Report Size (8)
        0x95, 0x01,        //     Report Count (1)
        0x91, 0x02,        //     Output (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position,Non-volatile)
        0xC0,              //   End Collection
        0x85, 0x04,        //   Report ID (4)
        0x05, 0x06,        //   Usage Page (Generic Dev Ctrls)
        0x09, 0x20,        //   Usage (Battery Strength)
        0x15, 0x00,        //   Logical Minimum (0)
        0x26, 0xFF, 0x00,  //   Logical Maximum (255)
        0x75, 0x08,        //   Report Size (8)
        0x95, 0x01,        //   Report Count (1)
        0x81, 0x02,        //   Input (Data,Var,Abs,No Wrap,Linear,Preferred State,No Null Position)
        0xC0,              // End Collection
        // 306 bytes
};

// Xinput Device Description
extern SI_SEGMENT_VARIABLE(xinput_device_descriptor[],
                    const USB_DeviceDescriptor_TypeDef,
                    SI_SEG_CODE) =
{
  USB_DEVICE_DESCSIZE,             // bLength
  USB_DEVICE_DESCRIPTOR,           // bLength
  htole16(0x0110),                 // bcdUSB
  0x03,                            // bDeviceClass
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
  USB_CONFIG_DESCSIZE,             // bLength
  USB_CONFIG_DESCRIPTOR,           // bLength
  0x29,                            // wTotalLength(LSB)
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
  2,                               // bNumEndpoints
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
  sizeof( xinput_hid_descriptor ),     // wDescriptorLength(LSB)
  sizeof( xinput_hid_descriptor ) >> 8,    // wDescriptorLength(MSB)

  //Endpoint 1 IN Descriptor
  USB_ENDPOINT_DESCSIZE,           // bLength
  USB_ENDPOINT_DESCRIPTOR,         // bDescriptorType
  0x81,                            // bEndpointAddress
  USB_EPTYPE_INTR,                 // bAttrib
  0x40,                            // wMaxPacketSize (LSB)
  0x00,                            // wMaxPacketSize (MSB)
  0x02,                            // bInterval (2ms)

  //Endpoint 2 OUT Descriptor
  USB_ENDPOINT_DESCSIZE,           // bLength
  USB_ENDPOINT_DESCRIPTOR,         // bDescriptorType
  0x02,                            // bEndpointAddress
  USB_EPTYPE_INTR,                 // bAttrib
  0x40,                            // wMaxPacketSize (LSB)
  0x00,                            // wMaxPacketSize (MSB)
  0x04,                            // bInterval (4ms)
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
