/*
 * gpio_functions.h
 *
 *  Created on: Feb 24, 2016
 *      Author: wrv216
 */

#ifndef GPIO_FUNCTIONS_H_
#define GPIO_FUNCTIONS_H_

typedef enum
{
  off,
  low,
  med,
  high
} Fan_Modes;

extern void ac_GPIO_Configure();
extern void writeHighState(int pinNumber);
extern void writeLowState(int pinNumber);
extern void writeState(int pinNumber, int state);
extern void change_GPIO_Comp(int status);
extern void change_GPIO_Fan(Fan_Modes mode);

#endif /* GPIO_FUNCTIONS_H_ */
