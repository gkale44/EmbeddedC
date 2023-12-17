
#include<stdint.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#define input 0
#define output 1
#define LOW 0
#define HIGH 1
#define TRIGGER 2

int main()
{
   GPIOConfig(PD1,input);
   GPIOConfig(PC0,input);
   GPIOConfig(PD6,output);

    while(1)
    {
        uint8_t PIN_READ=0x00;
        PIN_READ=PIND;
         if((PIN_READ & (1<<PD1)))
        {
            ModeState();
        }
        else if(~(PIN_READ & (1<<PD1)))
        {
            AppMode();
        }
    }
}



