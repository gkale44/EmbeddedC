#include "PWM.h"
struct {
volatile unsigned int FLAG_ISR2: 1;
}
FLAG_BIT;
volatile uint8_t counter=0x00;
int main()
{
    GPIOconfig(PD1,input);
    GPIOconfig(PD2,input);
    GPIOconfig(PD3,input);
    GPIOconfig(PD6,output);
    GPIOconfig(PD7,output);
    EICRA |= (1 << ISC00);
    EICRA &= ~(1 << ISC01);
    EIMSK |= (1 << INT0);
    EICRA |= (1 << ISC10);
    EICRA &= ~(1 << ISC11);
    EIMSK |= (1 << INT1);
    TCCR0A = 0X00;
    TCNT0 = 0X00;
    TCCR0B |= ((1 << CS00) | (1 << CS02));
    TCCR0B &= ~(1 << CS01);
    TIMSK0 |= (1 << TOIE0);
    sei();
    while(1)
    {
        uint8_t PIN_READ = 0x00;
        PIN_READ=PIND;
        if ((PIN_READ & (1<<PD1)))
        {
            GPIOPinWrite(PD6,LOW);
            if(FLAG_BIT.FLAG_ISR2 == 1)
            {
                ModeState();
            }
            FLAG_BIT.FLAG_ISR2 = 0;
        }
        else if(~(PIN_READ & (1<<PD1)))
        {
            GPIOPinWrite(PD7,LOW);
            AppMode();
        }
    }
}
  ISR(TIMER0_OVF_vect)
  {
      counter++;

      if(counter >=62)

      FLAG_BIT.FLAG_ISR2 = 1;
      counter = 0;
      }
}



