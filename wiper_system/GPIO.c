


#include "GPIO.h"
int GPIOConfig(pin,mode)
{
    if(mode==0)
    {
        CLR_BIT(DDRD,pin);
        SET_BIT(PORTD,pin);
        CLR_BIT(DDRC,pin);
        SET_BIT(PORTC,pin);
    }
    else if(mode==1)
    {
        SET_BIT(DDRD,pin);
        CLR_BIT(PORTD,pin);
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
         PORTD ^=(1 << pin);
    }
}
