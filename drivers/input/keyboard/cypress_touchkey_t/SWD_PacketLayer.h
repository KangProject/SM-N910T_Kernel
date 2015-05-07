/*
 * SWD_PacketLayer.h
 * Cypress CapSense FW download packet layer interface.
 * Supported parts include:
 * CY8C40XXX
 *
 * Copyright (C) 2012-2013 Cypress Semiconductor, Inc.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2, and only version 2, as published by the
 * Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Contact Cypress Semiconductor at www.cypress.com <ttdrivers@cypress.com>
 *
 */


#ifndef __SWD_PACKETLAYER_H
#define __SWD_PACKETLAYER_H

#include <linux/slab.h>

/******************************************************************************
*   Constant definitions
******************************************************************************/
/* Data size of a SWD Packet in bytes */
#define DATA_BYTES_PER_PACKET   4

/* Number of dummy SWDCK clocks at end of each SWD packet.
   Required for bit banging programmers where clock is not free running  */
#define NUMBER_OF_DUMMY_SWD_CLOCK_CYCLES    3 

/* Minimum number of SWDCK clock cycles to reset the SWD line state */
#define NUMBER_OF_SWD_RESET_CLOCK_CYCLES    60

/* ACK response in a SWD packet is a 3-bit value */
#define NUMBER_OF_ACK_BITS  3

/* SWD ACK response meanings.
*  Parity error definition is not part of SWD ACK response from target PSoC 4.
*  The actual ACK response is only 3-bit length. The parity error bit is 
*  defined as fourth bit by host application. It is generated by host if there
*  is a parity error in the SWD Read packet data from target PSoC 4 */ 
#define SWD_OK_ACK          0x01
#define SWD_WAIT_ACK        0x02
#define SWD_FAULT_ACK       0x04
#define SWD_PARITY_ERROR    0x08

/* Maximum SWD packet loop timeout for SWD_WAIT_ACK response */
#define NUMBER_OF_WAIT_ACK_LOOPS    5

/* Mask value to define Most significant bit (MSb) in a Byte */
#define MSB_BIT_MASK 		0x80
/* Mask value to define Least significant bit (LSb) in a Byte */
#define LSB_BIT_MASK 		0x01

/******************************************************************************
*   Global Variable declaration
******************************************************************************/
/* The below global variables are accessed by the upper layer files to create
   SWD packet header, ACK, data */
   
extern u8 swd_PacketHeader; 
extern u8 swd_PacketAck;    
extern u8 swd_PacketData[DATA_BYTES_PER_PACKET];

/******************************************************************************
*   Function Prototypes
******************************************************************************/
/* The below public fuctions are called by the upper layer files to send SWD
   packets */
void Swd_WritePacket(void);
void Swd_ReadPacket(void);
void Swd_LineReset(void);

void Swd_configPhysical(int swdio_gpio, int swdck_gpio);

#endif /* __SWD_PACKETLAYER_H */


/* [] END OF FILE */