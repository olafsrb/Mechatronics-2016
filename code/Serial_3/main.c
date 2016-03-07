/*
 * main.c
 *
 *  Created on: 25. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"

#define FOSC 16000000 // clock speed
#define BAUD 9600
#define BRC  ((FOSC/16/BAUD)-1)       //FOSC/16/BAUD-1
//#define BUFFERSIZE 128

//Declaration of our functions
void USART_init(void);
unsigned char receive(void);
void transmitt( unsigned char data);
void appendChar(char* Ptr);


char textArray[]= "Hello world!!\n\r";


int main(void)
{
	USART_init();
//	int arr[20];
//	int number = 238;
//	int count = 0;
	while(1)
	{
//		if ( number < 10)
//		{
//			arr[0] = number;
//			count++;
//		}
//		while( number % 10  < 0 )
//		{
//			arr[count] = number % 10;
//			number = number / 10;
//			count++;
//		}


//		for(int i  = count ; i >= 0 ; i--)
//		{
//			UDR0 = arr[i];
//		}
		UDR0 = 0x31;


//		appendChar(textArray);
//		delay_ms(5000);

	}

return 0;
}

void USART_init(void)
{

// UBRR0H = (unsigned long)(BRC>>8);
// UBRR0L = (unsigned long)(BRC);
// UCSR0B = (1<<RXEN0)|(1<<TXEN0);
// UCSR0C = (3<<UCSZ00);


 UBRR0H = (BRC >> 8);		// Set the baudrate for the upper byte
 	UBRR0L = BRC;			// Set the baud rate for the lower byte

 	UCSR0B |= (1 << RXEN0)  | (1 << RXCIE0);// Enable receiver and interrupt enable for receiver finished

 	UCSR0B |= (1 << TXEN0)  | (1 << TXCIE0);	// Enable the transmitter and the interrupt enable for transmission finished
 	UCSR0C  = (1 << UCSZ01) | (1 << UCSZ00);			// Set 8 bit data frame


}

unsigned char receive(void){

 while(!(UCSR0A & (1<<RXC0)));
 return UDR0;

}

void transmitt( unsigned char data){

 while(!(UCSR0A & (1<<UDRE0)));
 UDR0 = data;

}

void appendChar(char* Ptr)
{

	while(*Ptr != '\0')
	{
	 transmitt(*Ptr);
	 Ptr++;
	}

}


