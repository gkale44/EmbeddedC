/*
 */
#include "GPIO.h"
#include "AppMode.h"
#include"ModeState.h"
#include "ADC.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{
   // uint16_t ADC_value=ADC;
   int state;
    GPIO();
    InitADC();

while(1)
{
    if(state =0)
    {
        AppMode();
    }
    else if(state =1)
    {
        ModeState();
    }
}

    return 0;
}
