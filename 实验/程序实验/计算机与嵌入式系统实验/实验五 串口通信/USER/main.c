#include "sys.h" 
#include "delay.h" 
#include "usart.h" 
#include "12864.h"
extern u16 USART_TX_EN;
extern u8 USART_RX_BUF[USART_REC_LEN];
extern u16 USART_RX_STA;
int main()
{

	char USART_SendBuf[]="Hello!";
int i,j;
int Len=strlen(USART_SendBuf);
NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
delay_init(168);
LCD_GPIO_Init();
LCD_Init();
uart_init(115200);
	j=0;
	while(1){
	delay_ms(2000);
if(USART_TX_EN)
{
for(i=0;i<Len;i++)
{
USART_SendData(USART1, USART_SendBuf[i]);
while(USART_GetFlagStatus(USART1,USART_FLAG_TXE)!=SET);
}
USART_TX_EN=0;
}
if(USART_TX_EN==0){
	LCD_Clear();
	LCD_Display_Words(j%4,0,USART_RX_BUF);
	j++;
}
}
//delay_init(168);
//LCD_GPIO_Init();
//LCD_Init();
//while(1)
//{
////LCD_Display_Picture(ImageData);
////delay_ms(2000);
//LCD_Display_Words(0,0,"��");
//LCD_Display_Words(0,1,"˵");
//LCD_Display_Words(0,2,"��");
//LCD_Display_Words(0,3,"��");
//LCD_Display_Words(0,4,"��");
//LCD_Display_Words(0,5,"��");
//LCD_Display_Words(0,6,"��");
//LCD_Display_Words(0,7,"��");
//LCD_Display_Words(1,0,"��");
//LCD_Display_Words(1,1,"ʵ");
//LCD_Display_Words(1,2,"��");
//LCD_Display_Words(1,3,"��");
//LCD_Display_Words(1,4,"һ");
//LCD_Display_Words(1,5,"��");
//LCD_Display_Words(1,6,"��");
//LCD_Display_Words(1,7,"��");
//LCD_Display_Words(2,0,"��");
//LCD_Display_Words(2,1,"��");
//LCD_Display_Words(2,2,"һ");
//LCD_Display_Words(2,3,"��");
//LCD_Display_Words(2,4,"��");
//LCD_Display_Words(2,5,"½");
//LCD_Display_Words(2,6,"��");
//LCD_Display_Words(2,7,"��");
//LCD_Display_Words(3,0,"ȫ");
//LCD_Display_Words(3,1,"��");
//LCD_Display_Words(3,2,"��");
//LCD_Display_Words(3,3,"��");
//LCD_Display_Words(3,4,"��");
//LCD_Display_Words(3,5,"��");
//LCD_Display_Words(3,6,"��");
//LCD_Display_Words(3,7,"Ϸ");
//}
}