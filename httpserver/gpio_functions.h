/*
 * gpio_functions.h
 *
 *  Created on: Feb 24, 2016
 *      Author: wrv216
 */

#ifndef GPIO_FUNCTIONS_H_
#define GPIO_FUNCTIONS_H_

extern void ac_GPIO_Configure();
extern void writeHighState(int pinNumber);
extern void writeLowState(int pinNumber);
extern void writeState(int pinNumber, int state);

typedef enum
{
  off,
  low,
  med,
  high
} Fan_Modes;

#endif /* GPIO_FUNCTIONS_H_ */
