#ifndef __SSGLIB_GPIO_H
#define __SSGLIB_GPIO_H

#include "N76E003.h"

/************************************ GPIO ************************************/

/**
  * @reg    NONE
  * @brief  I/O 引脚组类
  */
typedef enum {
    GPIO_PORT_P0                                = (uint8_t)0x00,    /*!< GPIO 端口组 0 */
    GPIO_PORT_P1                                = (uint8_t)0x01,    /*!< GPIO 端口组 1 */
    GPIO_PORT_P2                                = (uint8_t)0x02,    /*!< GPIO 端口组 2 */
    GPIO_PORT_P3                                = (uint8_t)0x03     /*!< GPIO 端口组 3 */
} GPIO_Port_TypeDef;

/**
  * @reg    NONE
  * @brief  I/O 端口类
  */
typedef enum {
    GPIO_PIN_0                                  = (uint8_t)0x00,    /*!< GPIO 端口0 */
    GPIO_PIN_1                                  = (uint8_t)0x01,    /*!< GPIO 端口1 */
    GPIO_PIN_2                                  = (uint8_t)0x02,    /*!< GPIO 端口2 */
    GPIO_PIN_3                                  = (uint8_t)0x03,    /*!< GPIO 端口3 */
    GPIO_PIN_4                                  = (uint8_t)0x04,    /*!< GPIO 端口4 */
    GPIO_PIN_5                                  = (uint8_t)0x05,    /*!< GPIO 端口5 */
    GPIO_PIN_6                                  = (uint8_t)0x06,    /*!< GPIO 端口6 */
    GPIO_PIN_7                                  = (uint8_t)0x07     /*!< GPIO 端口7 */
} GPIO_Pin_TypeDef;

/**
  * @reg    PxM1 | PxM2
  * @brief  I/O 工作模式类
  */
typedef enum {
    GPIO_MODE_IO_QUASI                          = (uint8_t)0x00,    /*!< 准双向 */
    GPIO_MODE_OUTPUT_PUSHPULL                   = (uint8_t)0x01,    /*!< 输出-推挽 */
    GPIO_MODE_INPUT                             = (uint8_t)0x10,    /*!< 输入(高阻) */
    GPIO_MODE_IO_OPENDRAIN                      = (uint8_t)0x11     /*!< 开漏 */
} GPIO_Mode_TypeDef;

/**
  * @reg    PxS
  * @brief  I/O 输入模式类
  */
typedef enum {
    GPIO_INPUTTRIGGERED_TTL                     = (uint8_t)0x00,    /*!< TTL电平输入 */
    GPIO_INPUTTRIGGERED_SMT                     = (uint8_t)0x01     /*!< 施密特触发输入 */
} GPIO_InputTriggered_TypeDef;

/**
  * @reg    PxSR
  * @brief  I/O 输出斜率类
  */
typedef enum {
    GPIO_SLEWRATE_NORMAL                        = (uint8_t)0x00,    /*!< 普通输出 */
    GPIO_SLEWRATE_FAST                          = (uint8_t)0x01     /*!< 高速输出 */
} GPIO_SlewRate_TypeDef;

void GPIO_DeInit(GPIO_Port_TypeDef port);

void GPIO_Init(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin, GPIO_Mode_TypeDef mode);

void GPIO_SetByte(GPIO_Port_TypeDef port, uint8_t portVal);

void GPIO_SetHigh(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin);

void GPIO_SetLow(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin);

void GPIO_SetReverse(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin);

uint8_t GPIO_ReadPin(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin);

void GPIO_SetInputTriggered(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin, GPIO_InputTriggered_TypeDef type);

void GPIO_SetSlewRate(GPIO_Port_TypeDef port, GPIO_Pin_TypeDef pin, GPIO_SlewRate_TypeDef speed);

#endif /* __SSGLIB_GPIO_H */