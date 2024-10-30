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
* File Name    : r_cg_it8bit.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for IT8Bit module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/
#ifndef IT8BIT_H
#define IT8BIT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    8-bit interval timer control register n (TRTCRn) 
*/
/* Mode select (TCSMDn) */
#define _00_IT8BIT_8BIT_COUNT_MODE           (0x00U) /* operates as 8-bit counter */
#define _80_IT8BIT_16BIT_COUNT_MODE          (0x80U) /* operates as 16-bit counter */
/* 8-bit interval timer clock enable (TCLKENn) */
#define _00_IT8BIT_CLOCK_STOP                (0x00U) /* clock operation stopped */
#define _10_IT8BIT_CLOCK_SUPPLY              (0x10U) /* clock operation supplied */
/* 8-bit interval timer 1 count start (TSTARTn1) */
#define _00_IT8BIT_COUNT1_STOP               (0x00U) /* counting stops */
#define _04_IT8BIT_COUNT1_START              (0x04U) /* counting starts */
/* 8-bit interval timer 0 count start (TSTARTn0) */
#define _00_IT8BIT_COUNT0_STOP               (0x00U) /* counting stops */
#define _01_IT8BIT_COUNT0_START              (0x01U) /* counting starts */

/*
    8-bit interval timer division register n (TRTMDn) 
*/
/* 8-bit interval timer 1 division select (TCKn1) */
#define _00_IT8BIT_CLOCK1_1                  (0x00U) /* fIL */
#define _10_IT8BIT_CLOCK1_2                  (0x10U) /* fIL/2 */
#define _20_IT8BIT_CLOCK1_4                  (0x20U) /* fIL/4 */
#define _30_IT8BIT_CLOCK1_8                  (0x30U) /* fIL/8 */
#define _40_IT8BIT_CLOCK1_16                 (0x40U) /* fIL/16 */
#define _50_IT8BIT_CLOCK1_32                 (0x50U) /* fIL/32 */
#define _60_IT8BIT_CLOCK1_64                 (0x60U) /* fIL/64 */
#define _70_IT8BIT_CLOCK1_128                (0x70U) /* fIL/128 */
/* 8-bit interval timer 0 division select (TCKn0) */
#define _00_IT8BIT_CLOCK0_1                  (0x00U) /* fIL */
#define _01_IT8BIT_CLOCK0_2                  (0x01U) /* fIL/2 */
#define _02_IT8BIT_CLOCK0_4                  (0x02U) /* fIL/4 */
#define _03_IT8BIT_CLOCK0_8                  (0x03U) /* fIL/8 */
#define _04_IT8BIT_CLOCK0_16                 (0x04U) /* fIL/16 */
#define _05_IT8BIT_CLOCK0_32                 (0x05U) /* fIL/32 */
#define _06_IT8BIT_CLOCK0_64                 (0x06U) /* fIL/64 */
#define _07_IT8BIT_CLOCK0_128                (0x07U) /* fIL/128 */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0E_IT8BIT_CMP00_VALUE               (0x0EU) /* 8-bit interval timer compare register 00 */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_IT8Bit0_Channel0_Create(void);
void R_IT8Bit0_Channel0_Start(void);
void R_IT8Bit0_Channel0_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
