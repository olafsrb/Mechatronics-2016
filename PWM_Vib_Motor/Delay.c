/*
 * Delay.c
 *
 *  Created on: 17. feb. 2016
 *      Author: Róbert
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"

volatile int DoverflowCounter = 0;
// SECOND
void delay_s(uint16_t timeInn)
{
	TCCR0B |= (1 << CS00) | (1 << CS02); 	//set up timer with prescaling 1024 or 16ms
	TCNT0 = 0; 		// initialize counter
	TIMSK0 |= (1 << TOIE0); 	// enables overflow interrupt
	sei();		// enables global interrupt
	DoverflowCounter = 0;
	int  tick = (timeInn)/ 0.016384; // calc the nr of ticks
	while(DoverflowCounter <= tick) // remains in a loop until time is over
		;
	DoverflowCounter = 0; // init overflow counter
}
// MILLISECONDS
void delay_ms(uint16_t timeInn)
{
	TCCR0B |=  (1 << CS00) | (1 << CS01); 	//set up timer with prescaling 64 or 1,024ms
	TCNT0 = 0; 		// initialize counter
	TIMSK0 |= (1 << TOIE0); 	// enables overflow interrupt
	sei();		// enables global interrupt
	DoverflowCounter = 0; // init overflow counter
	int tick = (timeInn)/ 1.024; // calc the nr of ticks
	if(tick < 1)
	{
		tick = 1;
	}
	while(DoverflowCounter <= tick) // remains in a loop until time is over
		;
	DoverflowCounter = 0; // init overflow counter
}
//MICROSECOND
void delay_us(uint16_t timeInn)
{
	TCCR0B |=  (1 << CS00); 	//set up timer with no prescaling
	TCNT0 = 0; 		// initialize counter
	TIMSK0 |= (1 << TOIE0); 	// enables overflow interrupt
	sei();		// enables global interrupt
	DoverflowCounter = 0; 	// init overflow counter
	int tick = (timeInn/(16)); // calc the nr of ticks
	DoverflowCounter = 0; 	// init overflow counter
	if(tick < 1)
	{
		tick = 1;
	}
	while(DoverflowCounter <= tick) // remains in a loop until time is over
		;
	DoverflowCounter = 0; // init overflow counter
}

ISR(TIMER0_OVF_vect)
{
	DoverflowCounter++; // keeps info/counting  of number of overflows
}
