
 #include "GPIO.h"
 #include <avr/io.h>

 void GPIO()
 {
     SET_BIT(PORTD,PD1);
     SET_BIT(PORTD,PD2);
     SET_BIT(PORTD,PD3);

     CLR_BIT(DDRD,PD1);
     CLR_BIT(DDRD,PD2);
     CLR_BIT(DDRD,PD3);

     SET_BIT(DDRD,PD5);
     SET_BIT(DDRD,PD6);
     SET_BIT(DDRD,PD7);


 }
