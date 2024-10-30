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
* File Name    : r_cg_pfdl.c
* Version      : Code Generator for RL78/G11 V1.02.03.02 [20 Nov 2019]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for PFDL module.
* Creation Date: 2022/09/07
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_cgc.h"
#include "r_cg_pfdl.h"
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
pfdl_status_t gFdlResult;    /* Return value */
pfdl_request_t gFdlReq;      /* Control variable for PFDL */
pfdl_descriptor_t gFdlDesc;
uint8_t gFdlStatus;	         /* This indicates status of FDL library that is "close" or "open". (open=1, close=0) */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_FDL_Create
* Description  : This function initializes the flash data library.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_FDL_Create(void)
{
    gFdlDesc.fx_MHz_u08 = _48_HOCO_CLOCK_MHz;   /* Set an integer of the range from 1 to 48 according to GUI setting of HOCO. */
    gFdlDesc.wide_voltage_mode_u08 = _FULL_SPEED_MODE; /* Voltage mode */
}
/***********************************************************************************************************************
* Function Name: R_FDL_Write
* Description  : This function writes a data to the RL78 data flash memory.
* Arguments    : index -
*                    It is destination address of flash memory for writing a data. The address range is from 0x0000 to 0x0FFF
*                buffer -
*                    The top address of data to write
*                bytecount -
*                    The size of data to write (Unit is byte)
* Return Value : pfdl_status_t -
*                    status of write command
***********************************************************************************************************************/
pfdl_status_t R_FDL_Write(pfdl_u16 index, __near pfdl_u08* buffer, pfdl_u16 bytecount)
{
    if (gFdlStatus == 1)
    {
        gFdlReq.index_u16     = index;
        gFdlReq.data_pu08     = buffer;
        gFdlReq.bytecount_u16 = bytecount;
        gFdlReq.command_enu   = PFDL_CMD_WRITE_BYTES;
        gFdlResult = PFDL_Execute(&gFdlReq);
        /* Wait for completing command */
        while (gFdlResult == PFDL_BUSY)
        {
            NOP();
            NOP();
            gFdlResult = PFDL_Handler();     /* The process for confirming end */
        }
    }
    else
    {
        gFdlResult = PFDL_ERR_PROTECTION;
    }
    return gFdlResult;
}
/***********************************************************************************************************************
* Function Name: R_FDL_Read
* Description  : This function reads a data flash memory.
* Arguments    : index -
*                    It is destination address of flash memory for reading a data. The address range is from 0x0000 to 0x0FFF
*                buffer -
*                    The top address of data to read
*                bytecount -
*                    The size of data to read (Unit is byte)
* Return Value : pfdl_status_t -
*                    status of read command
***********************************************************************************************************************/
pfdl_status_t R_FDL_Read(pfdl_u16 index, __near pfdl_u08* buffer, pfdl_u16 bytecount)
{
    if (gFdlStatus == 1)
    {
         gFdlReq.index_u16     = index;
         gFdlReq.data_pu08     = buffer;
         gFdlReq.bytecount_u16 = bytecount;
         gFdlReq.command_enu   = PFDL_CMD_READ_BYTES;
         gFdlResult = PFDL_Execute(&gFdlReq);
     }
     else 
     {
         gFdlResult = PFDL_ERR_PROTECTION;
     }
     return gFdlResult;
}
/***********************************************************************************************************************
* Function Name: R_FDL_Erase
* Description  : This function erases a block of data flash.
* Arguments    : blockno -
*                    The block number to erase data flash. The range of block number is from 0 to 3
* Return Value : pfdl_status_t -
*                    status of erase command
***********************************************************************************************************************/
pfdl_status_t R_FDL_Erase(pfdl_u16 blockno)
{
    if (gFdlStatus == 1)
    {
        gFdlReq.index_u16     = blockno;
        gFdlReq.command_enu   = PFDL_CMD_ERASE_BLOCK;
        gFdlResult = PFDL_Execute(&gFdlReq);
        /* Wait for completing command  */
        while(gFdlResult == PFDL_BUSY)
        {
            NOP(); 
            NOP();
            gFdlResult = PFDL_Handler();     /* The process for confirming end */
        }
    }
    else 
    {
        gFdlResult = PFDL_ERR_PROTECTION;
    }
    return gFdlResult;
}
/***********************************************************************************************************************
* Function Name: R_FDL_Open
* Description  : This function opens the RL78 data flash library.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_FDL_Open(void)
{
    gFdlDesc.fx_MHz_u08 = _48_HOCO_CLOCK_MHz;   /* Set an integer of the range from 1 to 48 according to GUI setting of HOCO. */
    gFdlDesc.wide_voltage_mode_u08 = _FULL_SPEED_MODE; /* Voltage mode */
    PFDL_Open(&gFdlDesc);
    gFdlStatus = 1;
}
/***********************************************************************************************************************
* Function Name: R_FDL_Close
* Description  : This function closes the RL78 data flash library.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_FDL_Close(void)
{
    PFDL_Close();
    gFdlStatus = 0;
}
/***********************************************************************************************************************
* Function Name: R_FDL_BlankCheck
* Description  : This function blank check a data to the RL78 data flash memory.
* Arguments    : index -
*                    It is destination address of flash memory for blank check.The address range is from 0x0000 to 0x0FFF
*                bytecount -
*                    The size of data to blank check(Unit is byte)
* Return Value : pfdl_status_t -
*                    status of blank check command
***********************************************************************************************************************/
pfdl_status_t R_FDL_BlankCheck(pfdl_u16 index, pfdl_u16 bytecount)
{
    if (gFdlStatus == 1)
    {
        gFdlReq.index_u16 = index;
        gFdlReq.bytecount_u16 = bytecount;
        gFdlReq.command_enu = PFDL_CMD_BLANKCHECK_BYTES;
        gFdlResult = PFDL_Execute(&gFdlReq);
        /* Wait for completing command */
        while (gFdlResult == PFDL_BUSY)
        {
            NOP();
            NOP();
            gFdlResult = PFDL_Handler();     /* The process for confirming end */
        }
    }
    else
    {
        gFdlResult = PFDL_ERR_PROTECTION;
    }
    return gFdlResult;
}
/***********************************************************************************************************************
* Function Name: R_FDL_IVerify
* Description  : This function writes a data to the RL78 data flash memory.
* Arguments    : index -
*                    It is destination address of flash memory for iverify a data.The address range is from 0x0000 to 0x0FFF
*                bytecount -
*                    The size of data to iverify(Unit is byte)
* Return Value : pfdl_status_t -
*                    status of iverify command
***********************************************************************************************************************/
pfdl_status_t R_FDL_IVerify(pfdl_u16 index, pfdl_u16 bytecount)
{
    if (gFdlStatus == 1)
    {
        gFdlReq.index_u16 = index;
        gFdlReq.bytecount_u16 = bytecount;
        gFdlReq.command_enu = PFDL_CMD_IVERIFY_BYTES;
        gFdlResult = PFDL_Execute(&gFdlReq);
        /* Wait for completing command */
        while (gFdlResult == PFDL_BUSY)
        {
            NOP();
            NOP();
            gFdlResult = PFDL_Handler();     /* The process for confirming end */
        }
    }
    else
    {
        gFdlResult = PFDL_ERR_PROTECTION;
    }
    return gFdlResult;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
