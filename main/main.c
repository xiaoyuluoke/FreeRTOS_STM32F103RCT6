#include "main.h"
#include "FreeRTOS.h"
#include "task.h"
/************************************************

*************************************************/
#define START_TASK_PRIO			1
#define START_STK_SIZE			128
TaskHandle_t 				startTask_Handler	;
void start_task(void * pvParameters)	;

/************************************************
��ʼ����
	������������
*************************************************/
void start_task(void * pvParameters)
{
	taskENTER_CRITICAL()	;
	
	xTaskCreate((TaskFunction_t		)LED_task,
							(const char *			)"LED_task",
							(uint16_t					)LED_STK_SIZE,
							(void*						)NULL,
							(UBaseType_t			)LED_TASK_PRIO,
							(TaskHandle_t*		)&LEDTask_Handler);
							
	vTaskDelete(startTask_Handler);	
	taskEXIT_CRITICAL();
}

/************************************************
_init_ ��ʼ��
	��ʼ����������

************************************************/
void _init_(void)
{
	taskENTER_CRITICAL()	;
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4); 
	delay_init();	    //��ʱ������ʼ��	  
	LED_Init();		  	//LED��ʼ��
	uart_init(115200);
	RTC_Init();
	delay_ms(300);
	printf("AT+CONA341513CD76A9\r\n");//���������豸
	
	taskEXIT_CRITICAL();

}

/*********************************************************

main:
	���̣߳�

**********************************************************/
 int main(void)
 {	

	_init_();
	
	delay_ms(1000);
	xTaskCreate((TaskFunction_t		)start_task,
							(const char *			)"start_task",
							(uint16_t					)START_STK_SIZE,
							(void*						)NULL,
							(UBaseType_t			)START_TASK_PRIO,
							(TaskHandle_t*		)&startTask_Handler);
	vTaskStartScheduler();
	
 }
