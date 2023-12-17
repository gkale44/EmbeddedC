/*
 */
#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define SET_BIT(PORT,BIT) PORT|=(1<<BIT);
#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT);
#define TOGGLE_BIT(PORT,BIT) PORT^= (1 << BIT);
volatile uint16_t counter = 0x00;

int main(void)
{
    SET_BIT(DDRD,PD7);//OUTPUT
    CLR_BIT(DDRD,PD2);//INPUT
    SET_BIT(PORTD,PD2);//PULL UP CONFIGURATION
    TCCR0A= 0x00;
    TCNT0=0x00;
    TCCR0B |=(1<<CS00) | (1<<CS02);
    TCCR0B &=~(1<<CS01);
    TIMSK0 |= (1 << TOIE0);
    //EICRA|=(1<<CS00);
    //EICRA &=~(1<<CS01);
    //EIMSK|=(1<<INT0);
    sei();
    //unsigned int i;
while(1)
{
         PORTD^=(1<<PD7);
         //TCNT0=0x00;
}

    return 0;
}
ISR(TIMER0_OVF_vect)
{

  counter++;

  if (counter >= 305) {
    //FLAG_BIT.FLAG_ISR1 = 1;
    counter = 0;
  }
}
