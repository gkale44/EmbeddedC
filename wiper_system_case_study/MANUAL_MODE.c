
#include "MANUAL_MODE.h"
#include "GPIO.h"
#include "ADC.h"

#include<stdint.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void MANUAL_MODE()
{
    //SET_BIT (PORTD,PD6);
    TCCR0A |= ((1 << WGM01) | (1 << WGM00));
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << COM0A0);
    TCNT0 = 0x00;
    OCR0A = 128;// 50% duty cycle
    TCCR0B |= ((1 << CS00) | (1 << CS02));//1024 prescaler
    TCCR0B &= ~(1 << CS01);
    sei();
    TCCR0B=0x00;
}


