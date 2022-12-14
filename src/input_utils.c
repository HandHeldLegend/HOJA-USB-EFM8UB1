/*
 * input_utils.c
 *
 *  Created on: Dec 13, 2022
 *      Author: Mitch
 */

#include "input_utils.h"

uint8_t getHatDir(Input_Hat_Type type, uint8_t leftRight, uint8_t upDown)
{
  uint8_t ret = 0x00;
  switch(type)
  {
      default:
      case DPAD_TYPE_DINPUT:
        ret = HAT_CENTER;
        if (leftRight == 2)
        {
          ret = HAT_RIGHT;
          if (upDown == 2)
          {
            ret = HAT_TOP_RIGHT;
          }
          else if (upDown == 0)
          {
            ret = HAT_BOTTOM_RIGHT;
          }
        }
        else if (leftRight == 0)
        {
          ret = HAT_LEFT;
          if (upDown == 2)
          {
            ret = HAT_TOP_LEFT;
          }
          else if (upDown == 0)
          {
            ret = HAT_BOTTOM_LEFT;
          }
        }

        else if (upDown == 2)
        {
          ret = HAT_TOP;
        }
        else if (upDown == 0)
        {
          ret = HAT_BOTTOM;
        }
        break;

      case DPAD_TYPE_XINPUT:
        ret = XI_HAT_CENTER;
        if (leftRight == 2)
        {
          ret = XI_HAT_RIGHT;
          if (upDown == 2)
          {
            ret = XI_HAT_TOP_RIGHT;
          }
          else if (upDown == 0)
          {
            ret = XI_HAT_BOTTOM_RIGHT;
          }
        }
        else if (leftRight == 0)
        {
          ret = XI_HAT_LEFT;
          if (upDown == 2)
          {
            ret = XI_HAT_TOP_LEFT;
          }
          else if (upDown == 0)
          {
            ret = XI_HAT_BOTTOM_LEFT;
          }
        }

        else if (upDown == 2)
        {
          ret = XI_HAT_TOP;
        }
        else if (upDown == 0)
        {
          ret = XI_HAT_BOTTOM;
        }
        break;
    }
    return ret;
}

