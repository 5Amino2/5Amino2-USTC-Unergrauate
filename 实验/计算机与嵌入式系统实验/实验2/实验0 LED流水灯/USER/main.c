#include "stm32f4xx.h"
#include "delay.h"//延时函数所在的头文件
#include "sys.h"

void LED_Init(void); 		

//#define ON   Bit_SET     //GPIO的布尔变量，用于GPIO_WriteBit函数
//#define OFF  Bit_RESET   //GPIO的布尔变量，用于GPIO_WriteBit函数

#define ON 1
#define OFF 0

//#define LED0(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_11, x)//写IO口状态，0/1
//#define LED1(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_10, x)
//#define LED2(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_9, x)
//#define LED3(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_7, x)
//#define LED4(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_3, x)
//#define LED5(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_2, x)
//#define LED6(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_13, x)
//#define LED7(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_12, x)

#define LED0(y) PGout(11)=y
#define LED1(y) PGout(10)=y
#define LED2(y) PGout(9)=y
#define LED3(y) PDout(7)=y
#define LED4(y) PGout(3)=y
#define LED5(y) PGout(2)=y
#define LED6(y) PDout(13)=y
#define LED7(y) PDout(12)=y

int main(void)
{ 
	LED_Init();		       //初始化LED端口
	delay_init(168);     //初始化延时函数

	while(1)
	{
		/*流水灯显示*/
		LED0(ON);delay_ms(500);LED0(OFF);delay_ms(500);
		LED1(ON);delay_ms(500);LED1(OFF);delay_ms(500);
		LED2(ON);delay_ms(500);LED2(OFF);delay_ms(500);
		LED3(ON);delay_ms(500);LED3(OFF);delay_ms(500);
		LED4(ON);delay_ms(500);LED4(OFF);delay_ms(500);
		LED5(ON);delay_ms(500);LED5(OFF);delay_ms(500);
		LED6(ON);delay_ms(500);LED6(OFF);delay_ms(500);
		LED7(ON);delay_ms(500);LED7(OFF);delay_ms(500);      
 	}
}
void LED_Init(void)
{    	 
  GPIO_InitTypeDef  GPIO_InitStructure;   //GPIO初始化结构体
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG|
								RCC_AHB1Periph_GPIOD, ENABLE);//使能GPIOG、GPIOD时钟

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_9 | GPIO_Pin_2 | GPIO_Pin_3;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOG, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOG,GPIO_Pin_11 | GPIO_Pin_10 | GPIO_Pin_7 | GPIO_Pin_9 | GPIO_Pin_2 | GPIO_Pin_3);//LED1,LED2,LED3,LED4,LED5

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_7 |GPIO_Pin_12 | GPIO_Pin_13;				 
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
  GPIO_Init(GPIOD, &GPIO_InitStructure);
	GPIO_ResetBits(GPIOD, GPIO_Pin_7 |GPIO_Pin_12|GPIO_Pin_13);  //LED6,LED7		 
}

