/*
 * maint.c
 *
 *  Created on: 14. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#define DISTURB 61
#define TICKS 9

//Variable that keeps count of nr of overflows
volatile uint16_t overflowCounter = 0;
// init times and interrupts and var
void timer();

int main()
{
	// Port output
	DDRB |= (1 << PORTB5);

	// init timer
	timer();

	while(1)
	{
		// first step is to check number of overflow match
		if(overflowCounter >= DISTURB)
		{
			// check for timer counts = 27
			if(TCNT0 >= TICKS)
			{
				// Toggle LED
				PORTB ^= (1 << PORTB5);

				//reset counter and overflow counter
				TCNT0 = 0;
				overflowCounter = 0;
				maxover = 0;
			}
		}

	}


	return 0;
}

void timer()
{
	//set up timer with prescaling 1024 or 16ms
	TCCR0B |= (1 << CS00) | (1 << CS02);

	// initialize counter
	TCNT0 = 0;

	// enables overflow interrupt
	TIMSK0 |= (1 << TOIE0);

	// enables global interrupt
	sei();

	// init overflow counter
	overflowCounter = 0;

}

ISR(TIMER0_OVF_vect)
{
	// keeps info/counting  of number of overflows for me

		overflowCounter++;
}







//---------------------------------------------------------------------------//
//  WITH OUT INTERRUPTS JUST TIMERS
//void tc0();
//
//int main()
//{
//	DDRB |= (1 << PORTB5);
//
//	// initialize the foo
//	tc0();
//	while(1)
//	{
//		if(TCNT0 >= 255)
//		{
//			PORTB ^= (1 << PORTB5);
//			TCNT0 = 0;
//		}
//	}
//	return 0;
//}
//void tc0()
//{
//	//set up timer with prescaling 1024 or 16ms
//	TCCR0B |= (1 << CS00) | (1 << CS02);
//
//	// initialize counter
//	TCNT0 = 0;
//}


