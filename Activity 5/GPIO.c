
# include "gpio.h"
#include <avr/io.h>

void GPIO()
{
    CLR_BIT(DDRD,PD1);//sw at input
    CLR_BIT(PORTD,PD1);
    SET_BIT(DDRD,PD7);// led at output
    SET_BIT(PORTD,PD7);
    CLR_BIT(PORTC,PC0);
    CLR_BIT(DDRC,PC0);//potentiometer at input
}
