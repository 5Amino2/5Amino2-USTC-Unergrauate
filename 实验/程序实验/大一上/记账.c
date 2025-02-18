#include<stdio.h>
int main(){
	int num100,num50,num20,num10,num5,num1,num05,num01,t=0;
	float money,own;
	printf("请输入你现在拥有的钱：");
a:	scanf("%f",&own);
	if(own<0){
		printf("你欠钱啦！\n重新输入吧！\n");
		goto a;
	}
	for(;;){
		num100=0;num50=0;num20=0;num10=0;num5=0;num1=0;num05=0;num01=0;
b:		printf("\n---菜单---");
		printf("\n[余额：%f]",own);
		printf("\n1.收入");
		printf("\n2.支出");
		printf("\n3.退出\n");
		scanf("%d",&t);
		if(t==1){
			printf("请输入收入金额（单位：元）：");
			scanf("%f",&money);
			if(money<1e-6){
				printf("输入错误！");
				goto b;
			}
			own+=money;
			break;
		}
		if(t==2){
			printf("请输入支出金额（单位：元）：");
			scanf("%f",&money);
			if(money<1e-6){
				printf("输入错误！");
				goto b;
			}
			own-=money;
			break;
		}
		if(t==3){
			return 2;
		}
		else{
			printf("输入错误，请重新输入！");
		}
	}
	while(money>=100){
		money-=100;
		num100++;
	}
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
	if(t==1) printf("收入");
	if(t==2) printf("支出");
	printf("方案：\n100.0元%d张\n50.0元%d张\n20.0元%d张\n10.0元%d张\n5.0元%d张\n1.0元%d张\n0.5元%d张\n0.1元%d张",num100,num50,num20,num10,num5,num1,num05,num01);
	printf("\n你现在的余额：%f",own);
	if(own<0){
		printf("\n你欠钱啦！");
		return -3;
	}
	goto b;
	return 0;
}
