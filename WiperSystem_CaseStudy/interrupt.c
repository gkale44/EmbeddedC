#include <avr/io.h>
#include "interrupt.h"

void INTERRUPT_INIT(){
    EICRA |= ((1<<ISC00)|(1<<ISC10));
    EIMSK |= ((1<<INT0)|(1<<INT1));
}


