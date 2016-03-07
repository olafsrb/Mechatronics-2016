/*
 * main.c
 *
 *  Created on: 2. mar. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"
#include "serialTransmit.h"


void serialPrintDec();
void Init_Uart();
void serialWrite(char c[]);

int main()
{
	DDRB = 0x01;
	PORTB = 0x02;
	uint8_t count = 0;
	Init_Uart();

	while(1)
	{

		if(!(PINB & 0x02))
		{
			PORTB|= 0x01;
			count++;
			serialPrintDec(count);


		}
		else
		{
			PORTB &= 0XFE;
		}
	}
}

