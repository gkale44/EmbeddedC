#include <avr/io.h>
#include "gpio.h"

void GPIP_INIT(){
    SET(DDRD,PD6);
    CLR(DDRB,PC0);
    SET(PORTC,PC0);
    CLR(DDRD,PD2);
    CLR(DDRD,PD3);

    SET(PORTD,PD2);
    CLR(PORTD,PD6);
    SET(PORTD,PD3);
}


