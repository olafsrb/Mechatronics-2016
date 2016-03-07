/*
 * main.c
 *
 *  Created on: 26. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"
#include "serialTransmit.h"


void serialPrintDec();
void Init_Uart();
void serialWrite(char c[]);
uint16_t adcRead(uint8_t ch);

int main()
{

	Init_Uart();

		// AREF = AVcc
	    ADMUX = (1<<REFS0);

	    // ADC Enable og prescaler er 128
	    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);

	    //Var for my analog value
	    uint16_t A0Value;
	    //Var for the calculation for the temp sensor LM 35 Dz hitanema
	    uint16_t temp;

	    while (1)
	    {
	    	//Read ACD value of the Pin
	    	A0Value = adcRead(0);
	    	// The formula is (sensorValue/1024)*5*100 but im working with
	    	// int so i have to multiply first and then divide by 1024
	    	temp = ((A0Value*500)/1024);
	    	//writes a string message and then the temp value
	    	//serialWrite("temperature is: ");
	    	delay_ms(1500);
	    	serialPrintDec(temp);
	    	serialWrite("\r");
	    	delay_ms(1500);
	    }
}


uint16_t adcRead(uint8_t ch)
{
    // select the corresponding channel 0~7
    // &with '7' will always keep the value
    // of 'ch' between 0 and 7
    ch &= 0b00000111;  // AND operation with 7
    ADMUX = (ADMUX & 0xF8)|ch;     // clears the bottom 3 bits before ||

    // start single conversion
    // write '1' to ADSC
    ADCSRA |= (1<<ADSC);

    // wait for conversion to complete
    // ADSC becomes '0' again
    // till then, run loop continuously
    while(ADCSRA & (1<<ADSC));

    return (ADC);
}
