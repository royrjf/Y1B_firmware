#include "config.h"
#include "lswitch.h"
#include "motor.h"
#include "usart.h"
#include "crc.h"
#include "delay.h"
u8 aaa1,aaa2,aaa3;
u8 (*readS[36])(void);
void lmtswitch_init(void)
{
 
	GPIO_InitTypeDef  GPIO_InitStructure;
 	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC|RCC_APB2Periph_GPIOD, ENABLE);	
	
	GPIO_InitStructure.GPIO_Pin = S16_Pin|S17_Pin|S18_Pin;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOA, &GPIO_InitStructure);					 
//	GPIO_SetBits(GPIOA,S16_Pin|S17_Pin|S18_Pin);	  //S16~18
	
	GPIO_InitStructure.GPIO_Pin = S9_Pin|S10_Pin|S11_Pin|S12_Pin|S25_Pin|S26_Pin|S27_Pin|S28_Pin;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOB, &GPIO_InitStructure);					 
	//GPIO_SetBits(GPIOB,S9_Pin|S10_Pin|S11_Pin|S12_Pin|S25_Pin|S26_Pin|S27_Pin|S28_Pin);	  //S9~12,25~28
	
	GPIO_InitStructure.GPIO_Pin = S13_Pin|S14_Pin|S15_Pin|S20_Pin|S21_Pin|S22_Pin;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOC, &GPIO_InitStructure);					 
	//GPIO_SetBits(GPIOC,S9_Pin|S10_Pin|S11_Pin|S12_Pin|S25_Pin|S26_Pin|S27_Pin|S28_Pin);	  //S7~9,10~12
	
	GPIO_InitStructure.GPIO_Pin = S1_Pin|S2_Pin|S3_Pin|S4_Pin|S5_Pin|S6_Pin|S29_Pin|S30_Pin|S31_Pin|S32_Pin|S33_Pin|S34_Pin|S35_Pin|S36_Pin;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU; 		 //上拉输入
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;		 
	GPIO_Init(GPIOD, &GPIO_InitStructure);					 
//	GPIO_SetBits(GPIOD,S1_Pin|S2_Pin|S3_Pin|S4_Pin|S5_Pin|S6_Pin|S29_Pin|S30_Pin|S31_Pin|S32_Pin|S33_Pin|S34_Pin|S35_Pin|S36_Pin);	  //S1~6,8~15
	

		//PD0,PD1 remap
	GPIO_PinRemapConfig(GPIO_Remap_PD01, ENABLE);   
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD | RCC_APB2Periph_AFIO, ENABLE); 
	GPIO_InitStructure.GPIO_Pin = S23_Pin|S24_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOD, &GPIO_InitStructure);    //S23,24
	//JTAG IO REMAP
	GPIO_PinRemapConfig(GPIO_Remap_SWJ_JTAGDisable, ENABLE);      
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA | RCC_APB2Periph_GPIOB | RCC_APB2Periph_AFIO, ENABLE); 
	GPIO_InitStructure.GPIO_Pin = S7_Pin| S8_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;  
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOB, &GPIO_InitStructure);   //S7,8
 
	GPIO_InitStructure.GPIO_Pin = S19_Pin;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; 
	GPIO_Init(GPIOA, &GPIO_InitStructure);    //S19

	
}
u8 readS0()
{
	u8 temp;
	temp=S1_in;
	return temp;
}

u8 readS1()
{
	u8 temp;
	temp=S2_in;
	return temp;
}

u8 readS2()
{
	u8 temp;
	temp=S3_in;
	return temp;
}

u8 readS3()
{
	u8 temp;
	temp=S4_in;
	return temp;
}

u8 readS4()
{
	u8 temp;
	temp=S5_in;
	return temp;
}


u8 readS5()
{
	u8 temp;
	temp=S6_in;
	return temp;
}

u8 readS6()
{
	u8 temp;
	temp=S7_in;
	return temp;
}

u8 readS7()
{
	u8 temp;
	temp=S8_in;
	return temp;
}

u8 readS8()
{
	u8 temp;
	temp=S9_in;
	return temp;
}

u8 readS9()
{
	u8 temp;
	temp=S10_in;
	return temp;
}

u8 readS10()
{
	u8 temp;
	temp=S11_in;
	return temp;
}

u8 readS11()
{
	u8 temp;
	temp=S12_in;
	return temp;
}

u8 readS12()
{
	u8 temp;
	temp=S13_in;
	return temp;
}

u8 readS13()
{
	u8 temp;
	temp=S14_in;
	return temp;
}

u8 readS14()
{
	u8 temp;
	temp=S15_in;
	return temp;
}

u8 readS15()
{
	u8 temp;
	temp=S16_in;
	return temp;
}

u8 readS16()
{
	u8 temp;
	temp=S17_in;
	return temp;
}

u8 readS17()
{
	u8 temp;
	temp=S18_in;
	return temp;
}

u8 readS18()
{
	u8 temp;
	temp=S19_in;
	return temp;
}

u8 readS19()
{
	u8 temp;
	temp=S20_in;
	return temp;
}

u8 readS20()
{
	u8 temp;
	temp=S21_in;
	return temp;
}

u8 readS21()
{
	u8 temp;
	temp=S22_in;
	return temp;
}

u8 readS22()
{
	u8 temp;
	temp=S23_in;
	return temp;
}

u8 readS23()
{
	u8 temp;
	temp=S24_in;
	return temp;
}

u8 readS24()
{
	u8 temp;
	temp=S25_in;
	return temp;
}

u8 readS25()
{
	u8 temp;
	temp=S26_in;
	return temp;
}

u8 readS26()
{
	u8 temp;
	temp=S27_in;
	return temp;
}

u8 readS27()
{
	u8 temp;
	temp=S28_in;
	return temp;
}

u8 readS28()
{
	u8 temp;
	temp=S29_in;
	return temp;
}

u8 readS29()
{
	u8 temp;
	temp=S30_in;
	return temp;
}

u8 readS30()
{
	u8 temp;
	temp=S31_in;
	return temp;
}

u8 readS31()
{
	u8 temp;
	temp=S32_in;
	return temp;
}

u8 readS32()
{
	u8 temp;
	temp=S33_in;
	return temp;
}

u8 readS33()
{
	u8 temp;
	temp=S34_in;
	return temp;
}

u8 readS34()
{
	u8 temp;
	temp=S35_in;
	return temp;
}

u8 readS35()
{
	u8 temp;
	temp=S36_in;
	return temp;
}




void s_in()
{
	readS[0]=readS0;
	readS[1]=readS1;
	readS[2]=readS2;
	readS[3]=readS3;
	
	readS[4]=readS4;
	readS[5]=readS5;
	readS[6]=readS6;
	readS[7]=readS7;
	
	readS[8]=readS8;
	readS[9]=readS9;
	readS[10]=readS10;
	readS[11]=readS11;
	
	readS[12]=readS12;
	readS[13]=readS13;
	readS[14]=readS14;
	readS[15]=readS15;
	
	readS[16]=readS16;
	readS[17]=readS17;
	readS[18]=readS18;
	readS[19]=readS19;
	
	readS[20]=readS20;
	readS[21]=readS21;
	readS[22]=readS22;
	readS[23]=readS23;
	
	readS[24]=readS24;
	readS[25]=readS25;
	readS[26]=readS26;
	readS[27]=readS27;
	
	readS[28]=readS28;
	readS[29]=readS29;
	readS[30]=readS30;
	readS[31]=readS31;
	
	readS[32]=readS32;
	readS[33]=readS33;
	readS[34]=readS34;
	readS[35]=readS35;
	
	
}

void lmtswitch_dect()    
{
	static u8 motor_start_num1;
	static u8 lock1,lock2,lock3,lock4,lock5,lock6,lock7,lock8,lock9;
	static u8 lock10,lock11,lock12,lock13,lock14,lock15,lock16,lock17,lock18;
	static u8 lock19,lock20,lock21,lock22,lock23,lock24,lock25,lock26,lock27;
	static u8 lock28,lock29,lock30,lock31,lock32,lock33,lock34,lock35,lock36;
	static u8 S1_count,S2_count,S3_count,S4_count,S5_count,S6_count,S7_count,S8_count,S9_count,S10_count,S11_count,S12_count;
	static u8 S13_count,S14_count,S15_count,S16_count,S17_count,S18_count,S19_count,S20_count,S21_count,S22_count,S23_count,S24_count;
	static u8 S25_count,S26_count,S27_count,S28_count,S29_count,S30_count,S31_count,S32_count,S33_count,S34_count,S35_count,S36_count;
	if(mrm.mtr1_flag==1)
	{
		if(S1_in==0)
		{
			S1_count++;
			if(S1_count>=1)
			{
				lock1=1;
			}
		}
		else if(lock1==1)   //limit switch have decteted the 0-1
		{
			lock1=0;		
			MAout4=0;
			mrm.mtr1_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock1=0;
			S1_count=0;
		}
	}
	
	if(mrm.mtr2_flag==1)
	{
		if(S2_in==0)
		{
			S2_count++;
			if(S2_count>=4)
			{
				lock2=1;
			}
		}
		else if(lock2==1)   //limit switch have decteted the 0-1
		{
			lock2=0;		
			MAout3=0;
			mrm.mtr2_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock2=0;
			S2_count=0;
		}
	}
	
	if(mrm.mtr3_flag==1)
	{
		if(S3_in==0)
		{
			S3_count++;
			if(S3_count>=4)
			{
				lock3=1;
			}
		}
		else if(lock3==1)   //limit switch have decteted the 0-1
		{
			lock3=0;		
			MAout2=0;
			mrm.mtr3_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock3=0;
			S3_count=0;
		}
	}
	

	if(mrm.mtr4_flag==1)
	{
		if(S4_in==0)
		{
		
		  S4_count++;
			if(S4_count>=4)
			{
				lock4=1;
			}
		}
		else if(lock4==1)   //limit switch have decteted the 0-1
		{

			lock4=0;		
			MAout1=0;
			mrm.mtr4_flag=0;	
			motor_start_num--;	
		}
		else 
		{
			lock4=0;
			S4_count=0;
		}
	}
	
	if(mrm.mtr5_flag==1)
	{
		if(S5_in==0)
		{
			S5_count++;
			if(S5_count>=4)
			{
				lock5=1;
			}
		}
		else if(lock5==1)   //limit switch have decteted the 0-1
		{
			lock5=0;		
			MBout4=0;
			mrm.mtr5_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock5=0;
			S1_count=0;
		}
	}
	
	if(mrm.mtr6_flag==1)
	{
		if(S6_in==0)
		{
			S6_count++;
			if(S6_count>=4)
			{
				lock6=1;
			}
		}
		else if(lock6==1)   //limit switch have decteted the 0-1
		{

			lock6=0;		
			MBout3=0;
			mrm.mtr6_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock6=0;
			S6_count=0;
		}
	}
	
	if(mrm.mtr7_flag==1)
	{
		if(S7_in==0)
		{
			S7_count++;
			if(S7_count>=4)
			{
				lock7=1;
			}
		}
		else if(lock7==1)   //limit switch have decteted the 0-1
		{
			lock7=0;		
			MBout2=0;
			mrm.mtr7_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock7=0;
			S7_count=0;
		}
	}
	
	if(mrm.mtr8_flag==1)
	{
		if(S8_in==0)
		{
			S8_count++;
			if(S8_count>=4)
			{
				lock8=1;
			}
		}
		else if(lock8==1)   //limit switch have decteted the 0-1
		{
			lock8=0;		
			MBout1=0;
			mrm.mtr8_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock8=0;
			S8_count=0;
		}
	}
	
	if(mrm.mtr9_flag==1)
	{
		if(S9_in==0)
		{
			S9_count++;
			if(S9_count>=4)
			{
				lock9=1;
			}
		}
		else if(lock9==1)   //limit switch have decteted the 0-1
		{
			lock9=0;		
			MCout4=0;
			mrm.mtr9_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock9=0;
			S9_count=0;
		}
	}
	
		if(mrm.mtr10_flag==1)
	{
		if(S10_in==0)
		{
			S10_count++;
			if(S10_count>=4)
			{
				lock10=1;
			}
		}
		else if(lock10==1)   //limit switch have decteted the 0-1
		{
			lock10=0;		
			MCout3=0;
			mrm.mtr10_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock10=0;
			S10_count=0;
		}
	}
	
	if(mrm.mtr11_flag==1)
	{
		if(S11_in==0)
		{
			S11_count++;
			if(S11_count>=4)
			{
				lock11=1;
			}
		}
		else if(lock11==1)   //limit switch have decteted the 0-1
		{
			lock11=0;		
			MCout2=0;
			mrm.mtr12_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock11=0;
			S12_count=0;
		}
	}
	
	if(mrm.mtr12_flag==1)
	{
		if(S12_in==0)
		{
			S12_count++;
			if(S12_count>=4)
			{
				lock12=1;
			}
		}
		else if(lock12==1)   //limit switch have decteted the 0-1
		{
			lock12=0;		
			MCout1=0;
			mrm.mtr12_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock12=0;
			S12_count=0;
		}
	}

			if(mrm.mtr13_flag==1)
	{
		if(S13_in==0)
		{
			S13_count++;
			if(S13_count>=4)
			{
				lock13=1;
			}
		}
		else if(lock13==1)   //limit switch have decteted the 0-1
		{
			lock13=0;		
			MDout4=0;
			mrm.mtr13_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock13=0;
			S13_count=0;
		}
	}
		
	if(mrm.mtr14_flag==1)
	{
		if(S14_in==0)
		{
			S14_count++;
			if(S14_count>=4)
			{
				lock14=1;
			}
		}
		else if(lock14==1)   //limit switch have decteted the 0-1
		{

			lock14=0;		
			MDout3=0;
			mrm.mtr14_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock14=0;
			S14_count=0;
		}
	}
		
		
	if(mrm.mtr15_flag==1)
	{
		if(S15_in==0)
		{
			S15_count++;
			if(S15_count>=4)
			{
				lock15=1;
			}
		}
		else if(lock15==1)   //limit switch have decteted the 0-1
		{
			lock15=0;		
			MDout2=0;
			mrm.mtr15_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock15=0;
			S15_count=0;
		}
	}
		
	if(mrm.mtr16_flag==1)
	{
		if(S16_in==0)
		{
			S16_count++;
			if(S16_count>=4)
			{
				lock16=1;
			}
		}
		else if(lock16==1)   //limit switch have decteted the 0-1
		{
			lock16=0;		
			MDout1=0;
			mrm.mtr16_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock16=0;
			S16_count=0;
		}
	}
	
	if(mrm.mtr17_flag==1)
	{
		if(S17_in==0)
		{
			S17_count++;
			if(S17_count>=4)
			{
				lock17=1;
			}
		}
		else if(lock17==1)   //limit switch have decteted the 0-1
		{
			lock17=0;		
			MEout4=0;
			mrm.mtr17_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock17=0;
			S17_count=0;
		}
	}
	
	if(mrm.mtr18_flag==1)
	{
		if(S18_in==0)
		{
			S18_count++;
			if(S18_count>=4)
			{
				lock18=1;
			}
		}
		else if(lock18==1)   //limit switch have decteted the 0-1
		{
			lock18=0;		
			MEout3=0;
			mrm.mtr18_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock18=0;
			S18_count=0;
		}
	}
	
	if(mrm.mtr19_flag==1)
	{
		if(S19_in==0)
		{
			S19_count++;
			if(S19_count>=4)
			{
				lock19=1;
			}
		}
		else if(lock19==1)   //limit switch have decteted the 0-1
		{
			lock19=0;		
			MEout2=0;
			mrm.mtr19_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock19=0;
			S19_count=0;
		}
	}
	
	if(mrm.mtr20_flag==1)
	{
		if(S20_in==0)
		{
			S20_count++;
			if(S20_count>=4)
			{
				lock20=1;
			}
		}
		else if(lock20==1)   //limit switch have decteted the 0-1
		{
			lock20=0;		
			MEout1=0;
			mrm.mtr20_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock20=0;
			S20_count=0;
		}
	}
	
	if(mrm.mtr21_flag==1)
	{
		if(S21_in==0)
		{
			S21_count++;
			if(S21_count>=4)
			{
				lock21=1;
			}
		}
		else if(lock21==1)   //limit switch have decteted the 0-1
		{
			lock21=0;		
			MFout4=0;
			mrm.mtr21_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock21=0;
			S21_count=0;
		}
	}
	
	if(mrm.mtr22_flag==1)
	{
		if(S22_in==0)
		{
			S22_count++;
			if(S22_count>=4)
			{
				lock22=1;
			}
		}
		else if(lock22==1)   //limit switch have decteted the 0-1
		{
			lock22=0;		
			MFout3=0;
			mrm.mtr22_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock22=0;
			S22_count=0;
		}
	}
	
	if(mrm.mtr23_flag==1)
	{
		if(S23_in==0)
		{
			S23_count++;
			if(S23_count>=4)
			{
				lock23=1;
			}
		}
		else if(lock23==1)   //limit switch have decteted the 0-1
		{
			lock23=0;		
			MFout2=0;
			mrm.mtr23_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock23=0;
			S23_count=0;
		}
	}
	
	if(mrm.mtr24_flag==1)
	{
		if(S24_in==0)
		{
			S24_count++;
			if(S24_count>=4)
			{
				lock24=1;
			}
		}
		else if(lock24==1)   //limit switch have decteted the 0-1
		{
			lock24=0;		
			MFout1=0;
			mrm.mtr24_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock24=0;
			S24_count=0;
		}
	}
	
	if(mrm.mtr25_flag==1)
	{
		if(S25_in==0)
		{
			S25_count++;
			if(S25_count>=4)
			{
				lock25=1;
			}
		}
		else if(lock25==1)   //limit switch have decteted the 0-1
		{
			lock25=0;		
			MGout4=0;
			mrm.mtr25_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock25=0;
			S25_count=0;
		}
	}
	
	if(mrm.mtr26_flag==1)
	{
		if(S26_in==0)
		{
			S26_count++;
			if(S26_count>=4)
			{
				lock26=1;
			}
		}
		else if(lock26==1)   //limit switch have decteted the 0-1
		{
			lock26=0;		
			MGout3=0;
			mrm.mtr26_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock26=0;
			S26_count=0;
		}
	}
	
	if(mrm.mtr27_flag==1)
	{
		if(S27_in==0)
		{
			S27_count++;
			if(S27_count>=4)
			{
				lock27=1;
			}
		}
		else if(lock27==1)   //limit switch have decteted the 0-1
		{
			lock27=0;		
			MGout2=0;
			mrm.mtr27_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock27=0;
			S27_count=0;
		}
	}
	
	if(mrm.mtr28_flag==1)
	{
		if(S28_in==0)
		{
			S28_count++;
			if(S28_count>=4)
			{
				lock28=1;
			}
		}
		else if(lock28==1)   //limit switch have decteted the 0-1
		{
			lock28=0;		
			MGout1=0;
			mrm.mtr28_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock28=0;
			S28_count=0;
		}
	}
	
	if(mrm.mtr29_flag==1)
	{
		if(S29_in==0)
		{
			S29_count++;
			if(S29_count>=4)
			{
				lock29=1;
			}
		}
		else if(lock29==1)   //limit switch have decteted the 0-1
		{
			lock29=0;		
			MHout4=0;
			mrm.mtr29_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock29=0;
			S29_count=0;
		}
	}
	
	if(mrm.mtr30_flag==1)
	{
		if(S30_in==0)
		{
			S30_count++;
			if(S30_count>=4)
			{
				lock30=1;
			}
		}
		else if(lock30==1)   //limit switch have decteted the 0-1
		{
			lock30=0;		
			MHout3=0;
			mrm.mtr30_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock30=0;
			S30_count=0;
		}
	}
	
		if(mrm.mtr31_flag==1)
	{
		if(S31_in==0)
		{
			S31_count++;
			if(S31_count>=4)
			{
				lock31=1;
			}
		}
		else if(lock31==1)   //limit switch have decteted the 0-1
		{
			lock31=0;		
			MHout2=0;
			mrm.mtr31_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock31=0;
			S31_count=0;
		}
	}
	
	if(mrm.mtr32_flag==1)
	{
		if(S32_in==0)
		{
			S32_count++;
			if(S32_count>=4)
			{
				lock32=1;
			}
		}
		else if(lock32==1)   //limit switch have decteted the 0-1
		{
			lock32=0;		
			MHout1=0;
			mrm.mtr32_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock32=0;
			S32_count=0;
		}
	}
	
	if(mrm.mtr33_flag==1)
	{
		if(S33_in==0)
		{
			S33_count++;
			if(S33_count>=4)
			{
				lock33=1;
			}
		}
		else if(lock33==1)   //limit switch have decteted the 0-1
		{
			lock33=0;		
			MIout4=0;
			mrm.mtr33_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock33=0;
			S33_count=0;
		}
	}
	
	if(mrm.mtr34_flag==1)
	{
		if(S34_in==0)
		{
			S34_count++;
			if(S34_count>=4)
			{
				lock34=1;
			}
		}
		else if(lock34==1)   //limit switch have decteted the 0-1
		{
			lock34=0;		
			MIout3=0;
			mrm.mtr34_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock34=0;
			S34_count=0;
		}
	}
	
	if(mrm.mtr35_flag==1)
	{
		if(S35_in==0)
		{
			S35_count++;
			if(S35_count>=4)
			{
				lock35=1;
			}
		}
		else if(lock35==1)   //limit switch have decteted the 0-1
		{
			lock35=0;		
			MIout2=0;
			mrm.mtr35_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock35=0;
			S35_count=0;
		}
	}
	
	if(mrm.mtr36_flag==1)
	{
		if(S36_in==0)
		{
			S36_count++;
			if(S36_count>=4)
			{
				lock36=1;
			}
		}
		else if(lock36==1)   //limit switch have decteted the 0-1
		{
			lock36=0;		
			MIout1=0;
			mrm.mtr36_flag=0;
			motor_start_num--;
		}
		else 
		{
			lock36=0;
			S36_count=0;
		}
	}
	
	if(push_flag==1)
	{
		if(motor_start_num==0)
		{
			motor_start_num=100;
	//		motor_start_num1=0;
			push_flag=0;
			
			CRCValue=crc_calculate("Z,PUSH,OK,",10);
			CRC_4=(CRCValue>>24)&0xff;
			CRC_3=(CRCValue>>16)&0xff;
			CRC_2=(CRCValue>>8)&0xff;
			CRC_1=(CRCValue)&0xff;
			
			
			snprintf(sendbuf, 21,"Z,PUSH,OK,%x%x%x%x",CRC_4,CRC_3,CRC_2,CRC_1);
			PCout(6)=1;
			printf("%s\r\n",sendbuf);
			delay_us(150);
			PCout(6)=0;
			bufclr();
		}
	}

}


