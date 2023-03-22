/*
 * gamepad.c
 *
 *  Created on: Sep 12, 2022
 *      Author: Mitch
 */

#include "gamepad.h"

usb_subcore_t gamepadSubcore = USB_SUBCORE_DINPUT;
ui2c_gamepad_status_t gamepadStatus = GAMEPAD_STATUS_IDLE;
ui2c_usb_status_t usbStatus = USB_STATUS_NOBUS;

bool sendReport = false;

bool gpRumble         = false; // Flag that toggles rumble on/off
bool gpConfigRequest  = false; // Flag that tells the I2C master to send back config data
bool gpConfigWrite    = false; // Flag that tells the I2C master to write config data
uint8_t gpConfigData[8] = {0}; // Tmp storage for what data to send

// Stop the USB mode from running if it's running
void gamepadStop()
{
  // Clear USB if we are already running.
  if (gamepadStatus != GAMEPAD_STATUS_IDLE)
  {
    // Stop the current USB and change the mode.
    sendReport = false;
    USBD_Stop();
    gamepadStatus = GAMEPAD_STATUS_IDLE;
  }
}

// Handle an I2C gamepad command
void gamepadCmd()
{
  // Check the command byte which is the first byte of the I2C rx
  switch (rx_buffer[I2C_COMMAND_IDX])
  {
    default:
    case I2C_SYSCMD_IDLE:
      break;

    case I2C_SYSCMD_SETUSB:
      gamepadUSBModeSet((usb_subcore_t) rx_buffer[I2C_SUBCMD_IDX]);
      break;

    case I2C_SYSCMD_SETMODE:
      gamepadModeSet((ui2c_setmode_t) rx_buffer[I2C_SUBCMD_IDX]);
      break;

    case I2C_SYSCMD_INPUT:
      gamepadInput();
      break;

    case I2C_SYSCMD_CONFIG:
      gamepadConfigInput();
      break;
  }
  gamepadReturnCmd();
}

// Handle a system command. Stop, start, or reset.
void gamepadModeSet(ui2c_setmode_t cmd)
{
  uint8_t usbret = USB_STATUS_OK;

  switch(cmd)
  {
      default:
      case I2C_SETMODE_STOP:
        gamepadStop();
        break;

      case I2C_SETMODE_START:

        if (gamepadStatus == GAMEPAD_STATUS_INITIALIZED)
        {
          return;
        }
        switch(gamepadSubcore)
        {
          default:
              break;

          case USB_SUBCORE_DINPUT:
              // Start USB
              usbret = USBD_Init(&dinput_init_struct);
              if (usbret != USB_STATUS_OK)
              {
                // Change nothing if we fail
                return;
              }
              else if (usbret == USB_STATUS_OK)
              {
                gamepadStatus = GAMEPAD_STATUS_INITIALIZED;
                return;
              }
              break;

          case USB_SUBCORE_NS:
              // Start USB
              usbret = USBD_Init(&nspro_init_struct);
              if (usbret != USB_STATUS_OK)
              {
                // Change nothing if we fail
                return;
              }
              else if (usbret == USB_STATUS_OK)
              {
                gamepadStatus = GAMEPAD_STATUS_INITIALIZED;
                return;
              }
              break;

          case USB_SUBCORE_XINPUT:
              // Start USB
              usbret = USBD_Init(&xinput_init_struct);
              if (usbret != USB_STATUS_OK)
              {
                // Change nothing if we fail
                return;
              }
              else if (usbret == USB_STATUS_OK)
              {
                  gamepadStatus = GAMEPAD_STATUS_INITIALIZED;
                return;
              }
              break;

          case USB_SUBCORE_GCINPUT:
              // Start USB
              usbret = USBD_Init(&nspro_init_struct);
              if (usbret != USB_STATUS_OK)
              {
                // Change nothing if we fail
                return;
              }
              else if (usbret == USB_STATUS_OK)
              {
                gamepadStatus = GAMEPAD_STATUS_INITIALIZED;
                return;
              }
              break;
        }
        break;

      case I2C_SETMODE_RESET:
        gamepadModeSet(I2C_SETMODE_STOP);
        gamepadModeSet(I2C_SETMODE_START);
        break;
  }
}

// Set the USB Gamepad mode
void gamepadUSBModeSet(usb_subcore_t coreType)
{
    // Make sure we are IDLE
    gamepadStop();
    gamepadSubcore = USB_SUBCORE_IDLE;
    gamepadSubcore = coreType;
}

// Send a USB Input report with gamepad data
void gamepadInput()
{
  if (usbStatus != USB_STATUS_BUSOK)
  {
      return;
  }
  else
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

}

// Send a USB Input report with config data
void gamepadConfigInput()
{

}

bool first_set = false;

// Pass through config data request to I2C
void gamepadReturnCmd()
{
  if (!first_set)
  {
      // Clear TX buffer first
      memset(&tx_buffer, 0, sizeof(tx_buffer));
      first_set = true;
  }

  ui2c_return_msg.rumble         = gpRumble;
  ui2c_return_msg.config_request = gpConfigRequest;
  ui2c_return_msg.config_write   = gpConfigWrite;
  ui2c_return_msg.gamepad_status = gamepadStatus;
  ui2c_return_msg.usb_status     = (usbStatus == USB_STATUS_BUSOK);

  if (gpConfigWrite)
    {

      memcpy(&tx_buffer[1], gpConfigData, 9);
      gpConfigWrite = false;
    }

  if (gpConfigRequest)
  {

    memcpy(&tx_buffer[1], gpConfigData, 9);
    gpConfigRequest = false;
  }

  memcpy(&tx_buffer[0], &ui2c_return_msg, sizeof(uint8_t));

  tx_idx = 0;
  tx_remaining = 11;
}
