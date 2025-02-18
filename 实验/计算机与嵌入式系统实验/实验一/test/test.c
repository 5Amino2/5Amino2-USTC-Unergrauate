#include "stm32f4xx.h"
int num_one(unsigned char input){
	int i;
	int num=0;
	for(i=0;i<8;i++){
		num+=((input>>i)&0x01);
	}
	return num;
}
int main (void) 
{
	unsigned int ui_tmp;
	unsigned int ui_a, ui_b, ui_c;
	static int i_tmp;			//signed int (32bits)
static short s16_tmp;	//signed short (16bits)
static float f_tmp;		//floating point (32bits)
static	int s[8];
	unsigned char uc_c=0x78;
	int k;
	
	//????,??uiTmp, a, b, c??????
	//??????PC???	ui_tmp = 255;
	ui_a = 1;
	ui_b = 2;
	ui_c = 0xFF;

	//?????PSR??????? Negtive	
ui_c = ui_a - ui_b;
	ui_tmp = ui_c;

	//????????(??)	
i_tmp = -1;
	i_tmp = i_tmp - 1;
	s16_tmp = -1;
	s16_tmp = -2;
	s16_tmp = s16_tmp - 32766;
	

	//?????????	
for(k=8; k>0; --k)
		s[k-1] = 0x80000000 + k;

	//??????,(-1)^S×2^(e-127)×(1+M)	
f_tmp = -0.5;						
	f_tmp = f_tmp + 1;
	k=num_one(uc_c);
	ui_tmp = __get_FAULTMASK(); //Get Fault Mask register 
ui_tmp = __get_BASEPRI(); //Get Base Priority register 
ui_tmp = __get_PRIMASK(); //Get Priority Mask Register
ui_tmp = __get_CONTROL(); //Get CONTROL Register 
ui_tmp = __get_xPSR(); //Get xPSR Register 
ui_tmp = __get_MSP(); //Get Main Stack Pointer
				
}
