/*
 * dinput.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#ifndef INC_DINPUT_H_
#define INC_DINPUT_H_

#include "usb_includes.h"

#define DINPUT_INPUT_SIZE 10

// Input structure for Nintendo Switch USB gamepad Data
typedef struct dinput_input
{
  uint8_t report_id;

  struct
  {
   uint8_t button_y    : 1;
   uint8_t button_b    : 1;
   uint8_t button_a    : 1;
   uint8_t button_x    : 1;
   uint8_t trigger_l   : 1;
   uint8_t trigger_r   : 1;
   uint8_t trigger_zl  : 1;
   uint8_t trigger_zr  : 1;
  } buttons_1;

  struct
  {
    uint8_t button_minus  : 1;
    uint8_t button_plus   : 1;
    uint8_t stick_left    : 1;
    uint8_t stick_right   : 1;
    uint8_t button_home   : 1;
    uint8_t button_capture: 1;
    uint8_t dummy_1       : 2;
  } buttons_2;

  uint8_t dpad_hat;
  uint8_t stick_left_x;
  uint8_t stick_left_y;
  uint8_t stick_right_x;
  uint8_t stick_right_y;
  uint8_t trigger_left_analog;
  uint8_t trigger_right_analog;

} dinput_input_s;

extern dinput_input_s dinput_reportBuffer;

void dinputUpdateReport(void);

#endif /* INC_DINPUT_H_ */
