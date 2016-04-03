/*
 * serialTransmit.h
 *
 *  Created on: 29. feb. 2016
 *      Author: Róbert
 */

#ifndef SERIAL_H_
#define SERIAL_H_

#define FOSC 16000000 // clock speed
#define BAUD 9600
#define BRC  ((FOSC/16/BAUD)-1)
#define BUFFERSIZE 128

char serialBuffer[BUFFERSIZE];



void appendSerial(char c); //svipad og transmitByte
void serialWrite(char c[]); // svipad og printString
void serialPrintDec(int value);
void Init_Uart ();
//*****************************//
void transmitByte(int data);
int receiveByte(void);
void printString(const char myString[]);

#endif /* SERIAL_H_ */
