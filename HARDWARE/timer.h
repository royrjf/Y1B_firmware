#ifndef __TIMER_H
#define __TIMER_H
#include "sys.h"

extern void TIM3_Int_Init(u16 arr,u16 psc);
extern void TIM4_Int_Init(u16 arr,u16 psc);  

extern u8 OTPTF_Table[36];//over time print flag table
extern volatile u8 Timeup_Flag;
#endif
