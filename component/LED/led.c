#include "led.h"
/*********************************************************

��ʼ��PB11����.��ʹ������ڵ�ʱ��		    
LED IO��ʼ��

**********************************************************/

TaskHandle_t LEDTask_Handler	;

void LED_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);	 //ʹ��PB
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11;					//LED0-->PB.11 �˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	//�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOB, &GPIO_InitStructure);					 		//�����趨������ʼ��GPIOB.11
 GPIO_SetBits(GPIOB,GPIO_Pin_11);										//PB.11 �����

 }
 
/*********************************************************

**********************************************************/
void Relay_Init(void)
{
 
 GPIO_InitTypeDef  GPIO_InitStructure;
 	
 RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);	 //ʹ��C4
	
 GPIO_InitStructure.GPIO_Pin = GPIO_Pin_4;					//Relay-->PC.4�˿�����
 GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP; 	//�������
 GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;	//IO���ٶ�Ϊ50MHz
 GPIO_Init(GPIOC, &GPIO_InitStructure);					 		//�����趨������ʼ��GPIOB.11
 GPIO_ResetBits(GPIOC,GPIO_Pin_4);										//PC.4 �����

 }
/*********************************************************


**********************************************************/
void LED_task(void * pvParameters)
{
	while(1)
	{
		LED0=0;
		vTaskDelay(500);
		LED0=1;
		vTaskDelay(500);
	}
}
