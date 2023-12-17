#include "GPIO.h"
#include "AUTO_MODE.h"

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void AUTO_MODE()
{
    uint16_t ADC_value=0x00;
    //TCCR1A |= ((1 << WGM11) | (1 << WGM10));
    //TCCR1A |= (1 << COM0A1);
    //TCCR1A |= (1 << COM0A0);
    //TCNT1 = 0x00;
    /*OCR0A = 0x00;
    TCCR0B |= ((1 << CS00) | (1 << CS02));
    TCCR0B &= ~(1 << CS01);
    sei();
    ADMUX &=0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1<< ADEN);*/
    while(1)
    {
        ADCSRA |= (1 << ADSC);
        while (ADCSRA & (1 << ADSC));
        ADC_value=ADC;

        if((ADC_value>=0) && (ADC_value<50))
        {
            OCR0A = 0x00;
        }
        else if((ADC_value>=50) && (ADC_value<200))
        {
            OCR0A = 64;
        }
        else if((ADC_value>=200) && (ADC_value<500))
        {
            OCR0A = 128;
        }
        else if((ADC_value>=500) && (ADC_value<1000))
        {
            OCR0A = 192;
        }
        else if(ADC_value>=1000)
        {
            OCR0A = 255;
        }
    }
    Timer1_Init();

}





