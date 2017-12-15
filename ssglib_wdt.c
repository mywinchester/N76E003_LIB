#include "ssglib_wdt.h"

void WDT_Init(WDT_Mode_TypeDef mode, WDT_PreScalar_TypeDef prescalar)
{
    SFR_TA_UNLOCK(SFR_SET_NAMED_BIT(CHPCON, CHPCON_IAPEN_MASK));

    SFR_SET_BYTE(IAPAH, (uint8_t)((uint8_t)WDT_CONFIG4_ADDR >> 8U));
    SFR_SET_BYTE(IAPAL, (uint8_t)WDT_CONFIG4_ADDR);

    SFR_SET_BYTE(IAPFD, (uint8_t)mode);

    SFR_SET_BYTE(IAPCN, (uint8_t)WDT_CONFIG4_WRITE_COMMAND);

    SFR_TA_UNLOCK(SFR_SET_NAMED_BIT(IAPUEN, IAPUEN_CFUEN_MASK));

    SFR_TA_UNLOCK(SFR_SET_NAMED_BIT(IAPTRG, IAPTRG_IAPGO_MASK));
    while (0 != (CHPCON & CHPCON_IAPFF_MASK))
        ;

    SFR_TA_UNLOCK(SFR_RESET_NAMED_BIT(IAPUEN, IAPUEN_CFUEN_MASK));
    SFR_TA_UNLOCK(SFR_RESET_NAMED_BIT(CHPCON, CHPCON_IAPEN_MASK));

    SFR_TA_UNLOCK(WDCON &= (uint8_t)(~(uint8_t)WDCON_WDPS_MASK));
    SFR_TA_UNLOCK(WDCON |= (uint8_t)prescalar);
}

void WDT_SetState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_TA_UNLOCK(SFR_RESET_NAMED_BIT(WDCON, WDCON_WDTR_MASK));
    }
    else
    {
        SFR_TA_UNLOCK(SFR_SET_NAMED_BIT(WDCON, WDCON_WDTR_MASK));
    }
}

void WDT_KickDog(void)
{
    SFR_TA_UNLOCK(SFR_SET_NAMED_BIT(WDCON, WDCON_WDCLR_MASK));
}

void WDT_SetWorkState(WDT_WorkState_TypeDef state)
{
    if (WDT_WORKSTATE_STOP == state)
    {
        SFR_TA_UNLOCK(SFR_RESET_NAMED_BIT(WDCON, WDCON_WIDPD_MASK));
    }
    else
    {
        SFR_TA_UNLOCK(SFR_SET_NAMED_BIT(WDCON, WDCON_WIDPD_MASK));
    }
}

void WDT_ClearFlag(WDT_Flag_TypeDef flag)
{
    if (WDT_FLAG_RESET == flag)
    {
        SFR_TA_UNLOCK(SFR_RESET_NAMED_BIT(WDCON, WDCON_WDTRF_MASK));
    }
    else if (WDT_FLAG_TIMEOUT == flag)
    {
        SFR_TA_UNLOCK(SFR_RESET_NAMED_BIT(WDCON, WDCON_WDTF_MASK));
    }
}

FlagStatus WDT_GetFlag(WDT_Flag_TypeDef flag)
{
    FlagStatus tempFlag = RESET;

    if (WDT_FLAG_CLEAR == flag)
    {
        tempFlag = (FlagStatus)(SFR_READ_NAMED_BIT(WDCON, WDCON_WDCLR_MASK) ? SET : RESET);
    }
    else if (WDT_FLAG_RESET == flag)
    {
        tempFlag = (FlagStatus)(SFR_READ_NAMED_BIT(WDCON, WDCON_WDTRF_MASK) ? SET : RESET);
    }
    else if (WDT_FLAG_TIMEOUT == flag)
    {
        tempFlag = (FlagStatus)(SFR_READ_NAMED_BIT(WDCON, WDCON_WDTF_MASK) ? SET : RESET);
    }

    return (FlagStatus)tempFlag;
}