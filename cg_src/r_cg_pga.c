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
* File Name    : r_cg_pga.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for PGA module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_pga.h"
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
* Function Name: R_PGA_Create
* Description  : This function initializes the programmable gain amplifier module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGA_Create(void)
{
    PGA0RES = 1U;   /* reset PGA */
    PGA0RES = 0U;   /* reset release of PGA */
    PGA0EN = 1U;    /* enables input clock supply */
    PGAEN = 0U;     /* PGA operation stopped */
    PGACTL = _00_PGA_VSS_SELECTED | _03_PGA_AMPLIFICATION_X32;
    /* Set PGAI pin */
    PMC2 |= 0x04U;
    PM2 |= 0x04U;
}
/***********************************************************************************************************************
* Function Name: R_PGA_Start
* Description  : This function starts the programmable gain amplifier.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGA_Start(void)
{
    PGAEN = 1U;     /* PGA operation enabled */
}
/***********************************************************************************************************************
* Function Name: R_PGA_Stop
* Description  : This function stops the programmable gain amplifier.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGA_Stop(void)
{
    PGAEN = 0U;     /* PGA operation stopped */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
