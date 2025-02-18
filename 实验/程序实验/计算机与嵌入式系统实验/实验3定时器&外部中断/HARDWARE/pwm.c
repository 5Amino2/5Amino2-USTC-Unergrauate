#include "pwm.h"
void TIM2_PWM_Init(u32 arr, u32 psc)
{
GPIO_InitTypeDef GPIO_InitStructure;
TIM_TimeBaseInitTypeDef TIM_TimeBaseStructure;
TIM_OCInitTypeDef TIM_OCInitStructure;
RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2);
GPIO_PinAFConfig(GPIOB,GPIO_PinSource10,GPIO_AF_TIM2);
GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF; //????
GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz; //?? 100MHz
GPIO_InitStructure.GPIO_OType = GPIO_OType_PP; //??????
GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP; //??
GPIO_Init(GPIOB,&GPIO_InitStructure);//......//?? GPIO B10,???? GPIO_Mode_AF ????
TIM_TimeBaseStructure.TIM_Prescaler=psc;
TIM_TimeBaseStructure.TIM_CounterMode=TIM_CounterMode_Up;
TIM_TimeBaseStructure.TIM_Period=arr;
TIM_TimeBaseStructure.TIM_ClockDivision=TIM_CKD_DIV1;
TIM_TimeBaseInit(TIM2,&TIM_TimeBaseStructure);
TIM_OCInitStructure.TIM_OCMode = TIM_OCMode_PWM1;
TIM_OCInitStructure.TIM_OutputState = TIM_OutputState_Enable;
TIM_OCInitStructure.TIM_OCPolarity = TIM_OCPolarity_High ;
TIM_OC3Init(TIM2, &TIM_OCInitStructure);//......//?? TIM_TimeBaseStructure,? 3.1
TIM_Cmd(TIM2, ENABLE);
}