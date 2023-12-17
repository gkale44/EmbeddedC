# include "Basic.h"

void Basic_Init()
{
    SET_BIT(DDRD,PD6);//LED AT PIN NO 6
    SET_BIT(PORTD,PD6);
    CLR_BIT(PORTD,PD2);

  while(1)
  {
     uint8_t PIN_READ=0x00;
     PIN_READ=PIND;
    if(PIN_READ &(1<<PD6))
    {
        SET_BIT(PORTD,PD6);
        _delay_ms(1000);
        CLR_BIT(PORTD,PD6);
        _delay_ms(1000);
    }
  }
}
