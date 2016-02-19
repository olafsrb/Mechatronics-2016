/*
 * serial.c
 *
 *  Created on: 13. feb. 2016
 *      Author: Róbert
 */

#include "serial.h"
#include <avr/io.h>
#include <avr/interrupt.h>

void Init_Uart ()
{
	UBRR0H= (BRCALC >> 8); // setur Baud register high BRCALC i bita 8
	UBRR0L= BRCALC; // setur baud register low BRCALC

	 // enable receiver and transmitter , Rx complete interrupt enable
	UCSR0B = (1<<RXEN0) |(1<<TXEN0) |(1<<RXCIE0);
	 // set frame format
	UCSR0C=(1<<USBS0) |(3<<UCSZ00); // held ad thetta enable baadi
	//UCSZ01 og natt UCSZ00 = 8 bita format asamt stopp bita = 2 bit
}

// ineterrupt vektor fyrir USART
ISR (USART_RX_vect)
{
	char cRx ;
	cRx = UDR0;
	UDR0 = cRx + 1;
}
