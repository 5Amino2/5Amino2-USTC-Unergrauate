#include<stdio.h>
int main(){
	int num50=0,num20=0,num10=0,num5=0,num1=0,num05=0,num01=0;
	float money,money2;
	printf("�����뻨�ѣ���λ��Ԫ����");
	scanf("%f",&money);//�����money�ǻ��ѽ��
	if(money<1e-6||money-100>1e-6){//���ѽ����0~100֮��
		printf("�������");
		return -1;
	}
	money=100-money;//�����moneyתΪ������
	money2=money;//��money2��¼������Ա��ӡ
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
	printf("����%.2fԪ��������50.0Ԫ%d�ţ�20.0Ԫ%d�ţ�10.0Ԫ%d�ţ�5.0Ԫ%d�ţ�1.0Ԫ%d�ţ�0.5Ԫ%d�ţ�0.1Ԫ%d��",money2,num50,num20,num10,num5,num1,num05,num01);
	return 0;
}
