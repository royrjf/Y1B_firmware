#include "sys.h"
#include "usart.h"
#include "string.h"
#include "u485.h"

QUEUE_485_t Q_485;

#if 1
#pragma import(__use_no_semihosting)             
            
struct __FILE 
{ 
	int handle; 

}; 

FILE __stdout;       

void _sys_exit(int x) 
{ 
	x = x; 
} 

int fputc(int ch, FILE *f)
{      
	while((USART1->SR&0X40)==0);
  USART1->DR = (u8) ch;      
	return ch;
}
#endif 

 void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch)
{
      
        USART_SendData(pUSARTx,ch);
            
        while (USART_GetFlagStatus(pUSARTx, USART_FLAG_TC) == RESET);        
}

void Usart_SendString(USART_TypeDef * pUSARTx, u8* p,u8 num)
{
	u8 i;
	for(i=0;i<num;i++)
	{
		Usart_SendByte( pUSARTx, *p++);
	}
} 
  
void u485_init(u32 bound){

  GPIO_InitTypeDef GPIO_InitStructure;
	USART_InitTypeDef USART_InitStructure;
	NVIC_InitTypeDef NVIC_InitStructure;
	 
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1|RCC_APB2Periph_GPIOA|RCC_APB2Periph_GPIOC, ENABLE);	//使能USART1，GPIOA时钟
  
	//USART1_TX   GPIOA.9
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9; //PA.9
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;	
  GPIO_Init(GPIOA, &GPIO_InitStructure);
   
  //USART1_RX	  GPIOA.10初始化
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;//PA10
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(GPIOA, &GPIO_InitStructure);
	
	//485 EN 
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_6; 
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
  GPIO_Init(GPIOC, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOC,GPIO_Pin_6);	
   		

  //Usart1 NVIC 配置
  NVIC_InitStructure.NVIC_IRQChannel = USART1_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=3 ;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 3;		
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;		
	NVIC_Init(&NVIC_InitStructure);	
  
 

	USART_InitStructure.USART_BaudRate = bound;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

  USART_Init(USART1, &USART_InitStructure); 
  USART_ITConfig(USART1, USART_IT_RXNE, ENABLE);
	 USART_ITConfig(USART1, USART_IT_IDLE, ENABLE);

  USART_Cmd(USART1, ENABLE);               
}


void USART1_IRQHandler(void)             
	{
	u8 Res,clr;

	if(USART_GetITStatus(USART1, USART_IT_RXNE) != RESET)   //RX Interrupt
		{
			
			Res =USART_ReceiveData(USART1);	
		
			if(Q_485.rx_flag==1)     //first data flag
			{
				Q_485.rx_flag=0;
				Q_485.count=0;
				Q_485.frame_ready=0;
				Q_485.rx_len=0;
			}
						
			Q_485.queue[Q_485.count]=Res; 
			Q_485.count++;
			
			if(Q_485.count>= RXBUF_485_MAX)
			{
					u485_queue_init();	
			}
     } 
	else if(USART_GetITStatus(USART1, USART_IT_IDLE) != RESET)    //IDLE interrupt  
	{
		  clr=USART1->SR;
		  clr=USART1->DR;
		
			Q_485.rx_flag=1;
			Q_485.frame_ready=1;
			Q_485.rx_len=Q_485.count;
			Q_485.count=0;
		
	}
}
	



