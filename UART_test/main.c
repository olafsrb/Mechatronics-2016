/*
 * main.c
 *
 *  Created on: 11. feb. 2016
 *      Author: Róbert
 */
#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t cDelayDone =0;

void Delay ( uint8_t cDelay )
{
	cDelayDone =0;
	OCR0A=cDelay ; //compare value set
	TCNT0=0; // clear the counter
	TIMSK0=0x02 ; // turn on compare match A
	while ( cDelayDone==0)
		{
			; // wait
		}
	TIMSK0=0; // turn off interrupt
}

//----------------------------MAIN----------------------------------------------------------------------//

int main()
{
	DDRB=0x20 ; // pin5 i s out
	// set up timer 0 to generate interrupt on register A compare
	OCR0A=0xFF ; //compare value
	TCCR0A=0x00 ; // output compare pins disconnected
	TCCR0B = 0x05 ; // f /1024 = 16MHz/1024=15625Hz
	TIFR0=0x03 ; // clear all flags
	TIMSK0=0; // disable all counter 0 interrupts
	TIFR0=0x03 ;

	sei();
	while(1)
	{
		PORTB =0x20;
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);

		PORTB = 0;
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);
		Delay(2000);

	}
	return 0;
}

ISR (TIMER0_COMPA_vect)
{
// this IST is called when register value i s equal OCR0A
cDelayDone =1;
}

ISR (TIMER0_OVF_vect)
{
// this ISR rou tine is called when the counter 0 overflows ( goes from 0xFF to 0x00 )
// n
}
