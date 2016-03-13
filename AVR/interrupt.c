#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define FCPU 16000000


volatile char cDelayDone = 0;
void Delay(char cDelay)
{
	cDelayDone = 0;
	OCR0A = cDelay;
	TCNT0 = 0;
	TIMSKO = (1 << OCIE0A);
	while (cDelayDone == 0)
	{
		;
	}
	TIMSKO = 0;
}

double dutyCycle = 0;
int xtra1 = 0;

int main()
{
	DDRD = (1 << PD6); // setur pinna 6 í D zone
	TCCR0A = (1 << COM0A1) | (1 << WGM01) | (1 << WGM00); // setur compare mode til ad skilgreina duty cycle waveform generation mode sem Fast PWM
	TCCR0B = (1 << CS00); //| (1 << CS02); // startar timanum
	TIMSK0 = (1 << TOIE0);
	OCR0A = (dutyCycle/100)*255;

	sei();

	TCCR0B = (1 << CS00); //| (1 << CS02); // startar timanum

	while(1)
	{
		_delay_ms(100);

		dutyCycle += 10;

		if(dutyCycle > 100)
		{
			dutyCycle = 0;
		}
	}


}




ISR(TIMER0_OVF_vect)
{
	OCR0A = (dutyCycle/100)*255;
}

