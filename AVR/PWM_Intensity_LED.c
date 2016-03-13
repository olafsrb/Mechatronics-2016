#include <avr/io.h>
#include <avr/interrupt.h>
#include "intense.h"

#define DISTURB 1 // gives that it has to overflow 9 times
#define TICKS 2	// and 39 time ticks to give delay around 50 ms
////-------------DECLERATIONS-----------------------------------//

void timerInit();
int dutyCycle = 0;
volatile uint8_t overflowCounter = 0;
int direction = 0;

//------------------MAIN--------------------------------------//

int main()
{
	DDRD |= (1 << PORTD6); // Puts out on pin 6
	fastPWMMInit();

	TCCR0A |= (1 << COM0A1) |(1 << WGM00) | (1 << WGM01);
	TIMSK0 |= (1 << TOIE0);

	sei();
	TCCR0B |= (1 << CS00) | (1 << CS02);

	// initialize the foo timer
	timerInit();

	while(1)
	{
		// first step is to check number of overflow match
		if(overflowCounter >= DISTURB)
		{
			// check for timer ticks
			if(TCNT0 >= TICKS)
			{
				// if its 0 we increase to 100% duty by 1%
				if(dutyCycle == 0)
				{
					direction = 1;
				}
				// else we decrease it if its 100% by 1 %
				else if (dutyCycle >= 100)
				{
					direction = -1;
				}

				dutyCycle += direction;

				//reset the counter and the overflow counter
				TCNT0 = 0;
				overflowCounter = 0;
			}
		}
	}
}
//---------FUNCTIONS------------------------------//
void timerInit()
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
//---------------------------------------------------//
ISR(TIMER0_OVF_vect)
{
	// duty cycle is the value in the main (steps I wanna make and get the ratio from 0 to 255)
	OCR0A = (dutyCycle/100.0)*255;
	// keeps info/counting  of number of overflows for me
	overflowCounter++;
}
