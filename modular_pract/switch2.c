
#include <avr/interrupt.h>
#include <util/delay.h>
#include "GPIO.h"
#include "switch2.h"

void switch2()
{

    EICRA|=(1<<ISC00);
    EICRA&=~(1<<ISC01);
    EIMSK|=(1<<INT0);
    sei();

}

