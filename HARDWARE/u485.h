#ifndef __U485_H
#define __U485_H	 
#include "sys.h"

extern void u485_tick(void);
extern void u485_test(void);
extern void u485_queue_init(void);
extern void u485_tx_on(void);
extern void u485_tx_off(void);
extern void u485_test1(void);
extern void bufclr(void);

typedef struct{
	volatile u8 motor_num_table[10];
	volatile u8 count;
}motor_list;
extern motor_list M_list;
typedef struct
{
	u8 chkm_table[36];
	volatile u8 chkm_flag;
	volatile u8 chkm_num;

	volatile u8 chkm_timer_flag;
	
	volatile u8 chkm_lock;
	volatile u8 chkm_run_cur_num;//  current
}chk_motor;

extern chk_motor CHK_Motor;

typedef struct{
	volatile u8 motor_num_table[36];
	volatile u8 count;
}motor_test;

extern motor_test M_test;

extern volatile u8 motor_start_num;
extern volatile u8 push_flag;
extern char sendbuf[50];
extern volatile u8 CRC_4;
extern volatile u8 CRC_3;
extern volatile u8 CRC_2;
extern volatile u8 CRC_1;

extern volatile u32 CRCValue;


		 				    
#endif
