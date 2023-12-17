
#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT);
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT);

#include "Timer.h"
#include "GPIO.h"
//#include "AUTO_MODE.h"
#endif // MANUAL_MODE_H_INCLUDED

