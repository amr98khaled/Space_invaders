#include "SWITCHES.h"



void SWITCHES_INIT(void)
{
	//clock FOR PORTE enabled in ADC_INIT
	GPIO_PORTE_DIR_R&=~0x03;
	GPIO_PORTE_AFSEL_R&=~0x03;
	GPIO_PORTE_DEN_R|=0x03;
	GPIO_PORTE_AMSEL_R&=~0x03;
	GPIO_PORTE_PCTL_R&=~0x000000FF;
	/*GPIO_PORTE_IM_R&=~0x03;
	GPIO_PORTE_IS_R&=~0x03;
	GPIO_PORTE_IBE_R&=~0x03;
	GPIO_PORTE_IEV_R&=~0x03;
	GPIO_PORTE_ICR_R|=0x03;
	GPIO_PORTE_IM_R|=0x03;
	NVIC_PRI1_R=(NVIC_PRI1_R&0xFFFFFF00)|0x00000040;  //PRIORITY FOR SWITCHES = '2'
	NVIC_EN0_R|=(1<<4);
	*/
	//ENABLE_INTERRRUPTS IN MAIN
}

unsigned long SW_INPUT(void)
{
	volatile unsigned long input;
	
	if((GPIO_PORTE_DATA_R&0x01)==0x01)
	{
		input=SW1;
	}
	else if((GPIO_PORTE_DATA_R&0x02)==0x02)
	{
		input=SW2;
	}
	else
	{
		input=0;
	}
	return input;
}


/*
void GPIOPortE_Handler(void)
{
	if((GPIO_PORTE_RIS_R&0x01)==0x01)
	{
		GPIO_PORTE_ICR_R|=0x01;
		SW1_FLAG=1;
	}
	else if(((GPIO_PORTE_RIS_R&0x01)==0))
	{
		//GPIO_PORTE_ICR_R|=0x01;
		SW1_FLAG=0;
	}
	else if(((GPIO_PORTE_RIS_R&0x02)==0x02))
	{
		GPIO_PORTE_ICR_R|=0x02;
		SW2_FLAG=1;
	}
	else if((GPIO_PORTE_RIS_R&0x02)==0)
	{
		//GPIO_PORTE_ICR_R|=0x02;
		SW2_FLAG=0;
	}
}
*/
