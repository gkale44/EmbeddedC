#include <avr/io.h>
#include "adc.h"


void ADC_INIT(){
    ADCSRA |= (1<<ADEN);
}
void Adc_Conv(){
    ADMUX |= ((0<<MUX0)|(0<<MUX1)|(0<<MUX2)|(0<<MUX3));
    ADCSRA |= (1<<ADSC);
    while (ADSC==1);
    ADC_value=ADC;
}
void Stop_Conv(){
    ADCSRA |= (0<<ADSC);
    ADC=0x00;
}


