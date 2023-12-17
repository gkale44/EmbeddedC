#include "GPIO.h"

struct
{
  volatile unsigned int FLAG_ISR1: 1;
}
FLAG_BIT;
volatile uint8_t  counter=0x00;
void Auto_Mode()
{
    uint8_t ADC_value;
   EICRA |= (1 << ISC10);
   EICRA &= ~(1 << ISC11); //Any logical change will raise interrupt.
   EIMSK |= (1 << INT1);
   TCCR0A |= ((1<<WGM01) | (1<<WGM00));
   TCCR0A |= (1<<COM0A1);
   TCCR0A |= (1<<COM0A0);
    TCNT0=0x00;
    OCR0A=0;
    TCCR0B |= ((1<<CS02) | (1<<CS01));
    TCCR0B &= ~(1<<CS01);
    sei();
//    TIMSK = (1<< TOIE0);
    ADMUX &= 0x00;
    ADMUX |= (1<<REFS0);
    ADCSRA |= (1<<ADEN);
    while(1)
    {
        ADCSRA |= (1<<ADSC);
        while(ADCSRA & (1<<ADSC));
        ADC_value=ADC;
        if((ADC_value>=0) && (ADC_value<=50))
        {
            OCR0A=0;
        }
        else if((ADC_value>=50) && (ADC_value<=200))
        {
            OCR0A=64;
        }
         else if((ADC_value>=200) && (ADC_value<=500))
        {
            OCR0A=128;
        }
         else if((ADC_value>=500) && (ADC_value<=1000))
        {
            OCR0A=192;
        }
         else if(ADC_value>=1000)
        {
            OCR0A=255;
        }
    }
}

ISR(TIMER0_OVF_vect)
{
    counter++;
    if(counter>=305)
    {
        FLAG_BIT.FLAG_ISR1=1;
        counter=0;
    }
}

