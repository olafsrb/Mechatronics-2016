/*
 * main.Delay.c
 *
 *  Created on: 17. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"

void delay_ms(uint16_t timeInn);

int main()
{
	DDRB |= (1 << PORTB5);
	while(1)
	{
		PORTB |= (1 << PORTB5);
		delay_ms(100);
		PORTB = 0;
		delay_ms(100);
	}
	return 0;
}
