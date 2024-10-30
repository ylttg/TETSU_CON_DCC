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
* File Name    : r_cg_cgc.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for CGC module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_CGC_Create
* Description  : This function initializes the clock generator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_CGC_Create(void)
{
    volatile uint32_t w_count;

    /* Set fMX */
    CMC = _00_CGC_HISYS_PORT | _00_CGC_SYSOSC_UNDER10M;
    MSTOP = 1U;     /* X1 oscillator/external clock stopped */
    /* Set fIM */
    MIOEN = 0U;     /* middle-speed on-chip oscillator stopped */
    /* Set fIL */
    SELLOSC = 1U;   /* select fIL as fSUB */

    /* Change the waiting time according to the system */
    for (w_count = 0U; w_count <= CGC_FILWAITTIME; w_count++)
    {
        NOP();
    }

    OSMC = _10_CGC_IT_CLK_FIL;
    /* Set fCLK */
    CSS = 0U;       /* main system clock (fMAIN) */
    /* Set fMAIN */
    MCM0 = 0U;      /* selects fOCO as the main system clock (fMAIN) */
    /* Set fMAIN control */
    MCM1 = 0U;      /* high-speed on-chip oscillator clock */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
