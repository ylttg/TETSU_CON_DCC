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
* File Name    : r_cg_dtc.c
* Version      : Code Generator for RL78/G11 V1.02.06.02 [08 Nov 2021]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for DTC module.
* Creation Date: 2024/08/05
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_dtc.h"
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

#pragma address dtc_vectortable = 0x0FFD00U
uint8_t __near dtc_vectortable[40U];

#pragma address dtc_controldata_0 = 0x0FFD40U
st_dtc_data_t __near dtc_controldata_0;
#pragma address dtc_controldata_1 = 0x0FFD48U
st_dtc_data_t __near dtc_controldata_1;
#pragma address dtc_controldata_2 = 0x0FFD50U
st_dtc_data_t __near dtc_controldata_2;
#pragma address dtc_controldata_3 = 0x0FFD58U
st_dtc_data_t __near dtc_controldata_3;
#pragma address dtc_controldata_4 = 0x0FFD60U
st_dtc_data_t __near dtc_controldata_4;
/***********************************************************************************************************************
* Function Name: R_DTC_Create
* Description  : This function initializes the DTC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DTC_Create(void)
{
    /* Enable input clock supply */
    DTCEN = 1U;     /* enables input clock supply */
    /* Disable all DTC channels operation */
    DTCEN0 = 0x00U;
    DTCEN1 = 0x00U;
    DTCEN2 = 0x00U;
    /* Set base address */
    DTCBAR = 0xFDU;
    /* Set DTCD0 */
    dtc_vectortable[21U] = 0x40U;
    dtc_controldata_0.dtccr = _00_DTC_DATA_SIZE_8BITS | _00_DTC_REPEAT_INT_DISABLE | _10_DTC_CHAIN_TRANSFER_ENABLE | 
                              _00_DTC_DEST_ADDR_FIXED | _02_DTC_REPEAT_AREA_SOURCE | _01_DTC_TRANSFER_MODE_REPEAT;
    dtc_controldata_0.dtbls = _01_DTCD0_TRANSFER_BLOCKSIZE;
    dtc_controldata_0.dtcct = _F0_DTCD0_TRANSFER_BYTE;
    dtc_controldata_0.dtrld = _F0_DTCD0_TRANSFER_BYTE;
    dtc_controldata_0.dtsar = _FB00_DTCD0_SRC_ADDRESS;
    dtc_controldata_0.dtdar = _0400_DTCD0_DEST_ADDRESS;
    /* Set DTCD1 */
    dtc_controldata_1.dtccr = _00_DTC_DATA_SIZE_8BITS | _00_DTC_REPEAT_INT_DISABLE | _10_DTC_CHAIN_TRANSFER_ENABLE | 
                              _00_DTC_DEST_ADDR_FIXED | _02_DTC_REPEAT_AREA_SOURCE | _01_DTC_TRANSFER_MODE_REPEAT;
    dtc_controldata_1.dtbls = _01_DTCD1_TRANSFER_BLOCKSIZE;
    dtc_controldata_1.dtcct = _F0_DTCD1_TRANSFER_BYTE;
    dtc_controldata_1.dtrld = _F0_DTCD1_TRANSFER_BYTE;
    dtc_controldata_1.dtsar = _FC00_DTCD1_SRC_ADDRESS;
    dtc_controldata_1.dtdar = _0402_DTCD1_DEST_ADDRESS;
    /* Set DTCD2 */
    dtc_controldata_2.dtccr = _00_DTC_DATA_SIZE_8BITS | _00_DTC_REPEAT_INT_DISABLE | _10_DTC_CHAIN_TRANSFER_ENABLE | 
                              _00_DTC_DEST_ADDR_FIXED | _02_DTC_REPEAT_AREA_SOURCE | _01_DTC_TRANSFER_MODE_REPEAT;
    dtc_controldata_2.dtbls = _01_DTCD2_TRANSFER_BLOCKSIZE;
    dtc_controldata_2.dtcct = _F0_DTCD2_TRANSFER_BYTE;
    dtc_controldata_2.dtrld = _F0_DTCD2_TRANSFER_BYTE;
    dtc_controldata_2.dtsar = _FC00_DTCD2_SRC_ADDRESS;
    dtc_controldata_2.dtdar = _0404_DTCD2_DEST_ADDRESS;
    /* Set DTCD3 */
    dtc_controldata_3.dtccr = _00_DTC_DATA_SIZE_8BITS | _00_DTC_REPEAT_INT_DISABLE | _10_DTC_CHAIN_TRANSFER_ENABLE | 
                              _00_DTC_DEST_ADDR_FIXED | _02_DTC_REPEAT_AREA_SOURCE | _01_DTC_TRANSFER_MODE_REPEAT;
    dtc_controldata_3.dtbls = _01_DTCD3_TRANSFER_BLOCKSIZE;
    dtc_controldata_3.dtcct = _F0_DTCD3_TRANSFER_BYTE;
    dtc_controldata_3.dtrld = _F0_DTCD3_TRANSFER_BYTE;
    dtc_controldata_3.dtsar = _FB00_DTCD3_SRC_ADDRESS;
    dtc_controldata_3.dtdar = _0406_DTCD3_DEST_ADDRESS;
    /* Set DTCD4 */
    dtc_controldata_4.dtccr = _00_DTC_DATA_SIZE_8BITS | _00_DTC_CHAIN_TRANSFER_DISABLE | _00_DTC_DEST_ADDR_FIXED | 
                              _00_DTC_SOURCE_ADDR_FIXED | _00_DTC_TRANSFER_MODE_NORMAL;
    dtc_controldata_4.dtbls = _01_DTCD4_TRANSFER_BLOCKSIZE;
    dtc_controldata_4.dtcct = _F0_DTCD4_TRANSFER_BYTE;
    dtc_controldata_4.dtrld = 0x00U;
    dtc_controldata_4.dtsar = _FCF0_DTCD4_SRC_ADDRESS;
    dtc_controldata_4.dtdar = _0412_DTCD4_DEST_ADDRESS;
}
/***********************************************************************************************************************
* Function Name: R_DTCD0_Start
* Description  : This function enables DTCD0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DTCD0_Start(void)
{
     DTCEN2 |= _04_DTC_TMKB_ACTIVATION_ENABLE;
}
/***********************************************************************************************************************
* Function Name: R_DTCD0_Stop
* Description  : This function disables DTCD0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_DTCD0_Stop(void)
{
    DTCEN2 &= (uint8_t)~_04_DTC_TMKB_ACTIVATION_ENABLE;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
