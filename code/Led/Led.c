/*
 * Led.c
 *
 *  Created on: 2. feb. 2016
 *      Author: R�bert
 */

#include "Led.h"
#include <avr/io.h>


void ledInit()
{
	DIR |= PIN_LED;
}
void ledOn()
{
	PORT |= PIN_LED;
}
void ledOff()
{
	PORT &= -PIN_LED;
}

