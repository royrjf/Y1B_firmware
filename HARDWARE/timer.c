#include "timer.h"
#include "motor.h"
#include "lswitch.h"
#include "u485.h"
#include "usart.h"
u8 OTPTF_Table[36];//over time print flag table
volatile u8 Timeup_Flag;

void TIM3_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3, ENABLE); //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器

	TIM_Cmd(TIM3, ENABLE);  //使能TIMx					 
}

void TIM4_Int_Init(u16 arr,u16 psc)
{
  TIM_TimeBaseInitTypeDef  TIM_TimeBaseStructure;
	NVIC_InitTypeDef NVIC_InitStructure;

	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE); //时钟使能
	
	//定时器TIM3初始化
	TIM_TimeBaseStructure.TIM_Period = arr; //设置在下一个更新事件装入活动的自动重装载寄存器周期的值	
	TIM_TimeBaseStructure.TIM_Prescaler =psc; //设置用来作为TIMx时钟频率除数的预分频值
	TIM_TimeBaseStructure.TIM_ClockDivision = TIM_CKD_DIV1; //设置时钟分割:TDTS = Tck_tim
	TIM_TimeBaseStructure.TIM_CounterMode = TIM_CounterMode_Up;  //TIM向上计数模式
	TIM_TimeBaseInit(TIM4, &TIM_TimeBaseStructure); //根据指定的参数初始化TIMx的时间基数单位
 
	TIM_ITConfig(TIM4,TIM_IT_Update,ENABLE ); //使能指定的TIM3中断,允许更新中断

	//中断优先级NVIC设置
	NVIC_InitStructure.NVIC_IRQChannel = TIM4_IRQn;  //TIM3中断
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;  //先占优先级0级
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 4;  //从优先级3级
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE; //IRQ通道被使能
	NVIC_Init(&NVIC_InitStructure);  //初始化NVIC寄存器
		 
}
//定时器3中断服务程序
void TIM3_IRQHandler(void)   //TIM3中断
{
	static u8 j;
	static u16 i;
  static u16 count1,count2,count3,count4,count5,count6,count7,count8,count9,count10,count11,count12,count13,count14,count15,count16,count17,count18;
	static u8 count19,count20,count21,count22,count23,count24,count25,count26,count27,count28,count29,count30,count31,count32,count33,count34,count35,count36;
	
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) != RESET)  
		{
			TIM_ClearITPendingBit(TIM3, TIM_IT_Update  );
			i++;
			
			if(CHK_Motor.chkm_timer_flag==1)
			{
					j++;
					if(j==250)
					{
						CHK_Motor.chkm_timer_flag=0;
						j=0;
						motorchk[CHK_Motor.chkm_table[CHK_Motor.chkm_run_cur_num++]-1](DISABLE);  //close the running motor
						CHK_Motor.chkm_lock=1;
					}
			}
		if(i==200)
			{
				i=0;
			PAout(4)=!PAout(4);
			}
			if(mrm.mtr1_flag==1)
			{
				count1++;
				if(count1==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr1_flag=0;
					MAout4=0;
					OTPTF_Table[0]=1;
				}
			}
			else 
			{
				count1=0;
			}
			
			if(mrm.mtr2_flag==1)
			{
				count2++;
				if(count2==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr2_flag=0;
					MAout3=0;
					OTPTF_Table[1]=1;
					motor_start_num=100;
				}
			}
			else 
			{
				count2=0;
			}
			
			if(mrm.mtr3_flag==1)
			{
				count3++;
				if(count3==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr3_flag=0;
					MAout2=0;
					OTPTF_Table[2]=1;
				}
			}
			else 
			{
				count3=0;
			}
			
			if(mrm.mtr4_flag==1)
			{
				count4++;
				if(count4==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr4_flag=0;	
					MAout1=0;
					OTPTF_Table[3]=1;
				}
			}
			else 
			{
				count4=0;
			}
			
			if(mrm.mtr5_flag==1)
			{
				count5++;
				if(count5==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr5_flag=0;
					MBout4=0;
					OTPTF_Table[4]=1;
				}
			}
			else 
			{
				count5=0;
			}
			
			if(mrm.mtr6_flag==1)
			{
				count6++;
				if(count6==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr6_flag=0;		
					MBout3=0;
					OTPTF_Table[5]=1;
				}
			}
			else 
			{
				count6=0;
			}
			
			if(mrm.mtr7_flag==1)
			{
				count7++;
				if(count7==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr7_flag=0;
					MBout2=0;
					OTPTF_Table[6]=1;
				}
			}
			else 
			{
				count7=0;
			}
			
			if(mrm.mtr8_flag==1)
			{
				count8++;
				if(count8==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr8_flag=0;
					MBout1=0;
					OTPTF_Table[7]=1;
				}
			}
			else 
			{
				count8=0;
			}
			
			if(mrm.mtr9_flag==1)
			{
				count9++;
				if(count9==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr9_flag=0;
					MCout4=0;
					OTPTF_Table[8]=1;
				}
			}
			else 
			{
				count9=0;
			}
			
			if(mrm.mtr10_flag==1)
			{
				count10++;
				if(count10==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr10_flag=0;
					MCout3=0;
					OTPTF_Table[9]=1;
				}
			}
			else 
			{
				count10=0;
			}
			
			if(mrm.mtr11_flag==1)
			{
				count11++;
				if(count11==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr11_flag=0;
					MCout2=0;
					OTPTF_Table[10]=1;
				}
			}
			else 
			{
				count11=0;
			}
			
			if(mrm.mtr12_flag==1)
			{
				count12++;
				if(count12==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr12_flag=0;
					MCout1=0;
					OTPTF_Table[11]=1;
				}
			}
			else 
			{
				count12=0;
			}
			
			if(mrm.mtr13_flag==1)
			{
				count13++;
				if(count13==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr13_flag=0;
					MDout4=0;
					OTPTF_Table[12]=1;
				}
			}
			else 
			{
				count13=0;
			}
			
			if(mrm.mtr14_flag==1)
			{
				count14++;
				if(count14==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr14_flag=0;
					MDout3=0;
					OTPTF_Table[13]=1;
				}
			}
			else 
			{
				count14=0;
			}
			
			if(mrm.mtr15_flag==1)
			{
				count15++;
				if(count15==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr15_flag=0;
					MDout2=0;
					OTPTF_Table[14]=1;
				}
			}
			else 
			{
				count15=0;
			}
			
			if(mrm.mtr16_flag==1)
			{
				count16++;
				if(count16==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr16_flag=0;
					MDout1=0;
					OTPTF_Table[15]=1;
				}
			}
			else 
			{
				count16=0;
			}
			
			if(mrm.mtr17_flag==1)
			{
				count17++;
				if(count17==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr17_flag=0;
					MEout4=0;
					OTPTF_Table[16]=1;
				}
			}
			else 
			{
				count17=0;
			}
			
			if(mrm.mtr18_flag==1)
			{
				count18++;
				if(count18==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr18_flag=0;
					MEout3=0;
					OTPTF_Table[17]=1;
				}
			}
			else 
			{
				count18=0;
			}
			
			if(mrm.mtr19_flag==1)
			{
				count19++;
				if(count19==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr19_flag=0;
					MEout2=0;
					OTPTF_Table[18]=1;
				}
			}
			else 
			{
				count19=0;
			}
			
			if(mrm.mtr20_flag==1)
			{
				count20++;
				if(count20==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr20_flag=0;
					MEout1=0;
					OTPTF_Table[19]=1;
				}
			}
			else 
			{
				count20=0;
			}
			
			
			
			if(mrm.mtr21_flag==1)
			{
				count21++;
				if(count21==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr21_flag=0;
					MFout4=0;
					OTPTF_Table[20]=1;
				}
			}
			else 
			{
				count21=0;
			}
			
			if(mrm.mtr22_flag==1)
			{
				count22++;
				if(count22==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr22_flag=0;
					MFout3=0;
					OTPTF_Table[21]=1;
				}
			}
			else 
			{
				count22=0;
			}
			
				if(mrm.mtr23_flag==1)
			{
				count23++;
				if(count23==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr23_flag=0;
					MFout2=0;
					OTPTF_Table[22]=1;
				}
			}
			else 
			{
				count23=0;
			}
			
			if(mrm.mtr24_flag==1)
			{
				count24++;
				if(count24==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr24_flag=0;
					MFout1=0;
					OTPTF_Table[23]=1;
				}
			}
			else 
			{
				count24=0;
			}
			
				if(mrm.mtr25_flag==1)
			{
				count25++;
				if(count25==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr25_flag=0;
					MGout4=0;
					OTPTF_Table[24]=1;
				}
			}
			else 
			{
				count25=0;
			}
			
				if(mrm.mtr26_flag==1)
			{
				count26++;
				if(count26==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr26_flag=0;
					MGout3=0;
					OTPTF_Table[25]=1;
				}
			}
			else 
			{
				count26=0;
			}
			
			if(mrm.mtr27_flag==1)
			{
				count27++;
				if(count27==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr27_flag=0;
					MGout2=0;
					OTPTF_Table[26]=1;
				}
			}
			else 
			{
				count27=0;
			}
			
				if(mrm.mtr28_flag==1)
			{
				count28++;
				if(count28==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr28_flag=0;
					MGout1=0;
					OTPTF_Table[28]=1;
				}
			}
			else 
			{
				count28=0;
			}
			
			if(mrm.mtr29_flag==1)
			{
				count29++;
				if(count29==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr29_flag=0;
					MHout4=0;
					OTPTF_Table[28]=1;
				}
			}
			else 
			{
				count29=0;
			}
			
				if(mrm.mtr30_flag==1)
			{
				count30++;
				if(count30==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr30_flag=0;
					MHout3=0;
					OTPTF_Table[29]=1;
				}
			}
			else 
			{
				count30=0;
			}
			
				if(mrm.mtr31_flag==1)
			{
				count31++;
				if(count31==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr31_flag=0;
					MHout2=0;
					OTPTF_Table[30]=1;
				}
			}
			else 
			{
				count31=0;
			}
			
			if(mrm.mtr32_flag==1)
			{
				count32++;
				if(count32==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr32_flag=0;
					MHout1=0;
					OTPTF_Table[31]=1;
				}
			}
			else 
			{
				count32=0;
			}
			
			if(mrm.mtr33_flag==1)
			{
				count33++;
				if(count33==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr33_flag=0;
					MIout4=0;
					OTPTF_Table[32]=1;
				}
			}
			else 
			{
				count33=0;
			}
			
			if(mrm.mtr34_flag==1)
			{
				count34++;
				if(count34==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr34_flag=0;
					MIout3=0;
					OTPTF_Table[33]=1;
				}
			}
			else 
			{
				count34=0;
			}
			
			if(mrm.mtr35_flag==1)
			{
				count35++;
				if(count35==200)
				{
					Timeup_Flag=1;
					push_flag=0;
					mrm.mtr35_flag=0;
					MIout2=0;
						OTPTF_Table[34]=1;
				}
			}
			else 
			{
				count35=0;
			}
			
			if(mrm.mtr36_flag==1)
			{
				count36++;
				if(count36==200)
				{
					Timeup_Flag=1;
					mrm.mtr36_flag=0;
					MIout1=0;
					push_flag=0;
					OTPTF_Table[35]=1;
				}
			}
			else 
			{
				count36=0;
			}	
		}
}

void TIM4_IRQHandler(void)  
{
	static u8 i;
	//static u8 lock1,lock2,lock3,lock4;
	if(TIM_GetITStatus(TIM4, TIM_IT_Update) != RESET)  //检查TIM3更新中断发生与否
		{
			TIM_ClearITPendingBit(TIM4, TIM_IT_Update );  //清除TIMx更新中断标志 
			i++;
			if(i==100)
			{
	//			if(M_test.motor_num_table[0]==1)
			//		{
				//		MAout(4)=1;
			//		}
			}
		}
}











