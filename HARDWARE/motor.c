#include "motor.h"
#include "u485.h"
#include "usart.h"
#include "crc.h"
#include "delay.h"
#include "current.h"
#include "stdio.h"
#include "config.h"
char str_chk[25];
Motor_t mrm; 
void(*motorchk[36])(FunctionalState NewState);
void motor1(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MAout4=1;
	}
	else
	{
		MAout4=0;
	}
}
void motor2(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MAout3=1;
	}
	else
	{
		MAout3=0;
	}
}
void motor3(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MAout2=1;
	}
	else
	{
		MAout2=0;
	}
}
void motor4(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MAout1=1;
	}
	else
	{
		MAout1=0;
	}
}

void motor5(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MBout4=1;
	}
	else
	{
		MBout4=0;
	}
}
void motor6(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MBout3=1;
	}
	else
	{
		MBout3=0;
	}
}
void motor7(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MBout2=1;
	}
	else
	{
		MBout2=0;
	}
}
void motor8(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MBout1=1;
	}
	else
	{
		MBout1=0;
	}
}

void motor9(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MCout4=1;
	}
	else
	{
		MCout4=0;
	}
}
void motor10(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MCout3=1;
	}
	else
	{
		MCout3=0;
	}
}
void motor11(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MCout2=1;
	}
	else
	{
		MCout2=0;
	}
}
void motor12(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MCout1=1;
	}
	else
	{
		MCout1=0;
	}
}

void motor13(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MDout4=1;
	}
	else
	{
		MDout4=0;
	}
}
void motor14(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MDout3=1;
	}
	else
	{
		MDout3=0;
	}
}
void motor15(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MDout2=1;
	}
	else
	{
		MDout2=0;
	}
}
void motor16(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MDout1=1;
	}
	else
	{
		MDout1=0;
	}
}

void motor17(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MEout4=1;
	}
	else
	{
		MEout4=0;
	}
}
void motor18(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MEout3=1;
	}
	else
	{
		MEout3=0;
	}
}
void motor19(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MEout2=1;
	}
	else
	{
		MEout2=0;
	}
}
void motor20(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MEout1=1;
	}
	else
	{
		MEout1=0;
	}
}

void motor21(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MFout4=1;
	}
	else
	{
		MFout4=0;
	}
}
void motor22(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MFout3=1;
	}
	else
	{
		MFout3=0;
	}
}
void motor23(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MFout2=1;
	}
	else
	{
		MFout2=0;
	}
}
void motor24(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MFout1=1;
	}
	else
	{
		MFout1=0;
	}
}

void motor25(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MGout4=1;
	}
	else
	{
		MGout4=0;
	}
}
void motor26(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MGout3=1;
	}
	else
	{
		MGout3=0;
	}
}
void motor27(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MGout2=1;
	}
	else
	{
		MGout2=0;
	}
}
void motor28(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MGout1=1;
	}
	else
	{
		MGout1=0;
	}
}

void motor29(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MHout4=1;
	}
	else
	{
		MHout4=0;
	}
}
void motor30(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MHout3=1;
	}
	else
	{
		MHout3=0;
	}
}
void motor31(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MHout2=1;
	}
	else
	{
		MHout2=0;
	}
}
void motor32(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MHout1=1;
	}
	else
	{
		MHout1=0;
	}
}

void motor33(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MIout4=1;
	}
	else
	{
		MIout4=0;
	}
}
void motor34(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MIout3=1;
	}
	else
	{
		MIout3=0;
	}
}
void motor35(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MIout2=1;
	}
	else
	{
		MIout2=0;
	}
}
void motor36(FunctionalState NewState)
{
	if(NewState==ENABLE)
	{
		MIout1=1;
	}
	else
	{
		MIout1=0;
	}
}


void motor_function()
{
	motorchk[0]=motor1;
	motorchk[1]=motor2;
	motorchk[2]=motor3;
	motorchk[3]=motor4;
	
	motorchk[4]=motor5;
	motorchk[5]=motor6;
	motorchk[6]=motor7;
	motorchk[7]=motor8;
	
	motorchk[8]=motor9;
	motorchk[9]=motor10;
	motorchk[10]=motor11;
	motorchk[11]=motor12;
	
	motorchk[12]=motor13;
	motorchk[13]=motor14;
	motorchk[14]=motor15;
	motorchk[15]=motor16;
	
	motorchk[16]=motor17;
	motorchk[17]=motor18;
	motorchk[18]=motor19;
	motorchk[19]=motor20;
	
	motorchk[20]=motor21;
	motorchk[21]=motor22;
	motorchk[22]=motor23;
	motorchk[23]=motor24;
	
	motorchk[24]=motor25;
	motorchk[25]=motor26;
	motorchk[26]=motor27;
	motorchk[27]=motor28;
	
	motorchk[28]=motor29;
	motorchk[29]=motor30;
	motorchk[30]=motor31;
	motorchk[31]=motor32;
	
	motorchk[32]=motor33;
	motorchk[33]=motor34;
	motorchk[34]=motor35;
	motorchk[35]=motor36;	
}





 
void motor_init(void)   //PC13,14,15 speed limit 2MHZ£¬3ma 
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOE, ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin =MD1|ME4|ME3|ME2|ME1|MF4|MF3|GPIO_Pin_4;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 		
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOA,MD1|ME4|ME3|ME2|ME1|MF4|MF3);	
	
	GPIO_InitStructure.GPIO_Pin =MA4|MI1|MG3|MG4|GPIO_Pin_11;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOB,MA4|MI1|MG3|MG4|GPIO_Pin_11);	
	
	GPIO_InitStructure.GPIO_Pin =MC1|MD4|MD3|MD2|MF2|MF1;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOC,MC1|MD4|MD3|MD2|MF2|MF1);	
	
	GPIO_InitStructure.GPIO_Pin =MC4|MC3|MC2;	   //PC13,14,15
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_2MHz;	
	GPIO_Init(GPIOC, &GPIO_InitStructure);	
	GPIO_ResetBits(GPIOC,MC4|MC3|MC2);	
	
	
	GPIO_InitStructure.GPIO_Pin =MA3|MA2|MA1|MB4|MB3|MB2|MB1|MG2|MG1|MH4|MH3|MH2|MH1|MI4|MI3|MI2;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOE, &GPIO_InitStructure);					 
	GPIO_ResetBits(GPIOE,MA3|MA2|MA1|MB4|MB3|MB2|MB1|MG2|MG1|MH4|MH3|MH2|MH1|MI4|MI3|MI2);	
	
	motor_function();
	motor_start_num=100;
}

void motor_start_manage(motor_list p)
{
	u8 i;
	for(i=0;i<p.count;i++)
	{
			if(i>=10)
			{
				break;
			}
			switch(p.motor_num_table[i])    
			{
				case 1: MAout4=1; mrm.mtr1_flag=1;push_flag=1;   break;   //A1
				case 2: MAout3=1; mrm.mtr2_flag=1;push_flag=1;   break;   //A2
				case 3: MAout2=1; mrm.mtr3_flag=1;push_flag=1;   break;   //A3
				case 4: MAout1=1; mrm.mtr4_flag=1;push_flag=1;   break;   //A4
				
				case 5: MBout4=1; mrm.mtr5_flag=1;push_flag=1;    break;   //B1
				case 6: MBout3=1; mrm.mtr6_flag=1;push_flag=1;    break;   //B2
				case 7: MBout2=1; mrm.mtr7_flag=1;push_flag=1;    break;   //B3
				case 8: MBout1=1; mrm.mtr8_flag=1;push_flag=1;    break;   //B4
				
				case 9: MCout4=1; mrm.mtr9_flag=1;push_flag=1;    break;   //C1
				case 10:MCout3=1; mrm.mtr10_flag=1;push_flag=1;   break;   //C2
				case 11:MCout2=1; mrm.mtr11_flag=1;push_flag=1;   break;   //C3
				case 12:MCout1=1; mrm.mtr12_flag=1;push_flag=1;   break;   //C4
				
				case 13:MDout4=1; mrm.mtr13_flag=1;push_flag=1;  break;    //D1
				case 14:MDout3=1; mrm.mtr14_flag=1;push_flag=1;  break;    //D2
				case 15:MDout2=1; mrm.mtr15_flag=1;push_flag=1;  break;    //D3
				case 16:MDout1=1; mrm.mtr16_flag=1;push_flag=1;  break;     //D4
				
				case 17:MEout4=1; mrm.mtr17_flag=1;push_flag=1;  break;    //E1
				case 18:MEout3=1; mrm.mtr18_flag=1;push_flag=1;  break;    //E2
				case 19:MEout2=1; mrm.mtr19_flag=1;push_flag=1;  break;    //E3
				case 20:MEout1=1; mrm.mtr20_flag=1;push_flag=1;  break;    //E4
				
				case 21:MFout4=1; mrm.mtr21_flag=1;push_flag=1;  break;    //F1
				case 22:MFout3=1; mrm.mtr22_flag=1;push_flag=1;  break;    //F2
				case 23:MFout2=1; mrm.mtr23_flag=1;push_flag=1; break;    //F3
				case 24:MFout1=1; mrm.mtr24_flag=1;push_flag=1; break;    //F4
				
				case 25:MGout4=1; mrm.mtr25_flag=1;push_flag=1;  break;    //G1
				case 26:MGout3=1; mrm.mtr26_flag=1;push_flag=1;  break;    //G2
				case 27:MGout2=1; mrm.mtr27_flag=1;push_flag=1;  break;    //G3
				case 28:MGout1=1; mrm.mtr28_flag=1;push_flag=1;  break;    //G4
				
				case 29:MHout4=1; mrm.mtr29_flag=1;push_flag=1;  break;    //H1
				case 30:MHout3=1; mrm.mtr30_flag=1;push_flag=1;  break;    //H2
				case 31:MHout2=1; mrm.mtr31_flag=1;push_flag=1;  break;    //H3
				case 32:MHout1=1; mrm.mtr32_flag=1;push_flag=1;  break;    //H4
				
				case 33:MIout4=1; mrm.mtr33_flag=1;push_flag=1;  break;	  //I1
				case 34:MIout3=1; mrm.mtr34_flag=1;push_flag=1;  break;   //I2
				case 35:MIout2=1; mrm.mtr35_flag=1;push_flag=1;  break;   //I3
				case 36:MIout1=1; mrm.mtr36_flag=1;push_flag=1;  break;		//I4
	}
	}
	
}
void motor_chk()
{
	u16 cur;
	if((CHK_Motor.chkm_flag==1)&&(CHK_Motor.chkm_lock==1))
	{
		  	CHK_Motor.chkm_lock=0;	
				//CHK_Motor.chkm_run_cur_num=i;
				motorchk[CHK_Motor.chkm_table[CHK_Motor.chkm_run_cur_num]-1](ENABLE);
				CHK_Motor.chkm_timer_flag=1;
				delay_ms(100);
				cur=Get_ADC_Value(ADC_Channel_8,10);
		
				if(cur>=ST_CURRENT)
				{
					cur=cur-ST_CURRENT;
					snprintf(str_chk, 15,"B,CHKM,%d,%d,",CHK_Motor.chkm_table[CHK_Motor.chkm_run_cur_num],50+9*cur);
				}
				else
				{
					snprintf(str_chk, 15,"B,CHKM,%d,%d,",CHK_Motor.chkm_table[CHK_Motor.chkm_run_cur_num],50);
				}
	
				
			  CRCValue=crc_calculate(str_chk,sizeof(str_chk));
			  CRC_4=(CRCValue>>24)&0xff;
			  CRC_3=(CRCValue>>16)&0xff;
			  CRC_2=(CRCValue>>8)&0xff;
			  CRC_1=(CRCValue)&0xff;
		 
		  	snprintf(str_chk, 23,"%s%x%x%x%x",str_chk,CRC_4,CRC_3,CRC_2,CRC_1);
				PCout(6)=1;
				printf("%s\r\n",str_chk);
				delay_us(150);
				PCout(6)=0;
				if(CHK_Motor.chkm_run_cur_num==(CHK_Motor.chkm_num-1))
				{
					CHK_Motor.chkm_flag=0;
				}			
	}
}
void motor_close()
{
	MAout1=0;
	MAout2=0;
	MAout3=0;
	MAout4=0;
	
	MBout1=0;
	MBout2=0;
	MBout3=0;
	MBout4=0;
	
	MCout1=0;
	MCout2=0;
	MCout3=0;
	MCout4=0;
	
	MDout1=0;
	MDout2=0;
	MDout3=0;
	MDout4=0;
	
	MEout1=0;
	MEout2=0;
	MEout3=0;
	MEout4=0;
	
	MFout1=0;
	MFout2=0;
	MFout3=0;
	MFout4=0;
	
	MGout1=0;
	MGout2=0;
	MGout3=0;
	MGout4=0;
	
	MHout1=0;
	MHout2=0;
	MHout3=0;
	MHout4=0;
	
	MIout1=0;
	MIout2=0;
	MIout3=0;
	MIout4=0;

}


