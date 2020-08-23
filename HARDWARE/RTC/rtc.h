/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               RTC_Time.h
** Descriptions:            None
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-10-30
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             
** Modified date:           
** Version:                 
** Descriptions:            
**
*********************************************************************************************************/

#ifndef _RTC_TIME_H_
#define _RTC_TIME_H_

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x.h"
#include <time.h>
#include <stdio.h>
#include <string.h>

/* Private function prototypes -----------------------------------------------*/
void RTC_Init(void);
void Time_Display(void);
void Time_Set(u16 year,u8 mon,u8 day,u8 hour,u8 min,u8 sec);

/* Private variables ---------------------------------------------------------*/
extern FunctionalState TimeDisplay;

#endif

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
