#include "crc.h"

void crc_init()
{
	RCC_AHBPeriphClockCmd(RCC_AHBPeriph_CRC, ENABLE);
}

u32 crc_calculate(char *p,u8 num)
{
	u8 i;
	u32 data;
	CRC_ResetDR ();
		for(i=0;i<num;i++)
		{
				CRC->DR =*p++;
		}
		
		data=CRC->DR;
		return data; 		
}


