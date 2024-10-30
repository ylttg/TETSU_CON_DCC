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
* File Name    : r_cg_it8bit.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for IT8Bit module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_it8bit.h"
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
* Function Name: R_IT8Bit0_Channel0_Create
* Description  : This function initializes the 8 bit interval timer unit0 channel0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT8Bit0_Channel0_Create(void)
{
    TRTCR0 |= _10_IT8BIT_CLOCK_SUPPLY;
    TSTART00 = 0U;  /* counting stops */
    ITMK00 = 1U;    /* disable INTIT00 interrupt */
    ITIF00 = 0U;    /* clear INTIT00 interrupt flag */
    /* Set INTIT00 low priority */
    ITPR100 = 1U;
    ITPR000 = 1U;
    TRTCR0 |= _00_IT8BIT_8BIT_COUNT_MODE;
    TRTMD0 |= _00_IT8BIT_CLOCK0_1;
    TRTCMP00 = _0E_IT8BIT_CMP00_VALUE;
}
/***********************************************************************************************************************
* Function Name: R_IT8Bit0_Channel0_Start
* Description  : This function starts 8 bit interval timer unit0 Channel0 operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT8Bit0_Channel0_Start(void)
{
    ITIF00 = 0U;    /* clear INTIT00 interrupt flag */
    ITMK00 = 0U;    /* enable INTIT00 interrupt */
    TSTART00 = 1U;  /* counting starts */
}
/***********************************************************************************************************************
* Function Name: R_IT8Bit0_Channel0_Stop
* Description  : This function stops 8 bit interval timer unit0 Channel0 operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT8Bit0_Channel0_Stop(void)
{
    ITMK00 = 1U;    /* disable INTIT00 interrupt */
    ITIF00 = 0U;    /* clear INTIT00 interrupt flag */
    TSTART00 = 0U;  /* counting stops */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
