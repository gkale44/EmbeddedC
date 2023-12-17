
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED
#include <avr/io.h>

#include "GPIO.h"
#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)
#define TOGGLE_BIT(PORT, BIT) PORT ^= (1<<BIT)

#endif // GPIO_H_INCLUDED
