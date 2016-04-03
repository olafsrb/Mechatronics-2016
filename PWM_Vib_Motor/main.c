/*
 * main.c
 *
 *  Created on: 8. mar. 2016
 *      Author: Róbert
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Delay.h"
#include "PWM.h"
#include "ADC.h"

typedef enum {false = 0, true = !false} bool; // makes the type bool that has to definition , false and true
bool stateOn = false;

void initPWM();
void PWMOutput(uint8_t duty);
void initADC();
uint16_t ACDRead(uint8_t channel);

int main()
{
	DDRB  &= ~(1 << PIN1); 	//Port B input as button
	PORTB  |= (1 << PIN1);
	DDRD |= (1 << PORTD6); 	//Output for the motor

	uint16_t deg;
	uint16_t analogValue;

	initPWM();				//initialize PWM
	initADC();				//initizlize AD Converter

	while(1)
	{
		if((PINB & (1 << PIN1))) //reads if the button is pressed
		{
			uint8_t buttonState = 1; // button = 1 if it has been pressed
			while(buttonState == 1) // while button has ben presses we loop until we realeased
			{
				if(!(PINB & (1 << PIN1))) // reads if the button has been released
				{
					buttonState = 0;// button = 0 if it has been released
					delay_ms(100); // for debouncing
					stateOn = !stateOn; // always flips the state
				}
			}
		}

		if(stateOn == true) //Permission to read analog input from sense and control the motor
		{
			 analogValue = ACDRead(0); // reading from A0

			  deg = ((analogValue * 0.1846) -73); // m = 0.1923x -86 : this converts the analog value to degree
			// deg = ((analogValue * 0.1526) -41); // m = 0.1526x -41 : this converts the analog value to degre
			 if(deg >= 30 &&  deg < 45)
			 {
				 PWMOutput(135); // ca 50% of the motor power
				 delay_ms(500);
				 PWMOutput(0);
				 delay_ms(500);
			 }

			 if(deg >= 45 &&  deg < 60)
			 {
				 PWMOutput(210); // ca 80% of the motor power
				 delay_ms(1000);
				 PWMOutput(0);
				 delay_ms(400);
			 }

			 if(deg >= 60 && deg <= 90) // 90 DEG is theoretical biggest value and between 60 and 90 it is all 100% motor power
			 {
				 PWMOutput(255);
				 delay_ms(1500);
				 PWMOutput(0);
				 delay_ms(100);
			}

			if(deg > 90) // puts the Analog read to zero if it goes to 1023 like if its not connected  then the motor will not go on
			{
				deg = 0;
			}

			else // if it it less than 30 deg then its off
			{
				PWMOutput(0);
			}
		}

		if(stateOn == false) // if state is false then do nothing until the button has been pushed
		{
			;
		}
	}
}


////#include "serial.h"
//void Init_Uart();
//void printString(const char myString[]);
//void serialPrintDec();
//---------------------------------------------//
//	Init_Uart();
//---------------------------------------------//
//	printString("***Transmission begin***\n\r");
//			printString("StateOn = True");
//			printString("\n\r ");
//---------------------------------------------//
// 			printString("Analog is: ");
//			 delay_ms(100);
//			 serialPrintDec(analogValue);
//			 printString("\n\r ");
//			 delay_ms(100);
//---------------------------------------------//
//			 printString("DEG is: ");
//			 printString("\n\r ");
//			 serialPrintDec(deg);
//			 delay_ms(100);
//			 printString("\n\r ");
//			 delay_ms(100);
//---------------------------------------------//
//			printString("State Off ");
//			printString("\n\r ");
