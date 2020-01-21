#include "wdg.h"

void IWDG_Config(u8 prv,u16 rlv)
{
	if(RCC_GetFlagStatus(RCC_FLAG_IWDGRST)!=RESET)
	{
		RCC_ClearFlag();
	}
	IWDG_WriteAccessCmd(IWDG_WriteAccess_Enable);
	IWDG_SetPrescaler(prv);
	IWDG_SetReload(rlv);
	IWDG_ReloadCounter ();
	IWDG_Enable();
}

void IWDG_Feed(void)
{
	IWDG_ReloadCounter ();
}
