#include "ssglib_uart0.h"

void UART0_Init(UART0_Mode_TypeDef mode, uint32_t baudrate,
                FunctionalState baudrateDoubleState,
                UART0_TimeBase_TypeDef timeBase, FunctionalState multiCommState)
{
    uint8_t tempSCON = SCON_RESET_VALUE;
    uint16_t tempTIMbr = 0;

    UART0_IO_INIT(UART0_RXIO_PORT, UART0_RXIO_PIN);
    UART0_IO_INIT(UART0_TXIO_PORT, UART0_TXIO_PIN);

    tempSCON |= (uint8_t)mode;
    tempSCON |= (uint8_t)multiCommState;

    SFR_RESET_NAMED_BIT(PCON, PCON_SMOD0_MASK);

    SCON = tempSCON;

    if (DISABLE == baudrateDoubleState)
    {
        SFR_RESET_NAMED_BIT(PCON, PCON_SMOD_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(PCON, PCON_SMOD_MASK);
    }

    if (UART0_TIMEBASE_TIMER1 == timeBase)
    {
        SFR_RESET_NAMED_BIT(TCON, TCON_TF1_MASK); // 关闭TIM1
        SFR_RESET_NAMED_BIT(TCON, TCON_TR1_MASK);

        SFR_RESET_NAMED_BIT(IE, IE_ET1_MASK); // 清除TIM1中断使能

        TMOD &= (uint8_t)(~(uint8_t)UART0_TIM1_TMOD_RESET_MASK); // TIM1重新设置为自动重载模式
        SFR_SET_NAMED_BIT(TMOD, TMOD_M1_T1_MASK);

        SFR_SET_NAMED_BIT(CKCON, CKCON_T1M_MASK); // TIM1设置默认时钟源Fsys，无分频

        SFR_RESET_NAMED_BIT(T3CON, T3CON_BRCK_MASK); // 指定串口波特率时钟源为TIM1

        tempTIMbr = (uint8_t)(256 - (uint16_t)(
                                        (uint32_t)((uint32_t)HIRC_VALUE / (DISABLE == baudrateDoubleState ? 32 : 16)) /
                                        (uint32_t)baudrate)); // 设置波特率

        if (0xFF < tempTIMbr)
            tempTIMbr = (uint8_t)0xFF - 1;

        TH1 = tempTIMbr;

        SFR_SET_NAMED_BIT(TCON, TCON_TR1_MASK); // 开启TIM1

        //SFR_SET_NAMED_BIT(TI); // For printf function must setting TI = 1
    }
    else
    {
        SFR_RESET_NAMED_BIT(T3CON, T3CON_TF3_MASK); // 关闭TIM3
        SFR_RESET_NAMED_BIT(T3CON, T3CON_TR3_MASK);

        SFR_RESET_NAMED_BIT(EIE1, EIE1_ET3_MASK); // 清除TIM3中断使能

        T3CON &= (uint8_t)(~((uint8_t)0x07)); // TIM3设置为1分频

        SFR_SET_NAMED_BIT(T3CON, T3CON_BRCK_MASK); // 指定串口波特率时钟源为TIM3

        tempTIMbr = (uint16_t)(65536 - (uint32_t)(
                                           (uint32_t)((uint32_t)HIRC_VALUE / (DISABLE == baudrateDoubleState ? 32 : 16)) /
                                           (uint32_t)baudrate)); // 设置波特率

        if (0xFFFF < tempTIMbr)
            tempTIMbr = (uint16_t)0xFFFF - 1;

        RH3 = (uint8_t)(tempTIMbr >> 8U); // 设置定时器重载高8位
        RL3 = (uint8_t)tempTIMbr;         // 设置定时器重载低8位

        SFR_SET_NAMED_BIT(T3CON, T3CON_TR3_MASK); // 开启TIM3
    }
}

void UART0_SetITState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(IE, IE_ES_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(IE, IE_ES_MASK);
    }
}

void UART0_SetRXState(FunctionalState state)
{
    if (DISABLE == state)
    {
        SFR_RESET_NAMED_BIT(SCON, SCON_REN_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(SCON, SCON_REN_MASK);
    }
}

void UART0_SetFEFlagAccess(FunctionalState accessState)
{
    if (DISABLE == accessState)
    {
        SFR_RESET_NAMED_BIT(PCON, PCON_SMOD0_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(PCON, PCON_SMOD0_MASK);
    }
}

void UART0_ClearFlag(UART0_Flag_TypeDef flag)
{
    if (UART0_FLAG_RXNE == flag)
    {
        SFR_RESET_NAMED_BIT(SCON, SCON_RI_MASK);
    }

    else if (UART0_FLAG_TXE == flag)
    {
        SFR_RESET_NAMED_BIT(SCON, SCON_TI_MASK);
    }

    else if (UART0_FLAG_FE == flag)
    {
        if (0 != (PCON & PCON_SMOD0_MASK))
        {
            SFR_RESET_NAMED_BIT(SCON, SCON_FE_MASK);
        }
        else
        {
            SFR_SET_NAMED_BIT(PCON, PCON_SMOD0_MASK);
            SFR_RESET_NAMED_BIT(SCON, SCON_FE_MASK);
            SFR_RESET_NAMED_BIT(PCON, PCON_SMOD0_MASK);
        }
    }
}

FlagStatus UART0_GetFlag(UART0_Flag_TypeDef flag)
{
    FlagStatus reFlag = RESET;

    if (UART0_FLAG_RXNE == flag)
    {
        reFlag = (FlagStatus)(SFR_READ_NAMED_BIT(SCON, SCON_RI_MASK) ? SET : RESET);
    }

    else if (UART0_FLAG_TXE == flag)
    {
        reFlag = (FlagStatus)(SFR_READ_NAMED_BIT(SCON, SCON_TI_MASK) ? SET : RESET);
    }

    else if (UART0_FLAG_FE == flag)
    {
        if (0 != (PCON & PCON_SMOD0_MASK))
        {
            reFlag = (FlagStatus)(SFR_READ_NAMED_BIT(SCON, SCON_FE_MASK) ? SET : RESET);
        }
    }

    return (FlagStatus)reFlag;
}

void UART0_SetDoubleBaudrate(FunctionalState baudrateDoubleState)
{
    if (DISABLE == baudrateDoubleState)
    {
        SFR_RESET_NAMED_BIT(PCON, PCON_SMOD_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(PCON, PCON_SMOD_MASK);
    }
}

void UART0_SetSyncBaudSpeed(UART0_SyncSpeed_TypeDef syncSpeed)
{
    if (UART0_SYNCSPEED_STANDARD == syncSpeed)
    {
        SFR_RESET_NAMED_BIT(SCON, SCON_SM2_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(SCON, SCON_SM2_MASK);
    }
}

void UART0_SetIOExchange(FunctionalState exchangeState)
{
    if (DISABLE == exchangeState)
    {
        SFR_RESET_NAMED_BIT(AUXR1, AUXR1_UART0PX_MASK);
    }
    else
    {
        SFR_SET_NAMED_BIT(AUXR1, AUXR1_UART0PX_MASK);
    }
}

void UART0_SendByte(const uint8_t u8Byte)
{
    SFR_RESET_NAMED_BIT(SCON, SCON_TI_MASK);
    SBUF = u8Byte;
    while (0 == SFR_READ_NAMED_BIT(SCON, SCON_TI_MASK))
        ;
}

void UART0_SendWord(const uint16_t u16Word)
{
    UART0_SendByte((uint8_t)(u16Word >> 8U));
    UART0_SendByte((uint8_t)u16Word);
}

void UART0_SendArray(uint8_t *pArray, const uint16_t u16Length)
{
    uint16_t l = 0;

    for (l = 0; l < u16Length; l++)
    {
        UART0_SendByte(pArray[l]);
    }
}

void UART0_SendString(uint8_t *pString)
{
    while (NULL != *pString)
    {
        UART0_SendByte(*pString);
        pString++;
    }
}

void UART0_EmptyBuffer(sUart0_RxBuffer *psBuffer)
{
    uint16_t l = 0;

    psBuffer->length = 0;

    for (l = 0; l < UART0_RX_BUF_SIZE; l++)
    {
        psBuffer->bData[l] = 0;
    }
}