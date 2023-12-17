/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>
#include "GPIO.h"
#include "switch1.h"
#include "switch2.h"
#include "switch3.h"
int main(void)
{
    char i=0;
    GPIO();
    switch2();
    switch3();
while(1)
    {
        if(TCNT0>=255)
        {
        if(i>61)
        {
            PORTD^=(1<<PD5);
            TCNT0=0;
        }
        }
    }
}

void Timer0_init_(TIMER0_OVF)
{
    TCCR0B=((1<<CS00)|(1<<CS02));
    TCCR0B&=(1<<CS01);
}
ISR (INT0_vect)
{
    SET_BIT(PORTD,PD6);
    _delay_ms(1000);
    CLR_BIT(PORTD,PD6);
    _delay_ms(1000);
    SET_BIT(PORTD,PD6);
    _delay_ms(1000);
    CLR_BIT(PORTD,PD6);
    _delay_ms(1000);
}

ISR (INT1_vect)
{
    int i;
    for (i=0;i<=5;i++)
    {
        SET_BIT(PORTD,PD7);
        _delay_ms(1000);
        CLR_BIT(PORTD,PD7);
        _delay_ms(1000);
    }
}
