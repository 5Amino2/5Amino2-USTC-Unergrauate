#include<stdio.h>
int main(){
	int year,week,i,runnian=0,day,daymax,m;
	printf("输入一年的年份和1月1日是星期几（1~7）：");
	scanf("%d%d",&year,&week);
	if(year<=0||week<=0||week>=8){//年份必须是正数，星期必须是1~7的整数
		printf("输入错误！");
		return -1;
	}
	if(year%400==0||(year%4==0&&year%100!=0)) runnian=1;//判断闰年
	for(i=1;i<=12;i++){//这里的i是指月份
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)daymax=31;//根据月份确定每月的日期数
		if(i==4||i==6||i==9||i==11)daymax=30;
		if(runnian==1&&i==2)daymax=29;
		if(runnian==0&&i==2)daymax=28;
		printf("%d年%2d月\n",year,i);
		printf("\n星期一 星期二 星期三 星期四 星期五 星期六 星期天\n");
		for(m=0;m<week-1;m++){//每月起始星期的空格
			printf("       ");
		}
		for(day=1;day<=daymax;week++,day++){
			printf("  %-5.2d",day);//打印日期，左对齐
			if(week==7){//到星期天换行
				week=0;
				printf("\n");
			}
		}
		printf("\n\n");
	}
	return 0;
}
