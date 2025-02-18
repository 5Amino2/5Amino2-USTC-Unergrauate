#include<stdio.h>
int main(){
	int num50=0,num20=0,num10=0,num5=0,num1=0,num05=0,num01=0;
	float money,money2;
	printf("请输入花费（单位：元）：");
	scanf("%f",&money);//这里的money是花费金额
	if(money<1e-6||money-100>1e-6){//花费金额在0~100之间
		printf("输入错误！");
		return -1;
	}
	money=100-money;//这里把money转为找零金额
	money2=money;//用money2记录找零金额，以便打印
	while(money>=50){
		money-=50;
		num50++;
	}
	while(money>=20){
		money-=20;
		num20++;
	}
	while(money>=10){
		money-=10;
		num10++;
	}
	while(money>=5){
		money-=5;
		num5++;
	}
	while(money>=1){
		money-=1;
		num1++;
	}
	while(money>=0.5){
		money-=0.5;
		num05++;
	}
	while(money>=0.1){
		money-=0.1;
		num01++;
	}
	if(money-0.05>=1e-6){
		num01++;
	}
	printf("找零%.2f元，方案：50.0元%d张，20.0元%d张，10.0元%d张，5.0元%d张，1.0元%d张，0.5元%d张，0.1元%d张",money2,num50,num20,num10,num5,num1,num05,num01);
	return 0;
}
