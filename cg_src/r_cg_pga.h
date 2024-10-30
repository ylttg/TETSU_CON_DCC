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
* File Name    : r_cg_pga.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for PGA module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/
#ifndef PGA_H
#define PGA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    PGA control register (PGACTL) 
*/
/* PGA operation selection (PGAEN) */
#define _00_PGA_OPERATION_STOP             (0x00U) /* PGA operation stopped */
#define _80_PGA_OPERATION_ENABLE           (0x80U) /* PGA operation enabled */
/* GND selection of feedback resistance of the programmable gain amplifier (PVRVS) */
#define _00_PGA_VSS_SELECTED               (0x00U) /* selects VSS */
#define _08_PGA_PGAGND_SELECTED            (0x08U) /* selects PGAGND */
/* Selected PGA amplification (PGAVG1,PGAVG0) */
#define _00_PGA_AMPLIFICATION_X4           (0x00U) /* *4 is selected as the gain */
#define _01_PGA_AMPLIFICATION_X8           (0x01U) /* *8 is selected as the gain */
#define _02_PGA_AMPLIFICATION_X16          (0x02U) /* *16 is selected as the gain */
#define _03_PGA_AMPLIFICATION_X32          (0x03U) /* *32 is selected as the gain */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/


/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_PGA_Create(void);
void R_PGA_Start(void);
void R_PGA_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
