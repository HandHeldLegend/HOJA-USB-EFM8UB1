/*
 * xinput.h
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#ifndef INC_XINPUT__H_
#define INC_XINPUT__H_

#include "usb_includes.h"

#define XI_INPUT_SIZE 16

// Input structure for Xinput USB gamepad Data
typedef struct xinput_input
{
    uint8_t   report_id;
    uint16_t  stick_left_x;
    uint16_t  stick_left_y;
    uint16_t  stick_right_x;
    uint16_t  stick_right_y;

    uint16_t  analog_trigger_l;
    uint16_t  analog_trigger_r;

    struct
    {
      uint8_t dpad_hat        : 4;
      uint8_t dpad_padding    : 4;
    } dpad;

    struct
    {
      uint8_t button_a    : 1;
      uint8_t button_b    : 1;
      uint8_t button_x    : 1;
      uint8_t button_y    : 1;
      uint8_t bumper_l    : 1;
      uint8_t bumper_r    : 1;
      uint8_t button_back : 1;
      uint8_t button_menu : 1;
    } buttons_1;

    struct
    {
      uint8_t button_stick_left     : 1;
      uint8_t button_stick_right    : 1;
      uint8_t padding : 6;
    } buttons_2;


} xinput_input_s;

extern xinput_input_s xinput_reportBuffer;

void xinputUpdateReport(void);

#endif /* INC_XINPUT__H_ */
