
#include "ADC.h"
#include <avr/io.h>

void InitADC(void)
{
    uint16_t ADC_value;
    TCCR0A|=((1<<WGM01)|(WGM00));
    TCCR0A |=(1<<COM0A0);
    TCCR0A |=(1<<COM0A1);
    OCR0A =64;
    TCNT0=0x00;
    TCCR0B|=((1<<CS02)|(1<<CS00));//1024 prescalar
    TCCR0B&=~(1<<CS01);
    sei();
    ADMUX &= 0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1 << ADEN);
while (1)
 {
    ADCSRA |= (1 << ADSC);
    while (ADCSRA & (1 << ADSC));
    ADC_value = ADC;
    if(0<=ADC_value && ADC_value<=204)
    {
        OCR0A=64;
    }
    else if(204<=ADC_value && ADC_value<=509)
    {
        OCR0A=128;
    }
    else if(509<=ADC_value && ADC_value<=614)
    {
        OCR0A=192;
    }
    else if(ADC_value>=614)
    {
      OCR0A=255;
    }

  }
}
