#include "sys.h" 
#include "delay.h" 
#include "usart.h" 
#include "12864.h"
int main()
{
delay_init(168);
LCD_GPIO_Init();
LCD_Init();
while(1)
{
//LCD_Display_Picture(ImageData);
//delay_ms(2000);
LCD_Display_Words(0,0,"你");
LCD_Display_Words(0,1,"说");
LCD_Display_Words(0,2,"得");
LCD_Display_Words(0,3,"对");
LCD_Display_Words(0,4,"，");
LCD_Display_Words(0,5,"但");
LCD_Display_Words(0,6,"是");
LCD_Display_Words(0,7,"大");
LCD_Display_Words(1,0,"雾");
LCD_Display_Words(1,1,"实");
LCD_Display_Words(1,2,"验");
LCD_Display_Words(1,3,"是");
LCD_Display_Words(1,4,"一");
LCD_Display_Words(1,5,"款");
LCD_Display_Words(1,6,"发");
LCD_Display_Words(1,7,"生");
LCD_Display_Words(2,0,"在");
LCD_Display_Words(2,1,"《");
LCD_Display_Words(2,2,"一");
LCD_Display_Words(2,3,"教");
LCD_Display_Words(2,4,"大");
LCD_Display_Words(2,5,"陆");
LCD_Display_Words(2,6,"》");
LCD_Display_Words(2,7,"的");
LCD_Display_Words(3,0,"全");
LCD_Display_Words(3,1,"新");
LCD_Display_Words(3,2,"开");
LCD_Display_Words(3,3,"放");
LCD_Display_Words(3,4,"世");
LCD_Display_Words(3,5,"界");
LCD_Display_Words(3,6,"游");
LCD_Display_Words(3,7,"戏");
}
}