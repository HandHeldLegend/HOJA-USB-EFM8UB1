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

// Shortcuts for I2C data indexes
#define I2C_COMMAND_IDX  0
#define I2C_DATA_IDX     1

#define I2C_SUBCMD_IDX 1

#define I2C_SUBCORE_IDX  2
#define I2C_CONFIG_IDX   2

typedef enum
{
  I2C_CMD_IDLE,    // No command
  I2C_CMD_STATUS,  // Returns the current USB status and gamepadStatus
  I2C_CMD_SETMODE, // Start, stop, or reset USB function
  I2C_CMD_SETUSB,  // Set the current USB input mode
  I2C_CMD_INPUT,   // Sends an Input report over USB
  I2C_CMD_CONFIG,  // Sends a configuration report over USB

} I2C_Command_TypeDef;

typedef enum
{
  I2C_RETURN_CMD_IDLE,  // No return data
  I2C_RETURN_CMD_STATUS,// Return status data of USB and Gamepad
  I2C_RETURN_CMD_RUMBLE,// Return any rumble status if it's changed
  I2C_RETURN_CMD_CONFIG,// Return any configuration request
} I2C_Return_Command_TypeDef;

typedef enum
{
  I2C_CONFIG_SAVERESET,
  I2C_CONFIG_GETALL,
  I2C_CONFIG_ANALOG_CALIBRATION,
  I2C_CONFIG_TRIGGER_SENSITIVITY,
  I2C_CONFIG_TRIGGER_MODE,
  I2C_CONFIG_CALIBRATE_SET,
} I2C_Config_TypeDef;

// System set commands
typedef enum
{
  I2C_SETMODE_START = 0,
  I2C_SETMODE_STOP  = 1,
  I2C_SETMODE_RESET = 2
} I2C_Command_Setmode_TypeDef;


// I2C Response Status Messages
typedef enum
{
  I2C_OK       = 0,  // Message and command executed OK
  I2C_FAIL     = 1,  // Message and command did not execute OK
} I2C_Response_Message_TypeDef;

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
