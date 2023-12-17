/* jyoti_pawase_214953_case_study */

#include "Timer.h"
#include "GPIO.h"
#include "AUTO_MODE.h"
#include "MANUAL_MODE.h"
//#include "ADC.h"

#include <stdint.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

//#define SET_BIT(PORT,BIT) PORT|=(1<<BIT);
//#define CLR_BIT(PORT,BIT) PORT&=~(1<<BIT);
//#define READ_BIT(PORT,BIT) PORT & (1<<BIT);
struct{
    volatile unsigned int FLAG_ISR0:1;
}FLAG_BIT;

int main(void)
{
    GPIO();
    CLR_BIT(DDRD,PD1);// Engine at input
    SET_BIT(PORTD,PD1);// sw1 connected at pin no 1
    SET_BIT (PORTD,PD2);// PULL UP CONFIGURATION

    CLR_BIT(DDRD,PD2); //Wiper at input
    //CLR_BIT(PORTD,PD2);// sw2 connected at pin no 2

    CLR_BIT(DDRC,PC0); //Rain Sensor at input
    CLR_BIT(PORTC,PC0);//Potentiometer connected at pin PC0

    SET_BIT(DDRD,PD6);//PWMout at output
    CLR_BIT(PORTD,PD6);// output at pin no 6
    EICRA |= (1 << ISC00);
    EICRA &= ~(1 << ISC01); //Any logical change will raise interrupt.
    EIMSK |= (1 << INT0); //Local Interrupt enable
    sei();
    OCR0A = 0x00;
    TCCR0B |= ((1 << CS00) | (1 << CS02));
    TCCR0B &= ~(1 << CS01);
    //sei();
    ADMUX &=0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1<< ADEN);
while(1)
    {
        //int switch;
        uint8_t PIN_READ=0x00;
        PIN_READ=PIND;
        if (PIN_READ & (1<<PD1))//engine is in on state
        {
            if(PIN_READ & (1<<PD2))
            {
                AUTO_MODE();// wiper auto mode
            }
            else if(~(PIN_READ & (1<<PD2)))
            {
                MANUAL_MODE();// wiper manual mode
            }
        }

    }
    return 0;
}

/*ISR(INT1_vect)
{
    TCCR1B|=((1<<CS10)|(1<<CS12));//1024 prescalar
    TCCR1B&=~(1<<CS11);
}*/

ISR(INT0_vect)
{
    FLAG_BIT.FLAG_ISR0 = 0;
}

