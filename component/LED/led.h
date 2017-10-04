#ifndef __LED_H
#define __LED_H	 

#include "sys.h"
#include "delay.h"

#include "FreeRTOS.h"
#include "task.h"

#define LED_TASK_PRIO			2
#define LED_STK_SIZE			128

#define LED0 PBout(11)	// PB11

extern TaskHandle_t LEDTask_Handler	;

void LED_Init(void);		//初始化
void LED_task(void * pvParameters) ; //LED 任务       
		 				    
#endif
