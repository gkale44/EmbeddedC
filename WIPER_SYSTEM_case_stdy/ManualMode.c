
#include "GPIO.h"
void Manual_Mode()
{
    TCCR0A |= ((1<< WGM01) | (1 << WGM00));
    TCCR0A |=(1 << COM0A1);
    TCCR0A |=(1 << COM0A0);
    TCNT0 = 0x00;
    OCR0A = 128;
    TCCR0B |= ((1 << CS02) | (1 << CS01));
    TCCR0B &= (1 <<CS01);
    sei();
    _delay_ms(10000);
    //TCCR0B = 0x00;
}

