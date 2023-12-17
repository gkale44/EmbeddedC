
#include "ModeState.h"
void ModeState()
{

    TCCR0A |= ((1 << WGM01) | (1 << WGM00));
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << COM0A0);
    TCNT0 = 0x00;
    OCR0A = 64;
    TCCR0B |= ((1 << CS00) | (1 << CS02));
    TCCR0B &= ~(1 << CS01);
    sei();
    _delay_ms(10000);
    TCCR0B=0x00;
}

