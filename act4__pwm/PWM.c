#include "PWM.h"
struct {
volatile unsigned int FLAG_ISR0: 1;
volatile unsigned int FLAG_ISR1: 1;
}
FLAG_BIT;
int PWM()
{
    TCCR0A |= (1 << COM0A1);
    TCCR0A &= ~(1 << COM0A1);
    OCR0A = 128;
    if((FLAG_BIT.FLAG_ISR0 == 1) && (OCR0A <= 255))
    {
        while(FLAG_BIT.FLAG_ISR1 == 1)
        {
            GPIOPinWrite(PD6,HIGH);
            _dealy_ms(2000);
            GPIOPinWrite(PD6,LOW);
            _delay_ms(2000);
        }
        OCR0A = OCR0A + (0.1 * OCR0A);
        FLAG_BIT.FLAG_ISR0 = 0;
    }
    if((FLAG_BIT.FLAG_ISR1 == 1) && (OCR0A >=0))
    {
        while(FLAG_BIT.FLAG_ISR0 == 0)
        {
            GPIOPinWrite(PD6,HIGH);
            -delay_ms(2000);
            GPIOPinWrite(PD6,LOW);
            _delay_ms(2000);
        }
        OCR0A = OCR0A - (0.1 * OCR0A);
        FLAG_BIT.FLAG_ISR1 = 0;
    }
}
ISR(INT0_vect)
{
    cli();
    FLAG_BIT.FLAG_ISR0 = 1;
    sei();
}
ISR(INT1_vect)
{
    FLAG_BIT.FLAG_ISR1 = 1;
}
