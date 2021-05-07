#include "..//tm4c123gh6pm.h"

extern unsigned long SW1_FLAG;
extern unsigned long SW2_FLAG;


//SWITCHES ON PE0,PE1
//FIRE ON PE0
//SPECIAL WEAPON ON PE1
//EDGE TRIGGERED INTERRUPTS 

void SWITCHES_INIT(void);
unsigned long SW_INPUT(void);

#define SW1 0x01 // FIRE
#define SW2 0x02  
