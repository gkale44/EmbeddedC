#include "GPIO.h"
void Wiper_Mode()
{
    while (1)
    {
      uint8_t PIN_READ=0x00;
      PIN_READ=PIND;
      if((PIN_READ & (1<<PD2)))
        {
            Manual_Mode(); //WIPER MANUAL MODE
        }
        else if(~(PIN_READ & (1<<PD2)))
        {
           Auto_Mode();// WIPER AUTO MODE
        }
    }
}


