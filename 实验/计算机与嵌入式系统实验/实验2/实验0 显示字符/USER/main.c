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
LCD_Display_Words(0,0,"��");
LCD_Display_Words(0,1,"˵");
LCD_Display_Words(0,2,"��");
LCD_Display_Words(0,3,"��");
LCD_Display_Words(0,4,"��");
LCD_Display_Words(0,5,"��");
LCD_Display_Words(0,6,"��");
LCD_Display_Words(0,7,"��");
LCD_Display_Words(1,0,"��");
LCD_Display_Words(1,1,"ʵ");
LCD_Display_Words(1,2,"��");
LCD_Display_Words(1,3,"��");
LCD_Display_Words(1,4,"һ");
LCD_Display_Words(1,5,"��");
LCD_Display_Words(1,6,"��");
LCD_Display_Words(1,7,"��");
LCD_Display_Words(2,0,"��");
LCD_Display_Words(2,1,"��");
LCD_Display_Words(2,2,"һ");
LCD_Display_Words(2,3,"��");
LCD_Display_Words(2,4,"��");
LCD_Display_Words(2,5,"½");
LCD_Display_Words(2,6,"��");
LCD_Display_Words(2,7,"��");
LCD_Display_Words(3,0,"ȫ");
LCD_Display_Words(3,1,"��");
LCD_Display_Words(3,2,"��");
LCD_Display_Words(3,3,"��");
LCD_Display_Words(3,4,"��");
LCD_Display_Words(3,5,"��");
LCD_Display_Words(3,6,"��");
LCD_Display_Words(3,7,"Ϸ");
}
}