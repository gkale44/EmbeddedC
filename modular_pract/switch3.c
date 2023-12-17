

#include <avr/interrupt.h>
#include <util/delay.h>
#include "GPIO.h"
#include "switch3.h"

void switch3()
{

    EICRA|=(1<<ISC10);
    EICRA&=~(1<<ISC11);
    EIMSK|=(1<<INT1);
    sei();

}

