/*
 * PWM.c
 *
 *  Created on: 8. mar. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "PWM.h"

int dutyCycle = 0;
volatile uint8_t overflowCounter = 0;

void timerInit()
{
	//set up timer with prescaler 1024 or 16,384ms
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

void fastPWMMInit()
{
	// sets compare mode to define duty cycle waveform generation mode as Fast PWM
	TCCR0A |= (1 << COM0A1) |(1 << WGM00) | (1 << WGM01);
	TIMSK0 |= (1 << TOIE0); // Timer overflow interrupt enabled

	sei(); // enables global interrupt
	TCCR0B |= (1 << CS00) | (1 << CS02); // prescaler of 1024
}

ISR(TIMER0_OVF_vect)
{
	// duty cycle is the value in the main (steps I want make and get the ratio from 0 to 255)
	OCR0A = (dutyCycle/100.0)*255;
	// keeps info/counting  of number of overflows for me
	overflowCounter++;
}


