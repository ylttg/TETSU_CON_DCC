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
* File Name    : r_cg_port.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for Port module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
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
* Function Name: R_PORT_Create
* Description  : This function initializes the Port I/O.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PORT_Create(void)
{
    PMC0 = _FC_PMC0_DEFAULT_VALUE | _02_PMCn1_DI_ON | _00_PMCn0_NOT_USE;
    PMC2 = _F0_PMC2_DEFAULT_VALUE | _08_PMCn3_DI_ON | _04_PMCn2_DI_ON | _00_PMCn1_NOT_USE | _00_PMCn0_NOT_USE;
    PMC3 = _F4_PMC3_DEFAULT_VALUE | _00_PMCn3_NOT_USE | _02_PMCn1_DI_ON | _01_PMCn0_DI_ON;
    PMC5 = _BF_PMC5_DEFAULT_VALUE | _40_PMCn6_DI_ON;
    P0 = _00_Pn1_OUTPUT_0 | _01_Pn0_OUTPUT_1;
    P2 = _00_Pn3_OUTPUT_0 | _00_Pn2_OUTPUT_0 | _02_Pn1_OUTPUT_1 | _01_Pn0_OUTPUT_1;
    P5 = _00_Pn6_OUTPUT_0 | _00_Pn5_OUTPUT_0 | _00_Pn4_OUTPUT_0;
    PU3 = _08_PUn3_PULLUP_ON | _00_PUn1_PULLUP_OFF | _00_PUn0_PULLUP_OFF;
    PIM3 = _00_PIMn1_TTL_OFF | _00_PIMn0_TTL_OFF;
    POM0 = _00_POMn1_NCH_OFF | _00_POMn0_NCH_OFF;
    POM5 = _00_POMn6_NCH_OFF | _00_POMn5_NCH_OFF | _00_POMn4_NCH_OFF;
    PM0 = _FC_PM0_DEFAULT_VALUE | _02_PMn1_MODE_INPUT | _00_PMn0_MODE_OUTPUT;
    PM2 = _F0_PM2_DEFAULT_VALUE | _08_PMn3_MODE_INPUT | _04_PMn2_MODE_INPUT | _00_PMn1_MODE_OUTPUT | 
          _00_PMn0_MODE_OUTPUT;
    PM3 = _F4_PM3_DEFAULT_VALUE | _08_PMn3_MODE_INPUT | _02_PMn1_MODE_INPUT | _01_PMn0_MODE_INPUT;
    PM5 = _8F_PM5_DEFAULT_VALUE | _40_PMn6_MODE_INPUT | _00_PMn5_MODE_OUTPUT | _00_PMn4_MODE_OUTPUT;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
