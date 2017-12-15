#ifndef __SSGLIB_WDT_H
#define __SSGLIB_WDT_H

#include "N76E003.h"

/************************************ WDT ************************************/

#define WDT_CONFIG4_ADDR                        (uint16_t)0x0004    /*!< 配置字4地址 */
#define WDT_CONFIG4_WRITE_COMMAND               (uint8_t)0xE1       /*!< CONFIG 字节编程指令 */

/**
  * @reg    CONFIG4
  * @brief  WDT 运行模式类
  */
typedef enum {
    WDT_MODE_NORMAL                             = (uint8_t)0xFF,    /*!< 通用软件定时器 */
    WDT_MODE_RESET                              = (uint8_t)0x5F,    /*!< 超时复位定时器，空闲/掉电时停止运行 */
    WDT_MODE_RESET_KEEPRUNNING                  = (uint8_t)0x0F     /*!< 超时复位定时器，空闲/掉电时保持运行 */
} WDT_Mode_TypeDef;

/**
  * @reg    WDCON
  * @brief  WDT 空闲掉电运行类
  */
typedef enum {
    WDT_WORKSTATE_STOP                          = (uint8_t)0x00,    /*!< 通用定时器模式下，空闲/掉电时停止运行 */
    WDT_WORKSTATE_KEEPRUN                       = (uint8_t)0x10     /*!< 通用定时器模式下，空闲/掉电时保持运行 */
} WDT_WorkState_TypeDef;

/**
  * @reg    WDCON
  * @brief  WDT 预分频类
  */
typedef enum {
    WDT_PRESCALAR_1                             = (uint8_t)0x00,    /*!< 预分频为 1/1 F(LIRC)，溢出时间约为 6.40 ms */
    WDT_PRESCALAR_4                             = (uint8_t)0x01,    /*!< 预分频为 1/4 F(LIRC)，溢出时间约为 25.60 ms */
    WDT_PRESCALAR_8                             = (uint8_t)0x02,    /*!< 预分频为 1/8 F(LIRC)，溢出时间约为 51.20 ms */
    WDT_PRESCALAR_16                            = (uint8_t)0x03,    /*!< 预分频为 1/16 F(LIRC)，溢出时间约为 102.40 ms */
    WDT_PRESCALAR_32                            = (uint8_t)0x04,    /*!< 预分频为 1/32 F(LIRC)，溢出时间约为 204.80 ms */
    WDT_PRESCALAR_64                            = (uint8_t)0x05,    /*!< 预分频为 1/64 F(LIRC)，溢出时间约为 409.60 ms */
    WDT_PRESCALAR_128                           = (uint8_t)0x06,    /*!< 预分频为 1/128 F(LIRC)，溢出时间约为 819.20 ms */
    WDT_PRESCALAR_256                           = (uint8_t)0x07     /*!< 预分频为 1/256 F(LIRC)，溢出时间约为 1.638 s */
} WDT_PreScalar_TypeDef;

/**
  * @reg    WDCON
  * @brief  WDT 标志类
  */
typedef enum {
    WDT_FLAG_CLEAR                              = (uint8_t)0x40,    /*!< WDT计数器清零标志 */
    WDT_FLAG_TIMEOUT                            = (uint8_t)0x20,    /*!< WDT计数器溢出标志 */
    WDT_FLAG_RESET                              = (uint8_t)0x08     /*!< WDT复位标志 */
} WDT_Flag_TypeDef;

void WDT_Init(WDT_Mode_TypeDef mode, WDT_PreScalar_TypeDef prescalar);

void WDT_SetState(FunctionalState state);

void WDT_KickDog(void);

void WDT_SetWorkState(WDT_WorkState_TypeDef state);

void WDT_ClearFlag(WDT_Flag_TypeDef flag);

FlagStatus WDT_GetFlag(WDT_Flag_TypeDef flag);

#endif /* __SSGLIB_WDT_H */