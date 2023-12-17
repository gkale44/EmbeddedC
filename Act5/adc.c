
#include"adc.h"

void adc()
{
    uint16_t ADC_value;
    TCCR0A |= ((1 << WGM01) | (1 << WGM00));
    TCCR0A |= (1 << COM0A1);
    TCCR0A |= (1 << COM0A0);
    TCNT0 = 0x00;
    OCR0A = 64;
    TCCR0B |= ((1 << CS00) | (1 << CS02));
    TCCR0B &= ~(1 << CS01);
    sei();
    ADMUX &=0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1<< ADEN);
    while(1)
    {
        ADCSRA |= (1 << ADSC);
        while (ADCSRA & (1 << ADSC));
        ADC_value = ADC;

        if((ADC_value>=0) && (ADC_value<=204))
        {
            OCR0A = 64;
        }
        else if((ADC_value>=205) && (ADC_value<=408))
        {
            OCR0A = 128;
        }
        else if((ADC_value>=409) && (ADC_value<=612))
        {
            OCR0A = 192;
        }
        else if(ADC_value>=612)
        {
            OCR0A = 255;
        }
    }


}
