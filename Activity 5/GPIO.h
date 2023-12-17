#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)


#include "GPIO.h"
#endif // GPIO_H_INCLUDED
