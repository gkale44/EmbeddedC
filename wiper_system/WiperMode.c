#include "GPIO.h"
void wiper_mode()
{
    while (1)
    {
      uint8_t PIN_READ=0x00;
      PIN_READ=PIND;
      if((PIN_READ & (1<<PD3)))
        {
            manual_mode();
        }
        else if(~(PIN_READ & (1<<PD3)))
        {
           auto_mode();
        }
    }
}

