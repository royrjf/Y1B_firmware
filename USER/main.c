#include "config.h"
#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "lswitch.h"
#include "u485.h"
#include "timer.h"
#include "motor.h"
#include "current.h"
#include "config.h"
#include "dma.h"
#include "mos.h"
#include "crc.h"
#include "wdg.h"
volatile u16 ST_CURRENT; 
int main(void)
 {
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	delay_init();	    	 
	u485_init(115200);	 
	TIM3_Int_Init(4999,71);     //5ms
	//TIM4_Int_Init(9999,71);     //10ms
	crc_init();
	motor_init();
	adc_init();
	mos_init();
	lmtswitch_init();
	delay_ms(500);
	IWDG_Config(IWDG_Prescaler_64,625);  //1s 	 
	ST_CURRENT=Get_ADC_Value(ADC_Channel_8,20);
	 PAout(4)=0;
  while(1)
	{

		if(1)
		{
			u485_tick();
		}
		if(1)
		{
			lmtswitch_dect();    //¼ì²â1-0µÄ±ä»¯
		}
		if(1)
		{
			IWDG_Feed();
		}
		if(1)
		{
			motor_chk();
		}
		
	}	 
} 

