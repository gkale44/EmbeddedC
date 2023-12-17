/*Jyoti_Pawase_214953_wiper_system_case_study*/

#include "GPIO.h"
#include "WIPER_AUTO.h"
#include "WIPER_MANUAL.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//uint16_t ADC_value=0x00;
int main(void)
{
     GPIO();

    TCCR0A |= ((1 << WGM01) | (1 << WGM00));
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << COM0A0);
    TCNT0 = 0x00;
    TCCR0B |= ((1 << CS00) | (1 << CS02));//1024 prescaler
    TCCR0B &= ~(1 << CS01);
    EICRA |= (1 << ISC00);
    EICRA &= ~(1 << ISC01); //Any logical change will raise interrupt.
    EIMSK |= (1 << INT0); //Local Interrupt enable
    sei();
while(1)
    {
    uint8_t PIN_READ=0x00;
    PIN_READ=PIND;
    if (PIN_READ & (1<<PD1))
    {
        if (PIN_READ & (1<<PD2))
        {
            OCR0A=0;
        }
        else
        {
            OCR0A=0;
        }
    }
    else   if (PIN_READ & (1<<PD1))//engine is in on state
        {
            if(PIN_READ & (1<<PD2))
            {
               WIPER_AUTO();// wiper auto mode
            }
            else if((PIN_READ | (1<<PD2)))
            {
                 WIPER_MANUAL();// wiper manual mode

            }
        }

  return 0;
}


}
