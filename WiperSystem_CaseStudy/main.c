/* JYOTI_PAWASE_214953_CASE_STUDY*/


#include <avr/io.h>
#include <avr/interrupt.h>

#include "gpio.h"
#include "pwm.h"
#include "interrupt.h"
#include "adc.h"
#include "timer.h"

uint8_t Ignition;
uint8_t Mode;
uint8_t Ind;
uint8_t Count;

int main(void){
    GPIP_INIT();
    INTERRUPT_INIT();
    PWM_INIT();
    ADC_INIT();
    TIMER_INIT();
    sei();

    while(1){
        if(Ignition && Mode){
            CLR(PORTB,PB4);
            Adc_Conv();
            START_TIMER;
            if(Ind){
                SET(PORTB,PB4);
                if(ADC_value>=0 && ADC_value<=50){
                    SET_PWM_VALUE(0);
                }else if(ADC_value>=50 && ADC_value<=200){
                    SET_PWM_VALUE(64);
                }else if(ADC_value>=200 && ADC_value<=500){
                    SET_PWM_VALUE(128);
                }else if(ADC_value>=500 && ADC_value<=1000){
                    SET_PWM_VALUE(192);
                }else if(ADC_value>1000){
                    SET_PWM_VALUE(255);
                }
            }
        }else if (Ignition && !Mode){
                SET_PWM_VALUE(128);
            }else{
            STOP_TIMER;
            Stop_Conv();
            CLR(PORTB,PB4);
            SET_PWM_VALUE(0);
            Ind=0;
        }
    }
    return 0;
}
ISR(INT0_vect){
    Mode =~ Mode;
}

ISR(INT1_vect){
    Ignition =~ Ignition;
}


ISR(TIMER2_OVF_vect){
    Count++;
    if(Count>=240){
        Count=0;
        Ind=1;
    }
}

