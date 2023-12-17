# include "timer.h"
//void delay(unsigned int i)
//{
while(1)
 {
     TCCR0A=0x00;
       TIMSK0|=(1<<TOIE0);// enable timer
       TIFR0=(1<<TOV0);
       TCCR0B&=~(1<<CS01);
       TCNT0=0;

  if(TCNT0>=31250)
        {
            i++;
        }
        if(i>122)
            {
                PORTD^=(1<<PD5);
                TCNT0=0;//count reset
            }
 }

    //return 0;

void Timer0_init(TIMER0_OVF)
{
    TCCR0B=(1<<CS02)|(1<<CS00);
    TCNT0=0;
}

