#include "ssglib_timer0.h"

void TIMER0_Init(TIMER0_Mode_TypeDef mode, TIMER0_AccumulationMode_TypeDef acc,
                 TIMER0_Gate_TypeDef gate, uint16_t initVal)
{
    uint8_t tempTMOD = TMOD_RESET_VALUE;

    tempTMOD |= (uint8_t)mode;
    tempTMOD |= (uint8_t)acc;
    tempTMOD |= (uint8_t)gate;

    SFR_RESET_NAMED_BIT(TCON, TCON_TR0_MASK);
    SFR_RESET_NAMED_BIT(TCON, TCON_TF0_MASK);
    TMOD &= (uint8_t)(~(uint8_t)TIMER0_TMOD_RESET_MASK);

    TMOD |= (uint8_t)tempTMOD;

    if (NULL != initVal)
    {
        SFR_SET_BYTE(TH0, (uint8_t)(initVal >> 8U));
        SFR_SET_BYTE(TL0, (uint8_t)initVal);
    }
}

void TIMER0_SetState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(TCON, TCON_TR0_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(TCON, TCON_TR0_MASK);
    }
}

void TIMER0_SetClockSource(TIMER0_ClockMode_TypeDef src)
{
    if (TIMER0_CLOCKMODE_STANDARD == src)
    {
        SFR_RESET_NAMED_BIT(CKCON, CKCON_T0M_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(CKCON, CKCON_T0M_MASK);
    }
}

void TIMER0_SetOutputState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(P2S, P2S_T0OE_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(P2S, P2S_T0OE_MASK);
    }
}

void TIMER0_SetCounter(uint16_t val)
{
    if (NULL != val)
    {
        SFR_SET_BYTE(TH0, (uint8_t)(val >> 8U));
        SFR_SET_BYTE(TL0, (uint8_t)val);
    }
}

uint16_t TIMER0_ReadCounter(void)
{
    uint16_t tempVal = NULL;

    tempVal = (uint8_t)TH0;
    tempVal <<= 8U;
    tempVal |= (uint8_t)TL0;

    return tempVal;
}

void TIMER0_SetITState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(IE, IE_ET0_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(IE, IE_ET0_MASK);
    }
}

void TIMER0_ClearFlag(TIMER0_Flag_TypeDef flag)
{
    if (TIMER0_FLAG_OVERFLOW == flag)
    {
        SFR_RESET_NAMED_BIT(TCON, TCON_TF0_MASK);
    }
}

FlagStatus TIMER0_GetFlag(TIMER0_Flag_TypeDef flag)
{
    FlagStatus tempFlag = RESET;

    if (TIMER0_FLAG_OVERFLOW == flag)
    {
        tempFlag = (FlagStatus)(SFR_READ_NAMED_BIT(TCON, TCON_TF0_MASK) ? SET : RESET);
    }

    return (FlagStatus)tempFlag;
}