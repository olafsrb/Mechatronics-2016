/*
 * mainLed.c
 *
 *  Created on: 11. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
//#include <avr/interrupt.h>
#include <util/delay.h>

#define DELAY1 200
#define DELAY2 100
#define DELAY3 500
#define DELAY4 300
#define LED_PORT PORTB
#define LED_PIN PINB
#define LED_DDR DDRB

int main()
{

	LED_DDR = 0x1D;
	LED_PORT = 0;

	while(1)
	{

		LED_PORT |= (1 << 0);
		_delay_ms(DELAY1);
					LED_PORT = 0;
					_delay_ms(DELAY1);
	}
//		for(uint8_t i = 0; i < 3 ; i++)
//		{
//			LED_PORT |= (1 << 2);
//			_delay_ms(DELAY1);
//			LED_PORT = 0;
//			_delay_ms(DELAY1);
//
//		}
//		for(uint8_t i = 0; i < 3; i++)
//		{
//			LED_PORT |= (1 << 0);
//			LED_PORT |= (1 << 2);
//			_delay_ms(DELAY2);
//			LED_PORT = 0;
//			_delay_ms(DELAY2);
//		}
//		for(uint8_t i = 0; i < 2; i++)
//		{
//			LED_PORT |= (1 << 0);
//			LED_PORT |= (1 << 2);
//			_delay_ms(DELAY3);
//
//		}
//		for(uint8_t i = 0; i < 3 ; i++)
//		{
//			LED_PORT |= (1 << 3);
//			_delay_ms(DELAY4);
//			LED_PORT = 0;
//			_delay_ms(DELAY4);
//		}
//		for(uint8_t i = 0; i < 4 ; i++)
//		{
//			LED_PORT |= (1 << 4);
//			_delay_ms(DELAY2);
//			LED_PORT = 0;
//			_delay_ms(DELAY2);
//		}
//		for(uint8_t i = 0; i < 5 ; i++)
//		{
//			LED_PORT |= ((1 << 0) |(1 << 2) |(1 << 3) |(1 << 4));
//			_delay_ms(DELAY3);
//			LED_PORT = 0 ;
//			_delay_ms(DELAY3);
//
//		}
//	}

	return 0;
}
