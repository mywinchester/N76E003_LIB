#ifndef __SSGLIB_TIMER1_H
#define __SSGLIB_TIMER1_H

#include "N76E003.h"

/************************************ TIMER1 ************************************/

#define TIMER1_TMOD_RESET_MASK                  ((uint8_t)0xF0)     /*!< 定时器/计数器1 TMOD默认值 */

/**
  * @reg    TMOD
  * @brief  TIMER1 外部触发门类
  */
typedef enum {
    TIMER1_GATE_IGNORE                          = (uint8_t)0x00,    /*!< 忽略 INT1 ，当 定时器/计数器1 开启时，将进行计数 */
    TIMER1_GATE_TOGGLE                          = (uint8_t)0x80     /*!< 当 INT1 为1 且 定时器/计数器1 开启时，将进行计数 */
} TIMER1_Gate_TypeDef;

/**
  * @reg    TMOD
  * @brief  TIMER1 累加模式类
  */
typedef enum {
    TIMER1_ACCUMULATIONMODE_TIMER               = (uint8_t)0x00,    /*!< 工作在定时器模式 */
    TIMER1_ACCUMULATIONMODE_COUNTER             = (uint8_t)0x40     /*!< 工作在累加器模式 */
} TIMER1_AccumulationMode_TypeDef;

/**
  * @reg    TMOD
  * @brief  TIMER1 模式类
  */
typedef enum {
    TIMER1_MODE_13BIT_FULL                      = (uint8_t)0x00,    /*!< MODE_0 */
    TIMER1_MODE_16BIT_FULL                      = (uint8_t)0x10,    /*!< MODE_1 */
    TIMER1_MODE_8BIT_AUTORELOAD                 = (uint8_t)0x20,    /*!< MODE_2 */
    TIMER1_MODE_8BIT_COMPOSITE                  = (uint8_t)0x30     /*!< MODE_3 */
} TIMER1_Mode_TypeDef;

/**
  * @reg    TCON
  * @brief  TIMER1 标志类
  */
typedef enum {
    TIMER1_FLAG_OVERFLOW                        = (uint8_t)0x00     /*!< 定时器/累加器1 溢出标志 */
} TIMER1_Flag_TypeDef;

/**
  * @reg    CKCON
  * @brief  TIMER1 时钟源选择类
  */
typedef enum {
    TIMER1_CLOCKMODE_STANDARD                   = (uint8_t)0x00,    /*!< 定时器/累加器1 时钟源选择 [1/12系统时钟] */
    TIMER1_CLOCKMODE_FAST                       = (uint8_t)0x10     /*!< 定时器/累加器1 时钟源选择 [系统时钟] */
} TIMER1_ClockMode_TypeDef;

void TIMER1_Init(TIMER1_Mode_TypeDef mode, TIMER1_AccumulationMode_TypeDef acc,
                 TIMER1_Gate_TypeDef gate, uint16_t initVal);

void TIMER1_SetState(FunctionalState state);

void TIMER1_SetClockSource(TIMER1_ClockMode_TypeDef src);

void TIMER1_SetOutputState(FunctionalState state);

void TIMER1_SetCounter(uint16_t val);

uint16_t TIMER1_ReadCounter(void);

void TIMER1_SetITState(FunctionalState state);

void TIMER1_ClearFlag(TIMER1_Flag_TypeDef flag);

FlagStatus TIMER1_GetFlag(TIMER1_Flag_TypeDef flag);

#endif /* __SSGLIB_TIMER1_H */