/*
 * i2cbridge.h
 *
 *  Created on: Sep 13, 2022
 *      Author: Mitch
 */

#ifndef INC_I2CBRIDGE_H_
#define INC_I2CBRIDGE_H_

#include <SI_EFM8UB1_Register_Enums.h>
#include "EFM8UB1_I2C_Slave.h"

// Defines for i2c custom protocol information
#define I2C_SLAVE_ADDR    0x45

// Shortcuts for I2C data indexes
#define I2C_COMMAND_IDX  0
#define I2C_DATA_IDX     1

#define I2C_SUBCMD_IDX 1

#define I2C_SUBCORE_IDX  2
#define I2C_CONFIG_IDX   2

// Return message format for I2C transactions
typedef struct ui2c_return_msg
{
  uint8_t rumble          : 1; // Rumble is enabled or disabled
  uint8_t gamepad_status  : 1; // Gamepad is initialized or not
  uint8_t usb_status      : 1; // USB is plugged in or not
  uint8_t config_request  : 1; // Configuration request submitted
  uint8_t config_write    : 1; // Configuration write submitted
  uint8_t padding         : 3; // Padding (unused)
} ui2c_return_msg_s;

extern ui2c_return_msg_s ui2c_return_msg;

typedef enum
{
  GAMEPAD_STATUS_IDLE,
  GAMEPAD_STATUS_INITIALIZED,
} ui2c_gamepad_status_t;

typedef enum
{
  USB_STATUS_NOBUS,
  USB_STATUS_ATTACHED,
  USB_STATUS_BUSOK,
} ui2c_usb_status_t;

typedef enum
{
  I2C_SYSCMD_IDLE = 0,  // No command
  I2C_SYSCMD_SETUSB,    // Set the current USB input mode
  I2C_SYSCMD_SETMODE,   // Start, stop, or reset USB function
  I2C_SYSCMD_INPUT,     // Standard input
  I2C_SYSCMD_CONFIG,    // Sends a configuration report over USB

} ui2c_syscmd_t;

typedef enum
{
  USB_SUBCORE_IDLE    = 0,
  USB_SUBCORE_DINPUT  = 1,
  USB_SUBCORE_NS      = 2,
  USB_SUBCORE_XINPUT  = 3,
  USB_SUBCORE_GCINPUT = 4,
  USB_SUBCORE_MAX,
} usb_subcore_t;

typedef enum
{
  I2C_CONFIGCMD_SAVERESET,
  I2C_CONFIGCMD_GETALL,
  I2C_CONFIGCMD_ANALOG_CALIBRATION,
  I2C_CONFIGCMD_TRIGGER_SENSITIVITY,
  I2C_CONFIGCMD_TRIGGER_MODE,
  I2C_CONFIGCMD_CALIBRATE_SET,
} ui2c_configcmd_t;

// System set commands
typedef enum
{
  I2C_SETMODE_STOP,
  I2C_SETMODE_START,
  I2C_SETMODE_RESET,
} ui2c_setmode_t;

// I2C gamepad struct format
typedef struct i2c_input
{
  struct
  {
    uint8_t dpad_up       : 1;
    uint8_t dpad_down     : 1;
    uint8_t dpad_left     : 1;
    uint8_t dpad_right    : 1;
    uint8_t button_up     : 1;
    uint8_t button_down   : 1;
    uint8_t button_left   : 1;
    uint8_t button_right  : 1;
  } buttons_1;

  struct
  {
    uint8_t trigger_l               : 1;
    uint8_t trigger_zl              : 1;
    uint8_t trigger_r               : 1;
    uint8_t trigger_zr              : 1;
    uint8_t button_start            : 1;
    uint8_t button_select           : 1;
    uint8_t button_stick_left       : 1;
    uint8_t button_stick_right      : 1;
  } buttons_2;

  struct
  {
    uint8_t button_capture  : 1;
    uint8_t button_home     : 1;
    uint8_t padding         : 6;
  } buttons_3;

  uint8_t ls_x;
  uint8_t ls_y;
  uint8_t rs_x;
  uint8_t rs_y;
  uint8_t lt_a;
  uint8_t rt_a;

} i2c_input_s;

extern i2c_input_s i2c_input_buffer;

#define I2C_INPUT_SIZE  9

extern volatile uint8_t rx_buffer[11];
extern volatile uint8_t rx_idx;
extern volatile uint8_t rx_remaining;

extern volatile bool rx_complete;

extern volatile uint8_t tx_buffer[11];
extern volatile uint8_t tx_idx;
extern volatile uint8_t tx_remaining;

#endif /* INC_I2CBRIDGE_H_ */
