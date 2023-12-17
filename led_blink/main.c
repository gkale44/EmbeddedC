/*
 */
#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)

int main(void)
{
    SET_BIT(DDRD,PD7);//led at OUTPUT PIN NO 7
    CLR_BIT(PORTD,PD7);//PULL UP CONFIGURATION
    CLR_BIT(DDRD,PD3); // switch at pin no 3
    SET_BIT(PORTD,PD3);//INPUT
    EICRA|=(1<<ISC10);
    EICRA&=~(1<<ISC11);
    EIMSK=(1<<INT1);
    SREG|=(1<<7);
    sei();

    while(1)
    {
      CLR_BIT(PORTD,PD7);
    }

    return 0;

}

ISR(INT1_vect)
{
        SET_BIT(PORTD,PD7);
        _delay_ms(1000);
}
