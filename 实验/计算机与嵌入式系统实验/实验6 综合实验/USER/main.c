#include "led.h"
#include "timer.h"
#include "pwm.h"
#include "sys.h" 
#include "delay.h" 
#include "usart.h" 
#include "12864.h"

void update(uint8_t* data,uint32_t pwmm);

int main(){
uint32_t pwm=0;
uint8_t data[7]={0};
delay_init(168);
LCD_GPIO_Init();
LCD_Init();
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
TIM2_PWM_Init(3000,0);
LCD_Clear();
	while(1)
{
	
	for(pwm=0;pwm<3000;pwm+=5){
		delay_ms(1);
TIM_SetCompare3(TIM2, pwm); //pwm ?? CCRx
		update(data,pwm);
	LCD_Display_Words(0,0,data);
	}
	for(pwm=3000;pwm>0;pwm-=5){
		delay_ms(1);
TIM_SetCompare3(TIM2, pwm); //pwm ?? CCRx
		update(data,pwm);
	LCD_Display_Words(0,0,data);
	}

}
}
void update(uint8_t* data,uint32_t pwmm){
	data[0]=(pwmm*10/3000)%10+48;
	data[1]=(pwmm*100/3000)%10+48;
	data[2]='.';
	data[3]=(pwmm*1000/3000)%10+48;
	data[4]=(pwmm*10000/3000)%10+48;
	data[5]='%';
	data[6]=0;
}