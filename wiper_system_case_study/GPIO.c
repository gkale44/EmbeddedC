#include "GPIO.h"
#include <avr/io.h>
#include <util/delay.h>

void GPIO()
{
    CLR_BIT(DDRD,PD1);// Engine at input
    CLR_BIT(PORTD,PD1);// sw1 connected at pin no 1

    CLR_BIT(DDRD,PD2); //Wiper at input
    CLR_BIT(PORTD,PD2);// sw2 connected at pin no 2

    CLR_BIT(DDRC,PC0); //Rain Sensor at input
    CLR_BIT(PORTC,PC0);//Potentiometer connected at pin PC0

    SET_BIT(DDRD,PD6);//PWMout at output
    SET_BIT(PORTD,PD6);// output at pin no 6

}
