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

typedef enum
{
  I2CB_CMD_CHECKREADY = 0,
  I2CB_CMD_SYSTEMSET  = 1,
  I2CB_CMD_INPUT      = 2,
  I2CB_CMD_USBCHANGE  = 3,

} I2C_Bridge_Command_TypeDef;

#define I2CB_COMMAND_IDX  0
#define I2CB_DATA_IDX     1
#define I2CB_SUBCORE_IDX  2

// System set commands
typedef enum
{
  I2CB_SYSTEM_START = 0,
  I2CB_SYSTEM_STOP  = 1,
  I2CB_SYSTEM_RESET = 2
} I2C_System_Command_TypeDef;


// I2C Response Status Messages
typedef enum
{
  I2CB_OK       = 0,
  I2CB_FAIL     = 1,
  I2CB_NOSTART  = 2,
  I2CB_NOSTOP   = 3,
} I2C_Response_Messsage_TypeDef;

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

extern volatile uint8_t tx_buffer[4];
extern volatile uint8_t tx_idx;
extern volatile uint8_t tx_remaining;

#endif /* INC_I2CBRIDGE_H_ */
