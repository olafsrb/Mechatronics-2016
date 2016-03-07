/*
 * stall.c
 *
 *  Created on: 9. feb. 2016
 *      Author: Róbert
 */

#include "stall.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void INTERRUPT(void)
{
	IRDIRREG = 0x01;
	TCCR0A = (1 << WGM01);
	OCR0A = 1;
	TIMSK0 = (1 << OCIE0A);
	sei(); //sets global flag
	TCCR0B = (1 << CS02) | (1 << CS00); // starta a 1024 prescaler
}

void INTERRUPT2(void)
{
	IRDIRREG = 0x01;
	TCCR1B =(1 << WGM12);
	OCR1A = 15625;
	TIMSK1 =(1<< OCIE1A);
	sei();
	TCCR1B = (1<< CS12) | (1<< CS10);
}
