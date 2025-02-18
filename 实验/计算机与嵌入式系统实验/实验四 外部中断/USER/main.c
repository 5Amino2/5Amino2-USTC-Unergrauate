#include "stm32f4xx.h"
#include "delay.h"//延时函数所在的头文件
#include "led.h"
#include "key.h"
#include "exti.h"
int main(void)
{
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
delay_init(168);
LED_Init();
KEY_Init();
EXTIX_Init();
LED0=1;
while(1)
{
} 
}