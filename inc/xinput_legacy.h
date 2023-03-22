/*
 * xinput_legacy.h
 *
 *  Created on: Mar 21, 2023
 *      Author: Mitch
 */

#ifndef INC_XINPUT_LEGACY_H_
#define INC_XINPUT_LEGACY_H_

#include "usb_includes.h"

#define XI_INPUT_SIZE 20

typedef struct xinput_input
{
    uint8_t report_id;
    uint8_t report_size;

    struct
    {
        uint8_t dpad_up     : 1;
        uint8_t dpad_down   : 1;
        uint8_t dpad_left      : 1;
        uint8_t dpad_right      : 1;
        uint8_t button_menu     : 1;
        uint8_t button_back     : 1;
        uint8_t button_stick_left  : 1;
        uint8_t button_stick_right  : 1;
    } buttons_1;

    struct
    {
        uint8_t bumper_l    : 1;
        uint8_t bumper_r    : 1;
        uint8_t button_guide: 1;
        uint8_t blank_1     : 1;
        uint8_t button_a    : 1;
        uint8_t button_b    : 1;
        uint8_t button_x    : 1;
        uint8_t button_y    : 1;
    } buttons_2;

    uint8_t analog_trigger_l;
    uint8_t analog_trigger_r;
    short stick_left_x;
    short stick_left_y;
    short stick_right_x;
    short stick_right_y;
    uint8_t reserved_1[6];

} xinput_input_s;

extern xinput_input_s xinput_reportBuffer;

void xinputUpdateReport(void);

#endif /* INC_XINPUT_LEGACY_H_ */
