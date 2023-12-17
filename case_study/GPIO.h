
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED
#define input 0
#define output 1
#define LOW 0
#define HIGH 1
#define TRIGGER 2

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT);
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT);

#include "GPIO.h"
#endif // GPIO_H_INCLUDED
