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
* File Name    : r_cg_port.h
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for Port module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/
#ifndef PORT_H
#define PORT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Port mode registers (PMn) 
*/
/* Pn0 pin I/O mode selection (PMn0) */
#define _00_PMn0_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _01_PMn0_MODE_INPUT           (0x01U) /* input mode (output buffer off) */
/* Pn1 pin I/O mode selection (PMn1) */
#define _00_PMn1_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _02_PMn1_MODE_INPUT           (0x02U) /* input mode (output buffer off) */
/* Pn2 pin I/O mode selection (PMn2) */
#define _00_PMn2_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _04_PMn2_MODE_INPUT           (0x04U) /* input mode (output buffer off) */
/* Pn3 pin I/O mode selection (PMn3) */
#define _00_PMn3_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _08_PMn3_MODE_INPUT           (0x08U) /* input mode (output buffer off) */
/* Pn4 pin I/O mode selection (PMn4) */
#define _00_PMn4_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _10_PMn4_MODE_INPUT           (0x10U) /* input mode (output buffer off) */
/* Pn5 pin I/O mode selection (PMn5) */
#define _00_PMn5_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _20_PMn5_MODE_INPUT           (0x20U) /* input mode (output buffer off) */
/* Pn6 pin I/O mode selection (PMn6) */
#define _00_PMn6_MODE_OUTPUT          (0x00U) /* output mode (output buffer on) */
#define _40_PMn6_MODE_INPUT           (0x40U) /* input mode (output buffer off) */

/*
    Port mode registers (Pn) 
*/
/* Pn0 pin output latch selection (Pn0) */
#define _00_Pn0_OUTPUT_0              (0x00U) /* Pn0 output 0 */
#define _01_Pn0_OUTPUT_1              (0x01U) /* Pn0 output 1 */
/* Pn1 pin output latch selection (Pn1) */
#define _00_Pn1_OUTPUT_0              (0x00U) /* Pn1 output 0 */
#define _02_Pn1_OUTPUT_1              (0x02U) /* Pn1 output 1 */
/* Pn2 pin output latch selection (Pn2) */
#define _00_Pn2_OUTPUT_0              (0x00U) /* Pn2 output 0 */
#define _04_Pn2_OUTPUT_1              (0x04U) /* Pn2 output 1 */
/* Pn3 pin output latch selection (Pn3) */
#define _00_Pn3_OUTPUT_0              (0x00U) /* Pn3 output 0 */
#define _08_Pn3_OUTPUT_1              (0x08U) /* Pn3 output 1 */
/* Pn4 pin output latch selection (Pn4) */
#define _00_Pn4_OUTPUT_0              (0x00U) /* Pn4 output 0 */
#define _10_Pn4_OUTPUT_1              (0x10U) /* Pn4 output 1 */
/* Pn5 pin output latch selection (Pn5) */
#define _00_Pn5_OUTPUT_0              (0x00U) /* Pn5 output 0 */
#define _20_Pn5_OUTPUT_1              (0x20U) /* Pn5 output 1 */
/* Pn6 pin output latch selection (Pn6) */
#define _00_Pn6_OUTPUT_0              (0x00U) /* Pn6 output 0 */
#define _40_Pn6_OUTPUT_1              (0x40U) /* Pn6 output 1 */
/* Pn7 pin output latch selection (Pn7) */
#define _00_Pn7_OUTPUT_0              (0x00U) /* Pn7 output 0 */
#define _80_Pn7_OUTPUT_1              (0x80U) /* Pn7 output 1 */

/*
    Pull-up resistor option registers (PUn) 
*/
/* Pn0 pin on-chip pull-up resistor selection (PUn0) */
#define _00_PUn0_PULLUP_OFF           (0x00U) /* Pn0 pull-up resistor not connected */
#define _01_PUn0_PULLUP_ON            (0x01U) /* Pn0 pull-up resistor connected */
/* Pn1 pin on-chip pull-up resistor selection (PUn1) */
#define _00_PUn1_PULLUP_OFF           (0x00U) /* Pn1 pull-up resistor not connected */
#define _02_PUn1_PULLUP_ON            (0x02U) /* Pn1 pull-up resistor connected */
/* Pn3 pin on-chip pull-up resistor selection (PUn3) */
#define _00_PUn3_PULLUP_OFF           (0x00U) /* Pn3 pull-up resistor not connected */
#define _08_PUn3_PULLUP_ON            (0x08U) /* Pn3 pull-up resistor connected */
/* Pn4 pin on-chip pull-up resistor selection (PUn4) */
#define _00_PUn4_PULLUP_OFF           (0x00U) /* Pn4 pull-up resistor not connected */
#define _10_PUn4_PULLUP_ON            (0x10U) /* Pn4 pull-up resistor connected */
/* Pn5 pin on-chip pull-up resistor selection (PUn5) */
#define _00_PUn5_PULLUP_OFF           (0x00U) /* Pn5 pull-up resistor not connected */
#define _20_PUn5_PULLUP_ON            (0x20U) /* Pn5 pull-up resistor connected */
/* Pn6 pin on-chip pull-up resistor selection (PUn6) */
#define _00_PUn6_PULLUP_OFF           (0x00U) /* Pn6 pull-up resistor not connected */
#define _40_PUn6_PULLUP_ON            (0x40U) /* Pn6 pull-up resistor connected */

/*
    Port input mode registers (PIMn) 
*/
/* Pn0 pin input buffer selection (PIMn0) */
#define _00_PIMn0_TTL_OFF             (0x00U) /* Pn0 normal input buffer */
#define _01_PIMn0_TTL_ON              (0x01U) /* Pn0 TTL input buffer */
/* Pn1 pin input buffer selection (PIMn1) */
#define _00_PIMn1_TTL_OFF             (0x00U) /* Pn1 normal input buffer */
#define _02_PIMn1_TTL_ON              (0x02U) /* Pn1 TTL input buffer */
/* Pn5 pin input buffer selection (PIMn5) */
#define _00_PIMn5_TTL_OFF             (0x00U) /* Pn5 normal input buffer */
#define _20_PIMn5_TTL_ON              (0x20U) /* Pn5 TTL input buffer */
/* Pn6 pin input buffer selection (PIMn6) */
#define _00_PIMn6_TTL_OFF             (0x00U) /* Pn6 normal input buffer */
#define _40_PIMn6_TTL_ON              (0x40U) /* Pn6 TTL input buffer */

/*
    Port output mode registers (POMn) 
*/
/* Pn0 pin output mode selection (POMn0) */
#define _00_POMn0_NCH_OFF             (0x00U) /* Pn0 normal output mode */
#define _01_POMn0_NCH_ON              (0x01U) /* Pn0 N-ch open-drain output (VDD tolerance) mode */
/* Pn1 pin output mode selection (POMn1) */
#define _00_POMn1_NCH_OFF             (0x00U) /* Pn1 normal output mode */
#define _02_POMn1_NCH_ON              (0x02U) /* Pn1 N-ch open-drain output (VDD tolerance) mode */
/* Pn4 pin output mode selection (POMn4) */
#define _00_POMn4_NCH_OFF             (0x00U) /* Pn4 normal output mode */
#define _10_POMn4_NCH_ON              (0x10U) /* Pn4 N-ch open-drain output (VDD tolerance) mode */
/* Pn5 pin output mode selection (POMn5) */
#define _00_POMn5_NCH_OFF             (0x00U) /* Pn5 normal output mode */
#define _20_POMn5_NCH_ON              (0x20U) /* Pn5 N-ch open-drain output (VDD tolerance) mode */
/* Pn6 pin output mode selection (POMn6) */
#define _00_POMn6_NCH_OFF             (0x00U) /* Pn6 normal output mode */
#define _40_POMn6_NCH_ON              (0x40U) /* Pn6 N-ch open-drain output (VDD tolerance) mode */

/*
    Port Mode Control Registers (PMCn) 
*/
/* Pn0 pin digital I/O/analog input selection (PMCn0) */
#define _00_PMCn0_NOT_USE             (0x00U) /* digital I/O (alternate function other than analog input) */
#define _01_PMCn0_DI_ON               (0x01U) /* analog input */
/* Pn1 pin digital I/O/analog input selection (PMCn1) */
#define _00_PMCn1_NOT_USE             (0x00U) /* digital I/O (alternate function other than analog input) */
#define _02_PMCn1_DI_ON               (0x02U) /* analog input */
/* Pn2 pin digital I/O/analog input selection (PMCn2) */
#define _00_PMCn2_NOT_USE             (0x00U) /* digital I/O (alternate function other than analog input) */
#define _04_PMCn2_DI_ON               (0x04U) /* analog input */
/* Pn3 pin digital I/O/analog input selection (PMCn3) */
#define _00_PMCn3_NOT_USE             (0x00U) /* digital I/O (alternate function other than analog input) */
#define _08_PMCn3_DI_ON               (0x08U) /* analog input */
/* Pn6 pin digital I/O/analog input selection (PMCn6) */
#define _00_PMCn6_NOT_USE             (0x00U) /* digital I/O (alternate function other than analog input) */
#define _40_PMCn6_DI_ON               (0x40U) /* analog input */


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _FC_PM0_DEFAULT_VALUE         (0xFCU) /* PM0 default value */
#define _F0_PM2_DEFAULT_VALUE         (0xF0U) /* PM2 default value */
#define _F4_PM3_DEFAULT_VALUE         (0xF4U) /* PM3 default value */
#define _FE_PM4_DEFAULT_VALUE         (0xFEU) /* PM4 default value */
#define _8F_PM5_DEFAULT_VALUE         (0x8FU) /* PM5 default value */
#define _FC_PMC0_DEFAULT_VALUE        (0xFCU) /* PMC0 default value */
#define _F0_PMC2_DEFAULT_VALUE        (0xF0U) /* PMC2 default value */
#define _F4_PMC3_DEFAULT_VALUE        (0xF4U) /* PMC3 default value */
#define _BF_PMC5_DEFAULT_VALUE        (0xBFU) /* PMC5 default value */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_PORT_Create(void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif
