/*
 * main.c
 *
 *  Created on: 23. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"

#define FOSC 16000000 // clock speed
#define BAUD 9600
#define BRC  ((FOSC/16/BAUD)-1)       //FOSC/16/BAUD-1
#define BUFFERSIZE 128

char serialBuffer[BUFFERSIZE];
uint8_t writePos = 0;
uint8_t readPos = 0;

void init(void);
void writeCursor(void);
void readCursor(void);
void init(void);
char getMessage(void);
void sendMessage(char data[]);
void append(char data);

int main()
{
//	init();
//
//	while (1)
//	{
//		if (getMessage() == '1')
//		{
//			//appendString('h');
//		}
//
//		else
//		{
//			//appendString(string);
//			//delay_ms(3000);
//		}
//	}
	return 0;
}


void init(void)
{
	UBRR0H = (unsigned char)(BRC >> 8); // baudrate = 57600
	UBRR0L = (unsigned char)(BRC);

	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

char receiveMessage(void)
{
	while(!(UCSR0A & (1 << RXC0))) // receive complete for USART
		;
	return UDR0; // receive data buffer register
}

void transmitMessage(char data[])
{
	for(uint8_t i = 0; i != strlen(data); i++) // transmitting data
		{
			append(data[i]);
		}

}

void append(char data) // append data to the buffer and increment the cursor
{
//	int  write = 1;
//	if(write == 1)
	//if (UCSR0A &= (1 << TXC0))

		serialBuffer[writePos] = data;
		writeCursor();

//	else
//	{
//		serialBuffer[readPos] = data;
//		//readCursor();
//		readPos++;
//	}
}


//void readCursor(void)
//{
//	readPos++;
//}
