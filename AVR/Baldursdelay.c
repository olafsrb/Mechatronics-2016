#include <avr/io.h>
#include <avr/interrupt.h>


volatile char cDelayDone = 0;
void Delay ( char cDelay )
{
	cDelayDone =0;
	OCR0A=cDelay ; //compare value set
	TCNT0=0; // clear the counter
	TIMSK0=0x02 ; // turn on compare match A
	while ( cDelayDone == 0)
	{
		;// wait
	}
	TIMSK0 = 0; // turn off interrupt
 }

 int main ()
 {
	DDRB= 0x20; // pin5 is out
	// set up timer 0 to generate interrupton register A compare
	OCR0A= 0xFF; //compare value
	TCCR0A= 0x00; // output compare pins disconnected
	TCCR0B = 0x05; // f/1024 = 16MHz/1024=15625Hz
	TIFR0= 0x03; // clear all flags
	TIMSK0= 0; // disable all counter 0 interrupts
	TIFR0= 0x03;

	sei(); // enable globalinterrupts
	while (1)
	{
		PORTB=0x20;
		Delay (1500); // wait for 15* 1024/16MHz=1ms (960 us )
		PORTB=0;
	}
}

ISR (TIMER0_COMPA_vect)
{
	// this IST is called when register value is equal OCR0A
	cDelayDone =1;
}

ISR (TIMER0_OVF_vect)
{
// this ISR routine is called when the counter 0 overflows ( goes
//from 0xFF to 0x00 )
// not used in t h i s example
}
