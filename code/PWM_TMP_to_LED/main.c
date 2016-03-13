/*
 * main.c
 *
 *  Created on: 12. mar. 2016
 *      Author: Róbert
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"
#include "serial.h"

void printString(const char myString[]);
void serialPrintDec();
void Init_Uart();
void serialWrite(char c[]);

void initPWM()
{
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << CS00); // [Fast PWM (WGM0X)] and  [Compare output mode as clear Oc0A1 on mopare match] and [No prescaling]
}

void initADC()
{
	ADMUX = (1 << REFS0); //AV_CC with external capacitor at AREF pin bls 248
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);   // Enable ADC, AND putting division factor for ADC prescaler as 128 bls 249 and 250
}

//uint16_t ReadACD(uint8_t ch)
//{
//	ADMUX |= ch;
//	ADCSRA |= (1 << ADSC); //Bit 6-> starts the ADC conversation
//	while (!(ADCSRA & (1 << ADIF))); // while  NOT(ADC interrupt flag) BIT for in ADSCRA, page 250
//	ADCSRA |= (1 << ADIF);
//
//	return ADC;
//}

uint16_t ReadACD(uint8_t analogPort)
{

    analogPort &= (1 << PC0);  // AND operation with A0 PORT
    ADMUX = (ADMUX & 0xF8) | analogPort;     // clears the bottom 3 bits before ||

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


void SetPWMOutput(uint8_t duty)
{
	OCR0A = duty;
}


int main()
{
	DDRD |= (1 << PORTD6);
	uint16_t temp;
	uint16_t A0Value;

	Init_Uart();
	initPWM();
	initADC();


	while(1)
	{
		 A0Value = ReadACD(0);

		 printString("Analog is: ");
		 delay_ms(500);
		 serialPrintDec(A0Value);
		 printString("\n\r ");
		 delay_ms(500);

		 temp = ((A0Value*500)*0.00097752);

		if(temp <= 26)
				{
					SetPWMOutput(0);
				}

				if(temp > 26 &&  temp <= 27)
				{
					SetPWMOutput(50);
				}

				if(temp > 25 &&  temp <= 27)
				{
					SetPWMOutput(150);
				}
				if(temp > 27 &&  temp <= 29)
				{
					SetPWMOutput(200);
				}
				if(temp >29  &&  temp <= 32)
				{
					SetPWMOutput(200);
				}
				if(temp > 32)
				{
					SetPWMOutput(245);
				}

		    	printString("Temp is: ");
		    	delay_ms(500);
		    	serialPrintDec(temp);
		    	printString("\n\r ");
		    	delay_ms(500);
	}
}
