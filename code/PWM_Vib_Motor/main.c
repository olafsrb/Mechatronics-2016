/*
 * main.c
 *
 *  Created on: 8. mar. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"
#include "serial.h"

void printString(const char myString[]);
void serialPrintDec();
void Init_Uart();

void initPWM()
{
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << CS00); // [Fast PWM (WGM0X)] and  [Compare output mode as clear Oc0A1 on mopare match] and [No prescaling]
}

void initADC()
{
	ADMUX = (1 << REFS0); //AV_CC with external capacitor at AREF pin bls 248
	ADCSRA = (1 << ADEN) | (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);   // Enable ADC, AND putting division factor for ADC prescaler as 128 bls 249 and 250
}

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
	uint16_t flexi;
	uint16_t analogValue;

	Init_Uart();
	initPWM();
	initADC();

	printString("***Transmission begin***\n\r");

	while(1)
	{

		 analogValue = ReadACD(0);

		 printString("Analog is: ");
		 delay_ms(500);
		 serialPrintDec(analogValue);
		 printString("\n\r ");
		 delay_ms(500);

		 flexi = ((analogValue * 0.1759530792)-121);// 860-690

		 if(flexi < 1)
		 {
			 SetPWMOutput(0);
		 }
		 if(flexi >= 1 &&  flexi < 15)
		 {
			 SetPWMOutput(150);
			 delay_ms(2000);
			 SetPWMOutput(0);
			 delay_ms(1000);
		 }

		 if(flexi >= 15 &&  flexi < 30)
		 {

			 SetPWMOutput(120);
			 delay_ms(2000);
			 SetPWMOutput(0);
			 delay_ms(1000);
		 }

		 if(flexi >= 30)
		 {

			 SetPWMOutput(240);
			 delay_ms(2000);
			 SetPWMOutput(0);
			 delay_ms(1000);
		}

		 printString("Flexi is: ");
		 delay_ms(500);
		 serialPrintDec(flexi);
		 printString("\n\r ");
		 delay_ms(500);
	}
}
