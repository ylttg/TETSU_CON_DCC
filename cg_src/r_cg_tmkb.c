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
* File Name    : r_cg_tmkb.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for TMKB module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_tmkb.h"
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
* Function Name: R_TMR_KB_Create
* Description  : This function initializes the TMKB module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB_Create(void)
{
    TKB0RES = 1U;   /* reset TMKB0 */
    TKB0RES = 0U;   /* reset release of TMKB0 */
    TKB0EN = 1U;    /* enables input clock supply */
    TPS2 = _00_TMKB_CK21_FCLK_0 | _00_TMKB_CK20_FCLK_0;
    TMKBMK0 = 1U;   /* disable INTTMKB0 interrupt */
    TMKBIF0 = 0U;   /* clear INTTMKB0 interrupt flag */
    /* Set INTTMKB0 low priority */
    TMKBPR10 = 1U;
    TMKBPR00 = 1U;
    TKBCTL01 = _00_TMKB_CK20_SELECTED | _00_TMKB_STANDALONE_MASTER;
    TKBCTL00 = _0000_TMKB_SMOOTH_START1_DISABLE | _0000_TMKB_DITHERING1_DISABLE | 
               _0000_TMKB_SMOOTH_START0_DISABLE | _0000_TMKB_DITHERING0_DISABLE | _0000_TMKB_MAXFREQ_DISABLE | 
               _0000_TMKB_TRIGGER_DISABLED;
    TKBIOC00 = _00_TMKB_OUTPUT1_ACTIVE_HIGH | _00_TMKB_OUTPUT0_ACTIVE_HIGH | _00_TMKB_OUTPUT1_DEFAULT_LOW | 
               _00_TMKB_OUTPUT0_DEFAULT_LOW;
    TKBCR00 = _01DF_TMKB_CYCLE00_VALUE;
    TKBCR01 = _0000_TMKB_DUTY01_VALUE;
    TKBCR02 = _0000_TMKB_DUTY02_VALUE;
    TKBCR03 = _0000_TMKB_DUTY03_VALUE;
    TKBTGCR0 = _12C0_TMKB_TKBTGCR0_VALUE;
    TKBPACTL00 = _0000_TMKB_FUNCTION2_INTP11_DISABLE | _0000_TMKB_FUNCTION2_INTP10_DISABLE | 
                 _0000_TMKB_FUNCTION2_COMP1_DISABLE | _0000_TMKB_FUNCTION2_COMP0_DISABLE | 
                 _0000_TMKB_FUNCTION1_COMP1_DISABLE | _0010_TMKB_FUNCTION1_COMP0_ENABLE | 
                 _000C_TMKB_FORCED_FUNCTION1_TYPE4 | _0002_TMKB_FORCED_LOW_LOW;
    TKBPACTL01 = _0000_TMKB_FUNCTION2_INTP11_DISABLE | _0000_TMKB_FUNCTION2_INTP10_DISABLE | 
                 _0000_TMKB_FUNCTION2_COMP1_DISABLE | _0000_TMKB_FUNCTION2_COMP0_DISABLE | 
                 _0000_TMKB_FUNCTION1_COMP1_DISABLE | _0010_TMKB_FUNCTION1_COMP0_ENABLE | 
                 _000C_TMKB_FORCED_FUNCTION1_TYPE4 | _0002_TMKB_FORCED_LOW_LOW;
    TKBPACTL02 = _02_TMKB_FORCED_STOP_PIN1_ENABLED | _01_TMKB_FORCED_STOP_PIN0_ENABLED;
    /* Set TKBO0 pin */
    POM3 &= 0xFDU;
    PMC3 &= 0xFDU;
    P3 &= 0xFDU;
    PM3 &= 0xFDU;
    /* Set TKBO1 pin */
    POM3 &= 0xFEU;
    PMC3 &= 0xFEU;
    P3 &= 0xFEU;
    PM3 &= 0xFEU;
}

/***********************************************************************************************************************
* Function Name: R_TMR_KB0_Start
* Description  : This function starts the TMKB0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB0_Start(void)
{
    TMKBIF0 = 0U;   /* clear INTTMKB0 interrupt flag */
    TMKBMK0 = 0U;   /* enable INTTMKB0 interrupt */
    TKBIOC01 = _02_TMKB_PIN1_OUTPUT_ENABLED | _01_TMKB_PIN0_OUTPUT_ENABLED;
    TKBCE0 = 1U;    /* enables timer count operation */
}
/***********************************************************************************************************************
* Function Name: R_TMR_KB0_Stop
* Description  : This function stops the TMKB0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB0_Stop(void)
{
    TKBCE0 = 0U;    /* stops timer operation */
    TMKBMK0 = 1U;   /* disable INTTMKB0 interrupt */
    TMKBIF0 = 0U;   /* clear INTTMKB0 interrupt flag */
    TKBIOC01 = _00_TMKB_PIN1_OUTPUT_DISABLED | _00_TMKB_PIN0_OUTPUT_DISABLED;
}
/***********************************************************************************************************************
* Function Name: R_TMR_KB0_ForcedOutput_00_Start
* Description  : This function starts forced output stop feature of TKBO0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB0_ForcedOutput_00_Start(void)
{
    TKBPAHTS00 = 1U;/* starts forced output stop function 1 for TKBO0 output */
}
/***********************************************************************************************************************
* Function Name: R_TMR_KB0_ForcedOutput_00_Stop
* Description  : This function stops forced output stop feature of TKBO0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB0_ForcedOutput_00_Stop(void)
{
    TKBPAHTT00 = 1U;/* stops forced output stop function 1 for TKBO0 output */
}
/***********************************************************************************************************************
* Function Name: R_TMR_KB0_ForcedOutput_01_Start
* Description  : This function starts forced output stop feature of TKBO1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB0_ForcedOutput_01_Start(void)
{
    TKBPAHTS01 = 1U;/* starts forced output stop function 1 for TKBO1 output */
}
/***********************************************************************************************************************
* Function Name: R_TMR_KB0_ForcedOutput_01_Stop
* Description  : This function stops forced output stop feature of TKBO1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_TMR_KB0_ForcedOutput_01_Stop(void)
{
    TKBPAHTT01 = 1U;/* stops forced output stop function 1 for TKBO0 output */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
