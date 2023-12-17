#include "AUTO_MODE.h"
#include "Timer.h"

#include <avr/interrupt.h>
#include <avr/io.h>
#include <util/delay.h>

void Timer1_Init()
{
    char i=0;
    TCNT1=0x00;
    TCCR1A |= ((1 << WGM11) | (1 << WGM10));
    TCCR1A |= (1 << COM1A1);
    TCCR1A |= (1 << COM1A0);
    TIMSK1 |= (1 << TOIE1); // Timer Overflow INT enable

 while(1)
    {
        if(TCNT1>=65536)
        {
          i++;
        }
          if(i>=1)
        {
            //PORTD^=(1<<PD6);//toggle pin6
            TCNT1=0x00;

        }

    }
}
ISR(INT1_vect)
{
    TCCR1B|=((1<<CS10)|(1<<CS12));//1024 prescalar
    TCCR1B&=~(1<<CS11);
}
