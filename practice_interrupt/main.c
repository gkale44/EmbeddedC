/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT);
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT);

int main(void)
{
    SET_BIT(DDRD,PD7); //OUTPUT
    CLR_BIT(DDRD,PD2);//INPUT
    SET_BIT(PORTD,PD2);//PULL UP CONFIGURATION
    //CLR_BIT(PORTD,PD7);//LED OFF STATE
    EIMSK |=(1<<INT0);
    EICRA |=(1<<ISC00);
    EICRA &=~(1<<ISC01);
    sei();
    while(1)
    {
       CLR_BIT(PORTD,PD7);
    }
    return 0;
}

ISR(INT0_vect)
{
    SET_BIT(PORTD,PD7);
    _delay_ms(1000);
}
