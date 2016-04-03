/*
 * ADC.h
 *
 *  Created on: 16. mar. 2016
 *      Author: Róbert
 */

#ifndef ADC_H_
#define ADC_H_
#define ANALOG_PORT PC0

void initADC();
uint16_t ACDRead(uint8_t channel);

#endif /* ADC_H_ */
