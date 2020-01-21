#ifndef __CRC__H
#define __CRC__H

#include "sys.h" 

extern void crc_init(void);
extern u32 crc_calculate(char *p,u8 num);

#endif

