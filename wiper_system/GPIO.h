#include<avr/io.h>
#include<avr/interrupt.h>
#include<util/delay.h>
//Macros
#define SET_BIT(PORT, BIT) PORT |= (1 << BIT)
#define CLR_BIT(PORT, BIT) PORT &= ~(1 << BIT)
#define TOGGLE_BIT(PORT,BIT) PORT^=(1<<BIT)
#define input 0
#define output 1
#define LOW 0
#define HIGH 1
#define TRIGGER 1
