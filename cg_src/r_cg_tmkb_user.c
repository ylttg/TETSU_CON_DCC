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
* File Name    : r_cg_tmkb_user.c
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
#include "TETSU_CON_G11_user.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_tmr_kb0_interrupt(vect=INTTMKB0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern unsigned char	Dcc_bit_pos;
extern unsigned char	Dcc_address_byte;
extern unsigned char	Dcc_first_data_byte;
extern unsigned char 	Dcc_second_data_byte;
extern unsigned char	Dcc_third_data_byte;
extern unsigned char	Dcc_error_byte;
extern unsigned char	Dcc_sending_preamble;
extern unsigned char	Dcc_sending_lock;
extern unsigned char 	Dcc_mode;
extern unsigned char	Dcc_send_byte;
extern unsigned char	Dcc_preamble_size;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_tmr_kb0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_tmr_kb0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
    unsigned char temp_bit = 0;
    static unsigned char preamble_count = DCC_PREAMBLE_BIT;
    static unsigned char bitshift_count  = 7;
    static unsigned char state = 0;
    
    if ( Dcc_mode == DCC_ANALOG_MODE )
    	return;

    __nop();

    switch ( state ){
      case 0 :
	if( Dcc_sending_preamble == 1 && Dcc_sending_lock == 1 ){
		/* nothing */
	}else{
		preamble_count--;
	}
	temp_bit = 1;
	if( preamble_count == 0 ){
		state++;
		Dcc_sending_preamble = 0;
		/* need to add long preamble and different frame sending */
		preamble_count = DCC_PREAMBLE_BIT;
	}else{
		Dcc_sending_preamble = 1;
	}
		
	break;
      case 1 :
      case 3 :
      case 5 :
      case 7 :
	/* send start bit */
      		temp_bit = 0;
		state++;
	break;  
      case 2 :
	/* send address bit */
	temp_bit = Dcc_address_byte >> bitshift_count;
	temp_bit &= 0x01;
	if( bitshift_count == 0 ){
		bitshift_count = 7;
		state++;		
	}else{
		bitshift_count--;
	}	
	break;	
      case 4 :
	/* send first byte */
	temp_bit = Dcc_first_data_byte >> bitshift_count;
	temp_bit &= 0x01;
	if( bitshift_count == 0 ){
		bitshift_count = 7;
		if( Dcc_send_byte == 3 ){
			/* 3byte sending */
			state += 3;
		}else{
			state++;		
		}
	}else{
		bitshift_count--;
	}	
	break;	
      case 6 :
	/* send second byte */
	temp_bit = Dcc_second_data_byte >> bitshift_count;
	temp_bit &= 0x01;
	if( bitshift_count == 0 ){
		bitshift_count = 7;
//		if( Dcc_send_byte == 4 ){
			/* 4byte sending */
//			state += 3;
//		}else{
			state++;		
//		}
	}else{
		bitshift_count--;
	}	
	break;	
      case 8 :
	/* send error byte */
	temp_bit = Dcc_error_byte >> bitshift_count;
	temp_bit &= 0x01;
	if( bitshift_count == 0 ){
		bitshift_count = 7;
		state++;		
	}else{
		bitshift_count--;
	}	
	break;	
      case 9 :
      default :
 	/* send stop bit */
	temp_bit = 0x01;
    	state = 0;
	break;
    }
				
	if( temp_bit == 1 ){
		TKBCR00 = DCC_TKBCR0_BIT_1;
		TKBCR01 = DCC_TKBCR1_BIT_1;
		TKBCR02 = DCC_TKBCR2_BIT_1;
		TKBCR03 = DCC_TKBCR3_BIT_1;
	}else{
		TKBCR00 = DCC_TKBCR0_BIT_0;
		TKBCR01 = DCC_TKBCR1_BIT_0;
		TKBCR02 = DCC_TKBCR2_BIT_0;
		TKBCR03 = DCC_TKBCR3_BIT_0;
	}
	TKBRDT0 = 1;

   
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
