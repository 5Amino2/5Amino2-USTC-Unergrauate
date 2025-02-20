//????? 3 ?????
//arr:?????? psc:??????
//???????????:Tout=((arr+1)*(psc+1))/Ft us. //Ft=???????,??:Mhz
//????????? 3
#include "timer.h"
#include "led.h"
void TIM3_Init(u16 arr, u16 psc)
{
TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;
NVIC_InitTypeDef NVIC_InitStructure;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
//??? TIM3 ??
TIM_TimeBaseInitStructure.TIM_Period = arr;
//??????
TIM_TimeBaseInitStructure.TIM_Prescaler=psc;
//?????
TIM_TimeBaseInitStructure.TIM_CounterMode=TIM_CounterMode_Up;
//??????
TIM_TimeBaseInitStructure.TIM_ClockDivision=TIM_CKD_DIV1;
TIM_TimeBaseInit(TIM3,&TIM_TimeBaseInitStructure);
// ???????TIM3 
TIM_ITConfig(TIM3,TIM_IT_Update,ENABLE);
//?????? 3 ????
NVIC_InitStructure.NVIC_IRQChannel=TIM3_IRQn;
//??? 3 ??
NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority=0x01;
//????? 1
NVIC_InitStructure.NVIC_IRQChannelSubPriority=0x03;
//???? 3
NVIC_InitStructure.NVIC_IRQChannelCmd=ENABLE;
NVIC_Init(&NVIC_InitStructure);
// ???? NVIC
TIM_Cmd(TIM3,ENABLE);
//?????? 3
}
//void TIM2_Init(u16 arr, u16 psc){
//	TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
//	NVIC_InitTypeDef NVIC_InitStructure;
//	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
//	TIM_TimeBaseStructure.TIM_Prescaler=psc;
//	TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
//	TIM_TimeBaseStructure.TIM_Period=arr;
//	TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
//	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);

//	
//	TIM_OCInitTypeDef TIM_OCInitStructure
//	TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
//	TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
//	TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;
//	TIM_OC3Init(TIM2, &TIM_OCInitStructure);

//	TIM_Cmd(TIM2, ENABLE);
//}
void TIM3_IRQHandler(void)
{
if(TIM_GetITStatus(TIM3,TIM_IT_Update)!=RESET) //TIM3 ????
{
LED1=!LED1;
}
TIM_ClearITPendingBit(TIM3,TIM_IT_Update); //???????
}