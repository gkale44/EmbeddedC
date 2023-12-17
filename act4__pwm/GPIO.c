#include "PWM.h"
int GPIOConfig(pin,mode)
{
    if(mode==0)
    {
        CLR_BIT(DDRD,pin);
        SET_BIT(PORTD,pin);
    }
    else if(mode==1)
    {
        CLR_BIT(PORTD,pin);
        SET_BIT(DDRD,pin);
    }
}
int GPIOPinWrite(pin,state)
{
    if(state == 1)
    {
        SET_BIT(PORTD,pin);
    }
    else if(state == 0)
    {
        CLR_BIT(PORTD,pin);
    }
    else if(state == 2)
    {
        PORTD ^= (1<<pin);
    }
}
