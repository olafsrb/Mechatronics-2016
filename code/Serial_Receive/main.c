/*
 * main.c
 *
 *  Created on: 22. feb. 2016
 *      Author: Róbert
 */
#include <avr/io.h>
#include <avr/interrupt.h>
//#include "Delay.h"

#define FOSC 16000000 // clock speed
#define BAUD 9600
#define BRC  ((FOSC/16/BAUD)-1)       //FOSC/16/BAUD-1
//#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
//#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))
#define BUFFERSIZE 128

char rxBuffer[BUFFERSIZE];
char getChar(void);
//char peekChar(void);
void receiveMessage(void);

uint8_t rxReadPos = 0;
uint8_t rxWritePos = 0;
char serialBuffer[BUFFERSIZE];

int main()
{
	//Init_Uart();

	UBRR0H = (unsigned char)(BRC >> 8); // baudrate = 57600
	UBRR0L = (unsigned char)BRC;

	UCSR0B = (1 << RXEN0) | (1 << RXCIE0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);

	DDRB |= (1 << PORTB5);

	sei();

	while (1)
	{

		receiveMessage();


//		char c = getChar();

		if(serialBuffer == 'a')
		{
			PORTB |= (1 << PORTB5);
		}
		else
		{
			PORTB = 0;
		}
	}
	return 0;
}

char getChar(void)
{
	char ret = '\0';
	if(rxReadPos != rxWritePos)
	{
		ret = rxBuffer[rxReadPos];
		rxReadPos++;

		if(rxReadPos >= BUFFERSIZE)
		{
			rxReadPos = 0;
		}
	}
	return ret;
}

void receiveMessage(void) {
	while(UCSR0A &= ~(1 << UDRE0)){
		serialBuffer[rxReadPos] = getChar();
	}
//	for(uint8_t i = 0; UCSR0A &= ~(1 << UDRE0); i++) {
//		serialBuffer[i] = getChar();
//	}
}

char peekChar(void)
{
	char ret = '0';
	if(rxReadPos != rxWritePos)
	{
		ret = rxBuffer[rxReadPos];
	}
	return ret;
}

ISR(USART_RX_vect)
{
	rxBuffer[rxWritePos] = UDR0;
	rxWritePos++;

	if(rxReadPos >= BUFFERSIZE)
	{
		rxReadPos = 0;
	}

}
