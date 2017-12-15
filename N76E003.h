/**
  ******************************************************************************
  * @file    N76E003.h
  * @author  MGD
  * @version V0.0.1
  * @date    5-nov-2017
  * @brief   This file contains all HW registers definitions and memory mapping.
  ******************************************************************************
  */
/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __N76E003_H
#define __N76E003_H

#ifdef FOSC_160000
    #define HIRC_VALUE                      ((uint32_t)16000000)    /*!< Typical Value of the HIRC in Hz */
#elif FOSC_166000
    #define HIRC_VALUE                      ((uint32_t)16600000)    /*!< Typical Value of the HIRC in Hz */
#endif /* Typical HIRC Value */
#define LIRC_VALUE                          ((uint32_t)10000)       /*!< Typical Value of the LIRC in Hz */

#define __I                                 volatile const  /*!< defines 'read only' permissions     */
#define __O                                 volatile        /*!< defines 'write only' permissions    */
#define __IO                                volatile        /*!< defines 'read / write' permissions  */

/*!< Signed integer types  */
typedef signed char                         int8_t;
typedef signed short                        int16_t;
typedef signed long                         int32_t;

typedef int32_t                             S32;
typedef int16_t                             S16;
typedef int8_t                              S8;

/*!< Unsigned integer types  */
typedef unsigned char                       uint8_t;
typedef unsigned short                      uint16_t;
typedef unsigned long                       uint32_t;

typedef uint32_t                            U32;
typedef uint16_t                            U16;
typedef uint8_t                             U8;

typedef enum { FALSE = 0, TRUE = !FALSE } bool;

typedef enum { RESET = 0, SET = !RESET } FlagStatus, ITStatus, BitStatus, BitAction;

typedef enum { DISABLE = 0, ENABLE = !DISABLE } FunctionalState;

typedef enum { LOW = 0, HIGH = !LOW } LevelState;

typedef enum { ERROR = 0, SUCCESS = !ERROR } ErrorStatus;

#define NULL                                (0)
#define U8_MAX                              (255)
#define S8_MAX                              (127)
#define S8_MIN                              (-128)
#define U16_MAX                             (65535u)
#define S16_MAX                             (32767)
#define S16_MIN                             (-32768)
#define U32_MAX                             (4294967295uL)
#define S32_MAX                             (2147483647)
#define S32_MIN                             (-2147483648uL)

#define BIT_MASK_0                          ((uint8_t)0x01) /*!< a byte(8bit) mask on [0000 0001] */
#define BIT_MASK_1                          ((uint8_t)0x02) /*!< a byte(8bit) mask on [0000 0010] */
#define BIT_MASK_2                          ((uint8_t)0x04) /*!< a byte(8bit) mask on [0000 0100] */
#define BIT_MASK_3                          ((uint8_t)0x08) /*!< a byte(8bit) mask on [0000 1000] */
#define BIT_MASK_4                          ((uint8_t)0x10) /*!< a byte(8bit) mask on [0001 0000] */
#define BIT_MASK_5                          ((uint8_t)0x20) /*!< a byte(8bit) mask on [0010 0000] */
#define BIT_MASK_6                          ((uint8_t)0x40) /*!< a byte(8bit) mask on [0100 0000] */
#define BIT_MASK_7                          ((uint8_t)0x80) /*!< a byte(8bit) mask on [1000 0000] */

#define BIT_MASK_8                          ((uint16_t)0x0100) /*!< double byte(16bit) mask on [0000 0001 0000 0000] */
#define BIT_MASK_9                          ((uint16_t)0x0200) /*!< double byte(16bit) mask on [0000 0010 0000 0000] */
#define BIT_MASK_10                         ((uint16_t)0x0400) /*!< double byte(16bit) mask on [0000 0100 0000 0000] */
#define BIT_MASK_11                         ((uint16_t)0x0800) /*!< double byte(16bit) mask on [0000 1000 0000 0000] */
#define BIT_MASK_12                         ((uint16_t)0x1000) /*!< double byte(16bit) mask on [0001 0000 0000 0000] */
#define BIT_MASK_13                         ((uint16_t)0x2000) /*!< double byte(16bit) mask on [0010 0000 0000 0000] */
#define BIT_MASK_14                         ((uint16_t)0x4000) /*!< double byte(16bit) mask on [0100 0000 0000 0000] */
#define BIT_MASK_15                         ((uint16_t)0x8000) /*!< double byte(16bit) mask on [1000 0000 0000 0000] */

/**
  * @ brief  sfr registers base address
  */
#define P0_BASE_ADDRESS                     0x80
#define SP_BASE_ADDRESS                     0x81
#define DPL_BASE_ADDRESS                    0x82
#define DPH_BASE_ADDRESS                    0x83
#define RCTRIM0_BASE_ADDRESS                0x84
#define RCTRIM1_BASE_ADDRESS                0x85
#define RWK_BASE_ADDRESS                    0x86
#define PCON_BASE_ADDRESS                   0x87

#define TCON_BASE_ADDRESS                   0x88
#define TMOD_BASE_ADDRESS                   0x89
#define TL0_BASE_ADDRESS                    0x8A
#define TL1_BASE_ADDRESS                    0x8B
#define TH0_BASE_ADDRESS                    0x8C
#define TH1_BASE_ADDRESS                    0x8D
#define CKCON_BASE_ADDRESS                  0x8E
#define WKCON_BASE_ADDRESS                  0x8F

#define P1_BASE_ADDRESS                     0x90
#define SFRS_BASE_ADDRESS                   0x91    //TA Protection
#define CAPCON0_BASE_ADDRESS                0x92
#define CAPCON1_BASE_ADDRESS                0x93
#define CAPCON2_BASE_ADDRESS                0x94
#define CKDIV_BASE_ADDRESS                  0x95
#define CKSWT_BASE_ADDRESS                  0x96    //TA Protection
#define CKEN_BASE_ADDRESS                   0x97    //TA Protection

#define SCON_BASE_ADDRESS                   0x98
#define SBUF_BASE_ADDRESS                   0x99
#define SBUF_1_BASE_ADDRESS                 0x9A
#define EIE_BASE_ADDRESS                    0x9B
#define EIE1_BASE_ADDRESS                   0x9C
#define CHPCON_BASE_ADDRESS                 0x9F    //TA Protection

#define P2_BASE_ADDRESS                     0xA0
#define AUXR1_BASE_ADDRESS                  0xA2
#define BODCON0_BASE_ADDRESS                0xA3    //TA Protection
#define IAPTRG_BASE_ADDRESS                 0xA4    //TA Protection
#define IAPUEN_BASE_ADDRESS                 0xA5    //TA Protection
#define IAPAL_BASE_ADDRESS                  0xA6
#define IAPAH_BASE_ADDRESS                  0xA7

#define IE_BASE_ADDRESS                     0xA8
#define SADDR_BASE_ADDRESS                  0xA9
#define WDCON_BASE_ADDRESS                  0xAA    //TA Protection
#define BODCON1_BASE_ADDRESS                0xAB    //TA Protection
#define P3M1_BASE_ADDRESS                   0xAC
#define P3S_BASE_ADDRESS                    0xAC    //Page1
#define P3M2_BASE_ADDRESS                   0xAD
#define P3SR_BASE_ADDRESS                   0xAD    //Page1
#define IAPFD_BASE_ADDRESS                  0xAE
#define IAPCN_BASE_ADDRESS                  0xAF

#define P3_BASE_ADDRESS                     0xB0
#define P0M1_BASE_ADDRESS                   0xB1
#define P0S_BASE_ADDRESS                    0xB1    //Page1
#define P0M2_BASE_ADDRESS                   0xB2
#define P0SR_BASE_ADDRESS                   0xB2    //Page1
#define P1M1_BASE_ADDRESS                   0xB3
#define P1S_BASE_ADDRESS                    0xB3    //Page1
#define P1M2_BASE_ADDRESS                   0xB4
#define P1SR_BASE_ADDRESS                   0xB4    //Page1
#define P2S_BASE_ADDRESS                    0xB5
#define IPH_BASE_ADDRESS                    0xB7
#define PWMINTC_BASE_ADDRESS                0xB7    //Page1

#define IP_BASE_ADDRESS                     0xB8
#define SADEN_BASE_ADDRESS                  0xB9
#define SADEN_1_BASE_ADDRESS                0xBA
#define SADDR_1_BASE_ADDRESS                0xBB
#define I2DAT_BASE_ADDRESS                  0xBC
#define I2STAT_BASE_ADDRESS                 0xBD
#define I2CLK_BASE_ADDRESS                  0xBE
#define I2TOC_BASE_ADDRESS                  0xBF

#define I2CON_BASE_ADDRESS                  0xC0
#define I2ADDR_BASE_ADDRESS                 0xC1
#define ADCRL_BASE_ADDRESS                  0xC2
#define ADCRH_BASE_ADDRESS                  0xC3
#define T3CON_BASE_ADDRESS                  0xC4
#define PWM4H_BASE_ADDRESS                  0xC4    //Page1
#define RL3_BASE_ADDRESS                    0xC5
#define PWM5H_BASE_ADDRESS                  0xC5    //Page1
#define RH3_BASE_ADDRESS                    0xC6
#define PIOCON1_BASE_ADDRESS                0xC6    //Page1
#define TA_BASE_ADDRESS                     0xC7

#define T2CON_BASE_ADDRESS                  0xC8
#define T2MOD_BASE_ADDRESS                  0xC9
#define RCMP2L_BASE_ADDRESS                 0xCA
#define RCMP2H_BASE_ADDRESS                 0xCB
#define TL2_BASE_ADDRESS                    0xCC
#define PWM4L_BASE_ADDRESS                  0xCC    //Page1
#define TH2_BASE_ADDRESS                    0xCD
#define PWM5L_BASE_ADDRESS                  0xCD    //Page1
#define ADCMPL_BASE_ADDRESS                 0xCE
#define ADCMPH_BASE_ADDRESS                 0xCF

#define PSW_BASE_ADDRESS                    0xD0
#define PWMPH_BASE_ADDRESS                  0xD1
#define PWM0H_BASE_ADDRESS                  0xD2
#define PWM1H_BASE_ADDRESS                  0xD3
#define PWM2H_BASE_ADDRESS                  0xD4
#define PWM3H_BASE_ADDRESS                  0xD5
#define PNP_BASE_ADDRESS                    0xD6
#define FBD_BASE_ADDRESS                    0xD7

#define PWMCON0_BASE_ADDRESS                0xD8
#define PWMPL_BASE_ADDRESS                  0xD9
#define PWM0L_BASE_ADDRESS                  0xDA
#define PWM1L_BASE_ADDRESS                  0xDB
#define PWM2L_BASE_ADDRESS                  0xDC
#define PWM3L_BASE_ADDRESS                  0xDD
#define PIOCON0_BASE_ADDRESS                0xDE
#define PWMCON1_BASE_ADDRESS                0xDF

#define ACC_BASE_ADDRESS                    0xE0
#define ADCCON1_BASE_ADDRESS                0xE1
#define ADCCON2_BASE_ADDRESS                0xE2
#define ADCDLY_BASE_ADDRESS                 0xE3
#define C0L_BASE_ADDRESS                    0xE4
#define C0H_BASE_ADDRESS                    0xE5
#define C1L_BASE_ADDRESS                    0xE6
#define C1H_BASE_ADDRESS                    0xE7

#define ADCCON0_BASE_ADDRESS                0xE8
#define PICON_BASE_ADDRESS                  0xE9
#define PINEN_BASE_ADDRESS                  0xEA
#define PIPEN_BASE_ADDRESS                  0xEB
#define PIF_BASE_ADDRESS                    0xEC
#define C2L_BASE_ADDRESS                    0xED
#define C2H_BASE_ADDRESS                    0xEE
#define EIP_BASE_ADDRESS                    0xEF

#define B_BASE_ADDRESS                      0xF0
#define CAPCON3_BASE_ADDRESS                0xF1
#define CAPCON4_BASE_ADDRESS                0xF2
#define SPCR_BASE_ADDRESS                   0xF3
#define SPCR2_BASE_ADDRESS                  0xF3    //Page1
#define SPSR_BASE_ADDRESS                   0xF4
#define SPDR_BASE_ADDRESS                   0xF5
#define AINDIDS_BASE_ADDRESS                0xF6
#define EIPH_BASE_ADDRESS                   0xF7

#define SCON_1_BASE_ADDRESS                 0xF8
#define PDTEN_BASE_ADDRESS                  0xF9    //TA Protection
#define PDTCNT_BASE_ADDRESS                 0xFA    //TA Protection
#define PMEN_BASE_ADDRESS                   0xFB
#define PMD_BASE_ADDRESS                    0xFC
#define EIP1_BASE_ADDRESS                   0xFE
#define EIPH1_BASE_ADDRESS                  0xFF

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/**** P0		80H *****/
#define P0_P07_MASK                         BIT_MASK_7
#define P0_P06_MASK                         BIT_MASK_6
#define P0_P05_MASK                         BIT_MASK_5
#define P0_P04_MASK                         BIT_MASK_4
#define P0_P03_MASK                         BIT_MASK_3
#define P0_P02_MASK                         BIT_MASK_2
#define P0_P01_MASK                         BIT_MASK_1
#define P0_P00_MASK                         BIT_MASK_0
#define P0_RESET_VALUE                      ((uint8_t)0xFF)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SP  	    81H ****
#define SP_RESET_VALUE                      ((uint8_t)0x07)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** DPH      82H ****
#define DPH_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** DPL      83H ****
#define DPL_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** RWK      86H ****
#define RWK_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PCON	    87H *****
#define PCON_SMOD_MASK                      BIT_MASK_7
#define PCON_SMOD0_MASK                     BIT_MASK_6
#define PCON_POF_MASK                       BIT_MASK_4
#define PCON_GF1_MASK                       BIT_MASK_3
#define PCON_GF0_MASK                       BIT_MASK_2
#define PCON_PD_MASK                        BIT_MASK_1
#define PCON_IDL_MASK                       BIT_MASK_0
#define PCON_RESET_VALUE                    ((uint8_t)0x10)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/**** TCON      88H ****/
#define TCON_TF1_MASK                       BIT_MASK_7
#define TCON_TR1_MASK                       BIT_MASK_6
#define TCON_TF0_MASK                       BIT_MASK_5
#define TCON_TR0_MASK                       BIT_MASK_4
#define TCON_IE1_MASK                       BIT_MASK_3
#define TCON_IT1_MASK                       BIT_MASK_2
#define TCON_IE0_MASK                       BIT_MASK_1
#define TCON_IT0_MASK                       BIT_MASK_0
#define TCON_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/**** TMOD      89H ****/
#define TMOD_GATE_T1_MASK                   BIT_MASK_7
#define TMOD_CT_T1_MASK                     BIT_MASK_6
#define TMOD_M1_T1_MASK                     BIT_MASK_5
#define TMOD_M0_T1_MASK                     BIT_MASK_4
#define TMOD_GATE_T0_MASK                   BIT_MASK_3
#define TMOD_CT_T0_MASK                     BIT_MASK_2
#define TMOD_M1_T0_MASK                     BIT_MASK_1
#define TMOD_M0_T0_MASK                     BIT_MASK_0
#define TMOD_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TH1		8AH ****
#define TH1_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TH0		8BH ****
#define TH0_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TL1		8CH	****
#define TL1_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TL0		8DH ****
#define TL0_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CKCON	8EH ****
#define CKCON_PWMCKS_MASK                   BIT_MASK_6
#define CKCON_T1M_MASK                      BIT_MASK_4
#define CKCON_T0M_MASK                      BIT_MASK_3
#define CKCON_CLOEN_MASK                    BIT_MASK_1
#define CKCON_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** WKCON	8FH ****
#define WKCON_WKTCK_MASK                    BIT_MASK_5
#define WKCON_WKTF_MASK                     BIT_MASK_4
#define WKCON_WKTR_MASK                     BIT_MASK_3
#define WKCON_WKPS2_MASK                    BIT_MASK_2
#define WKCON_WKPS1_MASK                    BIT_MASK_1
#define WKCON_WKPS0_MASK                    BIT_MASK_0
#define WKCON_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/**** P1		90H *****/
#define P1_P17_MASK                         BIT_MASK_7
#define P1_P16_MASK                         BIT_MASK_6
#define P1_P15_MASK                         BIT_MASK_5
#define P1_P14_MASK                         BIT_MASK_4
#define P1_P13_MASK                         BIT_MASK_3
#define P1_P12_MASK                         BIT_MASK_2
#define P1_P11_MASK                         BIT_MASK_1
#define P1_P10_MASK                         BIT_MASK_0
#define P1_RESET_VALUE                      ((uint8_t)0xFF)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//****SFRS		91H ****
#define SFRS_SFRPAGE_MASK                   BIT_MASK_0
#define SFRS_RESET_VALUE                    ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//****CAPCON0	92H ****
#define CAPCON0_CAPEN2_MASK                 BIT_MASK_6
#define CAPCON0_CAPEN1_MASK                 BIT_MASK_5
#define CAPCON0_CAPEN0_MASK                 BIT_MASK_4
#define CAPCON0_CAPF2_MASK                  BIT_MASK_2
#define CAPCON0_CAPF1_MASK                  BIT_MASK_1
#define CAPCON0_CAPF0_MASK                  BIT_MASK_0
#define CAPCON0_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CAPCON1	93H ****
#define CAPCON1_CAP2LS1_MASK                BIT_MASK_5
#define CAPCON1_CAP2LS0_MASK                BIT_MASK_4
#define CAPCON1_CAP1LS1_MASK                BIT_MASK_3
#define CAPCON1_CAP1LS0_MASK                BIT_MASK_2
#define CAPCON1_CAP0LS1_MASK                BIT_MASK_1
#define CAPCON1_CAP0LS0_MASK                BIT_MASK_0
#define CAPCON1_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CAPCON2		94H ****
#define CAPCON2_ENF2_MASK                   BIT_MASK_6
#define CAPCON2_ENF1_MASK                   BIT_MASK_5
#define CAPCON2_ENF0_MASK                   BIT_MASK_4
#define CAPCON2_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CKDIV		95H ****
#define CKDIV_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CKSWT		96H ****  TA protect register
#define CKSWT_HIRCST_MASK                   BIT_MASK_5
#define CKSWT_LIRCST_MASK                   BIT_MASK_4
#define CKSWT_ECLKST_MASK                   BIT_MASK_3
#define CKSWT_OSC1_MASK                     BIT_MASK_2
#define CKSWT_OSC0_MASK                     BIT_MASK_1
#define CKSWT_RESET_VALUE                   ((uint8_t)0x30) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CKEN 	97H **** TA protect register
#define CKEN_EXTEN1_MASK                    BIT_MASK_7
#define CKEN_EXTEN0_MASK                    BIT_MASK_6
#define CKEN_HIRCEN_MASK                    BIT_MASK_5
#define CKEN_CKSWTF_MASK                    BIT_MASK_0
#define CKEN_RESET_VALUE                    ((uint8_t)0x30) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SCON		98H ****
#define SCON_FE_MASK                        BIT_MASK_7
#define SCON_SM1_MASK                       BIT_MASK_6
#define SCON_SM2_MASK                       BIT_MASK_5
#define SCON_REN_MASK                       BIT_MASK_4
#define SCON_TB8_MASK                       BIT_MASK_3
#define SCON_RB8_MASK                       BIT_MASK_2
#define SCON_TI_MASK                        BIT_MASK_1
#define SCON_RI_MASK                        BIT_MASK_0
#define SCON_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SBUF		99H ****
#define SBUF_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SBUF_1	9AH ****
#define SBUF_1_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** EIE		9BH ****
#define EIE_ET2_MASK                        BIT_MASK_7
#define EIE_ESPI_MASK                       BIT_MASK_6
#define EIE_EFB_MASK                        BIT_MASK_5
#define EIE_EWDT_MASK                       BIT_MASK_4
#define EIE_EPWM_MASK                       BIT_MASK_3
#define EIE_ECAP_MASK                       BIT_MASK_2
#define EIE_EPI_MASK                        BIT_MASK_1
#define EIE_EI2C_MASK                       BIT_MASK_0
#define EIE_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** EIE1		9CH ****
#define EIE1_EWKT_MASK                      BIT_MASK_2
#define EIE1_ET3_MASK                       BIT_MASK_1
#define EIE1_ES_1_MASK                      BIT_MASK_0
#define EIE1_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CHPCON		9DH ****  TA protect register
#define CHPCON_SWRST_MASK                   BIT_MASK_7
#define CHPCON_IAPFF_MASK                   BIT_MASK_6
#define CHPCON_BS_MASK                      BIT_MASK_1
#define CHPCON_IAPEN_MASK                   BIT_MASK_0
#define CHPCON_RESET_VALUE                  ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P2		A0H ****
#define P2_RESET_VALUE                      ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** AUXR1	A2H ****
#define AUXR1_SWRF_MASK                     BIT_MASK_7
#define AUXR1_RSTPINF_MASK                  BIT_MASK_6
#define AUXR1_HARDF_MASK                    BIT_MASK_5
#define AUXR1_GF2_MASK                      BIT_MASK_3
#define AUXR1_UART0PX_MASK                  BIT_MASK_2
#define AUXR1_DPS_MASK                      BIT_MASK_0
#define AUXR1_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** BODCON0	A3H ****  TA protect register
#define BODCON0_BODEN_MASK                  BIT_MASK_7
#define BODCON0_BOV2_MASK                   BIT_MASK_6
#define BODCON0_BOV1_MASK                   BIT_MASK_5
#define BODCON0_BOV0_MASK                   BIT_MASK_4
#define BODCON0_BOF_MASK                    BIT_MASK_3
#define BODCON0_BORST_MASK                  BIT_MASK_2
#define BODCON0_BORF_MASK                   BIT_MASK_1
#define BODCON0_BOS_MASK                    BIT_MASK_0
#define BODCON0_RESET_VALUE                 ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IAPTRG		A4H	****  TA protect register
#define IAPTRG_IAPGO_MASK                   BIT_MASK_0
#define IAPTRG_RESET_VALUE                  ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IAPUEN		A5H **** TA protect register
#define IAPUEN_CFUEN_MASK                   BIT_MASK_2
#define IAPUEN_LDUEN_MASK                   BIT_MASK_1
#define IAPUEN_APUEN_MASK                   BIT_MASK_0
#define IAPUEN_RESET_VALUE                  ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IAPAL	A6H ****
#define IAPAL_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IAPAH	A7H ****
#define IAPAH_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IE			A8H ****
#define IE_EA_MASK                          BIT_MASK_7
#define IE_EADC_MASK                        BIT_MASK_6
#define IE_EBOD_MASK                        BIT_MASK_5
#define IE_ES_MASK                          BIT_MASK_4
#define IE_ET1_MASK                         BIT_MASK_3
#define IE_EX1_MASK                         BIT_MASK_2
#define IE_ET0_MASK                         BIT_MASK_1
#define IE_EX0_MASK                         BIT_MASK_0
#define IE_RESET_VALUE                      ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SADDR		A9H ****
#define SADDR_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** WDCON		AAH **** TA protect register
#define WDCON_WDTR_MASK                     BIT_MASK_7
#define WDCON_WDCLR_MASK                    BIT_MASK_6
#define WDCON_WDTF_MASK                     BIT_MASK_5
#define WDCON_WIDPD_MASK                    BIT_MASK_4
#define WDCON_WDTRF_MASK                    BIT_MASK_3
#define WDCON_WDPS_MASK                     (BIT_MASK_0 | BIT_MASK_1 | BIT_MASK_2)
#define WDCON_RESET_VALUE                   ((uint8_t)0x07) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** BODCON1 ABH **** TA protect register
#define BODCON1_LPBOD1_MASK                 BIT_MASK_2
#define BODCON1_LPBOD0_MASK                 BIT_MASK_1
#define BODCON1_BODFLT_MASK                 BIT_MASK_0
#define BODCON1_RESET_VALUE                 ((uint8_t)0x01) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P3M1		ACH PAGE0 ****
#define P3M1_P3M1_0_MASK                    BIT_MASK_0
#define P3M1_RESET_VALUE                    ((uint8_t)0x01)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P3S		ACH PAGE1 **** SFRS must set as 1 to modify this register
#define P3S_P3S_0_MASK                      BIT_MASK_0
#define P3S_RESET_VALUE                     ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P3M2		ADH PAGE0 ****
#define P3M2_P3M2_0_MASK                    BIT_MASK_0
#define P3M2_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P3SR		ADH PAGE1 **** SFRS must set as 1 to modify this register
#define P3SR_P3SR_0_MASK                    BIT_MASK_0
#define P3SR_RESET_VALUE                    ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IAPFD	AEH ****
#define IAPFD_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IAPCN	AFH ****
#define IAPN_FOEN_MASK                      BIT_MASK_5
#define IAPN_FCEN_MASK                      BIT_MASK_4
#define IAPN_FCTRL3_MASK                    BIT_MASK_3
#define IAPN_FCTRL2_MASK                    BIT_MASK_2
#define IAPN_FCTRL1_MASK                    BIT_MASK_1
#define IAPN_FCTRL0_MASK                    BIT_MASK_0
#define IAPCN_RESET_VALUE                   ((uint8_t)0x30)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P3		B0H ****
#define P3_P30_MASK                         BIT_MASK_0
#define P3_RESET_VALUE                      ((uint8_t)0x01)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P0M1	B1H PAGE0 ****
#define P0M1_P0M1_7_MASK                    BIT_MASK_7
#define P0M1_P0M1_6_MASK                    BIT_MASK_6
#define P0M1_P0M1_5_MASK                    BIT_MASK_5
#define P0M1_P0M1_4_MASK                    BIT_MASK_4
#define P0M1_P0M1_3_MASK                    BIT_MASK_3
#define P0M1_P0M1_2_MASK                    BIT_MASK_2
#define P0M1_P0M1_1_MASK                    BIT_MASK_1
#define P0M1_P0M1_0_MASK                    BIT_MASK_0
#define P0M1_RESET_VALUE                    ((uint8_t)0xFF)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P0S	B2H PAGE1 **** SFRS must set as 1 to modify this register
#define P0S_P0S_7_MASK                      BIT_MASK_7
#define P0S_P0S_6_MASK                      BIT_MASK_6
#define P0S_P0S_5_MASK                      BIT_MASK_5
#define P0S_P0S_4_MASK                      BIT_MASK_4
#define P0S_P0S_3_MASK                      BIT_MASK_3
#define P0S_P0S_2_MASK                      BIT_MASK_2
#define P0S_P0S_1_MASK                      BIT_MASK_1
#define P0S_P0S_0_MASK                      BIT_MASK_0
#define P0S_RESET_VALUE                     ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P0M2		B2H PAGE0 ****
#define P0M2_P0M2_7_MASK                    BIT_MASK_7
#define P0M2_P0M2_6_MASK                    BIT_MASK_6
#define P0M2_P0M2_5_MASK                    BIT_MASK_5
#define P0M2_P0M2_4_MASK                    BIT_MASK_4
#define P0M2_P0M2_3_MASK                    BIT_MASK_3
#define P0M2_P0M2_2_MASK                    BIT_MASK_2
#define P0M2_P0M2_1_MASK                    BIT_MASK_1
#define P0M2_P0M2_0_MASK                    BIT_MASK_0
#define P0M2_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P0SR		B0H PAGE1 **** SFRS must set as 1 to modify this register
#define P0SR_P0SR_7_MASK                    BIT_MASK_7
#define P0SR_P0SR_6_MASK                    BIT_MASK_6
#define P0SR_P0SR_5_MASK                    BIT_MASK_5
#define P0SR_P0SR_4_MASK                    BIT_MASK_4
#define P0SR_P0SR_3_MASK                    BIT_MASK_3
#define P0SR_P0SR_2_MASK                    BIT_MASK_2
#define P0SR_P0SR_1_MASK                    BIT_MASK_1
#define P0SR_P0SR_0_MASK                    BIT_MASK_0
#define P0SR_RESET_VALUE                    ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P1M1	B3H PAGE0 ****
#define P1M1_P1M1_7_MASK                    BIT_MASK_7
#define P1M1_P1M1_6_MASK                    BIT_MASK_6
#define P1M1_P1M1_5_MASK                    BIT_MASK_5
#define P1M1_P1M1_4_MASK                    BIT_MASK_4
#define P1M1_P1M1_3_MASK                    BIT_MASK_3
#define P1M1_P1M1_2_MASK                    BIT_MASK_2
#define P1M1_P1M1_1_MASK                    BIT_MASK_1
#define P1M1_P1M1_0_MASK                    BIT_MASK_0
#define P1M1_RESET_VALUE                    ((uint8_t)0xFF)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P1S B3H PAGE1 **** SFRS must set as 1 to modify this register
#define P1S_P1S_7_MASK                      BIT_MASK_7
#define P1S_P1S_6_MASK                      BIT_MASK_6
#define P1S_P1S_5_MASK                      BIT_MASK_5
#define P1S_P1S_4_MASK                      BIT_MASK_4
#define P1S_P1S_3_MASK                      BIT_MASK_3
#define P1S_P1S_2_MASK                      BIT_MASK_2
#define P1S_P1S_1_MASK                      BIT_MASK_1
#define P1S_P1S_0_MASK                      BIT_MASK_0
#define P1S_RESET_VALUE                     ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P1M2		B4H PAGE0 ****
#define P1M2_P12UP_MASK                     BIT_MASK_2
#define P1M2_P1M2_1_MASK                    BIT_MASK_1
#define P1M2_P1M2_0_MASK                    BIT_MASK_0
#define P1M2_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P1SR		B4H PAGE1 **** SFRS must set as 1 to modify this register
#define P1SR_P1SR_7_MASK                    BIT_MASK_7
#define P1SR_P1SR_6_MASK                    BIT_MASK_6
#define P1SR_P1SR_5_MASK                    BIT_MASK_5
#define P1SR_P1SR_4_MASK                    BIT_MASK_4
#define P1SR_P1SR_3_MASK                    BIT_MASK_3
#define P1SR_P1SR_2_MASK                    BIT_MASK_2
#define P1SR_P1SR_1_MASK                    BIT_MASK_1
#define P1SR_P1SR_0_MASK                    BIT_MASK_0
#define P1SR_RESET_VALUE                    ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** P2S		B5H	****
#define P2S_P20UP_MASK                      BIT_MASK_7
#define P2S_T1OE_MASK                       BIT_MASK_3
#define P2S_T0OE_MASK                       BIT_MASK_2
#define P2S_P2S_0_MASK                      BIT_MASK_0
#define P2S_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IPH    B7H PAGE0 ****
#define IPH_PADCH_MASK                      BIT_MASK_6
#define IPH_PBODH_MASK                      BIT_MASK_5
#define IPH_PSH_MASK                        BIT_MASK_4
#define IPH_PT1H_MASK                       BIT_MASK_3
#define IPH_PX11_MASK                       BIT_MASK_2
#define IPH_PT0H_MASK                       BIT_MASK_1
#define IPH_PX0H_MASK                       BIT_MASK_0
#define IPH_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWMINTC B7H PAGE1 **** SFRS must set as 1 to modify this register
#define PWMINTC_INTTYP1_MASK                BIT_MASK_5
#define PWMINTC_INTTYP0_MASK                BIT_MASK_4
#define PWMINTC_INTSEL2_MASK                BIT_MASK_2
#define PWMINTC_INTSEL1_MASK                BIT_MASK_1
#define PWMINTC_INTSEL0_MASK                BIT_MASK_0
#define PWMINTC_RESET_VALUE                 ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** IP		B8H	****
#define IP_PADC_MASK                        BIT_MASK_6
#define IP_PBOD_MASK                        BIT_MASK_5
#define IP_PS_MASK                          BIT_MASK_4
#define IP_PT1_MASK                         BIT_MASK_3
#define IP_PX1_MASK                         BIT_MASK_2
#define IP_PT0_MASK                         BIT_MASK_1
#define IP_PX0_MASK                         BIT_MASK_0
#define IP_RESET_VALUE                      ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SADEN		B9H ****
#define SADEN_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SADEN_1	    8AH ****
#define SADEN_1_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SADDR_1	    BBH ****
#define SADDR_1_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** I2DAT		BCH ****
#define I2DAT_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** I2STAT		BDH ****
#define I2STAT_RESET_VALUE                  ((uint8_t)0xF8)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** I2CLK		BEH ****
#define I2CLK_RESET_VALUE                   ((uint8_t)0x09)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** I2TOC		BFH ****
#define I2TOC_I2TOCEN_MASK                  BIT_MASK_2
#define I2TOC_DIV_MASK                      BIT_MASK_1
#define I2TOC_I2TOF_MASK                    BIT_MASK_0
#define I2TOC_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** I2CON  C0H ****
#define I2CON_I2CEN_MASK                    BIT_MASK_6
#define I2CON_STA_MASK                      BIT_MASK_5
#define I2CON_STO_MASK                      BIT_MASK_4
#define I2CON_SI_MASK                       BIT_MASK_3
#define I2CON_AA_MASK                       BIT_MASK_2
#define I2CON_I2CPX_MASK                    BIT_MASK_0
#define I2CON_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** I2ADDR		C1H ****
#define I2ADDR_GC_MASK                      BIT_MASK_0
#define I2ADDR_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCRL		C2H ****
#define ADCRL_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCRH		C3H ****
#define ADCRH_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** T3CON		C4H	PAGE0 ****
#define T3CON_SMOD_1_MASK                   BIT_MASK_7
#define T3CON_SMOD0_1_MASK                  BIT_MASK_6
#define T3CON_BRCK_MASK                     BIT_MASK_5
#define T3CON_TF3_MASK                      BIT_MASK_4
#define T3CON_TR3_MASK                      BIT_MASK_3
#define T3CON_T3PS2_MASK                    BIT_MASK_2
#define T3CON_T3PS1_MASK                    BIT_MASK_1
#define T3CON_T3PS0_MASK                    BIT_MASK_0
#define T3CON_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM4H	C4H	PAGE1 **** SFRS must set as 1 to modify this register
#define PWM4H_RESET_VALUE                   ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** RL3		C5H PAGE0 ****
#define RL3_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM5H	C5H PAGE1 **** SFRS must set as 1 to modify this register
#define PWM5H_RESET_VALUE                   ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** RH3		C6H PAGE0 ****
#define RH3_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PIOCON1 C6H PAGE1 **** SFRS must set as 1 to modify this register
#define PIOCON1_PIO15_MASK                  BIT_MASK_5
#define PIOCON1_PIO13_MASK                  BIT_MASK_3
#define PIOCON1_PIO12_MASK                  BIT_MASK_2
#define PIOCON1_PIO11_MASK                  BIT_MASK_1
#define PIOCON1_RESET_VALUE                 ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TA		C7H ****
#define TA_RESET_VALUE                      ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** T2CON  C8H ****
#define T2CON_TF2_MASK                      BIT_MASK_7
#define T2CON_TR2_MASK                      BIT_MASK_2
#define T2CON_CMRL2_MASK                    BIT_MASK_0
#define T2CON_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** T2MOD	C9H ****
#define T2MOD_LDEN_MASK                     BIT_MASK_7
#define T2MOD_T2DIV2_MASK                   BIT_MASK_6
#define T2MOD_T2DIV1_MASK                   BIT_MASK_5
#define T2MOD_T2DIV0_MASK                   BIT_MASK_4
#define T2MOD_CAPCR_MASK                    BIT_MASK_3
#define T2MOD_CMPCR_MASK                    BIT_MASK_2
#define T2MOD_LDTS1_MASK                    BIT_MASK_1
#define T2MOD_LDTS0_MASK                    BIT_MASK_0
#define T2MOD_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** RCMP2H CAH ****
#define RCMP2L_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** RCMP2L CBH ****
#define RCMP2H_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TL2		CCH PAGE0 ****
#define TL2_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM4L 	CCH PAGE1 **** SFRS must set as 1 to modify this register
#define PWM4L_RESET_VALUE                   ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** TH2		CDH PAGE0 ****
#define TH2_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM5L	CDH PAGE1 **** SFRS must set as 1 to modify this register
#define PWM5L_RESET_VALUE                   ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCMPL	CEH ****
#define ADCMPL_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCMPH	CFH ****
#define ADCMPH_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/****  PSW 		D0H ****/
#define PSW_CY_MASK                         BIT_MASK_7
#define PSW_AC_MASK                         BIT_MASK_6
#define PSW_F0_MASK                         BIT_MASK_5
#define PSW_RS1_MASK                        BIT_MASK_4
#define PSW_RS0_MASK                        BIT_MASK_3
#define PSW_OV_MASK                         BIT_MASK_2
#define PSW_P_MASK                          BIT_MASK_0
#define PSW_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWMPH		D1H ****
#define PWMPH_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM0H		D2H ****
#define PWM0H_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM1H		D3H ****
#define PWM1H_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM2H		D4H ****
#define PWM2H_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM3H		D5H	****
#define PWM3H_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PNP			D6H ****
#define PNP_PNP5_MASK                       BIT_MASK_5
#define PNP_PNP4_MASK                       BIT_MASK_4
#define PNP_PNP3_MASK                       BIT_MASK_3
#define PNP_PNP2_MASK                       BIT_MASK_2
#define PNP_PNP1_MASK                       BIT_MASK_1
#define PNP_PNP0_MASK                       BIT_MASK_0
#define PNP_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** FBD		D7H ****
#define FBD_FBF_MASK                        BIT_MASK_7
#define FBD_FBINLS_MASK                     BIT_MASK_6
#define FBD_FBD5_MASK                       BIT_MASK_5
#define FBD_FBD4_MASK                       BIT_MASK_4
#define FBD_FBD3_MASK                       BIT_MASK_3
#define FBD_FBD2_MASK                       BIT_MASK_2
#define FBD_FBD1_MASK                       BIT_MASK_1
#define FBD_FBD0_MASK                       BIT_MASK_0
#define FBD_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/**** PWMCON0			D8H ****/
#define PWMCON0_PWMRUN_MASK                 BIT_MASK_7
#define PWMCON0_LOAD_MASK                   BIT_MASK_6
#define PWMCON0_PWMF_MASK                   BIT_MASK_5
#define PWMCON0_CLRPWM_MASK                 BIT_MASK_4
#define PWMCON0_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWMPL		D9H ****
#define PWMPL_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM0L		DAH ****
#define PWM0L_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM1L		DBH ****
#define PWM1L_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM2L		DCH ****
#define PWM2L_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWM3L		DDH ****
#define PWM3L_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PIOCON0	DEH ****
#define PIOCON0_PIO05_MASK                  BIT_MASK_5
#define PIOCON0_PIO04_MASK                  BIT_MASK_4
#define PIOCON0_PIO03_MASK                  BIT_MASK_3
#define PIOCON0_PIO02_MASK                  BIT_MASK_2
#define PIOCON0_PIO01_MASK                  BIT_MASK_1
#define PIOCON0_PIO00_MASK                  BIT_MASK_0
#define PIOCON0_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PWMCON1	DFH ****
#define PWMCON1_PWMMOD1_MASK                BIT_MASK_7
#define PWMCON1_PWMMOD0_MASK                BIT_MASK_6
#define PWMCON1_GP_MASK                     BIT_MASK_5
#define PWMCON1_PWMTYP_MASK                 BIT_MASK_4
#define PWMCON1_FBINEN_MASK                 BIT_MASK_3
#define PWMCON1_PWMDIV2_MASK                BIT_MASK_2
#define PWMCON1_PWMDIV1_MASK                BIT_MASK_1
#define PWMCON1_PWMDIV0_MASK                BIT_MASK_0
#define PWMCON1_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ACC	E0H ****
#define ACC_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCCON1	E1H ****
#define ADCCON1_STADCPX_MASK                BIT_MASK_6
#define ADCCON1_ETGTYP1_MASK                BIT_MASK_3
#define ADCCON1_ETGTYP0_MASK                BIT_MASK_2
#define ADCCON1_ADCEX_MASK                  BIT_MASK_1
#define ADCCON1_ADCEN_MASK                  BIT_MASK_0
#define ADCCON1_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCON2		E2H ****
#define ADCCON2_ADFBEN_MASK                 BIT_MASK_7
#define ADCCON2_ADCMPOP_MASK                BIT_MASK_6
#define ADCCON2_ADCMPEN_MASK                BIT_MASK_5
#define ADCCON2_ADCMPO_MASK                 BIT_MASK_4
#define ADCCON2_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCDLY		E3H ****
#define ADCDLY_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** C0L			E4H ****
#define C0L_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** C0H			E5H ****
#define C0H_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** C1L			E6H ****
#define C1L_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** C1H			E7H ****
#define C1H_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** ADCCON0	EAH ****
#define ADCCON0_ADCF_MASK                   BIT_MASK_7
#define ADCCON0_ADCS_MASK                   BIT_MASK_6
#define ADCCON0_ETGSEL1_MASK                BIT_MASK_5
#define ADCCON0_ETGSEL0_MASK                BIT_MASK_4
#define ADCCON0_ADCHS3_MASK                 BIT_MASK_3
#define ADCCON0_ADCHS2_MASK                 BIT_MASK_2
#define ADCCON0_ADCHS1_MASK                 BIT_MASK_1
#define ADCCON0_ADCHS0_MASK                 BIT_MASK_0
#define ADCCON0_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PICON	E9H	****
#define PICON_PIT67_MASK                    BIT_MASK_7
#define PICON_PIT45_MASK                    BIT_MASK_6
#define PICON_PIT3_MASK                     BIT_MASK_5
#define PICON_PIT2_MASK                     BIT_MASK_4
#define PICON_PIT1_MASK                     BIT_MASK_3
#define PICON_PIT0_MASK                     BIT_MASK_2
#define PICON_PIPS1_MASK                    BIT_MASK_1
#define PICON_PIPS0_MASK                    BIT_MASK_0
#define PICON_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PINEN		EAH ****
#define PINEN_PINEN7_MASK                   BIT_MASK_7
#define PINEN_PINEN6_MASK                   BIT_MASK_6
#define PINEN_PINEN5_MASK                   BIT_MASK_5
#define PINEN_PINEN4_MASK                   BIT_MASK_4
#define PINEN_PINEN3_MASK                   BIT_MASK_3
#define PINEN_PINEN2_MASK                   BIT_MASK_2
#define PINEN_PINEN1_MASK                   BIT_MASK_1
#define PINEN_PINEN0_MASK                   BIT_MASK_0
#define PINEN_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PIPEN 		EBH ****
#define PIPEN_PIPEN7_MASK                   BIT_MASK_7
#define PIPEN_PIPEN6_MASK                   BIT_MASK_6
#define PIPEN_PIPEN5_MASK                   BIT_MASK_5
#define PIPEN_PIPEN4_MASK                   BIT_MASK_4
#define PIPEN_PIPEN3_MASK                   BIT_MASK_3
#define PIPEN_PIPEN2_MASK                   BIT_MASK_2
#define PIPEN_PIPEN1_MASK                   BIT_MASK_1
#define PIPEN_PIPEN0_MASK                   BIT_MASK_0
#define PIPEN_RESET_VALUE                   ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PIF	ECH ****
#define PIF_PIF7_MASK                       BIT_MASK_7
#define PIF_PIF6_MASK                       BIT_MASK_6
#define PIF_PIF5_MASK                       BIT_MASK_5
#define PIF_PIF4_MASK                       BIT_MASK_4
#define PIF_PIF3_MASK                       BIT_MASK_3
#define PIF_PIF2_MASK                       BIT_MASK_2
#define PIF_PIF1_MASK                       BIT_MASK_1
#define PIF_PIF0_MASK                       BIT_MASK_0
#define PIF_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** C2L  EDH ****
#define C2L_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** C2H	EEH ****
#define C2H_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** EIP	EFH ****
#define EIP_PT2_MASK                        BIT_MASK_7
#define EIP_PSPI_MASK                       BIT_MASK_6
#define EIP_PFB_MASK                        BIT_MASK_5
#define EIP_PWDT_MASK                       BIT_MASK_4
#define EIP_PPWM_MASK                       BIT_MASK_3
#define EIP_PCAP_MASK                       BIT_MASK_2
#define EIP_PPI_MASK                        BIT_MASK_1
#define EIP_PI2C_MASK                       BIT_MASK_0
#define EIP_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** B	F0H ****
#define B_RESET_VALUE                       ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CAPCON3		F1H ****
#define CAPCON3_CAP13_MASK                  BIT_MASK_7
#define CAPCON3_CAP12_MASK                  BIT_MASK_6
#define CAPCON3_CAP11_MASK                  BIT_MASK_5
#define CAPCON3_CAP10_MASK                  BIT_MASK_4
#define CAPCON3_CAP03_MASK                  BIT_MASK_3
#define CAPCON3_CAP02_MASK                  BIT_MASK_2
#define CAPCON3_CAP01_MASK                  BIT_MASK_1
#define CAPCON3_CAP00_MASK                  BIT_MASK_0
#define CAPCON3_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** CAPCON4		F2H ****
#define CAPCON4_CAP23_MASK                  BIT_MASK_3
#define CAPCON4_CAP22_MASK                  BIT_MASK_2
#define CAPCON4_CAP21_MASK                  BIT_MASK_1
#define CAPCON4_CAP20_MASK                  BIT_MASK_0
#define CAPCON4_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SPCR		F3H PAGE0 ****
#define SPCR_SSOE_MASK                      BIT_MASK_7
#define SPCR_SPIEN_MASK                     BIT_MASK_6
#define SPCR_LSBFE_MASK                     BIT_MASK_5
#define SPCR_MSTR_MASK                      BIT_MASK_4
#define SPCR_CPOL_MASK                      BIT_MASK_3
#define SPCR_CPHA_MASK                      BIT_MASK_2
#define SPCR_SPR1_MASK                      BIT_MASK_1
#define SPCR_SPR0_MASK                      BIT_MASK_0
#define SPCR_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SPCR2		F3H PAGE1 **** SFRS must set as 1 to modify this register
#define SPCR2_SPIS1_MASK                    BIT_MASK_1
#define SPCR2_SPIS0_MASK                    BIT_MASK_1
#define SPCR2_RESET_VALUE                   ((uint8_t)0x00) //Page1

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SPSR			F4H ****
#define SPSR_SPIF_MASK                      BIT_MASK_7
#define SPSR_WCOL_MASK                      BIT_MASK_6
#define SPSR_SPIOVF_MASK                    BIT_MASK_5
#define SPSR_MODF_MASK                      BIT_MASK_4
#define SPSR_DISMODF_MASK                   BIT_MASK_3
#define SPSR_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** SPDR		F5H ****
#define SPDR_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** AINDIDS	F6H ****
#define AINDIDS_P11DIDS_MASK                BIT_MASK_7
#define AINDIDS_P03DIDS_MASK                BIT_MASK_6
#define AINDIDS_P04DIDS_MASK                BIT_MASK_5
#define AINDIDS_P05DIDS_MASK                BIT_MASK_4
#define AINDIDS_P06DIDS_MASK                BIT_MASK_3
#define AINDIDS_P07DIDS_MASK                BIT_MASK_2
#define AINDIDS_P30DIDS_MASK                BIT_MASK_1
#define AINDIDS_P17DIDS_MASK                BIT_MASK_0
#define AINDIDS_RESET_VALUE                 ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** EIPH			F7H ****
#define EIPH_PT2H_MASK                      BIT_MASK_7
#define EIPH_PSPIH_MASK                     BIT_MASK_6
#define EIPH_PFBH_MASK                      BIT_MASK_5
#define EIPH_PWDTH_MASK                     BIT_MASK_4
#define EIPH_PPWMH_MASK                     BIT_MASK_3
#define EIPH_PCAPH_MASK                     BIT_MASK_2
#define EIPH_PPIH_MASK                      BIT_MASK_1
#define EIPH_PI2CH_MASK                     BIT_MASK_0
#define EIPH_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
/**** SCON_1		F8H ****/
#define SCON_1_FE_1_MASK                    BIT_MASK_7
#define SCON_1_SM1_1_MASK                   BIT_MASK_6
#define SCON_1_SM2_1_MASK                   BIT_MASK_5
#define SCON_1_REN_1_MASK                   BIT_MASK_4
#define SCON_1_TB8_1_MASK                   BIT_MASK_3
#define SCON_1_RB8_1_MASK                   BIT_MASK_2
#define SCON_1_TI_1_MASK                    BIT_MASK_1
#define SCON_1_RI_1_MASK                    BIT_MASK_0
#define SCON_1_RESET_VALUE                  ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PDTEN		F9H ****
#define PDTEN_PDT45EN_MASK                  BIT_MASK_2
#define PDTEN_PDT23EN_MASK                  BIT_MASK_1
#define PDTEN_PDT01EN_MASK                  BIT_MASK_0
#define PDTEN_RESET_VALUE                   ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PDTCNT		FAH ****
#define PDTCNT_RESET_VALUE                  ((uint8_t)0x00) //TA Protection

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PMEN   	FBH ****
#define PMEN_PMEN5_MASK                     BIT_MASK_5
#define PMEN_PMEN4_MASK                     BIT_MASK_4
#define PMEN_PMEN3_MASK                     BIT_MASK_3
#define PMEN_PMEN2_MASK                     BIT_MASK_2
#define PMEN_PMEN1_MASK                     BIT_MASK_1
#define PMEN_PMEN0_MASK                     BIT_MASK_0
#define PMEN_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** PMD		FCH ****
#define PMD_PMD7_MASK                       BIT_MASK_7
#define PMD_PMD6_MASK                       BIT_MASK_6
#define PMD_PMD5_MASK                       BIT_MASK_5
#define PMD_PMD4_MASK                       BIT_MASK_4
#define PMD_PMD3_MASK                       BIT_MASK_3
#define PMD_PMD2_MASK                       BIT_MASK_2
#define PMD_PMD1_MASK                       BIT_MASK_1
#define PMD_PMD0_MASK                       BIT_MASK_0
#define PMD_RESET_VALUE                     ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//****	EIP1 		FEH ****
#define EIP1_PWKT_MASK                      BIT_MASK_2
#define EIP1_PT3_MASK                       BIT_MASK_1
#define EIP1_PS_1_MASK                      BIT_MASK_0
#define EIP1_RESET_VALUE                    ((uint8_t)0x00)

/*----------------------------------------------------------------------------*/
/**
  * @brief  P0 I/O (port 0)
  */
//**** EIPH1		FFH ****
#define EIPH1_PWKTH_MASK                    BIT_MASK_2
#define EIPH1_PT3H_MASK                     BIT_MASK_1
#define EIPH1_PSH_1_MASK                    BIT_MASK_0
#define EIPH1_RESET_VALUE                   ((uint8_t)0x00)

/******************************************************************************/
/*                   Library configuration section                            */
/******************************************************************************/

#if defined(__IAR_SYSTEMS_ICC__) // IAR 8051
    #ifndef _SYSTEM_BUILD
        #pragma system_include
    #endif

    #pragma language = save
    #pragma language = extended

    // Put your IAR code here

    #pragma language = restore

#elif defined(__C51__) // KEIL_C51

    // Put your keil code here
    sfr P0                                  = P0_BASE_ADDRESS;
    sfr SP                                  = SP_BASE_ADDRESS;
    sfr DPL                                 = DPL_BASE_ADDRESS;
    sfr DPH                                 = DPH_BASE_ADDRESS;
    sfr RCTRIM0                             = RCTRIM0_BASE_ADDRESS;
    sfr RCTRIM1                             = RCTRIM1_BASE_ADDRESS;
    sfr RWK                                 = RWK_BASE_ADDRESS;
    sfr PCON                                = PCON_BASE_ADDRESS;

    sfr TCON                                = TCON_BASE_ADDRESS;
    sfr TMOD                                = TMOD_BASE_ADDRESS;
    sfr TL0                                 = TL0_BASE_ADDRESS;
    sfr TL1                                 = TL1_BASE_ADDRESS;
    sfr TH0                                 = TH0_BASE_ADDRESS;
    sfr TH1                                 = TH1_BASE_ADDRESS;
    sfr CKCON                               = CKCON_BASE_ADDRESS;
    sfr WKCON                               = WKCON_BASE_ADDRESS;

    sfr P1                                  = P1_BASE_ADDRESS;
    sfr SFRS                                = SFRS_BASE_ADDRESS;    //TA Protection
    sfr CAPCON0                             = CAPCON0_BASE_ADDRESS;
    sfr CAPCON1                             = CAPCON1_BASE_ADDRESS;
    sfr CAPCON2                             = CAPCON2_BASE_ADDRESS;
    sfr CKDIV                               = CKDIV_BASE_ADDRESS;
    sfr CKSWT                               = CKSWT_BASE_ADDRESS;   //TA Protection
    sfr CKEN                                = CKEN_BASE_ADDRESS;    //TA Protection

    sfr SCON                                = SCON_BASE_ADDRESS;
    sfr SBUF                                = SBUF_BASE_ADDRESS;
    sfr SBUF_1                              = SBUF_1_BASE_ADDRESS;
    sfr EIE                                 = EIE_BASE_ADDRESS;
    sfr EIE1                                = EIE1_BASE_ADDRESS;
    sfr CHPCON                              = CHPCON_BASE_ADDRESS;  //TA Protection

    sfr P2                                  = P2_BASE_ADDRESS;
    sfr AUXR1                               = AUXR1_BASE_ADDRESS;
    sfr BODCON0                             = BODCON0_BASE_ADDRESS; //TA Protection
    sfr IAPTRG                              = IAPTRG_BASE_ADDRESS;  //TA Protection
    sfr IAPUEN                              = IAPUEN_BASE_ADDRESS;  //TA Protection
    sfr IAPAL                               = IAPAL_BASE_ADDRESS;
    sfr IAPAH                               = IAPAH_BASE_ADDRESS;

    sfr IE                                  = IE_BASE_ADDRESS;
    sfr SADDR                               = SADDR_BASE_ADDRESS;
    sfr WDCON                               = WDCON_BASE_ADDRESS;   //TA Protection
    sfr BODCON1                             = BODCON1_BASE_ADDRESS; //TA Protection
    sfr P3M1                                = P3M1_BASE_ADDRESS;
    sfr P3S                                 = P3S_BASE_ADDRESS;     //Page1
    sfr P3M2                                = P3M2_BASE_ADDRESS;
    sfr P3SR                                = P3SR_BASE_ADDRESS;    //Page1
    sfr IAPFD                               = IAPFD_BASE_ADDRESS;
    sfr IAPCN                               = IAPCN_BASE_ADDRESS;

    sfr P3                                  = P3_BASE_ADDRESS;
    sfr P0M1                                = P0M1_BASE_ADDRESS;
    sfr P0S                                 = P0S_BASE_ADDRESS;     //Page1
    sfr P0M2                                = P0M2_BASE_ADDRESS;
    sfr P0SR                                = P0SR_BASE_ADDRESS;    //Page1
    sfr P1M1                                = P1M1_BASE_ADDRESS;
    sfr P1S                                 = P1S_BASE_ADDRESS;     //Page1
    sfr P1M2                                = P1M2_BASE_ADDRESS;
    sfr P1SR                                = P1SR_BASE_ADDRESS;    //Page1
    sfr P2S                                 = P2S_BASE_ADDRESS;
    sfr IPH                                 = IPH_BASE_ADDRESS;
    sfr PWMINTC                             = PWMINTC_BASE_ADDRESS; //Page1

    sfr IP                                  = IP_BASE_ADDRESS;
    sfr SADEN                               = SADEN_BASE_ADDRESS;
    sfr SADEN_1                             = SADEN_1_BASE_ADDRESS;
    sfr SADDR_1                             = SADDR_1_BASE_ADDRESS;
    sfr I2DAT                               = I2DAT_BASE_ADDRESS;
    sfr I2STAT                              = I2STAT_BASE_ADDRESS;
    sfr I2CLK                               = I2CLK_BASE_ADDRESS;
    sfr I2TOC                               = I2TOC_BASE_ADDRESS;

    sfr I2CON                               = I2CON_BASE_ADDRESS;
    sfr I2ADDR                              = I2ADDR_BASE_ADDRESS;
    sfr ADCRL                               = ADCRL_BASE_ADDRESS;
    sfr ADCRH                               = ADCRH_BASE_ADDRESS;
    sfr T3CON                               = T3CON_BASE_ADDRESS;
    sfr PWM4H                               = PWM4H_BASE_ADDRESS;   //Page1
    sfr RL3                                 = RL3_BASE_ADDRESS;
    sfr PWM5H                               = PWM5H_BASE_ADDRESS;   //Page1
    sfr RH3                                 = RH3_BASE_ADDRESS;
    sfr PIOCON1                             = PIOCON1_BASE_ADDRESS; //Page1
    sfr TA                                  = TA_BASE_ADDRESS;

    sfr T2CON                               = T2CON_BASE_ADDRESS;
    sfr T2MOD                               = T2MOD_BASE_ADDRESS;
    sfr RCMP2L                              = RCMP2L_BASE_ADDRESS;
    sfr RCMP2H                              = RCMP2H_BASE_ADDRESS;
    sfr TL2                                 = TL2_BASE_ADDRESS;
    sfr PWM4L                               = PWM4L_BASE_ADDRESS;   //Page1
    sfr TH2                                 = TH2_BASE_ADDRESS;
    sfr PWM5L                               = PWM5L_BASE_ADDRESS;   //Page1
    sfr ADCMPL                              = ADCMPL_BASE_ADDRESS;
    sfr ADCMPH                              = ADCMPH_BASE_ADDRESS;

    sfr PSW                                 = PSW_BASE_ADDRESS;
    sfr PWMPH                               = PWMPH_BASE_ADDRESS;
    sfr PWM0H                               = PWM0H_BASE_ADDRESS;
    sfr PWM1H                               = PWM1H_BASE_ADDRESS;
    sfr PWM2H                               = PWM2H_BASE_ADDRESS;
    sfr PWM3H                               = PWM3H_BASE_ADDRESS;
    sfr PNP                                 = PNP_BASE_ADDRESS;
    sfr FBD                                 = FBD_BASE_ADDRESS;

    sfr PWMCON0                             = PWMCON0_BASE_ADDRESS;
    sfr PWMPL                               = PWMPL_BASE_ADDRESS;
    sfr PWM0L                               = PWM0L_BASE_ADDRESS;
    sfr PWM1L                               = PWM1L_BASE_ADDRESS;
    sfr PWM2L                               = PWM2L_BASE_ADDRESS;
    sfr PWM3L                               = PWM3L_BASE_ADDRESS;
    sfr PIOCON0                             = PIOCON0_BASE_ADDRESS;
    sfr PWMCON1                             = PWMCON1_BASE_ADDRESS;

    sfr ACC                                 = ACC_BASE_ADDRESS;
    sfr ADCCON1                             = ADCCON1_BASE_ADDRESS;
    sfr ADCCON2                             = ADCCON2_BASE_ADDRESS;
    sfr ADCDLY                              = ADCDLY_BASE_ADDRESS;
    sfr C0L                                 = C0L_BASE_ADDRESS;
    sfr C0H                                 = C0H_BASE_ADDRESS;
    sfr C1L                                 = C1L_BASE_ADDRESS;
    sfr C1H                                 = C1H_BASE_ADDRESS;

    sfr ADCCON0                             = ADCCON0_BASE_ADDRESS;
    sfr PICON                               = PICON_BASE_ADDRESS;
    sfr PINEN                               = PINEN_BASE_ADDRESS;
    sfr PIPEN                               = PIPEN_BASE_ADDRESS;
    sfr PIF                                 = PIF_BASE_ADDRESS;
    sfr C2L                                 = C2L_BASE_ADDRESS;
    sfr C2H                                 = C2H_BASE_ADDRESS;
    sfr EIP                                 = EIP_BASE_ADDRESS;

    sfr B                                   = B_BASE_ADDRESS;
    sfr CAPCON3                             = CAPCON3_BASE_ADDRESS;
    sfr CAPCON4                             = CAPCON4_BASE_ADDRESS;
    sfr SPCR                                = SPCR_BASE_ADDRESS;
    sfr SPCR2                               = SPCR2_BASE_ADDRESS;   //Page1
    sfr SPSR                                = SPSR_BASE_ADDRESS;
    sfr SPDR                                = SPDR_BASE_ADDRESS;
    sfr AINDIDS                             = AINDIDS_BASE_ADDRESS;
    sfr EIPH                                = EIPH_BASE_ADDRESS;

    sfr SCON_1                              = SCON_1_BASE_ADDRESS;
    sfr PDTEN                               = PDTEN_BASE_ADDRESS;   //TA Protection
    sfr PDTCNT                              = PDTCNT_BASE_ADDRESS;  //TA Protection
    sfr PMEN                                = PMEN_BASE_ADDRESS;
    sfr PMD                                 = PMD_BASE_ADDRESS;
    sfr EIP1                                = EIP1_BASE_ADDRESS;
    sfr EIPH1                               = EIPH1_BASE_ADDRESS;

    /****************** BIT Registers ******************/

    /*  SCON_1  */
    sbit SM0_1                                  = SCON_1 ^ 7;
    sbit FE_1                                   = SCON_1 ^ 7;
    sbit SM1_1                                  = SCON_1 ^ 6;
    sbit SM2_1                                  = SCON_1 ^ 5;
    sbit REN_1                                  = SCON_1 ^ 4;
    sbit TB8_1                                  = SCON_1 ^ 3;
    sbit RB8_1                                  = SCON_1 ^ 2;
    sbit TI_1                                   = SCON_1 ^ 1;
    sbit RI_1                                   = SCON_1 ^ 0;

    /*  ADCCON0  */
    sbit ADCF                                   = ADCCON0 ^ 7;
    sbit ADCS                                   = ADCCON0 ^ 6;
    sbit ETGSEL1                                = ADCCON0 ^ 5;
    sbit ETGSEL0                                = ADCCON0 ^ 4;
    sbit ADCHS3                                 = ADCCON0 ^ 3;
    sbit ADCHS2                                 = ADCCON0 ^ 2;
    sbit ADCHS1                                 = ADCCON0 ^ 1;
    sbit ADCHS0                                 = ADCCON0 ^ 0;

    /*  PWMCON0  */
    sbit PWMRUN                                 = PWMCON0 ^ 7;
    sbit LOAD                                   = PWMCON0 ^ 6;
    sbit PWMF                                   = PWMCON0 ^ 5;
    sbit CLRPWM                                 = PWMCON0 ^ 4;

    /*  PSW */
    sbit CY                                     = PSW ^ 7;
    sbit AC                                     = PSW ^ 6;
    sbit F0                                     = PSW ^ 5;
    sbit RS1                                    = PSW ^ 4;
    sbit RS0                                    = PSW ^ 3;
    sbit OV                                     = PSW ^ 2;
    sbit P                                      = PSW ^ 0;

    /*  T2CON  */
    sbit TF2                                    = T2CON ^ 7;
    sbit TR2                                    = T2CON ^ 2;
    sbit CM_RL2                                 = T2CON ^ 0;

    /*  I2CON  */
    sbit I2CEN                                  = I2CON ^ 6;
    sbit STA                                    = I2CON ^ 5;
    sbit STO                                    = I2CON ^ 4;
    sbit SI                                     = I2CON ^ 3;
    sbit AA                                     = I2CON ^ 2;
    sbit I2CPX                                  = I2CON ^ 0;

    /*  IP  */
    sbit PADC                                   = IP ^ 6;
    sbit PBOD                                   = IP ^ 5;
    sbit PS                                     = IP ^ 4;
    sbit PT1                                    = IP ^ 3;
    sbit PX1                                    = IP ^ 2;
    sbit PT0                                    = IP ^ 1;
    sbit PX0                                    = IP ^ 0;

    /*  P3  */
    sbit P30                                    = P3 ^ 0;

    /*  IE  */
    sbit EA                                     = IE ^ 7;
    sbit EADC                                   = IE ^ 6;
    sbit EBOD                                   = IE ^ 5;
    sbit ES                                     = IE ^ 4;
    sbit ET1                                    = IE ^ 3;
    sbit EX1                                    = IE ^ 2;
    sbit ET0                                    = IE ^ 1;
    sbit EX0                                    = IE ^ 0;

    /*  P2  */
    sbit P20                                    = P2 ^ 0;

    /*  SCON  */
    sbit SM0                                    = SCON ^ 7;
    sbit FE                                     = SCON ^ 7;
    sbit SM1                                    = SCON ^ 6;
    sbit SM2                                    = SCON ^ 5;
    sbit REN                                    = SCON ^ 4;
    sbit TB8                                    = SCON ^ 3;
    sbit RB8                                    = SCON ^ 2;
    sbit TI                                     = SCON ^ 1;
    sbit RI                                     = SCON ^ 0;

    /*  P1  */
    sbit P17                                    = P1 ^ 7;
    sbit P16                                    = P1 ^ 6;
    sbit TXD_1                                  = P1 ^ 6;
    sbit P15                                    = P1 ^ 5;
    sbit P14                                    = P1 ^ 4;
    sbit SDA                                    = P1 ^ 4;
    sbit P13                                    = P1 ^ 3;
    sbit SCL                                    = P1 ^ 3;
    sbit P12                                    = P1 ^ 2;
    sbit P11                                    = P1 ^ 1;
    sbit P10                                    = P1 ^ 0;

    /*  TCON  */
    sbit TF1                                    = TCON ^ 7;
    sbit TR1                                    = TCON ^ 6;
    sbit TF0                                    = TCON ^ 5;
    sbit TR0                                    = TCON ^ 4;
    sbit IE1                                    = TCON ^ 3;
    sbit IT1                                    = TCON ^ 2;
    sbit IE0                                    = TCON ^ 1;
    sbit IT0                                    = TCON ^ 0;

    /*  P0  */
    sbit P07                                    = P0 ^ 7;
    sbit RXD                                    = P0 ^ 7;
    sbit P06                                    = P0 ^ 6;
    sbit TXD                                    = P0 ^ 6;
    sbit P05                                    = P0 ^ 5;
    sbit P04                                    = P0 ^ 4;
    sbit STADC                                  = P0 ^ 4;
    sbit P03                                    = P0 ^ 3;
    sbit P02                                    = P0 ^ 2;
    sbit RXD_1                                  = P0 ^ 2;
    sbit P01                                    = P0 ^ 1;
    sbit MISO                                   = P0 ^ 1;
    sbit P00                                    = P0 ^ 0;
    sbit MOSI                                   = P0 ^ 0;

#endif /* end of compiler select */

/******************************************************************************/
/*                             SFR control section                            */
/******************************************************************************/

#define SFR_STRING(X, Y) X##Y /*!< string connect */

/*----------------------------------------------------------------------------*/
/** @addtogroup Named_Bit_Control
  * @{
  */

/**
  * @brief  using this marco whill set a register named bit to 1
  * @using  SFR_SET_NAMED_BIT([declared sfr name], [declared bit name on this sfr])
  */
#define SFR_SET_NAMED_BIT(SFR_NAME, BIT_NAME) \
    SFR_NAME |= (uint8_t)BIT_NAME

/**
  * @brief  using this marco whill set a register named bit to 0
  * @using  SFR_RESET_NAMED_BIT([declared sfr name], [declared bit name on this sfr])
  */
#define SFR_RESET_NAMED_BIT(SFR_NAME, BIT_NAME) \
    SFR_NAME &= (uint8_t)(~(uint8_t)BIT_NAME)

/**
  * @brief  using this marco whill set a register named bit reverse
  * @using  SFR_REVERSE_NAMED_BIT([declared sfr name], [declared bit name on this sfr])
  */
#define SFR_REVERSE_NAMED_BIT(SFR_NAME, BIT_NAME) \
    SFR_NAME ^= (uint8_t)BIT_NAME

/**
  * @brief  using this marco whill read a register named bit
  * @using  SFR_READ_NAMED_BIT([declared sfr name], [declared bit name on this sfr])
  * @tip    return variable type undefined yet
  */
#define SFR_READ_NAMED_BIT(SFR_NAME, BIT_NAME) \
    (uint8_t)(SFR_NAME & (uint8_t)BIT_NAME)

/**
  * @}
  */

/*----------------------------------------------------------------------------*/
/** @addtogroup Absolute_Bit_Control
  * @{
  */

/**
  * @brief  using this marco whill set a register specific bit to 1
  * @using  SFR_SET_ABS_BIT([declared sfr name], [absolute bit position])
  */
#define SFR_SET_ABS_BIT(SFR_NAME, BIT) \
    SFR_NAME |= (uint8_t)((uint8_t)0x01 << (uint8_t)BIT)

/**
  * @brief  using this marco whill set a register specific bit to 0
  * @using  SFR_RESET_ABS_BIT([declared sfr name], [absolute bit position])
  */
#define SFR_RESET_ABS_BIT(SFR_NAME, BIT) \
    SFR_NAME &= (uint8_t)(~(uint8_t)((uint8_t)0x01 << (uint8_t)BIT))

/**
  * @brief  using this marco whill set a register specific bit reverse
  * @using  SFR_REVERSE_ABS_BIT([declared sfr name], [absolute bit position])
  */
#define SFR_REVERSE_ABS_BIT(SFR_NAME, BIT) \
    SFR_NAME ^= (uint8_t)((uint8_t)0x01 << (uint8_t)BIT)

/**
  * @brief  using this marco whill read a register specific bit
  * @using  SFR_READ_ABS_BIT([declared sfr name], [absolute bit position])
  * @tip    return variable type undefined yet
  */
#define SFR_READ_ABS_BIT(SFR_NAME, BIT) \
    (uint8_t)(SFR_NAME & (uint8_t)((uint8_t)0x01 << (uint8_t)BIT))

/**
  * @}
  */

/*----------------------------------------------------------------------------*/
/** @addtogroup SFR_Byte_Control
  * @{
  */

/**
  * @brief  set a SFR register to specific value
  * @using  SFR_SET_BYTE([declared sfr name], [setting value])
  */
#define SFR_SET_BYTE(SFR_NAME, DATA) \
    SFR_NAME = (uint8_t)DATA

/**
  * @brief  set a SFR register to reset value
  * @using  SFR_RESTORE_BYTE([declared sfr name])
  */
#define SFR_RESTORE_BYTE(SFR_NAME) \
    SFR_NAME = (uint8_t)SFR_STRING(SFR_NAME, _RESET_VALUE)

/**
  * @brief  read a SFR register byte
  * @using  SFR_READ_BYTE([declared sfr name])
  * @tip    return variable type undefined yet
  */
#define SFR_READ_BYTE(SFR_NAME) \
    (uint8_t)(SFR_NAME)

/**
  * @}
  */

/*----------------------------------------------------------------------------*/
/** @addtogroup SFR_Page_Control
  * @{
  */

/**
  * @brief  unlock SFR TA protected
  * @using  SFR_TA_UNLOCK([SFR control function])
  */
#define SFR_TA_UNLOCK(FUNC) \
    TA = (uint8_t)0xAA;     \
    TA = (uint8_t)0x55;     \
    FUNC

/**
  * @brief  change SFR page permanent
  * @using  SFR_PAGE_CHANGE([page number])
  */
#define SFR_PAGE_CHANGE(PAGE) \
    SFR_TA_UNLOCK(SFRS = (uint8_t)PAGE)

/**
  * @brief  change SFR page then change data, when operating over, page number whill turn back
  * @using  SFR_PAGE_WRITE([page number], [SFR control function])
  */
#define SFR_PAGE_WRITE(PAGE, FUNC)  \
    SFR_PAGE_CHANGE((uint8_t)PAGE); \
    FUNC;                           \
    SFR_PAGE_CHANGE((uint8_t)(~(uint8_t)PAGE))

/**
  * @}
  */

#endif /* __N76E003_H */