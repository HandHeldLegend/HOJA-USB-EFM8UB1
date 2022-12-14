/*
 * xinput.c
 *
 *  Created on: Sep 10, 2022
 *      Author: Mitch
 */

#include "xinput_.h"

xinput_input_s xinput_reportBuffer = {0};

void xinputUpdateReport()
{
  uint8_t lr = 1;
  uint8_t ud = 1;

  xinput_reportBuffer.report_id = 0x01;

  // Set all the right bits
  xinput_reportBuffer.buttons_1.button_b    = i2c_input_buffer.buttons_1.button_right;
  xinput_reportBuffer.buttons_1.button_a    = i2c_input_buffer.buttons_1.button_down;
  xinput_reportBuffer.buttons_1.button_y    = i2c_input_buffer.buttons_1.button_up;
  xinput_reportBuffer.buttons_1.button_x    = i2c_input_buffer.buttons_1.button_left;

  xinput_reportBuffer.buttons_1.bumper_l   = i2c_input_buffer.buttons_2.trigger_l;
  xinput_reportBuffer.buttons_1.bumper_r   = i2c_input_buffer.buttons_2.trigger_r;

  if (i2c_input_buffer.buttons_2.trigger_zl)
  {
      xinput_reportBuffer.analog_trigger_l = (255 << 2);
  }
  else
  {
      xinput_reportBuffer.analog_trigger_l = (i2c_input_buffer.lt_a << 2);
  }

  if (i2c_input_buffer.buttons_2.trigger_zr)
  {
      xinput_reportBuffer.analog_trigger_r = (255 << 2);
  }
  else
  {
      xinput_reportBuffer.analog_trigger_r = (i2c_input_buffer.rt_a << 2);
  }

  xinput_reportBuffer.buttons_1.button_menu     = i2c_input_buffer.buttons_2.button_start;
  xinput_reportBuffer.buttons_1.button_back     = i2c_input_buffer.buttons_2.button_select;

  xinput_reportBuffer.buttons_2.button_stick_left = i2c_input_buffer.buttons_2.button_stick_left;
  xinput_reportBuffer.buttons_2.button_stick_right = i2c_input_buffer.buttons_2.button_stick_right;

  xinput_reportBuffer.stick_left_x    = (i2c_input_buffer.ls_x);
  xinput_reportBuffer.stick_left_y    = (i2c_input_buffer.ls_y);
  xinput_reportBuffer.stick_right_x    = (i2c_input_buffer.rs_x);
  xinput_reportBuffer.stick_right_y    = (i2c_input_buffer.rs_y);

  lr = 1 - i2c_input_buffer.buttons_1.dpad_left + i2c_input_buffer.buttons_1.dpad_right;
  ud = 1 - i2c_input_buffer.buttons_1.dpad_down + i2c_input_buffer.buttons_1.dpad_up;

  xinput_reportBuffer.dpad.dpad_hat    = (uint8_t) getHatDir(DPAD_TYPE_XINPUT, lr, ud);

  if (sendReport)
  {
      sendReport = false;
      USBD_Write(EP1IN,
         (uint8_t *) &xinput_reportBuffer,
         XI_INPUT_SIZE,
         true);
  }

}

