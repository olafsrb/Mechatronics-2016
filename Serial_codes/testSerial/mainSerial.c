/*
 * mainSerial.c
 *
 *  Created on: 12. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "serial.h"
//_________________________________________________//
int main()
{
	 Init_Uart () ;
	 asm("sei");
	 LEDDDR = 0x01;
	 LEDPORT = 0;
	 while (1)
	 {
		 LEDPORT ^= (1 << 0);
		 LEDPORT = 0;
	 }
	 return 0;
}
//_________________________________________________________//


//	char cData;
//	//baudrate 4800
//	UBRR0H = 0;
//	UBRR0L =207;
//
//	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
//	UCSR0C = (1 << USBS0) | (3 << UCSZ00);
//
//	while(1)
//	{
//		while(!(UCSR0A & (1 << RXC0)))
//		{
//			;
//		}
//		cData = UDR0;
//
//		while(!(UCSR0A & (1 << UDRE0)))
//		{
//			;
//		}
//		UDR0 = cData;
//	}
//
//	return 0;
