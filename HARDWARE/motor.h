#ifndef __MOTOR_H
#define __MOTOR_H	 
#include "sys.h"
#include "u485.h"
extern void motor_start_manage(motor_list p);
extern void motor_init(void);  
extern void motor_close(void);
typedef struct{
	u8 mtr1_flag;
	u8 mtr2_flag;
	u8 mtr3_flag;
	u8 mtr4_flag;
	u8 mtr5_flag;
	u8 mtr6_flag;
	u8 mtr7_flag;
	u8 mtr8_flag;
	u8 mtr9_flag;
	u8 mtr10_flag;
	u8 mtr11_flag;
	u8 mtr12_flag;
	u8 mtr13_flag;
	u8 mtr14_flag;
	u8 mtr15_flag;
	u8 mtr16_flag;
	u8 mtr17_flag;
	u8 mtr18_flag;
	u8 mtr19_flag;
	u8 mtr20_flag;
	u8 mtr21_flag;
	u8 mtr22_flag;
	u8 mtr23_flag;
	u8 mtr24_flag;
	u8 mtr25_flag;
	u8 mtr26_flag;
	u8 mtr27_flag;
	u8 mtr28_flag;
	u8 mtr29_flag;
	u8 mtr30_flag;
	u8 mtr31_flag;
	u8 mtr32_flag;
	u8 mtr33_flag;
	u8 mtr34_flag;
	u8 mtr35_flag;
	u8 mtr36_flag;			
}Motor_t;

extern Motor_t mrm; //motor run message
extern void(*motorchk[36])(FunctionalState NewState);
extern void motor_chk(void);

#define MA1 GPIO_Pin_2
#define MA2 GPIO_Pin_1
#define MA3 GPIO_Pin_0
#define MA4 GPIO_Pin_9

#define MB1 GPIO_Pin_6
#define MB2 GPIO_Pin_5
#define MB3 GPIO_Pin_4
#define MB4 GPIO_Pin_3
#define MC1 GPIO_Pin_0
#define MC2 GPIO_Pin_15
#define MC3 GPIO_Pin_14
#define MC4 GPIO_Pin_13

#define MD1 GPIO_Pin_0
#define MD2 GPIO_Pin_3
#define MD3 GPIO_Pin_2
#define MD4 GPIO_Pin_1

#define ME1 GPIO_Pin_5
#define ME2 GPIO_Pin_3
#define ME3 GPIO_Pin_2
#define ME4 GPIO_Pin_1

#define MF1 GPIO_Pin_5
#define MF2 GPIO_Pin_4
#define MF3 GPIO_Pin_7
#define MF4 GPIO_Pin_6

#define MG1 GPIO_Pin_8
#define MG2 GPIO_Pin_7
#define MG3 GPIO_Pin_2
#define MG4 GPIO_Pin_1

#define MH1 GPIO_Pin_12
#define MH2 GPIO_Pin_11
#define MH3 GPIO_Pin_10
#define MH4 GPIO_Pin_9

#define MI1 GPIO_Pin_10
#define MI2 GPIO_Pin_15
#define MI3 GPIO_Pin_14
#define MI4 GPIO_Pin_13

#define MAout1 PEout(2)
#define MAout2 PEout(1)
#define MAout3 PEout(0)
#define MAout4 PBout(9)

#define MBout1 PEout(6)
#define MBout2 PEout(5)
#define MBout3 PEout(4)
#define MBout4 PEout(3)

#define MCout1 PCout(0)
#define MCout2 PCout(15)
#define MCout3 PCout(14)
#define MCout4 PCout(13)

#define MDout1 PAout(0)
#define MDout2 PCout(3)
#define MDout3 PCout(2)
#define MDout4 PCout(1)

#define MEout1 PAout(5)
#define MEout2 PAout(3)
#define MEout3 PAout(2)
#define MEout4 PAout(1)

#define MFout1 PCout(5)
#define MFout2 PCout(4)
#define MFout3 PAout(7)
#define MFout4 PAout(6)

#define MGout1 PEout(8)
#define MGout2 PEout(7)
#define MGout3 PBout(2)
#define MGout4 PBout(1)

#define MHout1 PEout(12)
#define MHout2 PEout(11)
#define MHout3 PEout(10)
#define MHout4 PEout(9)

#define MIout1 PBout(10)
#define MIout2 PEout(15)
#define MIout3 PEout(14)
#define MIout4 PEout(13)



		 				    
#endif
