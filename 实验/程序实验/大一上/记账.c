#include<stdio.h>
int main(){
	int num100,num50,num20,num10,num5,num1,num05,num01,t=0;
	float money,own;
	printf("������������ӵ�е�Ǯ��");
a:	scanf("%f",&own);
	if(own<0){
		printf("��ǷǮ����\n��������ɣ�\n");
		goto a;
	}
	for(;;){
		num100=0;num50=0;num20=0;num10=0;num5=0;num1=0;num05=0;num01=0;
b:		printf("\n---�˵�---");
		printf("\n[��%f]",own);
		printf("\n1.����");
		printf("\n2.֧��");
		printf("\n3.�˳�\n");
		scanf("%d",&t);
		if(t==1){
			printf("�������������λ��Ԫ����");
			scanf("%f",&money);
			if(money<1e-6){
				printf("�������");
				goto b;
			}
			own+=money;
			break;
		}
		if(t==2){
			printf("������֧������λ��Ԫ����");
			scanf("%f",&money);
			if(money<1e-6){
				printf("�������");
				goto b;
			}
			own-=money;
			break;
		}
		if(t==3){
			return 2;
		}
		else{
			printf("����������������룡");
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
	if(t==1) printf("����");
	if(t==2) printf("֧��");
	printf("������\n100.0Ԫ%d��\n50.0Ԫ%d��\n20.0Ԫ%d��\n10.0Ԫ%d��\n5.0Ԫ%d��\n1.0Ԫ%d��\n0.5Ԫ%d��\n0.1Ԫ%d��",num100,num50,num20,num10,num5,num1,num05,num01);
	printf("\n�����ڵ���%f",own);
	if(own<0){
		printf("\n��ǷǮ����");
		return -3;
	}
	goto b;
	return 0;
}
