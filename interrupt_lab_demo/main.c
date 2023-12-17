#include<stdint.h>
#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
struct {
  volatile unsigned int FLAG_ISR1: 1;
}
FLAG_BIT;

int main() {
  SET_BIT(DDRD, PD7); // PD7 as output
  CLR_BIT(DDRD, PD3); // PD3 as input
  SET_BIT(PORTD, PD3); // Pull up
  CLR_BIT(PORTD, PD7); // By Default value-0 for LED
  EICRA |= (1 << ISC10);
  EICRA &= ~(1 << ISC11); //Any logical change will raise interrupt.
  EIMSK |= (1 << INT1); //Local Interrupt enable
  sei(); // SREG|=(1<<7); macros to enable global INT sei(); cli();

  while (1) //super loop
  {
    if (FLAG_BIT.FLAG_ISR1 == 1) {
      CLR_BIT(PORTD, PD7); //LED OFF
      FLAG_BIT.FLAG_ISR1 = 0;
      _delay_ms(1000);
    } else {
      SET_BIT(PORTD, PD7); // LED ON
    }
  }
}

ISR(INT1_vect) {

  FLAG_BIT.FLAG_ISR1 = 1;

}
