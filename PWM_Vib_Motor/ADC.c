/*
 * ADC.c
 *
 *  Created on: 16. mar. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "ADC.h"

void initADC()
{
	ADMUX = (1 << REFS0); //AV_CC with external capacitor at AREF pin bls 248
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);   // Enable ADC, AND putting division factor for ADC prescaler as 128 bls 249 and 250
}

uint16_t ACDRead(uint8_t channel)
{

    channel &= (1 << ANALOG_PORT);  // AND operation with A0 PORT
    ADMUX = (ADMUX & 0xF8) | channel;     // clears the bottom 3 bits before ||

    // start single conversion
    // write '1' to ADSC
    ADCSRA |= (1<<ADSC);

    // wait for conversion to complete
    // ADSC becomes '0' again
    // till then, run loop continuously
    while(ADCSRA & (1<<ADSC));
    //loop_until_bit_is_clear(ADCSRA,ADSC);

    return (ADC);
}

