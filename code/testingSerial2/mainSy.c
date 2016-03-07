/*
 * mainSy.c
 *
 *  Created on: 13. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define FOSC 16000000
#define BAUD 9600
#define BRC FOSC/16/BAUD-1
#define TXBUFFERSIZE 128

char serialBuffer[TXBUFFERSIZE];
uint8_t serialReadPos = 0;
uint8_t serialWritePos = 0;

void appendSerial(char c);
void serialWrite(char c[]);


void Init_Uart ()
{
	// baudrate = 57600
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;

	UCSR0B = (1 << TXEN0) | (1 << TXCIE0);
	 // set frame format
	UCSR0C= (1 << UCSZ01) |(1 << UCSZ00) ;

}

int main()
{
	 Init_Uart();

	 sei();

	 serialWrite("hello\n\r");
	 serialWrite("world\n\r");
	 _delay_ms(1500);

	 serialWrite("GoodBye\n\r");

	 while (1)
	 {

	 }
	 return 0;
}

void appendSerial(char c)
{
	serialBuffer[serialWritePos] = c;
	serialWritePos++;
	if(serialWritePos >= TXBUFFERSIZE)
	{
		serialReadPos = 0;
	}
}

ISR(USART_TX_vect)
{
	if(serialReadPos != serialWritePos)
	{
		UDR0 = serialBuffer[serialReadPos];
		serialReadPos++;

		if(serialReadPos >= TXBUFFERSIZE)
		{
			serialReadPos++;
		}
	}
}


void serialWrite(char c[])
{
	for(uint8_t i = 0; i < strlen(c); i++)
	{
		appendSerial(c[i]);
	}
	if(UCSR0A & (1 << UDRE0))
	{
		UDR0 = 0;
	}

}

