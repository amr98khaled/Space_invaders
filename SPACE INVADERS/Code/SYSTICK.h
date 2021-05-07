#include "..//tm4c123gh6pm.h"
#include "ADC.h"
#include "Nokia5110.h"





//FIXED RELOAD VALUE (30 HZ) = 2666667
//PRIORITY OF SYSTICK HANDLER MUST BE LESS THAN THAT OF DAC(SOUND)
void Systick_init(void);

