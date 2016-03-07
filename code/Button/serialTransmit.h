/*
 * serialTransmit.h
 *
 *  Created on: 29. feb. 2016
 *      Author: Róbert
 */

#ifndef SERIALTRANSMIT_H_
#define SERIALTRANSMIT_H_

#define FOSC 16000000 // clock speed
#define BAUD 9600
#define BRC  ((FOSC/16/BAUD)-1)
#define BUFFERSIZE 128

char serialBuffer[BUFFERSIZE];



void appendSerial(char c);
void serialWrite(char c[]);
void serialPrintDec(int value);
void Init_Uart ();

#endif /* SERIALTRANSMIT_H_ */
