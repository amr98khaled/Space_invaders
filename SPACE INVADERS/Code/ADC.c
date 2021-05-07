#include "ADC.h"

//SLIDE POT
//PE2

void ADC_INIT(void)
{
	volatile unsigned long delay;
	SYSCTL_RCGC0_R|=(1<<16);   //ENABLE CLOCK ADC0
	delay=SYSCTL_RCGC0_R;
	SYSCTL_RCGC2_R|=(1<<4);    //ENABLE CLOCK FOR PORTE
	delay=SYSCTL_RCGC2_R;
	
	GPIO_PORTE_AFSEL_R|=(1<<2);
	GPIO_PORTE_DEN_R&=~(1<<2);
	GPIO_PORTE_AMSEL_R|=(1<<2);
	GPIO_PORTE_DIR_R &= ~0x04;      //make PE2 input
	
	ADC0_SSPRI_R=0x0123;       //SEQUENCER 3 HAS HIGHEST PRIORITY
	SYSCTL_RCGC0_R&=~0x00000300;   //MAX SAMPLING SPEED 125K/SEC 
	ADC0_ACTSS_R&=~(1<<3);     //DISABLE SEQUENCER DURING INITILIZATION
	ADC0_EMUX_R&=~0x0000F000;  //SOFTWARE TRIGGER 
	ADC0_SSMUX3_R=(ADC0_SSMUX3_R&0xFFFFFFF0)+1;        //PE2 IS CHANNEL '1'
	ADC0_SSCTL3_R|=0x06;       //SAMPLE INTERRUPT ENABLE , END OF SEQUENCE
	//ADC0_IM_R|=(1<<3);         //If interrupts are to be used, set the corresponding MASK bit in the ADCIM register.
	ADC0_ACTSS_R|=(1<<3);      //ENABLE SEQUENCER
	
}

 

unsigned long ADC0_INPUT_SET_X_POS(void)
{
	unsigned long result;
	unsigned long PLAYER_SHIP_X_POS;
	ADC0_PSSI_R|=(1<<3);   //INITIATE SEQUENCER 3
	while((ADC0_RIS_R&0x08)==0){};  //WAIT FOR INPUT 
	ADC0_ISC_R|=0x08; //ACKNOWLEDGE
  result=(ADC0_SSFIFO3_R&0x0FFF);
		
		if((result>0)&&(result<=409))
		{
			PLAYER_SHIP_X_POS=0;
		}
		else if((result>=410)&&(result<=819))
		{
			PLAYER_SHIP_X_POS=7;
		}
		else if((result>=820)&&(result<=1229))
		{
			PLAYER_SHIP_X_POS=14;
		}
		else if((result>=1230)&&(result<=1639))
		{
			PLAYER_SHIP_X_POS=21;
		}
		else if((result>=1640)&&(result<=2049))
		{
			PLAYER_SHIP_X_POS=28;
		}
		else if((result>=2050)&&(result<=2459))
		{
			PLAYER_SHIP_X_POS=35;
		}
		else if((result>=2460)&&(result<=2869))
		{
			PLAYER_SHIP_X_POS=42;
		}
		else if((result>=2870)&&(result<=3279))
		{
			PLAYER_SHIP_X_POS=49;
		}
		else if((result>=3280)&&(result<=3689))
		{
			PLAYER_SHIP_X_POS=58;
		}
		else if((result>=3690)&&(result<=4095))
		{
			PLAYER_SHIP_X_POS=66;
		}
		
		return PLAYER_SHIP_X_POS;
}




 

