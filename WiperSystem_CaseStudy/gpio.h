#ifndef GPIO_H_INCLUDED
#define GPIO_H_INCLUDED

#define SET(PORT,BIT) PORT |= (1<<BIT)
#define CLR(PORT,BIT) PORT &=~ (1<<BIT)
void GPIP_INIT();

#endif // GPIO_H_INCLUDED


