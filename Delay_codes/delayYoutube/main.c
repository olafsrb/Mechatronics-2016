/*
 * main.c
 *
 *  Created on: 13. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>

// global variable to count the number of overflows
volatile uint8_t overflow;

// TIMER0 overflow interrupt service routine
// called whenever TCNT0 overflows
ISR(TIMER0_OVF_vect)
{
    // keep a track of number of overflows
    overflow++;
}

void timer_init()
{
    // set up timer with prescaler = 1024
    TCCR0B |= (1 << CS02)| (1 << CS00);

    // initialize counter
    TCNT0 = 0;

    // enable overflow interrupt
    TIMSK0 |= (1 << TOIE0);

    sei();

    overflow = 0;
}

int main(void)
{
    // connect led to pin PC0
    DDRB = 0x20;

    // initialize timer
    timer_init();

    // loop forever
    while(1)
    {
        // check if no. of overflows = 12
        if (overflow >= 12)  // NOTE: '>=' is used
        {
            // check if the timer count reaches 53
            if (TCNT0 >= 200)
            {
                PORTB ^= (1 << PORTB5);    // toggles the led
                TCNT0 = 0;            // reset counter
                overflow = 0;     // reset overflow counter
            }
        }
    }
}
