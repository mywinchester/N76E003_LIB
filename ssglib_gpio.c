#include "ssglib_gpio.h"

void GPIO_DeInit(GPIO_Port_TypeDef port)
{
    if (GPIO_PORT_P0 == port)
    {
        SFR_RESTORE_BYTE(P0M1);
        SFR_RESTORE_BYTE(P0M2);
        SFR_PAGE_CHANGE(1);
        SFR_RESTORE_BYTE(P0S);
        SFR_RESTORE_BYTE(P0SR);
        SFR_PAGE_CHANGE(0);
    }
    else if (GPIO_PORT_P1 == port)
    {
        SFR_RESTORE_BYTE(P1M1);
        SFR_RESTORE_BYTE(P1M2);
        SFR_PAGE_CHANGE(1);
        SFR_RESTORE_BYTE(P1S);
        SFR_RESTORE_BYTE(P1SR);
        SFR_PAGE_CHANGE(0);
    }
    else if (GPIO_PORT_P2 == port)
    {
        SFR_PAGE_WRITE(1, SFR_RESTORE_BYTE(P2S));
    }
    else if (GPIO_PORT_P3 == port)
    {
        SFR_RESTORE_BYTE(P3M1);
        SFR_RESTORE_BYTE(P3M2);
        SFR_PAGE_CHANGE(1);
        SFR_RESTORE_BYTE(P3S);
        SFR_RESTORE_BYTE(P3SR);
        SFR_PAGE_CHANGE(0);
    }
}

void GPIO_Init(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin, GPIO_Mode_TypeDef mode)
{
    if (GPIO_PORT_P0 == port)
    {
        SFR_RESET_ABS_BIT(P0M1, (uint8_t)pin);
        SFR_RESET_ABS_BIT(P0M2, (uint8_t)pin);

        P0M1 |= (uint8_t)(((uint8_t)mode >> 4U) & (uint8_t)0x01) << (uint8_t)pin; // set
        P0M2 |= (uint8_t)((uint8_t)mode & (uint8_t)0x01) << (uint8_t)pin;         // set
    }
    else if (GPIO_PORT_P1 == port)
    {
        SFR_RESET_ABS_BIT(P1M1, (uint8_t)pin);
        SFR_RESET_ABS_BIT(P1M2, (uint8_t)pin);

        P1M1 |= (uint8_t)(((uint8_t)mode >> 4U) & (uint8_t)0x01) << (uint8_t)pin; // set
        P1M2 |= (uint8_t)((uint8_t)mode & (uint8_t)0x01) << (uint8_t)pin;         // set
    }
    else if (GPIO_PORT_P3 == port)
    {
        SFR_RESET_ABS_BIT(P3M1, (uint8_t)pin);
        SFR_RESET_ABS_BIT(P3M2, (uint8_t)pin);

        P3M1 |= (uint8_t)(((uint8_t)mode >> 4U) & (uint8_t)0x01) << (uint8_t)pin; // set
        P3M2 |= (uint8_t)((uint8_t)mode & (uint8_t)0x01) << (uint8_t)pin;         // set
    }
}

void GPIO_SetByte(GPIO_Port_TypeDef port, uint8_t portVal)
{
    if (GPIO_PORT_P0 == port)
    {
        SFR_SET_BYTE(P0, portVal);
    }
    else if (GPIO_PORT_P1 == port)
    {
        SFR_SET_BYTE(P1, portVal);
    }
    else if (GPIO_PORT_P2 == port)
    {
        SFR_SET_BYTE(P2, portVal);
    }
    else if (GPIO_PORT_P3 == port)
    {
        SFR_SET_BYTE(P3, portVal);
    }
}

void GPIO_SetHigh(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin)
{
    if (GPIO_PORT_P0 == port)
    {
        SFR_SET_ABS_BIT(P0, (uint8_t)pin);
    }
    else if (GPIO_PORT_P1 == port)
    {
        SFR_SET_ABS_BIT(P1, (uint8_t)pin);
    }
    else if (GPIO_PORT_P2 == port)
    {
        SFR_SET_ABS_BIT(P2, (uint8_t)pin);
    }
    else if (GPIO_PORT_P3 == port)
    {
        SFR_SET_ABS_BIT(P3, (uint8_t)pin);
    }
}

void GPIO_SetLow(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin)
{
    if (GPIO_PORT_P0 == port)
    {
        SFR_RESET_ABS_BIT(P0, (uint8_t)pin);
    }
    else if (GPIO_PORT_P1 == port)
    {
        SFR_RESET_ABS_BIT(P1, (uint8_t)pin);
    }
    else if (GPIO_PORT_P2 == port)
    {
        SFR_RESET_ABS_BIT(P2, (uint8_t)pin);
    }
    else if (GPIO_PORT_P3 == port)
    {
        SFR_RESET_ABS_BIT(P3, (uint8_t)pin);
    }
}

void GPIO_SetReverse(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin)
{
    if (GPIO_PORT_P0 == port)
    {
        SFR_REVERSE_ABS_BIT(P0, (uint8_t)pin);
    }
    else if (GPIO_PORT_P1 == port)
    {
        SFR_REVERSE_ABS_BIT(P1, (uint8_t)pin);
    }
    else if (GPIO_PORT_P2 == port)
    {
        SFR_REVERSE_ABS_BIT(P2, (uint8_t)pin);
    }
    else if (GPIO_PORT_P3 == port)
    {
        SFR_REVERSE_ABS_BIT(P3, (uint8_t)pin);
    }
}

uint8_t GPIO_ReadPin(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin)
{
    if (GPIO_PORT_P0 == port)
    {
        return SFR_READ_ABS_BIT(P0, (uint8_t)pin);
    }
    else if (GPIO_PORT_P1 == port)
    {
        return SFR_READ_ABS_BIT(P1, (uint8_t)pin);
    }
    else if (GPIO_PORT_P2 == port)
    {
        return SFR_READ_ABS_BIT(P2, (uint8_t)pin);
    }
    else if (GPIO_PORT_P3 == port)
    {
        return SFR_READ_ABS_BIT(P3, (uint8_t)pin);
    }
    else
    {
        return (uint8_t)0;
    }
}

void GPIO_SetInputTriggered(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin, GPIO_InputTriggered_TypeDef type)
{
    if (GPIO_INPUTTRIGGERED_TTL == type)
    {
        if (GPIO_PORT_P0 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P0S, (uint8_t)pin));
        }
        else if (GPIO_PORT_P1 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P1S, (uint8_t)pin));
        }
        else if (GPIO_PORT_P2 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P2S, (uint8_t)pin));
        }
        else if (GPIO_PORT_P3 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P3S, (uint8_t)pin));
        }
    }
    else
    {
        if (GPIO_PORT_P0 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P0S, (uint8_t)pin));
        }
        else if (GPIO_PORT_P1 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P1S, (uint8_t)pin));
        }
        else if (GPIO_PORT_P2 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P2S, (uint8_t)pin));
        }
        else if (GPIO_PORT_P3 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P3S, (uint8_t)pin));
        }
    }
}

void GPIO_SetSlewRate(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin, GPIO_SlewRate_TypeDef speed)
{
    if (GPIO_SLEWRATE_NORMAL == speed)
    {
        if (GPIO_PORT_P0 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P0SR, (uint8_t)pin));
        }
        else if (GPIO_PORT_P1 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P1SR, (uint8_t)pin));
        }
        else if (GPIO_PORT_P3 == port)
        {
            SFR_PAGE_WRITE(1, SFR_RESET_ABS_BIT(P3SR, (uint8_t)pin));
        }
    }
    else
    {
        if (GPIO_PORT_P0 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P0SR, (uint8_t)pin));
        }
        else if (GPIO_PORT_P1 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P1SR, (uint8_t)pin));
        }
        else if (GPIO_PORT_P3 == port)
        {
            SFR_PAGE_WRITE(1, SFR_SET_ABS_BIT(P3SR, (uint8_t)pin));
        }
    }
}