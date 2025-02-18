#include "stm32f4xx.h"
#include "stm32f4xx_exti.h"
#include "stm32f4xx_syscfg.h"
#include "sys.h"
void LED_Init(void); 		

#define ON   Bit_SET     //GPIO的布尔变量，用于GPIO_WriteBit函数
#define OFF  Bit_RESET   //GPIO的布尔变量，用于GPIO_WriteBit函数

//#define LED0(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_11, x)//写IO口状态，0/1
//#define LED1(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_10, x)
#define LED2(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_9, x)
#define LED3(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_7, x)
#define LED4(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_3, x)
#define LED5(x)  GPIO_WriteBit(GPIOG, GPIO_Pin_2, x)
#define LED6(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_13, x)
#define LED7(x)  GPIO_WriteBit(GPIOD, GPIO_Pin_12, x)
#define LED1 PGout(10)
#define LED0 PGout(11)