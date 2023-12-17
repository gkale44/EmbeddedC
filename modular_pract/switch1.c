
#include <avr/interrupt.h>
#include "GPIO.h"
#include "switch1.h"

void switch1()
{
    char i=0;
    SET_BIT(PORTD,PD5);
    TIMSK0|=(1<<TOIE0);
    TIFR0=(1<<TOV0);
    sei();
    void Timer0_init_();

}
