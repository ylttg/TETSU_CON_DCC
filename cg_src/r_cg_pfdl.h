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
* Copyright (C) 2016, 2019 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_pfdl.h
* Version      : Code Generator for RL78/G11 V1.02.03.02 [20 Nov 2019]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for PFDL module.
* Creation Date: 2022/09/07
***********************************************************************************************************************/
#ifndef PFDL_H
#define PFDL_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/*
*******************************************************************************
**  Include files
*******************************************************************************
*/
#include "pfdl.h"            /* library header file */
#include "pfdl_types.h"      /* library header file */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _48_HOCO_CLOCK_MHz             (48)  /* HOCO clock value in MHz */
#define _FULL_SPEED_MODE               (0)   /* Flash Programming Mode is Full Speed */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_FDL_Create(void);
pfdl_status_t R_FDL_Write(pfdl_u16 index, __near pfdl_u08* buffer, pfdl_u16 bytecount);
pfdl_status_t R_FDL_Read(pfdl_u16 index, __near pfdl_u08* buffer, pfdl_u16 bytecount);
pfdl_status_t R_FDL_Erase(pfdl_u16 blockno);
void R_FDL_Open(void);
void R_FDL_Close(void);
pfdl_status_t R_FDL_BlankCheck(pfdl_u16 index, pfdl_u16 bytecount);
pfdl_status_t R_FDL_IVerify(pfdl_u16 index, pfdl_u16 bytecount);

#endif
