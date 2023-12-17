#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

//#include "GPIO.h"
#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)
void GPIO();

#endif // GPIO_H_INCLUDED
