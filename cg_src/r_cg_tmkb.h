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
* File Name    : r_cg_tmkb.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for TMKB module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/
#ifndef TMKB_H
#define TMKB_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Timer clock select register 2 (TPS2) 
*/
/* Operating clock for CK20 (TPS202 - TPS200) */
#define _00_TMKB_CK20_FCLK_0                        (0x00U) /* fCLK */
#define _01_TMKB_CK20_FCLK_1                        (0x01U) /* fCLK/2^1 */
#define _02_TMKB_CK20_FCLK_2                        (0x02U) /* fCLK/2^2 */
#define _03_TMKB_CK20_FCLK_3                        (0x03U) /* fCLK/2^3 */
#define _04_TMKB_CK20_FCLK_4                        (0x04U) /* fCLK/2^4 */
#define _05_TMKB_CK20_FCLK_5                        (0x05U) /* fCLK/2^5 */
/* Operating clock for CK21 (TPS212 - TPS210) */
#define _00_TMKB_CK21_FCLK_0                        (0x00U) /* fCLK */
#define _10_TMKB_CK21_FCLK_1                        (0x10U) /* fCLK/2^1 */
#define _20_TMKB_CK21_FCLK_2                        (0x20U) /* fCLK/2^2 */
#define _30_TMKB_CK21_FCLK_3                        (0x30U) /* fCLK/2^3 */
#define _40_TMKB_CK21_FCLK_4                        (0x40U) /* fCLK/2^4 */
#define _50_TMKB_CK21_FCLK_5                        (0x50U) /* fCLK/2^5 */

/*
    16-bit timer KB operation control register 00 (TKBCTL00) 
*/
/* Selection of timer KB0 count start trigger (TKBSTS01,TKBSTS00) */
#define _0000_TMKB_TRIGGER_DISABLED                 (0x0000U) /* does not use trigger input */
#define _0001_TMKB_TRIGGER_INTP10                   (0x0001U) /* external interrupt signal (INTP10) */
#define _0002_TMKB_TRIGGER_INTP11                   (0x0002U) /* external interrupt signal (INTP11) */
#define _0003_TMKB_TRIGGER_COMPARATOR               (0x0003U) /* comparator detection specified by CTRGSELx */
/* Control of compare register batch overwrite function set by external trigger (TKBTSE0) */
#define _0000_TMKB_BATCH_OVERWRITE_DISABLE          (0x0000U) /* not use compare register set */
#define _0004_TMKB_BATCH_OVERWRITE_ENABLE           (0x0004U) /* use compare register set */
/* TKBO1 judgment range setting for interleave PFC output mode (TKBISR01,TKBISR00) */
#define _0000_TMKB_RANGE_T64                        (0x0000U) /* T/2 to T/2+T/64 */
#define _0010_TMKB_RANGE_T32                        (0x0010U) /* T/2 to T/2+T/32 */
#define _0020_TMKB_RANGE_T16                        (0x0020U) /* T/2 to T/2+T/16 */
#define _0030_TMKB_RANGE_T8                         (0x0030U) /* T/2 to T/2+T/8 */
/* Control of TKBO0 and TKBO1 maximum frequency limit function (TKBMFE0) */
#define _0000_TMKB_MAXFREQ_DISABLE                  (0x0000U) /* not use the maximum frequency limit function */
#define _0080_TMKB_MAXFREQ_ENABLE                   (0x0080U) /* use the maximum frequency limit function */
/* Control of TKBO0 PWM output dithering function (TKBDIE00) */
#define _0000_TMKB_DITHERING0_DISABLE               (0x0000U) /* does not use PWM output dithering function */
#define _0100_TMKB_DITHERING0_ENABLE                (0x0100U) /* use PWM output dithering function */
/* Control of TKBO0 PWM output smooth start function (TKBSSE00) */
#define _0000_TMKB_SMOOTH_START0_DISABLE            (0x0000U) /* does not use PWM output smooth start function */
#define _0200_TMKB_SMOOTH_START0_ENABLE             (0x0200U) /* use PWM output smooth start function */
/* Control of TKBO1 PWM output dithering function (TKBDIE01) */
#define _0000_TMKB_DITHERING1_DISABLE               (0x0000U) /* does not use PWM output dithering function */
#define _1000_TMKB_DITHERING1_ENABLE                (0x1000U) /* use PWM output dithering function */
/* Control of TKBO1 PWM output smooth start function (TKBSSE01) */
#define _0000_TMKB_SMOOTH_START1_DISABLE            (0x0000U) /* does not use PWM output smooth start function */
#define _2000_TMKB_SMOOTH_START1_ENABLE             (0x2000U) /* use PWM output smooth start function */

/*
    16-bit timer KB operation control register 01 (TKBCTL01) 
*/
/* Timer KB0 operation mode selection (TKBMD01,TKBMD00) */
#define _00_TMKB_STANDALONE_MASTER                  (0x00U) /* Standalone mode */
#define _03_TMKB_INTERLEAVE_PFC_OUTPUT              (0x03U) /* Interleave PFC output mode */
/* Timer KB0 clock selection (TKBCKS0) */
#define _00_TMKB_CK20_SELECTED                      (0x00U) /* ck20 clock selected by TPS202 to TPS200 bits */
#define _10_TMKB_CK21_SELECTED                      (0x10U) /* ck21 clock selected by TPS212 to TPS210 bits */
/* Timer KB0 operation control (TKBCE0) */
#define _00_TMKB_OPERATION_DISABLED                 (0x00U) /* stops timer operation */
#define _80_TMKB_OPERATION_ENABLED                  (0x80U) /* enables timer count operation */

/*
    16-bit timer KB operation control register 00 (TKBIOC00) 
*/
/* Default level setting of timer output TKBO0 (TKBTOD00) */
#define _00_TMKB_OUTPUT0_DEFAULT_LOW                (0x00U) /* low level */
#define _01_TMKB_OUTPUT0_DEFAULT_HIGH               (0x01U) /* high level */
/* Default level setting of timer output TKBO1 (TKBTOD01) */
#define _00_TMKB_OUTPUT1_DEFAULT_LOW                (0x00U) /* low level */
#define _02_TMKB_OUTPUT1_DEFAULT_HIGH               (0x02U) /* high level */
/* Active level setting of timer output TKBO0 (TKBTOL00) */
#define _00_TMKB_OUTPUT0_ACTIVE_HIGH                (0x00U) /* high level */
#define _04_TMKB_OUTPUT0_ACTIVE_LOW                 (0x04U) /* low level */
/* Active level setting of timer output TKBO1 (TKBTOL01) */
#define _00_TMKB_OUTPUT1_ACTIVE_HIGH                (0x00U) /* high level */
#define _08_TMKB_OUTPUT1_ACTIVE_LOW                 (0x08U) /* low level */

/*
    16-bit timer KB output control register 01 (TKBIOC01) 
*/
/* Timer output TKBO0 output selection (TKBTOE00) */
#define _00_TMKB_PIN0_OUTPUT_DISABLED               (0x00U) /* disables timer output */
#define _01_TMKB_PIN0_OUTPUT_ENABLED                (0x01U) /* enables timer output */
/* Timer output TKBO1 output selection (TKBTOE01) */
#define _00_TMKB_PIN1_OUTPUT_DISABLED               (0x00U) /* disables timer output */
#define _02_TMKB_PIN1_OUTPUT_ENABLED                (0x02U) /* enables timer output */

/*
    Forced output stop function control registers 0p (TKBPACTL0p) 
*/
/* Output level selection when executing forced output stop function (TKBPAMD0p1,TKBPAMD0p0) */
#define _0000_TMKB_FORCED_HIZ_LOW                   (0x0000U) /* Hi-Z Output / fixed at low level */
#define _0001_TMKB_FORCED_HIZ_HIGH                  (0x0001U) /* Hi-Z Output / fixed at high level */
#define _0002_TMKB_FORCED_LOW_LOW                   (0x0002U) /* function 1/2 : output fixed at low level */
#define _0003_TMKB_FORCED_HIGH_HIGH                 (0x0003U) /* function 1/2 : output fixed at high level */
/* Operation mode selection for forced output stop function 1 (TKBPAHCM0p1,TKBPAHCM0p0) */
#define _0000_TMKB_FORCED_FUNCTION1_TYPE1           (0x0000U) /* function 1 use type1 */
#define _0004_TMKB_FORCED_FUNCTION1_TYPE2           (0x0004U) /* function 1 use type2 */
#define _0008_TMKB_FORCED_FUNCTION1_TYPE3           (0x0008U) /* function 1 use type3 */
#define _000C_TMKB_FORCED_FUNCTION1_TYPE4           (0x000CU) /* function 1 use type4 */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS0p0) */
#define _0000_TMKB_FUNCTION1_COMP0_DISABLE          (0x0000U) /* comparator 0 can not be used as a trigger */
#define _0010_TMKB_FUNCTION1_COMP0_ENABLE           (0x0010U) /* comparator 0 can be used as a trigger */
/* Comparator trigger selection for forced output stop function 1 (TKBPAHZS0p1) */
#define _0000_TMKB_FUNCTION1_COMP1_DISABLE          (0x0000U) /* comparator 1 can not be used as a trigger */
#define _0020_TMKB_FUNCTION1_COMP1_ENABLE           (0x0020U) /* comparator 1 can be used as a trigger */
/* Operation mode selection for forced output stop function 2 (TKBPAFCM0p) */
#define _0000_TMKB_FORCED_FUNCTION2_TYPE1           (0x0000U) /* function 2 use type1 */
#define _0100_TMKB_FORCED_FUNCTION2_TYPE2           (0x0100U) /* function 2 use type2 */
/* Trigger selection for forced output stop function 2 (TKBPAFXS0p0) */
#define _0000_TMKB_FUNCTION2_COMP0_DISABLE          (0x0000U) /* comparator 0 can not be used as a trigger */
#define _1000_TMKB_FUNCTION2_COMP0_ENABLE           (0x1000U) /* comparator 0 can be used as a trigger */
/* Trigger selection for forced output stop function 2 (TKBPAFXS0p1) */
#define _0000_TMKB_FUNCTION2_COMP1_DISABLE          (0x0000U) /* comparator 1 can not be used as a trigger */
#define _2000_TMKB_FUNCTION2_COMP1_ENABLE           (0x2000U) /* comparator 1 can be used as a trigger */
/* Trigger selection for forced output stop function 2 (TKBPAFXS0p2) */
#define _0000_TMKB_FUNCTION2_INTP10_DISABLE         (0x0000U) /* intp10 can not be used as a trigger */
#define _4000_TMKB_FUNCTION2_INTP10_ENABLE          (0x4000U) /* intp10 can be used as a trigger */
/* Trigger selection for forced output stop function 2 (TKBPAFXS0p3) */
#define _0000_TMKB_FUNCTION2_INTP11_DISABLE         (0x0000U) /* intp11 can not be used as a trigger */
#define _8000_TMKB_FUNCTION2_INTP11_ENABLE          (0x8000U) /* intp11 can be used as a trigger */

/*
    Forced output stop functionn control register 02 (TKBPACTL02) 
*/
/* Input control of trigger signal used for forced output stop function (TKBPACE00) */
#define _00_TMKB_FORCED_STOP_PIN0_DISABLED          (0x00U) /* disable operation of forced output stop function */
#define _01_TMKB_FORCED_STOP_PIN0_ENABLED           (0x01U) /* enable operation of forced output stop function */
/* Input control of trigger signal used for forced output stop function (TKBPACE01) */
#define _00_TMKB_FORCED_STOP_PIN1_DISABLED          (0x00U) /* disable operation of forced output stop function */
#define _02_TMKB_FORCED_STOP_PIN1_ENABLED           (0x02U) /* enable operation of forced output stop function */

/*
    Peripheral function switch register (PFSEL0)
*/
/* Timer KB counter start trigger source (CTRGSEL1,CTRGSEL0) */
#define _00_TMKB_USE_COMPARATOR0_DETECTION          (0x00U) /* use comparator 0 detection */
#define _40_TMKB_USE_COMPARATOR1_DETECTION          (0x40U) /* use comparator 1 detection */
#define _80_TMKB_USE_COMPARATOR0_1_DETECTION        (0x80U) /* use comparator 0/1 detection */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _0000_TMKB_DUTY01_VALUE                     (0x0000U) 
#define _0000_TMKB_DUTY03_VALUE                     (0x0000U) 
#define _01DF_TMKB_CYCLE00_VALUE                    (0x01DFU) 
#define _0000_TMKB_DUTY02_VALUE                     (0x0000U) 
#define _12C0_TMKB_TKBTGCR0_VALUE                   (0x12C0U) 

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_TMR_KB_Create(void);
void R_TMR_KB0_Start(void);
void R_TMR_KB0_Stop(void);
void R_TMR_KB0_ForcedOutput_00_Start(void);
void R_TMR_KB0_ForcedOutput_00_Stop(void);
void R_TMR_KB0_ForcedOutput_01_Start(void);
void R_TMR_KB0_ForcedOutput_01_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
