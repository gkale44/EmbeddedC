
#include "GPIO.h"
int main()
{
    GPIOConfig(PD2,input);
    GPIOConfig(PD3,input);
    GPIOConfig(PC0,output);
    GPIOConfig(PD6,output);
    //GPIOConfig(PD7,output);
    while(1)
    {
        uint8_t PIN_READ = 0x00;
        PIN_READ = PIND;
        if ((PIN_READ & (1 << PD2)))
        {
            GPIOPinWrite(PD7,LOW);
        }
        else if (~(PIN_READ & (1 << PD2)))
        {
             GPIOPinWrite(PD7,HIGH);
             wiper_mode();
        }
    }
}

