/*
 * main.c
 * 16 bit timer
 *  Created on: 9. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>

//int xtraTime = 0;
void stall(void);
int main()
{
	stall();
	while(1)
	{}
}

ISR(TIMER1_COMPA_vect)
{
	PORTB ^= (1<< PORTB0);
}

void stall(void)
{
	DDRB = 0x01;

	TCCR1B =(1 << WGM12);

	OCR1A = 15625;
	TIMSK1 =(1<< OCIE1A);

	sei();

	TCCR1B |= (1<< CS12) | (1<< CS10);
}
