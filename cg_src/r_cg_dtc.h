/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016, 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_dtc.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for DTC module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/
#ifndef DTC_H
#define DTC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    DTC control register n (DTCCRn) 
*/
/* Transfer data size selection (SZ) */
#define _00_DTC_DATA_SIZE_8BITS                    (0x00U) /* 8 bits */
#define _40_DTC_DATA_SIZE_16BITS                   (0x40U) /* 16 bits */
/* Enabling/disabling repeat mode interrupts (RPTINT) */
#define _00_DTC_REPEAT_INT_DISABLE                 (0x00U) /* interrupt generation disabled */
#define _20_DTC_REPEAT_INT_ENABLE                  (0x20U) /* interrupt generation enabled */
/* Enabling/disabling chain transfers (CHNE) */
#define _00_DTC_CHAIN_TRANSFER_DISABLE             (0x00U) /* chain transfers disabled */
#define _10_DTC_CHAIN_TRANSFER_ENABLE              (0x10U) /* chain transfers enabled */
/* Transfer destination address control (DAMOD) */
#define _00_DTC_DEST_ADDR_FIXED                    (0x00U) /* fixed */
#define _08_DTC_DEST_ADDR_INCREMENTED              (0x08U) /* incremented */
/* Transfer source address control (SAMOD) */
#define _00_DTC_SOURCE_ADDR_FIXED                  (0x00U) /* fixed */
#define _04_DTC_SOURCE_ADDR_INCREMENTED            (0x04U) /* incremented */
/* Repeat area selection (RPTSEL) */
#define _00_DTC_REPEAT_AREA_DEST                   (0x00U) /* transfer destination is the repeat area */
#define _02_DTC_REPEAT_AREA_SOURCE                 (0x02U) /* transfer source is the repeat area */
/* Transfer mode selection (MODE) */
#define _00_DTC_TRANSFER_MODE_NORMAL               (0x00U) /* normal mode */
#define _01_DTC_TRANSFER_MODE_REPEAT               (0x01U) /* repeat mode */

/*
    DTC activation enable register 0 (DTCEN0) 
*/
/* DTC activation enable 06 (DTCEN06) */
#define _00_DTC_INTP0_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP0) */
#define _40_DTC_INTP0_ACTIVATION_ENABLE            (0x40U) /* activation enabled (INTP0) */
/* DTC activation enable 05 (DTCEN05) */
#define _00_DTC_INTP1_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP1) */
#define _20_DTC_INTP1_ACTIVATION_ENABLE            (0x20U) /* activation enabled (INTP1) */
/* DTC activation enable 04 (DTCEN04) */
#define _00_DTC_INTP2_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP2) */
#define _10_DTC_INTP2_ACTIVATION_ENABLE            (0x10U) /* activation enabled (INTP2) */
/* DTC activation enable 03 (DTCEN03) */
#define _00_DTC_INTP3_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP3) */
#define _08_DTC_INTP3_ACTIVATION_ENABLE            (0x08U) /* activation enabled (INTP3) */
/* DTC activation enable 02 (DTCEN02) */
#define _00_DTC_INTP4_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP4) */
#define _04_DTC_INTP4_ACTIVATION_ENABLE            (0x04U) /* activation enabled (INTP4) */
/* DTC activation enable 01 (DTCEN01) */
#define _00_DTC_INTP5_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP5) */
#define _02_DTC_INTP5_ACTIVATION_ENABLE            (0x02U) /* activation enabled (INTP5) */
/* DTC activation enable 00 (DTCEN00) */
#define _00_DTC_INTP6_ACTIVATION_DISABLE           (0x00U) /* activation disabled (INTP6) */
#define _01_DTC_INTP6_ACTIVATION_ENABLE            (0x01U) /* activation enabled (INTP6) */

/*
    DTC activation enable register 1 (DTCEN1) 
*/
/* DTC activation enable 17 (DTCEN17) */
#define _00_DTC_KEY_ACTIVATION_DISABLE             (0x00U) /* activation disabled (KEY) */
#define _80_DTC_KEY_ACTIVATION_ENABLE              (0x80U) /* activation enabled (KEY) */
/* DTC activation enable 16 (DTCEN16) */
#define _00_DTC_AD_ACTIVATION_DISABLE              (0x00U) /* activation disabled (AD) */
#define _40_DTC_AD_ACTIVATION_ENABLE               (0x40U) /* activation enabled (AD) */
/* DTC activation enable 15 (DTCEN15) */
#define _00_DTC_UART0R_ACTIVATION_DISABLE          (0x00U) /* activation disabled (UART0R) */
#define _20_DTC_UART0R_ACTIVATION_ENABLE           (0x20U) /* activation enabled (UART0R) */
/* DTC activation enable 14 (DTCEN14) */
#define _00_DTC_UART0T_ACTIVATION_DISABLE          (0x00U) /* activation disabled (UART0T) */
#define _10_DTC_UART0T_ACTIVATION_ENABLE           (0x10U) /* activation enabled (UART0T) */
/* DTC activation enable 13 (DTCEN13) */
#define _00_DTC_UART1R_ACTIVATION_DISABLE          (0x00U) /* activation disabled (UART1R) */
#define _08_DTC_UART1R_ACTIVATION_ENABLE           (0x08U) /* activation enabled (UART1R) */
/* DTC activation enable 12 (DTCEN12) */
#define _00_DTC_UART1T_ACTIVATION_DISABLE          (0x00U) /* activation disabled (UART1T) */
#define _04_DTC_UART1T_ACTIVATION_ENABLE           (0x04U) /* activation enabled (UART1T) */
/* DTC activation enable 11 (DTCEN11) */
#define _00_DTC_TAU00_ACTIVATION_DISABLE           (0x00U) /* activation disabled (TAU00) */
#define _02_DTC_TAU00_ACTIVATION_ENABLE            (0x02U) /* activation enabled (TAU00) */
/* DTC activation enable 10 (DTCEN10) */
#define _00_DTC_TAU01_ACTIVATION_DISABLE           (0x00U) /* activation disabled (TAU01) */
#define _01_DTC_TAU01_ACTIVATION_ENABLE            (0x01U) /* activation enabled (TAU01) */

/*
    DTC activation enable register 2 (DTCEN2) 
*/
/* DTC activation enable 27 (DTCEN27) */
#define _00_DTC_TAU02_ACTIVATION_DISABLE           (0x00U) /* activation disabled (TAU02) */
#define _80_DTC_TAU02_ACTIVATION_ENABLE            (0x80U) /* activation enabled (TAU02) */
/* DTC activation enable 26 (DTCEN26) */
#define _00_DTC_TAU03_ACTIVATION_DISABLE           (0x00U) /* activation disabled (TAU03) */
#define _40_DTC_TAU03_ACTIVATION_ENABLE            (0x40U) /* activation enabled (TAU03) */
/* DTC activation enable 25 (DTCEN25) */
#define _00_DTC_12BIT_ACTIVATION_DISABLE           (0x00U) /* activation disabled (12BIT) */
#define _20_DTC_12BIT_ACTIVATION_ENABLE            (0x20U) /* activation enabled (12BIT) */
/* DTC activation enable 24 (DTCEN24) */
#define _00_DTC_8BIT00_ACTIVATION_DISABLE          (0x00U) /* activation disabled (8BIT00) */
#define _10_DTC_8BIT00_ACTIVATION_ENABLE           (0x10U) /* activation enabled (8BIT00) */
/* DTC activation enable 23 (DTCEN23) */
#define _00_DTC_8BIT01_ACTIVATION_DISABLE          (0x00U) /* activation disabled (8BIT01) */
#define _08_DTC_8BIT01_ACTIVATION_ENABLE           (0x08U) /* activation enabled (8BIT01) */
/* DTC activation enable 22 (DTCEN22) */
#define _00_DTC_TMKB_ACTIVATION_DISABLE            (0x00U) /* activation disabled (TMKB) */
#define _04_DTC_TMKB_ACTIVATION_ENABLE             (0x04U) /* activation enabled (TMKB) */
/* DTC activation enable 21 (DTCEN21) */
#define _00_DTC_CMP0_ACTIVATION_DISABLE            (0x00U) /* activation disabled (CMP0) */
#define _02_DTC_CMP0_ACTIVATION_ENABLE             (0x02U) /* activation enabled (CMP0) */
/* DTC activation enable 20 (DTCEN20) */
#define _00_DTC_CMP1_ACTIVATION_DISABLE            (0x00U) /* activation disabled (CMP1) */
#define _01_DTC_CMP1_ACTIVATION_ENABLE             (0x01U) /* activation enabled (CMP1) */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _01_DTCD0_TRANSFER_BLOCKSIZE               (0x01U) /* transfer block size */
#define _01_DTCD1_TRANSFER_BLOCKSIZE               (0x01U) /* transfer block size */
#define _01_DTCD2_TRANSFER_BLOCKSIZE               (0x01U) /* transfer block size */
#define _01_DTCD3_TRANSFER_BLOCKSIZE               (0x01U) /* transfer block size */
#define _01_DTCD4_TRANSFER_BLOCKSIZE               (0x01U) /* transfer block size */
#define _F0_DTCD0_TRANSFER_BYTE                    (0xF0U) /* number of transfers */
#define _F0_DTCD1_TRANSFER_BYTE                    (0xF0U) /* number of transfers */
#define _F0_DTCD2_TRANSFER_BYTE                    (0xF0U) /* number of transfers */
#define _F0_DTCD3_TRANSFER_BYTE                    (0xF0U) /* number of transfers */
#define _F0_DTCD4_TRANSFER_BYTE                    (0xF0U) /* number of transfers */
#define _FB00_DTCD0_SRC_ADDRESS                    (0xFB00U) 
#define _FC00_DTCD1_SRC_ADDRESS                    (0xFC00U) 
#define _FC00_DTCD2_SRC_ADDRESS                    (0xFC00U) 
#define _FB00_DTCD3_SRC_ADDRESS                    (0xFB00U) 
#define _FCF0_DTCD4_SRC_ADDRESS                    (0xFCF0U) 
#define _0400_DTCD0_DEST_ADDRESS                   (0x0400U) 
#define _0402_DTCD1_DEST_ADDRESS                   (0x0402U) 
#define _0404_DTCD2_DEST_ADDRESS                   (0x0404U) 
#define _0406_DTCD3_DEST_ADDRESS                   (0x0406U) 
#define _0412_DTCD4_DEST_ADDRESS                   (0x0412U) 

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct
{
    uint8_t  dtccr;
    uint8_t  dtbls;
    uint8_t  dtcct;
    uint8_t  dtrld;
    uint16_t dtsar;
    uint16_t dtdar;
}st_dtc_data_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_DTC_Create(void);
void R_DTCD0_Start(void);
void R_DTCD0_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
