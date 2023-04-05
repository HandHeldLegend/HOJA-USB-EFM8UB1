#include "xinput_legacy.h"

xinput_input_s xinput_reportBuffer;

short xinput_sign_value(int input)
{
    int start = (int) input - 127;
    if ((start * 256) > 32765)
    {
        start = 32765;
    }
    else if ((start * 256) < -32765)
    {
        start = -32765;
    }
    else
    {
        start *= 256;
    }
    return (short) start;
}

void xinputUpdateReport()
{
  if (sendReport)
  {

    xinput_reportBuffer.report_id = 0x00;
    xinput_reportBuffer.report_size = XI_INPUT_SIZE;

    // Set all the right bits
    xinput_reportBuffer.buttons_2.button_b    = i2c_input_buffer.buttons_1.button_right;
    xinput_reportBuffer.buttons_2.button_a    = i2c_input_buffer.buttons_1.button_down;
    xinput_reportBuffer.buttons_2.button_y    = i2c_input_buffer.buttons_1.button_up;
    xinput_reportBuffer.buttons_2.button_x    = i2c_input_buffer.buttons_1.button_left;

    xinput_reportBuffer.buttons_2.bumper_l   = i2c_input_buffer.buttons_2.trigger_l;
    xinput_reportBuffer.buttons_2.bumper_r   = i2c_input_buffer.buttons_2.trigger_r;

    if (i2c_input_buffer.buttons_2.trigger_zl)
    {
        xinput_reportBuffer.analog_trigger_l = (255);
    }
    else
    {
        xinput_reportBuffer.analog_trigger_l = (i2c_input_buffer.lt_a);
    }

    if (i2c_input_buffer.buttons_2.trigger_zr)
    {
        xinput_reportBuffer.analog_trigger_r = (255);
    }
    else
    {
        xinput_reportBuffer.analog_trigger_r = (i2c_input_buffer.rt_a);
    }

    xinput_reportBuffer.buttons_1.button_menu     = i2c_input_buffer.buttons_2.button_start;
    xinput_reportBuffer.buttons_1.button_back     = i2c_input_buffer.buttons_2.button_select;

    xinput_reportBuffer.buttons_1.button_stick_left   = i2c_input_buffer.buttons_2.button_stick_left;
    xinput_reportBuffer.buttons_1.button_stick_right  = i2c_input_buffer.buttons_2.button_stick_right;

    xinput_reportBuffer.stick_left_x    = xinput_sign_value((int) i2c_input_buffer.ls_x);
    xinput_reportBuffer.stick_left_y    = xinput_sign_value((int) i2c_input_buffer.ls_y);
    xinput_reportBuffer.stick_right_x   = xinput_sign_value((int) i2c_input_buffer.rs_x);
    xinput_reportBuffer.stick_right_y   = xinput_sign_value((int) i2c_input_buffer.rs_y);

    xinput_reportBuffer.buttons_1.dpad_up     = i2c_input_buffer.buttons_1.dpad_up;
    xinput_reportBuffer.buttons_1.dpad_down   = i2c_input_buffer.buttons_1.dpad_down;
    xinput_reportBuffer.buttons_1.dpad_right  = i2c_input_buffer.buttons_1.dpad_right;
    xinput_reportBuffer.buttons_1.dpad_left   = i2c_input_buffer.buttons_1.dpad_left;

      sendReport = false;
      USBD_Write(EP1IN,
         (uint8_t *) &xinput_reportBuffer,
         XI_INPUT_SIZE,
         true);
  }

}
