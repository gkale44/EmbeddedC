#include "GPIO.h"
#include <avr/io.h>
#include <util/delay.h>
#include "WIPER_AUTO.h"
#include "WIPER_MANUAL.h"

void GPIO()
{
    CLR_BIT(DDRD,PD1);
    CLR_BIT(DDRD,PD2);
    SET_BIT(PORTD,PD1);
    SET_BIT (PORTD,PD2);// PULL UP CONFIGURATION
    CLR_BIT(DDRC,PC0); //Rain Sensor at input
    //CLR_BIT(PORTC,PC0);//Potentiometer connected at pin PC0
    SET_BIT(DDRD,PD6);//PWMout at output
    SET_BIT(PORTD,PD6);// output at pin no 6*/
}

/*void GPIOConfig(pin,mode)
{
    if(mode == 0)
    {
        CLR_BIT(DDRD,pin);//input
        SET_BIT(PORTD,pin);
        CLR_BIT(DDRC,pin);
        SET_BIT(PORTC,pin);
    }
    else if(mode == 1)
    {
       SET_BIT(DDRD,pin); //output
       CLR_BIT(PORTD,pin);
    }
}
void GPIOPinWrite(pin,state)
{
    if(state ==1)
    {
       SET_BIT(PORTD,pin);
    }
    else if(state==0)
    {
        CLR_BIT(PORTD,pin);
    }
    else if(state==2)
    {
        PORTD^=(1<<pin);
    }
} */

