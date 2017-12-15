#ifndef __SSGLIB_PWM_H
#define __SSGLIB_PWM_H

#include "N76E003.h"

/************************************ PWM ************************************/

typedef enum {
    PWM_STATE_DISABLE,
    PWM_STATE_ENABLE
} PWM_State_TypeDef;

typedef enum {
    PWM_LOAD_DISABLE,
    PWM_LOAD_ENABLE
} PWM_Load_TypeDef;

typedef enum {
    PWM_CLEAR_DISABLE,
    PWM_CLEAR_ENABLE
} PWM_Clear_TypeDef;

typedef enum {
    PWM_GROUPMODE_DISABLE,
    PWM_GROUPMODE_ENABLE
} PWM_GroupMode_TypeDef;

typedef enum {
    PWM_PRESCALAR_1,
    PWM_PRESCALAR_2,
    PWM_PRESCALAR_4,
    PWM_PRESCALAR_8,
    PWM_PRESCALAR_16,
    PWM_PRESCALAR_32,
    PWM_PRESCALAR_64,
    PWM_PRESCALAR_128
} PWM_PreScalar_TypeDef;

typedef enum {
    PWM_TIMEBASE_FSYS,
    PWM_TIMEBASE_TIMER1
} PWM_TimeBase_TypeDef;

typedef enum {
    PWM_ALIGNED_EDGE,
    PWM_ALIGNED_CENTER
} PWM_Aligned_TypeDef;

typedef enum {
    PWM_MODE_INDEPENDENT,
    PWM_MODE_COMPLEMENTARY,
    PWM_MODE_SYNCHRONIZED
} PWM_Mode_TypeDef;

typedef enum {
    PWM_DEADTIME_DISABLE,
    PWM_DEADTIME_ENABLE
} PWM_DeadTime_TypeDef;

typedef enum {
    PWM_MASK_DISABLE,
    PWM_MASK_ENABLE
} PWM_MASK_TypeDef;

typedef enum {
    PWM_FAULTBRAKE_DISABLE,
    PWM_FAULTBRAKE_ENABLE
} PWM_FaultBrake_TypeDef;

typedef enum {
    PWM_FBEDGE_FALLING,
    PWM_FBEDGE_RISING
} PWM_FBEdge_TypeDef;

typedef enum {
    PWM_FBOVERWRITTEN_LOW,
    PWM_FBOVERWRITTEN_HIGH
} PWM_FBOverwritten_TypeDef;

typedef enum {
    PWM_POLARITY_DIRECT,
    PWM_POLARITY_INVERSE
} PWM_Polarity_TypeDef;

typedef enum {
    PWM_ITTYPE_FALLING,
    PWM_ITTYPE_RISING,
    PWM_ITTYPE_CENTER,
    PWM_ITTYPE_END
} PWM_ITType_TypeDef;

typedef enum {
    PWM_ITCHANNEL_0,
    PWM_ITCHANNEL_1,
    PWM_ITCHANNEL_2,
    PWM_ITCHANNEL_3,
    PWM_ITCHANNEL_4,
    PWM_ITCHANNEL_5
} PWM_ITChannel_TypeDef;

typedef enum {
    PWM_FLAG_LOAD,
    PWM_FLAG_PERIOD,
    PWM_FLAG_CLEAR,
    PWM_FLAG_FB
} PWM_Flag_TypeDef;

#endif /* __SSGLIB_PWM_H */