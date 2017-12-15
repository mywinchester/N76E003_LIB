#ifndef __SSGLIB_UART0_H
#define __SSGLIB_UART0_H

#include "N76E003.h"

/************************************ UART0 ************************************/

#define UART0_RX_BUF_SIZE                       ((uint8_t)255)

#define UART0_RXIO_PORT                         P0                  /*!< RX 引脚端口号 */
#define UART0_RXIO_PIN                          7                   /*!< RX 引脚序列 */

#define UART0_TXIO_PORT                         P0                  /*!< TX 引脚端口号 */
#define UART0_TXIO_PIN                          6                   /*!< TX 引脚序列 */

#define UART0_TIM1_TMOD_RESET_MASK              ((uint8_t)0xF0)     /*!< TIM1 用作 UART0 时钟源时默认设置 */

/**
  * @reg    SCON
  * @brief  UART0 工作模式类 0~3
  */
typedef enum {
    UART0_MODE_SYNC_8FRAMEBITS_FSYSBAUDBASE     = (uint8_t)0x00,    /*!< MODE_0 */
    UART0_MODE_ASYNC_10FRAMEBITS_TIMERBAUDBASE  = (uint8_t)0x40,    /*!< MODE_1 */
    UART0_MODE_ASYNC_11FRAMEBITS_FSYSBAUDBASE   = (uint8_t)0x80,    /*!< MODE_2 */
    UART0_MODE_ASYNC_11FRAMEBITS_TIMERBAUDBASE  = (uint8_t)0xC0     /*!< MODE_3 */
} UART0_Mode_TypeDef;

/**
  * @reg    SCON
  * @brief  UART0 同步模式（模式0）速度类
  */
typedef enum {
    UART0_SYNCSPEED_STANDARD                    = (uint8_t)0x00,    /*!< 标准8051兼容速度，1/12 系统时钟 */
    UART0_SYNCSPEED_FAST                        = (uint8_t)0x20     /*!< 快速传输速度，1/2 系统时钟 */
} UART0_SyncSpeed_TypeDef;

/**
  * @reg    SCON
  * @brief  UART0 标志类
  */
typedef enum {
    UART0_FLAG_FE                               = (uint8_t)0x80,    /*!< 帧错误标志 */
    UART0_FLAG_TXE                              = (uint8_t)0x02,    /*!< 发送完成中断标志 */
    UART0_FLAG_RXNE                             = (uint8_t)0x01     /*!< 接收完成标志 */
} UART0_Flag_TypeDef;

/**
  * @reg    T3CON
  * @brief  UART0 时钟源类
  */
typedef enum {
    UART0_TIMEBASE_TIMER1                       = (uint8_t)0x00,    /*!< UART0时钟源使用TIM1 */
    UART0_TIMEBASE_TIMER3                       = (uint8_t)0x20     /*!< UART0时钟源使用TIM3 */
} UART0_TimeBase_TypeDef;

typedef struct
{
    uint16_t length;
    uint8_t bData[UART0_RX_BUF_SIZE];
} sUart0_RxBuffer;

/**
  * @ #MARCO UART0 IO FUNC
  */
#define UART0_XSTRING(X, Y) X##Y

#define UART0_IO_INIT(PORT, PIN)                                                   \
    UART0_XSTRING(PORT, M1) &= (uint8_t)(~(uint8_t)UART0_XSTRING(BIT_MASK_, PIN)); \
    UART0_XSTRING(PORT, M2) &= (uint8_t)(~(uint8_t)UART0_XSTRING(BIT_MASK_, PIN))

void UART0_Init(UART0_Mode_TypeDef mode, uint32_t baudrate,
                FunctionalState baudrateDoubleState,
                UART0_TimeBase_TypeDef timeBase, FunctionalState multiCommState);

void UART0_SetITState(FunctionalState state);

void UART0_SetRXState(FunctionalState state);

void UART0_SetFEFlagAccess(FunctionalState accessState);

void UART0_ClearFlag(UART0_Flag_TypeDef flag);

FlagStatus UART0_GetFlag(UART0_Flag_TypeDef flag);

void UART0_SetDoubleBaudrate(FunctionalState baudrateDoubleState);

void UART0_SetSyncBaudSpeed(UART0_SyncSpeed_TypeDef syncSpeed);

void UART0_SetIOExchange(FunctionalState exchangeState);

void UART0_SendByte(const uint8_t u8Byte);

void UART0_SendWord(const uint16_t u16Word);

void UART0_SendArray(uint8_t *pArray, const uint16_t u16Length);

void UART0_SendString(uint8_t *pString);

void UART0_EmptyBuffer(sUart0_RxBuffer *psBuffer);

#endif /* __SSGLIB_UART0_H */