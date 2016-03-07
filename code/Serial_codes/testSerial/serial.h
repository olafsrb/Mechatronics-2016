/*
 * serial.h
 *
 *  Created on: 13. feb. 2016
 *      Author: Róbert
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#define FOSC 16000000 // clock speed
#define BAUD 57600 // baudrate
#define BRCALC FOSC/16/BAUD-1 // =17,361
#define LEDPORT PORTB
#define LEDPIN PINB
#define LEDDDR DDRB

void Init_Uart ();

#endif /* SERIAL_H_ */
