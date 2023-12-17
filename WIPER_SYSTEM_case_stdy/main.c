/* JYOTI_PAWASE_214953_CASE_STUDY*/
/* DATE: 16th JULY 2020*/


#include "GPIO.h"
int main()
{
    GPIOConfig(PD1,input);
    GPIOConfig(PD2,input);
    GPIOConfig(PC0,input);
    GPIOConfig(PD6,output);
    while(1)
    {
        uint8_t PIN_READ = 0x00;
        PIN_READ = PIND;
        if ((PIN_READ & (1 << PD1)))
        {
            GPIOPinWrite(PD7,LOW);
        }
        else if (~(PIN_READ & (1 << PD1)))
        {
             GPIOPinWrite(PD7,HIGH);
             Wiper_Mode();
        }
    }
}


