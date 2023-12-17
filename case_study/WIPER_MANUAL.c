
#include "WIPER_AUTO.h"
#include "WIPER_MANUAL.h"
#include "GPIO.h"

#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>

void WIPER_MANUAL()
{
    OCR0A=128; //50% duty cycle
    //_delay_ms(1000);
    //TCCR0B = 0x00;

}
