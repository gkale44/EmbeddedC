


#include "GPIO.h"
void GPIOConfig(pin,mode)
{
    if(mode==0)
    {
        CLR_BIT(DDRD,pin);//input
        SET_BIT(PORTD,pin);
        CLR_BIT(DDRC,pin);//potentiometer at input
        SET_BIT(PORTC,pin);// A1 connected at pinC0
    }
    else if(mode==1)
    {
        SET_BIT(DDRD,pin);//output
        CLR_BIT(PORTD,pin);
    }
}
void GPIOPinWrite(pin,state)
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

