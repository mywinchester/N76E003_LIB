#ifndef __SSGLIB_TIMER0_H
#define __SSGLIB_TIMER0_H

#include "N76E003.h"

/************************************ TIMER0 ************************************/

#define TIMER0_TMOD_RESET_MASK                  ((uint8_t)0x0F)     /*!< 定时器/计数器0 TMOD默认值 */

/**
  * @reg    TMOD
  * @brief  TIMER0 外部触发门类
  */
typedef enum {
    TIMER0_GATE_IGNORE                          = (uint8_t)0x00,    /*!< 忽略 INT1 ，当 定时器/计数器0 开启时，将进行计数 */
    TIMER0_GATE_TOGGLE                          = (uint8_t)0x08     /*!< 当 INT1 为1 且 定时器/计数器0 开启时，将进行计数 */
} TIMER0_Gate_TypeDef;

/**
  * @reg    TMOD
  * @brief  TIMER0 累加模式类
  */
typedef enum {
    TIMER0_ACCUMULATIONMODE_TIMER               = (uint8_t)0x00,    /*!< 工作在定时器模式 */
    TIMER0_ACCUMULATIONMODE_COUNTER             = (uint8_t)0x04     /*!< 工作在累加器模式 */
} TIMER0_AccumulationMode_TypeDef;

/**
  * @reg    TMOD
  * @brief  TIMER0 模式类
  */
typedef enum {
    TIMER0_MODE_13BIT_FULL                      = (uint8_t)0x00,    /*!< MODE_0 */
    TIMER0_MODE_16BIT_FULL                      = (uint8_t)0x01,    /*!< MODE_1 */
    TIMER0_MODE_8BIT_AUTORELOAD                 = (uint8_t)0x02,    /*!< MODE_2 */
    TIMER0_MODE_8BIT_COMPOSITE                  = (uint8_t)0x03     /*!< MODE_3 */
} TIMER0_Mode_TypeDef;

/**
  * @reg    TCON
  * @brief  TIMER0 标志类
  */
typedef enum {
    TIMER0_FLAG_OVERFLOW                        = (uint8_t)0x00     /*!< 定时器/累加器0 溢出标志 */
} TIMER0_Flag_TypeDef;

/**
  * @reg    CKCON
  * @brief  TIMER0 时钟源选择类
  */
typedef enum {
    TIMER0_CLOCKMODE_STANDARD                   = (uint8_t)0x00,    /*!< 定时器/累加器0 时钟源选择 [1/12系统时钟] */
    TIMER0_CLOCKMODE_FAST                       = (uint8_t)0x08     /*!< 定时器/累加器0 时钟源选择 [系统时钟] */
} TIMER0_ClockMode_TypeDef;

void TIMER0_Init(TIMER0_Mode_TypeDef mode, TIMER0_AccumulationMode_TypeDef acc,
                 TIMER0_Gate_TypeDef gate, uint16_t initVal);

void TIMER0_SetState(FunctionalState state);

void TIMER0_SetClockSource(TIMER0_ClockMode_TypeDef src);

void TIMER0_SetOutputState(FunctionalState state);

void TIMER0_SetCounter(uint16_t val);

uint16_t TIMER0_ReadCounter(void);

void TIMER0_SetITState(FunctionalState state);

void TIMER0_ClearFlag(TIMER0_Flag_TypeDef flag);

FlagStatus TIMER0_GetFlag(TIMER0_Flag_TypeDef flag);

#endif /* __SSGLIB_TIMER0_H */