#include "stm32f4xx.h"
#include "delay.h"//延时函数所在的头文件
#include "sys.h"
void LED_Init(void);
#define ON 1
#define OFF 0
//#define LED0(y) PGout(11)=y
//#define LED1(y) PGout(10)=y
#define LED2(y) PGout(9)=y
#define LED3(y) PDout(7)=y
#define LED4(y) PGout(3)=y
#define LED5(y) PGout(2)=y
#define LED6(y) PDout(13)=y
#define LED7(y) PDout(12)=y
#define LED1 PGout(10)
#define LED0 PGout(11)