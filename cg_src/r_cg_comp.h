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
* File Name    : r_cg_comp.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for COMP module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/
#ifndef COMP_H
#define COMP_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Comparator Mode Setting Register (COMPMDR) 
*/
/* Comparator 1 monitor flag bit (C1MON) */
#define _00_COMP1_FLAG_REFERENCE_0                (0x00U) /* standard mode: IVCMP1 < Comparator 1 reference voltage;
                                                             window mode: IVCMP1 < IVREF0 or IVCMP1 > IVREF1 */
#define _80_COMP1_FLAG_REFERENCE_1                (0x80U) /* standard mode: IVCMP1 > Comparator 1 reference voltage;
                                                             window mode: IVREF0 < IVCMP1 < IVREF1 */
/* Comparator 1 reference voltage selection (C1VRF) */
#define _00_COMP1_REF_VOLTAGE_IVREF0              (0x00U) /* IVREF0 input */
#define _40_COMP1_REF_VOLTAGE_BGRVREF             (0x40U) /* BGRVREF input */
/* Comparator 1 window mode selection (C1WDE) */
#define _00_COMP1_MODE_NORMAL                     (0x00U) /* comparator 1 normal mode */
#define _20_COMP1_MODE_WINDOW                     (0x20U) /* comparator 1 window mode */
/* Comparator 1 operation enable bit (C1ENB) */
#define _00_COMP1_OPERATION_DISABLED              (0x00U) /* disable comparator 1 operation */
#define _10_COMP1_OPERATION_ENABLED               (0x10U) /* enable comparator 1 operation */
/* Comparator 0 monitor flag bit (C0MON) */
#define _00_COMP0_FLAG_REFERENCE_0                (0x00U) /* standard mode: IVCMP0 < Comparator 0 reference voltage;
                                                             window mode: IVCMP0 < IVREF0 or IVCMP0 > IVREF1 */
#define _08_COMP0_FLAG_REFERENCE_1                (0x08U) /* standard mode: IVCMP0 > Comparator 0 reference voltage;
                                                             window mode: IVREF0 < IVCMP0 < IVREF1 */
/* Comparator 0 reference voltage selection (C0VRF) */
#define _00_COMP0_REF_VOLTAGE_IVREF0ORDA          (0x00U) /* IVREF0 input or D/A converter 0 output */
#define _04_COMP0_REF_VOLTAGE_BGRVREF             (0x04U) /* BGRVREF input */
/* Comparator 0 window mode selection (C0WDE) */
#define _00_COMP0_MODE_NORMAL                     (0x00U) /* comparator 0 normal mode */
#define _02_COMP0_MODE_WINDOW                     (0x02U) /* comparator 0 window mode */
/* Comparator 0 operation enable bit (C0ENB) */
#define _00_COMP0_OPERATION_DISABLED              (0x00U) /* disable comparator 0 operation */
#define _01_COMP0_OPERATION_ENABLED               (0x01U) /* enable comparator 0 operation */

/*
    Comparator Filter Control Register (COMPFIR) 
*/
/* Comparator 1 edge detectioin selection (C1EDG) */
#define _00_COMP1_ONE_EDGE_INTERRUPT              (0x00U) /* interrupt when one edge */
#define _80_COMP1_BOTH_EDGES_INTERRUPT            (0x80U) /* interrupt when both edges */
/* Comparator 1 edges polarity selection (C1EPO) */
#define _00_COMP1_RISING_INTERRUPT                (0x00U) /* interrupt when rising edge  */
#define _40_COMP1_FALLING_INTERRUPT               (0x40U) /* interrupt when falling edge */
/* Comparator 1 filter selection (C1FCK1,C1FCK0) */
#define _00_COMP1_FILTER_NONE                     (0x00U) /* disable filter */
#define _10_COMP1_FILTER_FCLK                     (0x10U) /* sampling at fCLK */
#define _20_COMP1_FILTER_FCLK_8                   (0x20U) /* sampling at fCLK/2^3 */
#define _30_COMP1_FILTER_FCLK_32                  (0x30U) /* sampling at fCLK/2^5 */
/* Comparator 0 edge detectioin selection (C0EDG) */
#define _00_COMP0_ONE_EDGE_INTERRUPT              (0x00U) /* interrupt when one edge */
#define _08_COMP0_BOTH_EDGES_INTERRUPT            (0x08U) /* interrupt when both edges */
/* Comparator 0 edges polarity selection (C0EPO) */
#define _00_COMP0_RISING_INTERRUPT                (0x00U) /* interrupt when rising edge */
#define _04_COMP0_FALLING_INTERRUPT               (0x04U) /* interrupt when falling edge */
/* Comparator 0 filter selection (C0FCK1, C0FCK0) */
#define _00_COMP0_FILTER_NONE                     (0x00U) /* disable filter */
#define _01_COMP0_FILTER_FCLK                     (0x01U) /* sampling at fCLK */
#define _02_COMP0_FILTER_FCLK_8                   (0x02U) /* sampling at fCLK/2^3 */
#define _03_COMP0_FILTER_FCLK_32                  (0x03U) /* sampling at fCLK/2^5 */

/*
    Comparator Output Control Register (COMPOCR) 
*/
/* Comparator speed selection (SPDMD) */
#define _00_COMP_SPEED_LOW                        (0x00U) /* low speed */
#define _80_COMP_SPEED_HIGH                       (0x80U) /* high speed */
/* Comparator 1 VCOUT1 output polarity selection bit (C1OP) */
#define _00_COMP1_VCOUT1_NORMAL                   (0x00U) /* VCOUT1 normal output */
#define _40_COMP1_VCOUT1_INVERTED                 (0x40U) /* VCOUT1 inverted output */
/* Comparator 1 VCOUT1 output permission bit (C1OE) */
#define _00_COMP1_VCOUT1_DISABLE                  (0x00U) /* disable VCOUT1 output */
#define _20_COMP1_VCOUT1_ENABLE                   (0x20U) /* enable VCOUT1 output */
/* Comparator 1 interrupt demand permission bit (C1IE) */
#define _00_COMP1_INTERRUPT_DISABLE               (0x00U) /* disbale interrupt demand */
#define _10_COMP1_INTERRPUT_ENABLE                (0x10U) /* enable interrupt demand */
/* Comparator 0 VCOUT0 output polarity selection bit (C0OP) */
#define _00_COMP0_VCOUT0_NORMAL                   (0x00U) /* VCOUT0 normal output */
#define _04_COMP0_VCOUT0_INVERTED                 (0x04U) /* VCOUT0 inverted output */
/* Comparator 0 VCOUT0 output permission bit (C0OE) */
#define _00_COMP0_VCOUT0_DISABLE                  (0x00U) /* disable VCOUT0 output */
#define _02_COMP0_VCOUT0_ENABLE                   (0x02U) /* enable VCOUT0 output */
/* Comparator 0 interrupt demand permission bit (C0IE) */
#define _00_COMP0_INTERRUPT_DISABLE               (0x00U) /* disbale interrupt demand */
#define _01_COMP0_INTERRPUT_ENABLE                (0x01U) /* enable interrupt demand */

/*
    Comparator Input Signal Select Control Register (COMPISEL) 
*/
/* Selection of the input signal on + pin of the comparator 0 (COMP0SEL1,COMP0SEL0) */
#define _00_COMP0_POSITIVE_NOTHING                (0x00U) /* nothing is selected */
#define _04_COMP0_POSITIVE_IVCMP0                 (0x04U) /* IVCMP0 pin is selected */
#define _08_COMP0_POSITIVEE_PGA                   (0x08U) /* PGA output is selected */
/* Selection of the input signal on - pin of the comparator 0 (C0REFSEL1,C0REFSEL0) */
#define _00_COMP0_NEGATIVE_NOTHING                (0x00U) /* nothing is selected */
#define _01_COMP0_NEGATIVE_IVREF0                 (0x01U) /* IVREF0 pin is selected */
#define _02_COMP0_NEGATIVE_DA                     (0x02U) /* D/A converter 0 output is selected */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define COMP_WAIT_TIME                      (0xC8U)   /* wait time for 100us */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_COMP_Create(void);
void R_COMP0_Start(void);
void R_COMP0_Stop(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
