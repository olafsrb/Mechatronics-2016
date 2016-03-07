/*
 * intense.h
 *
 *  Created on: 14. feb. 2016
 *      Author: Róbert
 */

#ifndef INTENSE_H_
#define INTENSE_H_

#define DISTURB 1 //  gives that it has to overflow 1 times
#define TICKS 1 // and 1 time ticks to give delay around 16,4 ms

void timerInit();
void fastPWMMInit();

extern int dutyCycle;
extern volatile uint8_t overflowCounter;

#endif /* INTENSE_H_ */
