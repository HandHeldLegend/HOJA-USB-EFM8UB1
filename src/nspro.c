/*
 * nintendo.c
 *
 *  Created on: Sep 14, 2022
 *      Author: Mitch
 */

#include "nspro.h"

nspro_input_s nspro_reportBuffer = {0};

void nsproUpdateReport()
{
  uint8_t lr = 1;
  uint8_t ud = 1;

  // Set all the right bits
  nspro_reportBuffer.buttons_1.button_a    = i2c_input_buffer.buttons_1.button_right;
  nspro_reportBuffer.buttons_1.button_b    = i2c_input_buffer.buttons_1.button_down;
  nspro_reportBuffer.buttons_1.button_x    = i2c_input_buffer.buttons_1.button_up;
  nspro_reportBuffer.buttons_1.button_y    = i2c_input_buffer.buttons_1.button_left;

  nspro_reportBuffer.buttons_1.trigger_l   = i2c_input_buffer.buttons_2.trigger_l;
  nspro_reportBuffer.buttons_1.trigger_r   = i2c_input_buffer.buttons_2.trigger_r;
  nspro_reportBuffer.buttons_1.trigger_zl  = i2c_input_buffer.buttons_2.trigger_zl;
  nspro_reportBuffer.buttons_1.trigger_zr  = i2c_input_buffer.buttons_2.trigger_zr;

  nspro_reportBuffer.buttons_2.button_minus    = i2c_input_buffer.buttons_2.button_select;
  nspro_reportBuffer.buttons_2.button_plus     = i2c_input_buffer.buttons_2.button_start;
  nspro_reportBuffer.buttons_2.button_capture  = i2c_input_buffer.buttons_3.button_capture;
  nspro_reportBuffer.buttons_2.button_home     = i2c_input_buffer.buttons_3.button_home;

  nspro_reportBuffer.buttons_2.stick_left = i2c_input_buffer.buttons_2.button_stick_left;
  nspro_reportBuffer.buttons_2.stick_right = i2c_input_buffer.buttons_2.button_stick_right;

  nspro_reportBuffer.stick_left_x    = i2c_input_buffer.ls_x;
  nspro_reportBuffer.stick_left_y    = i2c_input_buffer.ls_y;
  nspro_reportBuffer.stick_right_x    = i2c_input_buffer.rs_x;
  nspro_reportBuffer.stick_right_y    = i2c_input_buffer.rs_y;

  lr = 1 - i2c_input_buffer.buttons_1.dpad_left + i2c_input_buffer.buttons_1.dpad_right;
  ud = 1 - i2c_input_buffer.buttons_1.dpad_down + i2c_input_buffer.buttons_1.dpad_up;

  nspro_reportBuffer.dpad_hat    = (uint8_t) getHatDir(DPAD_TYPE_DINPUT, lr, ud);

  if (sendReport)
  {
      sendReport = false;
      USBD_Write(EP1IN,
         (uint8_t *) &nspro_reportBuffer,
         NSPRO_INPUT_SIZE,
         true);
  }

}

