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
* File Name    : r_cg_it8bit_user.c
* Version      : Code Generator for RL78/G11 V1.02.03.02 [20 Nov 2019]
* Device(s)    : R5F1056A
* Tool-Chain   : CCRL
* Description  : This file implements device driver for IT8Bit module.
* Creation Date: 2022/10/23
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_it8bit.h"
/* Start user code for include. Do not edit comment generated here */
#include "TETSU_CON_G11_user.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_it8bit0_channel0_interrupt(vect=INTIT00)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
extern unsigned char Timer_tick;
extern unsigned char Direction_sw;
extern unsigned char Limit_sw;
extern unsigned char Start_sound;
extern unsigned char Blink_ledacc;
extern unsigned char Blink_ledbrk;
extern unsigned char Blink_leddir;
extern struct led_param Led_port[3];
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: r_it8bit0_channel0_interrupt
* Description  : None
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_it8bit0_channel0_interrupt(void)
{
    /* Start user code. Do not edit comment generated here */
	static unsigned int timer_count = 0;
	static unsigned int direction_sw_count = 0;
    	static unsigned char past_direction_sw = SW_OFF;
	static unsigned int limit_sw_count = 0;
    	static unsigned char past_limit_sw = SW_OFF;
	static unsigned char sound_count = 0;
	unsigned char i;
	unsigned int  blink_end;
	
    	/* main interval flag */
	timer_count++;
    	if ( timer_count == INTERVAL_COUNT )
	{
		timer_count = 0;
		Timer_tick = 1;
	}
 	if ( DIRECTION_SW_PORT == SW_ON )
	{
		if( past_direction_sw == SW_OFF )
		{
			direction_sw_count++;
			if( direction_sw_count == SW_CHATTERING_COUNT )
			{
				direction_sw_count = 0;
				Direction_sw = SW_ON;
				past_direction_sw = SW_ON;		/* 一度確定したら一度だけセットする */
			}
		}
	}else{
		direction_sw_count = 0;
		Direction_sw = SW_OFF;
		past_direction_sw = SW_OFF;
	}
 	if ( LIMIT_SW_PORT == SW_ON )
	{
		if( past_limit_sw == SW_OFF )
		{
			limit_sw_count++;
			if( limit_sw_count == SW_CHATTERING_COUNT )
			{
				limit_sw_count = 0;
				Limit_sw = SW_ON;
				past_limit_sw = SW_ON;		/* 一度確定したら一度だけセットする */
			}
		}
	}else{
		limit_sw_count = 0;
		Limit_sw = SW_OFF;
		past_limit_sw = SW_OFF;
	}

	if ( Start_sound == SOUND_ON )
	{
		CONTROL_SOUND = SOUND_ON;
		sound_count++;
		if( sound_count > SOUND_LIMIT )
		{
			sound_count = 0;
			CONTROL_SOUND = SOUND_OFF;
			Start_sound = SOUND_OFF;
		}		
		
	}
	
	for ( i = 0; i < 3 ; i++ )
	{
		if ( Led_port[i].blink_flag == BLINK_ON || Led_port[i].blink_flag == BLINK_FAST )
		{
			if ( Led_port[i].blink_flag == BLINK_FAST )
				blink_end = BLINK_PERIOD_FAST;
			else
				blink_end = BLINK_PERIOD;
			Led_port[i].blink_count++;
			if( Led_port[i].blink_count > blink_end )
			{
				Led_port[i].blink_count = 0;
				Led_port[i].blinking = !Led_port[i].blinking;
			}
		}else{
			Led_port[i].blink_count = 0;
			Led_port[i].blinking = Led_port[i].on_off;
		}
	}
	LED_ACC_PORT = Led_port[LED_ACC].blinking;
	LED_BRK_PORT = Led_port[LED_BRK].blinking;
	LED_DIRECTION_PORT = Led_port[LED_DIRECTION].blinking;
	
    
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
