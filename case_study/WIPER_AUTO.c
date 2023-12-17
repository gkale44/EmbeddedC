#include "GPIO.h"
#include "WIPER_AUTO.h"

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

uint16_t ADC_value=0x00;
void WIPER_AUTO()
{
    ADMUX &=0x00;
    ADMUX |= (1 << REFS0);
    ADCSRA |= (1<< ADEN);
    //OCR0A=0;
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

}




