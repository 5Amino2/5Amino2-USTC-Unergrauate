#include<stdio.h>
int main(){
	float x,m;
	int y,z;
	printf("请输入x的值：\n");
	scanf("%f",&x);
	if ((x-0)<(1e-6)||(x-30)>=(1e-6)){//限定范围
		printf("您输入的值超出范围！");
		return 2;
	}
	if ((float)x-(int)x<=1e-6){//x为整型
		y=(int)x;
		switch(y/10){
			case 0: z=y;
			break;
			case 1: z=y*y+1;
			break;
			case 2: z=y*y*y+y*y+1;
			break;
		}
		printf("x=%d时，y=%d",y,z);
	}
	else {//x为浮点型
		if (((x-0)<=(1e-6))||((x>0)&&(x<10))){
			m=x;
		}
		else if(((x-10)<=(1e-6))||((x>10)&&(x<20))){
			m=x*x+1;	
		}
		else if(((x-20)<=(1e-6))||((x>20)&&(x<30))){
			m=x*x*x+x*x+1;
		}
		printf("x=%f时，y=%f",x,m);
	}
	return 1;
}
