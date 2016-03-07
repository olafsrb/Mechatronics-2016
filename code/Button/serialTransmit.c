/*
 * serialTransmit.c
 *
 *  Created on: 29. feb. 2016
 *      Author: Róbert
 */
#include "serialTransmit.h"
#include <avr/interrupt.h>
#include <avr/io.h>
#include "delay.h"
uint8_t serialReadPos = 0;
uint8_t serialWritePos = 0;

void Init_Uart ()
{
	UBRR0H = (BRC >> 8);
	UBRR0L = BRC;

	UCSR0B = (1 << TXEN0) | (1 << TXCIE0);
	 // set frame format
	UCSR0C= (1 << UCSZ01) |(1 << UCSZ00) ;

	sei();

}

void appendSerial(char c)
{
	serialBuffer[serialWritePos] = c;
	serialWritePos++;
	if(serialWritePos >= BUFFERSIZE)
	{
		serialReadPos = 0;
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

ISR(USART_TX_vect)
{
	if(serialReadPos != serialWritePos)
	{
		UDR0 = serialBuffer[serialReadPos];
		serialReadPos++;

		if(serialReadPos >= BUFFERSIZE)
		{
			serialReadPos = 0;
		}
	}
}

void serialPrintDec(int value)
{
	char asciiArr[10] = {48,49,50,51,52,53,54,55,56,57};
	int arr[20];
	int count = 0;

	if ( value < 10)
	{
		arr[count] = value;
		delay_ms(1000);
	}

	while( value / 10  > 0 )
	{

		arr[count] = value % 10;
		value = value / 10;
		count++;

		if(value < 10)
		{
			arr[count] = value;
		}

	}

	for(int i  = count ; i >= 0 ; i--)
	{
		UDR0 = asciiArr[arr[i]];

		delay_ms(600);

	}
	//UDR0 = "\r";
	serialWrite("\r");
}
