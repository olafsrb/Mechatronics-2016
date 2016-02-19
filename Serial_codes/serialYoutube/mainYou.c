/*
 * mainYou.c
 *
 *  Created on: 13. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>

void Init_Uart ( )
{
	// baudrate = 57600
	UBRR0H=0;
	UBRR0L=16;
	 // enable receiver and transmitter , Rx complete interrupt enable
	UCSR0B = (1<<RXEN0) |(1<<TXEN0) |(1<<RXCIE0) ;
	 // set frame format
	UCSR0C=(1<<USBS0) |(3<<UCSZ00) ;
	//UCSR0C=0x06 ;
	 }

ISR (USART_RX_vect)
{
	char cRx ;
	cRx=UDR0;
	UDR0=cRx+1;
}

int main()
{
	 Init_Uart () ;
	 asm( "sei" ) ;
	 DDRB=0x20 ;
	 while (1)
	 {
		 PORTB=0x20 ;
		 PORTB=0;
	 }
	 return 0;


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
}

