/*
 * Led.h
 *
 *  Created on: 2. feb. 2016
 *      Author: Róbert
 */

#ifndef LED_H_
#define LED_H_

#define DIR DDRB
#define PORT PORTB
#define PIN_LED (1 << 5)

#define INIT_DIR |= PIN_LED
#define ON_PORT |= PIN_LED
#define OFF_PORT &= -PIN_LED

void ledInit();
void ledOn();
void ledOff();


#endif /* LED_H_ */

