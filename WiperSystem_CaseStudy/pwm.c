#include <avr/io.h>
#include "pwm.h"

void PWM_INIT(){
    TCNT0 =0x00;  // give access to timer and Counter
    TCCR0A |= ((1<<WGM00)|(1<<WGM01)|(1<<COM0A1)); // enabled the Mode and effect
    TCCR0B |= ((1<<CS02)|(0<<CS01)|(1<<CS00)); //clock and WGM02
}


