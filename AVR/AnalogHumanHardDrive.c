#include <avr/io.h>
#include <avr/interrupt.h>
#include "delay.h"
#include "serialTransmit.h"

int dutyCycle = 0;

void setupADC();
//void startConversion();

int main()
{
	uint16_t temperature;
	//DDRD |= (1 << PORTD6);
	// sets compare mode to define duty cycle waveform generation mode as Fast PWM
		//TCCR2A |= (1 << COM2A1) |(1 << WGM20) | (1 << WGM21);
		//TIMSK2 |= (1 << TOIE2); // Timer overflow interrupt enabled

		setupADC();
		//sei(); // enables global interrupt
		//TCCR2B |= (1 << CS20) | (1 << CS21) | (1 << CS22); // prescaler of 1024

		 // temperature=(sensorValue/1023)*powervoltage*100;
		  temperature =  ( ((ADCL >> 6) & 0x3) | (ADCH << 2) ) - 125;
		  seriaPrintDec(temperature);
}

void setupADC()
{
	ADMUX |= (1 << REFS0) | (1 << MUX0) | ( 1 << MUX2);
	ADCSRA |= (1 << ADEN) | ( 1 << ADIE) | ( 1 << ADPS0) | ( 1 << ADPS1) | (1 << ADPS2);
	DIDR0 |= (1 <<ADC5D);

	ADCSRA |= (1 << ADSC);

	//startConversion();
}

//void startConversion()
//{
//
//	ADCSRA |= (1 << ADSC);
//}


//ISR(TIMER2_OVF_vect)
//{
//	// duty cycle is the value in the main (steps I want make and get the ratio from 0 to 255)
//	OCR2A = dutyCycle;
//	seriaPrintDec(dutyCycle);
//}
//
//ISR(ADC_vect)
//{
//	dutyCycle = ADC;
//	startConversion();
//}



///NYTT///

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

int dutyCycle = 0;
int temperature = 0;
//void setupADC();
//void startConversion();
int sensorValue;
int temperature;
int volt = 5;
void serialPrintDec();
void Init_Uart();
void serialWrite(char c[]);
uint16_t adcRead(uint8_t ch);

int main()
{
	Init_Uart();
//	ADMUX |= (1 << REFS0);
//	ADCSRA |= (1 << ADEN) | ( 1 << ADPS0) | ( 1 << ADPS1) | (1 << ADPS2) | (1 << ADSC) | (1 << ADATE); //( 1 << ADIE)
//	//DIDR0 |= (1 <<ADC5D);
//
//	ADCSRA |= (1 << ADSC);

//	 // AREF = AVcc
//	    ADMUX = (1<<REFS0);
//
//	    // ADC Enable and prescaler of 128
//	    // 16000000/128 = 125000
//	    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);
//
//
//	while(1)
//	{
//		sensorValue = ADC;
//
//		//temperature = (sensorValue/1023)*volt*100;
//		temperature= ((sensorValue*500)/1023);
//		serialWrite("receiving data");
//		serialPrintDec(temperature);
//		serialWrite("\r");
//
//	}


		// AREF = AVcc
	    ADMUX = (1<<REFS0);

	    // ADC Enable and prescaler of 128
	    // 16000000/128 = 125000
	    ADCSRA = (1<<ADEN)|(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);


	    uint16_t A0Value;
	    uint16_t temp;
	    // read adc value at PA0
	    //adc_result1 = adc_read(1);      // read adc value at PA1



	    while (1)
	    {
	    	A0Value = adcRead(0);
	    	temp = ((A0Value*500)/1024);

	    	serialWrite("temperature is: ");
	    	delay_ms(1500);
	    	serialPrintDec(temp);
	    	serialWrite("\r");
	    	delay_ms(1500);

	    }




}


uint16_t adcRead(uint8_t ch)
{
    // select the corresponding channel 0~7
    // ANDing with '7' will always keep the value
    // of 'ch' between 0 and 7
    ch &= 0b00000111;  // AND operation with 7
    ADMUX = (ADMUX & 0xF8)|ch;     // clears the bottom 3 bits before ORing

    // start single conversion
    // write '1' to ADSC
    ADCSRA |= (1<<ADSC);

    // wait for conversion to complete
    // ADSC becomes '0' again
    // till then, run loop continuously
    while(ADCSRA & (1<<ADSC));

    return (ADC);
}

//void setupADC()
//{
//	ADMUX |= (1 << REFS0) | (1 << MUX0) | ( 1 << MUX2);
//	ADCSRA |= (1 << ADEN) | ( 1 << ADIE) | ( 1 << ADPS0) | ( 1 << ADPS1) | (1 << ADPS2);
//	DIDR0 |= (1 <<ADC5D);
//
//	ADCSRA |= (1 << ADSC);
//
//	//startConversion();
//}

//void startConversion()
//{
//
//	ADCSRA |= (1 << ADSC);
//}



//ISR(TIMER2_OVF_vect)
//{
//	// duty cycle is the value in the main (steps I want make and get the ratio from 0 to 255)
//	OCR2A = dutyCycle;
//	seriaPrintDec(dutyCycle);
//}
//
//ISR(ADC_vect)
//{
//	dutyCycle = ADC;
//	startConversion();
//}
