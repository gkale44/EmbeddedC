/*
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define SET_BIT(PORT,BIT) PORT|=(1<<BIT);
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT);

int main(void)
{
   SET_BIT(PORTD,PD7);
   SET_BIT(DDRD,PD7);
   CLR_BIT(PORTD,PD1);
   CLR_BIT(DDRD,PD1)
   CLR_BIT(PORTD,PD2);
   CLR_BIT(DDRD,PD2);
    while(1)
    {
        uint8_t PIN_READ=0x00;
        PIN_READ=PIND;
        if(PIN_READ && (1<<PD1))
        {
            CLR_BIT(PORTD,PD7);
            _delay_ms(1000);
        }
        else if(PIN_READ && (1<<PD1))
        {
            SET_BIT(PORTD,PD7);
            _delay_ms(5000);
        }
    }

    return 0;
}
