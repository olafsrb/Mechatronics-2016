/*
 * main.c
 *
 *  Created on: 13. mar. 2016
 *      Author: Róbert
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"
#include "serial.h"


void serialPrintDec();
void Init_Uart();

uint16_t adcRead(uint8_t ch);

int main()
{

	Init_Uart();

		// AREF = AVcc
	    ADMUX = (1<<REFS0);

	    // ADC Enable og prescaler er 128
	    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	    //Var for my analog value
	    uint16_t analogValue;
	    //float A0Value;
	    //Var for the calculation for the flexi sensor
	    uint16_t flexi;

	    while (1)
	    {
	    	//Read ACD value of the Pin
	    	analogValue = adcRead(0);


			 printString("Analog is: ");
			 delay_ms(500);
			 serialPrintDec(analogValue);
			 printString("\n\r ");
			 delay_ms(500);

	    	flexi = (analogValue*0.2492668622);
	    	//writes a string message and then the flexi value
	    	printString("flexbit is: ");
	    	delay_ms(500);
	    	serialPrintDec(flexi);
	    	printString("\n\r ");
	    	delay_ms(500);
	    }
}


uint16_t adcRead(uint8_t analogPort)
{
    // select the corresponding channel 0~7
    // &with '7' will always keep the value
    // of 'ch' between 0 and 7
    analogPort &= (1 << PC0);  // AND operation with A0 PORT
    ADMUX = (ADMUX & 0xF8) | analogPort;     // clears the bottom 3 bits before ||

    // start single conversion
    // write '1' to ADSC
    ADCSRA |= (1<<ADSC);

    // wait for conversion to complete
    // ADSC becomes '0' again
    // till then, run loop continuously
    while(ADCSRA & (1<<ADSC));
   // loop_until_bit_is_clear(ADCSRA,ADSC);

    return (ADC);
}
