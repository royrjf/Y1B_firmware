#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART_REC_LEN  			200  	//定义最大接收字节数 200
extern  void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
extern void Usart_SendString(USART_TypeDef * pUSARTx, u8* p,u8 num);
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //接收缓冲,最大USART_REC_LEN个字节.末字节为换行符 
extern u16 USART_RX_STA;         		//接收状态标记	
//如果想串口中断接收，请不要注释以下宏定义
void u485_init(u32 bound);


#define RXBUF_485_MAX 100
typedef struct 
{
    u8 queue[RXBUF_485_MAX];
    volatile u8 count;    
		volatile u8 rx_flag;
		volatile u8 rx_len;
  
    volatile u8 frame_ready; // frame ready flag 

} QUEUE_485_t;

extern QUEUE_485_t Q_485;


#endif


