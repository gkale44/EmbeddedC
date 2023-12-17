#ifndef PWM_H_INCLUDED
#define PWM_H_INCLUDED

#define SET_PWM_VALUE(value) OCR0A = value
void PWM_INIT();

#endif // PWM_H_INCLUDED


