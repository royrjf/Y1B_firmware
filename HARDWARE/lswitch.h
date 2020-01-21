#ifndef __LSWITCH_H
#define __LSWITCH_H	 
#include "sys.h"


extern void lmtswitch_dect(void);
extern u8 (*readS[36])(void);
extern void s_in(void);
#define S1_Pin    GPIO_Pin_2
#define S2_Pin    GPIO_Pin_3 
#define S3_Pin    GPIO_Pin_4 
#define S4_Pin    GPIO_Pin_5 
#define S5_Pin    GPIO_Pin_6 

#define S6_Pin    GPIO_Pin_7 
#define S7_Pin    GPIO_Pin_3
#define S8_Pin    GPIO_Pin_4 
#define S9_Pin    GPIO_Pin_5 
#define S10_Pin    GPIO_Pin_6
#define S11_Pin    GPIO_Pin_7 
#define S12_Pin    GPIO_Pin_8

#define S13_Pin    GPIO_Pin_7 
#define S14_Pin    GPIO_Pin_8 
#define S15_Pin    GPIO_Pin_9 

#define S16_Pin    GPIO_Pin_8 

#define S17_Pin    GPIO_Pin_11
#define S18_Pin    GPIO_Pin_12

#define S19_Pin   GPIO_Pin_15

#define S20_Pin    GPIO_Pin_10 
#define S21_Pin   GPIO_Pin_11 
#define S22_Pin    GPIO_Pin_12 

#define S23_Pin    GPIO_Pin_0 
#define S24_Pin    GPIO_Pin_1 

#define S25_Pin    GPIO_Pin_12 
#define S26_Pin    GPIO_Pin_13 
#define S27_Pin    GPIO_Pin_14 
#define S28_Pin    GPIO_Pin_15 

#define S29_Pin    GPIO_Pin_8 
#define S30_Pin    GPIO_Pin_9 
#define S31_Pin    GPIO_Pin_10 
#define S32_Pin    GPIO_Pin_11 
#define S33_Pin    GPIO_Pin_12 
#define S34_Pin    GPIO_Pin_13 
#define S35_Pin    GPIO_Pin_14 
#define S36_Pin    GPIO_Pin_15 


#define S1_in   PDin(2)
#define S2_in   PDin(3)
#define S3_in   PDin(4)
#define S4_in   PDin(5)
#define S5_in   PDin(6)
#define S6_in   PDin(7)

#define S7_in   PBin(3)
#define S8_in   PBin(4)
#define S9_in   PBin(5)
#define S10_in   PBin(6)
#define S11_in   PBin(7)
#define S12_in   PBin(8)

#define S13_in   PCin(7)
#define S14_in   PCin(8)
#define S15_in   PCin(9)

#define S16_in   PAin(8)

#define S17_in   PAin(11)
#define S18_in   PAin(12)

#define S19_in   PAin(15)

#define S20_in   PCin(10)
#define S21_in   PCin(11)
#define S22_in   PCin(12)

#define S23_in   PDin(0)
#define S24_in   PDin(1)

#define S25_in   PBin(12)
#define S26_in   PBin(13)
#define S27_in   PBin(14)
#define S28_in   PBin(15)

#define S29_in   PDin(8)
#define S30_in   PDin(9)
#define S31_in   PDin(10)
#define S32_in   PDin(11)
#define S33_in   PDin(12)
#define S34_in   PDin(13)
#define S35_in   PDin(14)
#define S36_in   PDin(15)

extern void lmtswitch_init(void);

		 				    
#endif
