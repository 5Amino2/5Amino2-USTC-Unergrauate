#include<stdio.h>
int main(){
	int year,week,i,runnian=0,day,daymax,m;
	printf("����һ�����ݺ�1��1�������ڼ���1~7����");
	scanf("%d%d",&year,&week);
	if(year<=0||week<=0||week>=8){//��ݱ��������������ڱ�����1~7������
		printf("�������");
		return -1;
	}
	if(year%400==0||(year%4==0&&year%100!=0)) runnian=1;//�ж�����
	for(i=1;i<=12;i++){//�����i��ָ�·�
		if(i==1||i==3||i==5||i==7||i==8||i==10||i==12)daymax=31;//�����·�ȷ��ÿ�µ�������
		if(i==4||i==6||i==9||i==11)daymax=30;
		if(runnian==1&&i==2)daymax=29;
		if(runnian==0&&i==2)daymax=28;
		printf("%d��%2d��\n",year,i);
		printf("\n����һ ���ڶ� ������ ������ ������ ������ ������\n");
		for(m=0;m<week-1;m++){//ÿ����ʼ���ڵĿո�
			printf("       ");
		}
		for(day=1;day<=daymax;week++,day++){
			printf("  %-5.2d",day);//��ӡ���ڣ������
			if(week==7){//�������컻��
				week=0;
				printf("\n");
			}
		}
		printf("\n\n");
	}
	return 0;
}
