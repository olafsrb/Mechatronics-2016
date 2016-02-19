/*
 * mainDelay.c
 *
 *  Created on: 13. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "intense.h"

////-------------DECLERATIONS-----------------------------------//
int direction = 0;

//------------------MAIN--------------------------------------//
int main()
{
	DDRD |= (1 << PORTD6); // Puts out on pin 6

	fastPWMMInit(); // init the fast PWM registers
	timerInit(); // initialize the foo timer

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
