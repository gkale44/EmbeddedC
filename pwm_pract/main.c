/*
 */

#include<stdint.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

#define SET_BIT(PORT, BIT) PORT|= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT&= ~(1 << BIT)

int main()
 {

  SET_BIT(DDRD, PD6); // PD6 (OC0A pin ) as output
  TCCR0A |= ((1 << WGM01) | (1 << WGM00));
  TCCR0A |= (1 << COM0A1);
  TCCR0A &= ~(1 << COM0A0);
  TCNT0 = 0x00; // Timer counter register
  OCR0A = 64;
  TCCR0B |= ((1 << CS00) | (1 << CS02)); // Clock selection 101
  TCCR0B &= ~(1 << CS01); //101
  sei(); // Global interrupt
  while (1) //super loop
  {
      SET_BIT(PORTD,PD6);
      _delay_ms(5000);
      //CLR_BIT(PORTD,PD6);
      //_delay_ms(1000);
    //TCCR0B=0x00;

  }
}
