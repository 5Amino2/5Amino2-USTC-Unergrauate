#include<stdio.h>
#define accuracy 20//����С����ľ���
int main(){
	float m,n;
	int q,i;
	int a[accuracy]={0};
	printf("������һ����������");
	scanf("%f",&m);
	printf("������Ϊ��");
	if(m<0){//����,����Ǹ���˳��ת��
		printf("-");
		m=(-m);
	}
	q=(int)m;//q������
	n=m-q;//n��С��
	for(i=0;q>1;i++){//�����Ĵ���
		a[i]=q%2;//һά����洢
		q=q/2;
	}
	a[i]=q;
	for(;i>=0;i--){
		printf("%d",a[i]);//һά�������������
	}
	if(n<1e-6){//����������������С��ʡ��
		return 2;
	}
	printf(".");//С����
	for(i=1;i<=accuracy;i++){//С���Ĵ���
	n*=2;
	if(n>=1){
		printf("1");
		n-=1;
		if(n<1e-6){//���������С����ֹͣ
			return 1;
		}
	}
	else{
		printf("0");
	}	
	}
	return 0;
}
