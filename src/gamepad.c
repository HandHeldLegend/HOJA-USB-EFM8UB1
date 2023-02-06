/*
 * gamepad.c
 *
 *  Created on: Sep 12, 2022
 *      Author: Mitch
 */

#include "gamepad.h"

Gamepad_USB_Subcore_TypeDef gamepadSubcore = USB_SUBCORE_DINPUT;
Gamepad_System_Status_TypeDef gamepadStatus = GAMEPAD_STATUS_IDLE;
USB_System_Status_TypeDef usbStatus = USB_STATUS_NOBUS;
bool gamepadRumble = false;
bool sendReport = false;

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
    case I2C_CMD_IDLE:
      memset(&tx_buffer, 0, sizeof(tx_buffer));
      break;

    case I2C_CMD_STATUS:
      gamepadCheckStatus();
      break;

    case I2C_CMD_SETMODE:
      gamepadReturnCmd(I2C_RETURN_CMD_IDLE);
      gamepadModeSet((I2C_Command_Setmode_TypeDef) rx_buffer[I2C_SUBCMD_IDX]);
      break;

    case I2C_CMD_SETUSB:
      gamepadReturnCmd(I2C_RETURN_CMD_IDLE);
      gamepadUSBModeSet((Gamepad_USB_Subcore_TypeDef) rx_buffer[I2C_SUBCMD_IDX]);
      break;

    case I2C_CMD_INPUT:
      gamepadReturnCmd(I2C_RETURN_CMD_RUMBLE);
      gamepadInput();
      break;

    case I2C_CMD_CONFIG:
      gamepadReturnCmd(I2C_RETURN_CMD_CONFIG);
      gamepadConfigInput();
      break;
  }
}

void gamepadCheckStatus()
{
  gamepadReturnCmd(I2C_RETURN_CMD_STATUS);
}

// Handle a system command. Stop, start, or reset.
void gamepadModeSet(I2C_Command_Setmode_TypeDef cmd)
{
  uint8_t usbret = USB_STATUS_OK;

  switch(cmd)
  {
      default:
      case I2C_SETMODE_STOP:
        gamepadStop();
        break;

      case I2C_SETMODE_START:
        gamepadStop();

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
                sendReport = true;
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
                sendReport = true;
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
                sendReport = true;
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
                sendReport = true;
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
void gamepadUSBModeSet(Gamepad_USB_Subcore_TypeDef coreType)
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

// Send a USB Input report with config data
void gamepadConfigInput()
{

}


// Pass through config data request to I2C
void gamepadReturnCmd(I2C_Return_Command_TypeDef ret_cmd)
{
  // Clear TX buffer first
  memset(&tx_buffer, 0, sizeof(tx_buffer));

  switch(ret_cmd)
  {
    default:
      break;

    case I2C_RETURN_CMD_STATUS:
      tx_buffer[I2C_COMMAND_IDX] = I2C_RETURN_CMD_STATUS;
      tx_buffer[I2C_DATA_IDX] = usbStatus;
      tx_buffer[I2C_DATA_IDX+1] = gamepadStatus;
      break;

    case I2C_RETURN_CMD_RUMBLE:
      tx_buffer[I2C_COMMAND_IDX] = I2C_RETURN_CMD_RUMBLE;
      tx_buffer[I2C_DATA_IDX] = gamepadRumble;
      break;
  }

  tx_idx = 0;
  tx_remaining = 11;
}
