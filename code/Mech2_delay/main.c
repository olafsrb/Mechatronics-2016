/*
 * main.c
 *
 *  Created on: 9. feb. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "stall.h"

int xtra1 =  0;									// tharf ad bua til int breytu til ad na i eina sekundu
int xtra2 = 0;
int xtra3 = 0;
int xtra4= 0;
int F1 = 1;
int F2 = 2;
//----------------------------MAIN----------------------------------------------------------------------//
int main()
{
	while(1)
	{
		if(F1 == 1)
		{
			for(int i = 0; i < 1; i++)
			{
				INTERRUPT();

			}
			F2 = 1;
			F1 = 0;
		}

		if(F2== 1)
		{
			for(int j = 0; j < 1; j++)
			{
				INTERRUPT2();
			}
			F2 = 0;
			F1 = 1;
		}

	}
	return (0);
}
//---------------------------FOLL-------------------------------------------------------------------------------------//
//ISR(TIMER0_COMPA_vect)
//{
//	xtra1++;
//	xtra2++;
//	// off
////	if(xtra1 > 100)
////	{
////		PORTB = PORTB | (1 << PORTB0);
////		xtra1 = 0;
////	}
////	//on
////	if(xtra2 > 50)
////	{
////		PORTB &=  ~(1 << PORTB0);
////		xtra2 = 0;
////	}
////}

//ISR(TIMER1_COMPA_vect)
//{
//	xtra3++;
//	xtra4++;
//	// off
//	if(xtra3 > 10)
//	{
//		PORTB = PORTB | (1 << PORTB0);
//		xtra3 = 0;
//	}
//	//on
//	if(xtra4 > 150)
//	{
//		PORTB &=  ~(1 << PORTB0);
//		xtra4 = 0;
//	}
//}
