

#include "ADC.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#include "ModeState.h"

void ModeState()
{
    TCCR0A|=((1<<WGM01)|(WGM00));
    TCCR0A |=(1<<COM0A0);
    TCCR0A |=(1<<COM0A1);
    OCR0A =64;//25% duty cycle
    TCNT0=0x00;
    TCCR0B|=((1<<CS02)|(1<<CS00));//1024 prescalar
    TCCR0B&=~(1<<CS01);
    sei();
    //CLR_BIT(PORTD,PD7);
    _delay_ms(10000);
    TCCR0B=0x00;

}
