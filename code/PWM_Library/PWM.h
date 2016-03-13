/*
 * PWM.h
 *
 *  Created on: 8. mar. 2016
 *      Author: R�bert
 */

#ifndef PWM_H_
#define PWM_H_

#define DISTURB 1 //  gives that it has to overflow 1 times
#define TICKS 1 // and 1 time ticks to give delay around 16,4 ms

void timerInit();
void fastPWMMInit();

extern int dutyCycle;
extern volatile uint8_t overflowCounter;


#endif /* PWM_H_ */
