#include "DAC.h"
#include "..//tm4c123gh6pm.h"

void DAC_Init(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC2_R|=0x02;
	delay=SYSCTL_RCGC2_R;
	GPIO_PORTB_DIR_R|=0x0F;
	GPIO_PORTB_AFSEL_R&=~0x0F;
	GPIO_PORTB_DR8R_R|=0x0F;
	GPIO_PORTB_DEN_R|=0x0F;
	GPIO_PORTB_AMSEL_R&=~0x0F;
	GPIO_PORTB_PCTL_R&=~0x0000FFFF;
}


void DAC_Out(unsigned long data)
{
	GPIO_PORTB_DATA_R=data;
}
