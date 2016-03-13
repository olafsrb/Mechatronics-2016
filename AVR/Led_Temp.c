#include <avr/io.h>
#include <avr/delay.h>
#include <avr/interrupt.h>
#include <avr/signal.h>
#include "lcd.h"

//FOLL//
void initPWM()
{
	TCCR0A |= (1 << WGM00) | (1 << WGM01) | (1 << COM0A1) | (1 << CS00); // [Fast PWM (WGM0X)] and  [Compare output mode as clear Oc0A1 on mopare match] and [No prescaling] 	
	DDRB |= (1 << PB3); //intitialize port D11
} 

void initADC()
{
	ADMUX = (1 << REFS0); //AV_CC with external capacitor at AREF pin bls 248
	ADCSRA = (1 << ADEN) | (1 ADPS2) | (1 << ADPS1) | (1 << ADPS0); // Enable ADC, AND putting division factor for ADC prescaler as 128 bls 249 and 250
}

uint16_t ReadACD(uint8_t ch)
{
	ADMUX |= ch;
	ADCSRA |= (1 << ADSC); //Bit 6-> starts the ADC conversation
	while (!(ADCSRA & (1 << ADIF))); // while  NOT(ADC interrupt flag) BIT for in ADSCRA, page 250
	ADCSRA |= (1 << ADIF);

	return ADC;
}	

void SetPWMOutput(uint8_t duty)
{
	OCR0 = duty;
}

void WAIT()
{
	uint8_t i;
	for(i = 0 ; i < 20; i++)
	{
		_delay_loop_2(0);
	}
}

int main()
{
	uint16_t temp;
	uint8_t i = 0;
	uint16_t j = 0;
	uint16_t k = 0;

	initPWM();

	uint16_t adc_result;

	initLCD(LS_BLINK | ULINE);
	LCDClear();

	initADC();

	while(1)
	{
		LCDClear();
		LCDWriteString("Fan control: ");
		LCDWriteStringXY(0,1 "TEMP=");

		adc_result = ReadACD(0);
		temp = (adc_result/2);

		LCDWriteStringXY(4,1temp,4);

		if(temp <= 25)
		{
			SetPWMOutput(0);
		}

		if(temp > 25 &&  temp <= 35)
		{
			SetPWMOutput(50);
		}

		if(temp > 35 &&  temp <= 45)
		{
			SetPWMOutput(100);
		}
		if(temp > 45 &&  temp <= 55)
		{
			SetPWMOutput(150);
		}
		if(temp > 55 &&  temp <= 65)
		{
			SetPWMOutput(200);
		}
		if(temp >= 65)
		{
			SetPWMOutput(245);
		}

		_delay_loop_2(0);
	}

}

