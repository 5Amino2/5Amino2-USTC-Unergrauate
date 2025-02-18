#include"led.h"
#include"timer.h"
#include "pwm.h"

//实验1

//int main(void)
//{
//delay_init(168); //???????
//NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);//??????????? 2
//TIM3_Init(12000-1, 7000-1);//???//TIM3 ???,?????????
//LED_Init();
//while(1)
//{
//delay_ms(500);
//	LED0=!LED0;//LED0 ??????
//}
//}

//实验2

int main(){
uint32_t pwm=0;
delay_init(168);
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
TIM2_PWM_Init(3000,0);
	while(1)
{
	for(pwm=0;pwm<3000;pwm+=5){
		delay_ms(1);
TIM_SetCompare3(TIM2, pwm); //pwm ?? CCRx
	}
	for(pwm=3000;pwm>0;pwm-=5){
		delay_ms(1);
TIM_SetCompare3(TIM2, pwm); //pwm ?? CCRx
	}

}
}