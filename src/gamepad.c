/*
 * gamepad.c
 *
 *  Created on: Sep 12, 2022
 *      Author: Mitch
 */

#include "gamepad.h"

Gamepad_USB_Subcore_TypeDef gamepadSubcore = USB_SUBCORE_DINPUT;
Gamepad_System_Status_TypeDef gamepadStatus = GAMEPAD_STATUS_NOCONNECT;
bool sendReport = false;

void gamepadCmd()
{
  switch (rx_buffer[I2CB_COMMAND_IDX])
  {
    default:
    case I2CB_CMD_CHECKREADY:
      gamepadCheckReady();
      break;
    case I2CB_CMD_SYSTEMSET:
      gamepadSysSet((Gamepad_System_Set_TypeDef) rx_buffer[I2CB_DATA_IDX]);
      break;
    case I2CB_CMD_INPUT:
      gamepadInput();
      break;
  }
}

void gamepadCheckReady()
{
    tx_buffer[I2CB_COMMAND_IDX] = 0x00;
    tx_buffer[I2CB_DATA_IDX] = gamepadStatus;
    tx_idx = 0;
    tx_remaining = 2;
}

void gamepadSysSet(Gamepad_System_Set_TypeDef setting)
{
  I2C_Response_Messsage_TypeDef ret = I2CB_FAIL;
  uint8_t usbret = USB_STATUS_OK;

  switch (setting)
  {
    default:
    case SYSTEM_SET_STARTUSB:
      ret = gamepadSetSubcore((Gamepad_USB_Subcore_TypeDef) rx_buffer[I2CB_SUBCORE_IDX]);
      break;
    case SYSTEM_SET_STOPUSB:
      USBD_Stop();
      ret = I2CB_OK;
      break;
    case SYSTEM_SET_SLEEPUSB:
      USBD_Stop();
      ret = I2CB_OK;
      break;
    case SYSTEM_SET_RESETUSB:
      USBD_Stop();
      ret = I2CB_OK;
      RSTSRC |= RSTSRC_SWRSF__BMASK;
      break;
  }

  tx_buffer[I2CB_COMMAND_IDX] = ret;
  tx_idx = 0;
  tx_remaining = 1;
}

void gamepadInput()
{
  memcpy(&i2c_input_buffer, &rx_buffer[1], I2C_INPUT_SIZE);
  switch(gamepadSubcore)
  {
    default:
    case USB_SUBCORE_DINPUT:
      dinputUpdateReport();
      break;
    case USB_SUBCORE_NS:
      nsproUpdateReport();
      break;
    case USB_SUBCORE_XINPUT:
      xinputUpdateReport();
      break;
    case USB_SUBCORE_GCINPUT:
      break;
  }
}

I2C_Response_Messsage_TypeDef gamepadSetSubcore(Gamepad_USB_Subcore_TypeDef mode)
{
  uint8_t usbret = USB_STATUS_OK;
  I2C_Response_Messsage_TypeDef ret = I2CB_FAIL;
  switch (mode)
  {
    default:
    case USB_SUBCORE_DINPUT:
      usbret = USBD_Init(&dinput_init_struct);
      if (usbret != USB_STATUS_OK)
      {
        ret = I2CB_FAIL;
      }
      else if (usbret == USB_STATUS_OK)
      {
        gamepadSubcore = USB_SUBCORE_DINPUT;
        ret = I2CB_OK;
        sendReport = true;
      }
      break;

    case USB_SUBCORE_NS:
      usbret = USBD_Init(&nspro_init_struct);
      if (usbret != USB_STATUS_OK)
      {
        ret = I2CB_FAIL;
      }
      else if (usbret == USB_STATUS_OK)
      {
        ret = I2CB_OK;
        gamepadSubcore = USB_SUBCORE_NS;
        sendReport = true;
      }
      break;

    case USB_SUBCORE_XINPUT:
      usbret = USBD_Init(&xinput_init_struct);
      if (usbret != USB_STATUS_OK)
      {
        ret = I2CB_FAIL;
      }
      else if (usbret == USB_STATUS_OK)
      {
        ret = I2CB_OK;
        gamepadSubcore = USB_SUBCORE_XINPUT;
        sendReport = true;
      }
      break;

    case USB_SUBCORE_GCINPUT:
      usbret = USBD_Init(&nspro_init_struct);
      if (usbret != USB_STATUS_OK)
      {
        ret = I2CB_FAIL;
      }
      else if (usbret == USB_STATUS_OK)
      {
        ret = I2CB_OK;
        gamepadSubcore = USB_SUBCORE_NS;
        sendReport = true;
      }
      break;
  }

  return ret;
}
