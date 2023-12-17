
#include "GPIO.h"
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)

void GPIO_Init()
{
    uint8_t PIN_READ=0x00;
    PIN_READ=PIND;
    SET_BIT(DDRD,PD5);//LED AT PIN NO 5
    SET_BIT(PORTD,PD5);

    SET_BIT(DDRD,PD7);//LED AT PIN NO 7
    SET_BIT(PORTD,PD7);
    CLR_BIT(PORTD,PD1);

    CLR_BIT(PORTD,PD3);
}

