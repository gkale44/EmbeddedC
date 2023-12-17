#include <avr/io.h>
#include "timer.h"

void TIMER_INIT()
{
    TCNT2=0x00;
    TCCR2A=0x00;
    TCCR2B |=((1<<CS22)|(1<<CS21)|(1<<CS20));
}


