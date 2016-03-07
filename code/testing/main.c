/*
 * main.c
 *
 *  Created on: 10. feb. 2016
 *      Author: Róbert
 */

#include <inttypes.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>
#include "iocompat.h"       /* Note [1] */
enum { UP, DOWN };
ISR (TIMER1_OVF_vect)       /* Note [2] */
{
    static uint16_t pwm;    /* Note [3] */
    static uint8_t direction;
    switch (direction)      /* Note [4] */
    {
        case UP:
            if (++pwm == TIMER1_TOP)
                direction = DOWN;
            break;
        case DOWN:
            if (--pwm == 0)
                direction = UP;
            break;
    }
    OCR = pwm;          /* Note [5] */
}
void
ioinit (void)           /* Note [6] */
{
    /* Timer 1 is 10-bit PWM (8-bit PWM on some ATtinys). */
    TCCR1A = TIMER1_PWM_INIT;
    /*
     * Start timer 1.
     *
     * NB: TCCR1A and TCCR1B could actually be the same register, so
     * take care to not clobber it.
     */
    TCCR1B |= TIMER1_CLOCKSOURCE;
    /*
     * Run any device-dependent timer 1 setup hook if present.
     */
#if defined(TIMER1_SETUP_HOOK)
    TIMER1_SETUP_HOOK();
#endif
    /* Set PWM value to 0. */
    OCR = 0;
    /* Enable OC1 as output. */
    DDROC = _BV (OC1);
    /* Enable timer 1 overflow interrupt. */
    TIMSK = _BV (TOIE1);
    sei ();
}
int
main (void)
{
    ioinit ();
    /* loop forever, the interrupts are doing the rest */
    for (;;)            /* Note [7] */
        sleep_mode();
    return (0);
}
