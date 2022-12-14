/*
 * dinput.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#include "dinput.h"

dinput_input_s dinput_reportBuffer = {0};

void dinputUpdateReport()
{
  uint8_t lr = 1;
  uint8_t ud = 1;

  // Set all the right bits
  dinput_reportBuffer.buttons_1.button_a    = i2c_input_buffer.buttons_1.button_right;
  dinput_reportBuffer.buttons_1.button_b    = i2c_input_buffer.buttons_1.button_down;
  dinput_reportBuffer.buttons_1.button_x    = i2c_input_buffer.buttons_1.button_up;
  dinput_reportBuffer.buttons_1.button_y    = i2c_input_buffer.buttons_1.button_left;

  dinput_reportBuffer.buttons_1.trigger_l   = i2c_input_buffer.buttons_2.trigger_l;
  dinput_reportBuffer.buttons_1.trigger_r   = i2c_input_buffer.buttons_2.trigger_r;
  dinput_reportBuffer.buttons_1.trigger_zl  = i2c_input_buffer.buttons_2.trigger_zl;
  dinput_reportBuffer.buttons_1.trigger_zr  = i2c_input_buffer.buttons_2.trigger_zr;

  dinput_reportBuffer.buttons_2.button_minus    = i2c_input_buffer.buttons_2.button_select;
  dinput_reportBuffer.buttons_2.button_plus     = i2c_input_buffer.buttons_2.button_start;
  dinput_reportBuffer.buttons_2.button_capture  = i2c_input_buffer.buttons_3.button_capture;
  dinput_reportBuffer.buttons_2.button_home     = i2c_input_buffer.buttons_3.button_home;

  dinput_reportBuffer.buttons_2.stick_left = i2c_input_buffer.buttons_2.button_stick_left;
  dinput_reportBuffer.buttons_2.stick_right = i2c_input_buffer.buttons_2.button_stick_right;

  dinput_reportBuffer.stick_left_x        = i2c_input_buffer.ls_x;
  dinput_reportBuffer.stick_left_y        = i2c_input_buffer.ls_y;
  dinput_reportBuffer.stick_right_x       = i2c_input_buffer.rs_x;
  dinput_reportBuffer.stick_right_y       = i2c_input_buffer.rs_y;
  dinput_reportBuffer.trigger_left_analog   = i2c_input_buffer.lt_a;
  dinput_reportBuffer.trigger_right_analog  = i2c_input_buffer.rt_a;

  lr = 1 - i2c_input_buffer.buttons_1.dpad_left + i2c_input_buffer.buttons_1.dpad_right;
  ud = 1 - i2c_input_buffer.buttons_1.dpad_down + i2c_input_buffer.buttons_1.dpad_up;

  nspro_reportBuffer.dpad_hat    = (uint8_t) getHatDir(DPAD_TYPE_DINPUT, lr, ud);

  if (sendReport)
  {
      sendReport = false;
      USBD_Write(EP1IN,
         (uint8_t *) &dinput_reportBuffer,
         DINPUT_INPUT_SIZE,
         true);
  }

}
