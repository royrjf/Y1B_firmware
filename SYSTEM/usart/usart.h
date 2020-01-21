#ifndef __USART_H
#define __USART_H
#include "stdio.h"	
#include "sys.h" 

#define USART_REC_LEN  			200  	//�����������ֽ��� 200
extern  void Usart_SendByte( USART_TypeDef * pUSARTx, uint8_t ch);
extern void Usart_SendString(USART_TypeDef * pUSARTx, u8* p,u8 num);
	  	
extern u8  USART_RX_BUF[USART_REC_LEN]; //���ջ���,���USART_REC_LEN���ֽ�.ĩ�ֽ�Ϊ���з� 
extern u16 USART_RX_STA;         		//����״̬���	
//����봮���жϽ��գ��벻Ҫע�����º궨��
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


