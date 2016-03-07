/*
 * main.c
 *
 *  Created on: 9. feb. 2016
 *      Author: Róbert
 *

/*
 * main.c
 *
 *  Created on: 9. feb. 2016
 *      Author: Róbert
 */
#include <avr/io.h>
#include <avr/delay.h>
int main()
{
	DDRB= 0x8;
	PORTB = 0;
	while(1)
	{
		PORTB=0x8;
		_delay_ms(1000);
		PORTB=0;
		_delay_ms(1000);
	}
}

