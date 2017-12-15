#include "ssglib_timer1.h"

void TIMER1_Init(TIMER1_Mode_TypeDef mode, TIMER1_AccumulationMode_TypeDef acc,
                 TIMER1_Gate_TypeDef gate, uint16_t initVal)
{
    uint8_t tempTMOD = TMOD_RESET_VALUE;

    tempTMOD |= (uint8_t)mode;
    tempTMOD |= (uint8_t)acc;
    tempTMOD |= (uint8_t)gate;

    SFR_RESET_NAMED_BIT(TCON, TCON_TR1_MASK);
    SFR_RESET_NAMED_BIT(TCON, TCON_TF1_MASK);
    TMOD &= (uint8_t)(~(uint8_t)TIMER1_TMOD_RESET_MASK);

    TMOD |= (uint8_t)tempTMOD;

    if (NULL != initVal)
    {
        SFR_SET_BYTE(TH1, (uint8_t)(initVal >> 8U));
        SFR_SET_BYTE(TL1, (uint8_t)initVal);
    }
}

void TIMER1_SetState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(TCON, TCON_TR1_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(TCON, TCON_TR1_MASK);
    }
}

void TIMER1_SetClockSource(TIMER1_ClockMode_TypeDef src)
{
    if (TIMER1_CLOCKMODE_STANDARD == src)
    {
        SFR_RESET_NAMED_BIT(CKCON, CKCON_T1M_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(CKCON, CKCON_T1M_MASK);
    }
}

void TIMER1_SetOutputState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(P2S, P2S_T1OE_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(P2S, P2S_T1OE_MASK);
    }
}

void TIMER1_SetCounter(uint16_t val)
{
    if (NULL != val)
    {
        SFR_SET_BYTE(TH1, (uint8_t)(val >> 8U));
        SFR_SET_BYTE(TL1, (uint8_t)val);
    }
}

uint16_t TIMER1_ReadCounter(void)
{
    uint16_t tempVal = NULL;

    tempVal = (uint8_t)TH1;
    tempVal <<= 8U;
    tempVal |= (uint8_t)TL1;

    return tempVal;
}

void TIMER1_SetITState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(IE, IE_ET1_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(IE, IE_ET1_MASK);
    }
}

void TIMER1_ClearFlag(TIMER1_Flag_TypeDef flag)
{
    if (TIMER1_FLAG_OVERFLOW == flag)
    {
        SFR_RESET_NAMED_BIT(TCON, TCON_TF1_MASK);
    }
}

FlagStatus TIMER1_GetFlag(TIMER1_Flag_TypeDef flag)
{
    FlagStatus tempFlag = RESET;

    if (TIMER1_FLAG_OVERFLOW == flag)
    {
        tempFlag = (FlagStatus)(SFR_READ_NAMED_BIT(TCON, TCON_TF1_MASK) ? SET : RESET);
    }

    return (FlagStatus)tempFlag;
}