/*
 * main.c
 *
 *  Created on: 19. feb. 2016
 *      Author: Róbert
 */


#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"
#include "serial.h"

void delay_ms(uint16_t timeInn);
int main()
{
	Init_Uart();

	while (1)
	{
		serialPrintDec(2179);
		delay_ms(1500);

	}
	return 0;
}

