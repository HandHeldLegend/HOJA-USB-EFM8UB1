/*
 * i2c.c
 *
 *  Created on: Sep 13, 2022
 *      Author: Mitch
 */

#include "i2cbridge.h"
#include <stdio.h>
#include <string.h>

uint8_t rx_buffer[11] = {0};
uint8_t rx_idx = 0;
uint8_t rx_remaining = 9;

bool rx_complete = false;

uint8_t tx_buffer[11] = {0};
uint8_t tx_idx = 0;
uint8_t tx_remaining = 9;

i2c_input_s i2c_input_buffer = {0};
ui2c_return_msg_s ui2c_return_msg = {0};

//-----------------------------------------------------------------------------
// I2C0_ISR
//-----------------------------------------------------------------------------
//
// I2C0 ISR Content goes here. Remember to clear flag bits:
// I2C0STAT::I2C0INT (I2C Interrupt)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT(I2C0_ISR, I2C0_IRQn)
{
  switch (I2C0STAT & I2C_STATUS_VECTOR_MASK) {

    case I2C_ADDR_RD:  // START+ADDR+R
      I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_RD__BMASK);

      tx_idx = 0;
      I2C0DOUT = tx_buffer[tx_idx];  // Write data to buffer for transmitting
      tx_idx+=1;
      break;

    case I2C_ADDR_WR: // START+ADDR+W
      I2C0STAT &= ~(I2C0STAT_START__BMASK | I2C0STAT_WR__BMASK);
      rx_idx = 0;
      break;


    case I2C_RD_DATA:
      // Check for NACK
      if ((I2C0STAT & I2C0STAT_NACK__BMASK) == I2C0STAT_NACK__SET) {
        // Master did not NACK
        // Stopping transfer of data
        // Flush FIFO if there is data in it
        I2C0STAT &= ~I2C0STAT_NACK__BMASK;
      } else { // Prepare data for master

        I2C0DOUT = tx_buffer[tx_idx];
        tx_idx+=1;

      }
      I2C0STAT &= ~I2C0STAT_RD__BMASK;
      break;

    case I2C_WR_DATA:  // FIFO is full, whatever slave ACK/NACK master
      I2C0STAT &= ~I2C0STAT_WR__BMASK;

      break;

    case I2C_STOSTA:
    case I2C_STOSTARD:
      I2C0STAT &= ~I2C0STAT_STOP__BMASK;
      //
      //  STOP Condition received.
      //
      return;   // START Flag set, so re-enter ISR
      break;

    case I2C_STO:
      I2C0STAT &= ~I2C0STAT_STOP__BMASK;
      //
      //  STOP Condition received.
      //memset(&tx_buffer, 0, 11);
      //
      break;
    default:
      break;
  }

  // Poll this bit is also OK
  // while(I2C0FCT&I2C0FCT_RXCNT__FMASK) {
  while((I2C0FCN1 & I2C0FCN1_RXE__BMASK) == I2C0FCN1_RXE__NOT_EMPTY) { // Read data out

      rx_buffer[rx_idx]  = I2C0DIN;

      if (rx_idx == 0)
      {
          rx_remaining = 10;
      }

      rx_idx += 1;
      rx_remaining -= 1;

      if (rx_remaining == 0 && !rx_complete)
      {
        rx_complete = true;
        rx_idx = 0;
      }

  }

  // Clear I2C interrupt flag
  I2C0STAT &= ~I2C0STAT_I2C0INT__BMASK;
}





//-----------------------------------------------------------------------------
// TIMER4_ISR
//-----------------------------------------------------------------------------
//
// TIMER4 ISR Content goes here. Remember to clear flag bits:
// TMR4CN0::TF4H (Timer # High Byte Overflow Flag)
// TMR4CN0::TF4L (Timer # Low Byte Overflow Flag)
//
//-----------------------------------------------------------------------------
SI_INTERRUPT(TIMER4_ISR, TIMER4_IRQn)
{
  SFRPAGE = I2CSLAVE0_PAGE;

  I2C0CN0 &= ~I2C0CN0_I2C0EN__BMASK;      // Disable I2C module
  I2C0CN0 |= I2C0CN0_I2C0EN__ENABLED;     // Re-enable I2C module

  SFRPAGE = TIMER4_PAGE;
  TMR4CN0 &= ~TMR4CN0_TF4H__BMASK;      // Clear Timer3 interrupt-pending flag
}
