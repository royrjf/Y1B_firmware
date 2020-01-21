#include "u485.h"
#include "usart.h"
#include "string.h"
#include "stdlib.h"
#include "motor.h"
#include <alloca.h> // alloca in MDK
#include "current.h"
#include "config.h"
#include "lswitch.h"
#include "stdio.h"
#include "timer.h"
#include "crc.h"
#include "delay.h"
char sendbuf[50];
motor_list M_list;
motor_test M_test;
chk_motor CHK_Motor;
volatile u32 CRCValue;
u32 buffer_table[50];

volatile u8 CRC_4;
volatile u8 CRC_3;
volatile u8 CRC_2;
volatile u8 CRC_1;

volatile u8 motor_start_num;
volatile u8 push_flag;     //judge whether all limite switch worked,set when motor start,set 0 in timer or limite switch worked ok

typedef  void (*pFunction)(void);
typedef struct _p_list
{
    char *para;
    struct _p_list *next;
} P_LIST_t;

void u485_queue_init(void)
{
	u8 i;
	for(i=0;i<Q_485.rx_len;i++)
	{
		Q_485.queue[i]=0;
	}
  Q_485.queue[0] = 0x00;
  Q_485.count = 0;
	Q_485.frame_ready=0;
	Q_485.rx_flag=1;
	Q_485.rx_len=0;
}
void bufclr()
{
		u8 i;
	for(i=0;i<36;i++)
	{
		sendbuf[i]=0;
	}
}
void u485_tx_on()
{
		PCout(6)=1;
}
void u485_tx_off()
{
		PCout(6)=0;
}

void u485_process_in()
{
	u8 i,j,temp,temp1;
	u8 table[5];
	i=0;j=0;
	s_in();
	for(i=0;i<36;i++)
	{
		temp1=readS[i]();
		if(temp1==0)
		{
			temp=temp&0x7f;
		}
		else
		{
			temp=temp|0x80;
		}
		
		if(((i+1)%8==0)||(i==35))
		{
			if(i==35)
			{
				temp>>=4;
			}
			table[j]=temp;
			j++;
			temp=0;
		}
		else
		{				
				temp=temp>>1;		
		}				
	}	
	
	snprintf(sendbuf,20,"B,IN,%x%s%x%s%x%s%x%s%x%s",
                     table[4],"_",table[3],"_",table[2],"_",table[1],"_",table[0],"_");
	
	CRCValue=crc_calculate(sendbuf,15);
	CRC_4=(CRCValue>>24)&0xff;
	CRC_3=(CRCValue>>16)&0xff;
	CRC_2=(CRCValue>>8)&0xff;
	CRC_1=(CRCValue)&0xff;
	
	snprintf(sendbuf,29,"%s,%x%x%x%x",sendbuf,CRC_4,CRC_3,CRC_2,CRC_1);
	
	
	
	PCout(6)=1;
	printf("%s\r\n",sendbuf);  
	delay_us(150);
	PCout(6)=0;
	bufclr();
}

void response(char *p,u8 num,u32 crc)    //string+hex
{
	u485_tx_on();
	Usart_SendString(USART1,(u8*)p,num);
	Usart_SendByte( USART1,((crc>>24)&0xff));
	Usart_SendByte( USART1,((crc>>16)&0xff));
	Usart_SendByte( USART1,((crc>>8)&0xff));
	Usart_SendByte( USART1,(crc&0xff));
	u485_tx_off();	
}

void chkm_timer_on()
{
	TIM_Cmd(TIM4, ENABLE);  
}


void chkm_timer_off()
{
	TIM_Cmd(TIM4, DISABLE);  
}
u8 decode_hexword(u8* buf)
{
		u8 i;
    u8 n;
		
    u8 digit[] = { 0, 0 };

    for (i = 0; i < 2; i++)
    {
        if (buf[i] > 0x29 && buf[i] < 0x40 )  // 0-9
        {
            digit[i] = buf[i] & 0x0f;
        }
        else if (buf[i] >='a' && buf[i] <= 'f') //if a to f
        {
            digit[i] = (buf[i] & 0x0f) + 9;
        }
        else if (buf[i] >='A' && buf[i] <= 'F') //if A to F
        {
            digit[i] = (buf[i] & 0x0f) + 9;
        }
				else if(i==1)
				{
					if(buf[i]==0)
					{
						digit[1]=digit[0];
						digit[0]=0;
					}
				}
    }
		
	
	 	 
		 n = digit[0] << 4 | digit[1]  ;
	 
    return n;
}
void u485_process()   
{
	u8 i,j;
	u8 motor_num;
	u16 value;

	P_LIST_t* curr, *para_head;
	char* p;
	char str[15];
	i=0;
	para_head=(P_LIST_t *)alloca(sizeof(P_LIST_t));	
	p = strtok((char*)(Q_485.queue), ",");	
	curr=para_head;
	while (p)
  {
    // p_count++;

     curr->para = p;
   // curr->next = (P_LIST_t *)alloca(sizeof(P_LIST_t));   //申请内存，离开作用域立即释放内存
		curr->next=(P_LIST_t *)alloca(sizeof(P_LIST_t));	
     curr = curr->next;
     p = strtok(NULL, ",");			 
  }
		curr->next = NULL;
	 
	/* if (!strcmp(para_head->para,"hello"))
	 {
			CRCValue=crc_calculate("hello,",5);
			CRC_4=(CRCValue>>24)&0xff;
			CRC_3=(CRCValue>>16)&0xff;
			CRC_2=(CRCValue>>8)&0xff;
			CRC_1=(CRCValue)&0xff;
		 
			snprintf(sendbuf,16,"hello,%x%x%x%x",CRC_4,CRC_3,CRC_2,CRC_1);
		 
		 	PCout(6)=1;
			printf("%s\r\n",sendbuf);
		  delay_us(150);
			PCout(6)=0;
		  bufclr();
	 }*/
	 
	 
	 if (!strcmp(para_head->para,"Z"))
	 {
		
		if (!strcmp(para_head->next->para,"OUTON"))
		{
			CHK_Motor.chkm_flag=0;
			PBout(11)=1;					
		 	CRCValue=crc_calculate("B,OUTON,",8);
			CRC_4=(CRCValue>>24)&0xff;
			CRC_3=(CRCValue>>16)&0xff;
			CRC_2=(CRCValue>>8)&0xff;
			CRC_1=(CRCValue)&0xff;
		 
			snprintf(sendbuf,16,"B,OUTON,%x%x%x%x",CRC_4,CRC_3,CRC_2,CRC_1);
			
		 	PCout(6)=1;
			printf("%s\r\n",sendbuf);
			delay_us(150);
			PCout(6)=0;
		  bufclr();
 	 }
		else if (!strcmp(para_head->next->para,"OUTOFF"))
		{
			PBout(11)=0;
			CHK_Motor.chkm_flag=0;
			CRCValue=crc_calculate("B,OUTOFF,",9);
			CRC_4=(CRCValue>>24)&0xff;
			CRC_3=(CRCValue>>16)&0xff;
			CRC_2=(CRCValue>>8)&0xff;
			CRC_1=(CRCValue)&0xff;
		 
			snprintf(sendbuf, 17,"B,OUTOFF,%x%x%x%x",CRC_4,CRC_3,CRC_2,CRC_1);

		  PCout(6)=1;
			printf("%s\r\n",sendbuf);
			delay_us(150);
		  PCout(6)=0;
		 
		  bufclr();
 	 }
		else if (!strcmp(para_head->next->para,"ADC"))
		{	
			CHK_Motor.chkm_flag=0;
			value=Get_ADC_Value(ADC_Channel_8,10);
			if(value>=ST_CURRENT)
			{
				value=value-ST_CURRENT;
				
				CRCValue=crc_calculate("B,ADC,",6);
		  	CRC_4=(CRCValue>>24)&0xff;
		  	CRC_3=(CRCValue>>16)&0xff;
		   	CRC_2=(CRCValue>>8)&0xff;
		  	CRC_1=(CRCValue)&0xff;
				
			  snprintf(sendbuf, 17,"B,ADC,%x,%x%x%x%x",50+9*value,CRC_4,CRC_3,CRC_2,CRC_1);
			
				PCout(6)=1;
				printf("%s\r\n",sendbuf);  
				delay_us(150);
				PCout(6)=0;
				bufclr();
			}
			else
			{
				CRCValue=crc_calculate("B,ADC,",6);
		  	CRC_4=(CRCValue>>24)&0xff;
		  	CRC_3=(CRCValue>>16)&0xff;
		   	CRC_2=(CRCValue>>8)&0xff;
		  	CRC_1=(CRCValue)&0xff;
				
				snprintf(sendbuf, 17,"B,ADC,%x,%x%x%x%x",50,CRC_4,CRC_3,CRC_2,CRC_1);
			
				PCout(6)=1;
				printf("%s\r\n",sendbuf); 
				delay_us(150);				
				PCout(6)=0;
				bufclr();	
			}
 	 }
		else if (!strcmp(para_head->next->para,"PUSH"))
		{
		  CHK_Motor.chkm_flag=0;
		  snprintf(str, 15,"%s",para_head->next->next->para);
			p=strtok(para_head->next->next->para,"_");
	
		 while(p)
		 {
			 motor_num=decode_hexword((u8*)p);		 
			 if(motor_num!=0)
			 {
					for(j=0;j<8;j++)
					{
						if((motor_num&0x01)==1)
						{
							if(M_list.count>=10)
							{
									M_list.count=0;
									snprintf(sendbuf, 33,"B,PUSH,EXCEED,%s,",str);								
									CRCValue=crc_calculate(sendbuf,(sizeof(str)-1));
									CRC_4=(CRCValue>>24)&0xff;
									CRC_3=(CRCValue>>16)&0xff;
									CRC_2=(CRCValue>>8)&0xff;
									CRC_1=(CRCValue)&0xff;
				
									snprintf(sendbuf, 43,"%s%x%x%x%x",sendbuf,CRC_4,CRC_3,CRC_2,CRC_1);
									PCout(6)=1;
									printf("%s\r\n",sendbuf);  
	
								  delay_us(150);
									for(i=0;i<15;i++)
									{
										str[i]=0;
									}
									PCout(6)=0;
									for(i=0;i<10;i++)
									{
										M_list.motor_num_table[i]=0;		
									}
								M_list.count=0;
								break;
							}							
							M_list.motor_num_table[M_list.count]=(4-i)*8+j+1;	
							M_list.count++;							
						}
						motor_num>>=1;
					}	
			}
			 p=strtok(NULL,"_");	
			 i++;					
 	 }
		 motor_start_num=M_list.count;	
	
		 motor_start_manage(M_list);
	 for(i=0;i<10;i++)
	 {
			M_list.motor_num_table[i]=0;
	 }
	 M_list.count=0;
	 
//		motor_start(motor_list* p)
	}
	 
		else if (!strcmp(para_head->next->para,"IN"))
		{
			CHK_Motor.chkm_flag=0;
			u485_process_in();
		}
		else if (!strcmp(para_head->next->para,"CHKM"))     //check motor
		{

		for(i=0;i<36;i++)
		{
			CHK_Motor.chkm_table[i]=0;
		}
		CHK_Motor.chkm_num=0;
		CHK_Motor.chkm_run_cur_num=0;   //init
		i=0;
		 p=strtok(para_head->next->next->para,"_");
		 while(p)
		 {
			 motor_num=decode_hexword((u8*)p);					 
			 if(i==0)
			 {
				motor_num=motor_num&0xf;
			 }
			 if(motor_num!=0)
			 {
					for(j=0;j<8;j++)
					{
						if((motor_num&0x80)!=0)
						{					
							CHK_Motor.chkm_table[CHK_Motor.chkm_num]=(4-i)*8+8-j;	
							CHK_Motor.chkm_num++;							
						}
						motor_num<<=1;
					}	
			}
			 p=strtok(NULL,"_");	
			 i++;			 		 		
 	 }		
		CHK_Motor.chkm_flag=1;
		CHK_Motor.chkm_lock=1;
	 
	 
 	 }
		else if (!strcmp(para_head->next->para,"CLOSE"))
		{
				CHK_Motor.chkm_flag=0;
	    	motor_close();
			  CRCValue=crc_calculate("B,CLOSE,",7);
			  CRC_4=(CRCValue>>24)&0xff;
			  CRC_3=(CRCValue>>16)&0xff;
		  	CRC_2=(CRCValue>>8)&0xff;
		   	CRC_1=(CRCValue)&0xff;
		 
				snprintf(sendbuf,16,"B,CLOSE,%x%x%x%x",CRC_4,CRC_3,CRC_2,CRC_1);
				u485_tx_on();
				printf("%s\r\n",sendbuf);
				delay_us(150);
			  u485_tx_off();
				bufclr();
			  
 	  }
		else
		{
				CRCValue=crc_calculate("B,CMDWRG,",9);
			  CRC_4=(CRCValue>>24)&0xff;
			  CRC_3=(CRCValue>>16)&0xff;
		  	CRC_2=(CRCValue>>8)&0xff;
		   	CRC_1=(CRCValue)&0xff;
		 
				snprintf(sendbuf,17,"B,CMDWRG,%x%x%x%x",CRC_4,CRC_3,CRC_2,CRC_1);
				u485_tx_on();
				printf("%s\r\n",sendbuf);
				delay_us(150);
				u485_tx_off();
				bufclr();
		}	
	}
	 
}

void motor_overtime_print()   //timeup print
{
	u8 table2[5];
	u8 i,j;
	u8 temp,temp1;
	i=0;j=0;
	for(i=0;i<36;i++)
	{
		temp1=OTPTF_Table[i];
		OTPTF_Table[i]=0;
		if(temp1==0)
		{
			temp=temp&0x7f;
		}
		else
		{
			temp=temp|0x80;
		}
		
		if(((i+1)%8==0)||(i==35))
		{
			if(i==35)
			{
				temp>>=4;
			}
			table2[j]=temp;
			j++;
			temp=0;
		}
		else
		{				
				temp=temp>>1;		
		}	
	}
	
	
	snprintf(sendbuf, 27, "B,PUSH,TOUT,%x_%x_%x_%x_%x_,", 
                     table2[4],table2[3],table2[2],table2[1],table2[0]);	
		
		CRC_ResetDR ();
		for(i=0;i<(sizeof(sendbuf)-1);i++)
		{
				CRC->DR =sendbuf[i];
		}
		
		CRCValue=CRC->DR;
			
		CRC_4=(CRCValue>>24)&0XFF;
		CRC_3=(CRCValue>>16)&0XFF;
		CRC_2=(CRCValue>>8)&0XFF;
		CRC_1=(CRCValue)&0XFF;
		
		snprintf(sendbuf, 37, "%s%x%x%x%x",sendbuf, CRC_4,CRC_3,CRC_2,CRC_1);
				
	PCout(6)=1;
	printf("%s\r\n",sendbuf);
	delay_us(150);		
	PCout(6)=0;
	bufclr();
}


void u485_tick()
{  
	if(Timeup_Flag==1)
	{
		Timeup_Flag=0;
		motor_overtime_print();
	}
	if(Q_485.frame_ready==1)
	{		
		Q_485.frame_ready=0;
		
		CRCValue=crc_calculate((char*)Q_485.queue,(Q_485.rx_len-4));
		CRC_4=(CRCValue>>24)&0xff;
		CRC_3=(CRCValue>>16)&0xff;
		CRC_2=(CRCValue>>8)&0xff;
		CRC_1=(CRCValue)&0xff;
		
		if(((CRC_1)==(Q_485.queue[Q_485.rx_len-1]))&&((CRC_2)==(Q_485.queue[Q_485.rx_len-2]))&&((CRC_3)==(Q_485.queue[Q_485.rx_len-3]))&&((CRC_4)==(Q_485.queue[Q_485.rx_len-4])))  //compare crc
		{
		
			u485_process();
			u485_queue_init();			
		}
		else if(Q_485.queue[0]=='B')
		{		
		//	u485_process();
		//	u485_queue_init();	
		/*	u485_tx_on();
			printf("%s\r\n","error1");  
			delay_us(120);
			u485_tx_off();*/
			if((Q_485.queue[2]=='M')&&(Q_485.queue[3]=='C')&&(Q_485.queue[4]=='U')&&(Q_485.queue[5]=='R')&&(Q_485.queue[6]=='E')&&(Q_485.queue[7]=='S')&&(Q_485.queue[8]=='E')&&(Q_485.queue[9]=='T'))
			{
				NVIC_SystemReset();
				u485_queue_init();		
			}			
		}
	//	else
	//	{
			//u485_process();
		/*	u485_tx_on();
			printf("%s\r\n","error2");  
			delay_us(120);
			u485_tx_off();*/
	//		u485_queue_init();		
		//}
	}
}


