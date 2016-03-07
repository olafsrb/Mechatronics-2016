/*
 * main.c
 *
 *  Created on: 2. feb. 2016
 *      Author: Róbert
 */

#include "Led.h"
#include <avr/io.h>
#include <avr/delay.h>

int main()
{
	ledInit();

	while(1)
	{
		ledOn();
		_delay_ms(1000);
		ledOff();
		_delay_ms(1000);
	}

	return 0;
}

