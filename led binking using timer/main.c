/* code for blinking led using time0 by pressing switch
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <stdint.h>

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT)
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT)


int main(void)
{
    SET_BIT(DDRD,PD7);//LED CONNECTED AT OUTPUT SIDE
    SET_BIT(PORTD,PD7);// LED AT PIN NO 7
    CLR_BIT(DDRD,PD2);// SWITCH CONNECTED AT INPUT SIDE
    CLR_BIT(PORTD,PD2); // SW AT PIN NO 2
    TCNT0=0x00;
    TCCR0A=0;
    TCCR0B=((1<<CS02)|(1<<CS00));
    TCCR0B&=~(1<<CS01);
    TIMSK0|=(1<<TOIE0);
while(1)
    {
        SET_BIT(PORTD,PD7);
    }

    return 0;
}


