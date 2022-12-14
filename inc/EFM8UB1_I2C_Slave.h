//-----------------------------------------------------------------------------
// EFM8BB2_I2C_Slave.h
//-----------------------------------------------------------------------------
// Copyright 2017 Silicon Laboratories, Inc.
// http://developer.silabs.com/legal/version/v11/Silicon_Labs_Software_License_Agreement.txt
//
// Header for main file:

#ifndef I2C_SLAVE_H_
#define I2C_SLAVE_H_

//-----------------------------------------------------------------------------
// Pin Definitions
//-----------------------------------------------------------------------------

#define LED_ON   0
#define LED_OFF  1

#define DISP_BC_DRIVEN   0             // 0 = Board Controller drives display
#define DISP_EFM8_DRIVEN 1             // 1 = EFM8 drives display

//-----------------------------------------------------------------------------
// Global Constants
//-----------------------------------------------------------------------------
#define  SYSCLK               24500000 // System clock frequency in Hz

#define  WRITE                    0x00 // I2C WRITE command
#define  READ                     0x01 // I2C READ command

#define  SLAVE_ADDR               0xF0 // Device addresses (7 bits,
                                       // lsb is a don't care).
                                       // Set (SLAVE_ADDR>>1) to sfr I2C0SLAD

#define  I2C_STATUS_VECTOR_MASK  0x0F   // NACK, START, STOP, WR, RD
// I2C States
#define  I2C_ADDR_RD    0x09			// Valid Slave Address + Master Read Request
#define  I2C_ADDR_WR    0x0A			// Valid Slave Address + Master Write Request
#define  I2C_RD_DATA    0x01			// Transfer data from Slave (Also can check
                                        // B4 to see what ACK we just received from master)
#define  I2C_WR_DATA    0x02			// Write data to Slave (Also can check B4 to
                                        // see what ACK(ACK/NACK) we just sent)
#define  I2C_STO        0x04
#define  I2C_STOSTA     0x0C
#define  I2C_STOSTARD   0x0D

// End status vector definition


#endif // I2C_SLAVE_H_
