#include<stdio.h>
int main(){
	int n,i;
	int a[45]={0,1};
	printf("������һ����������3~45����");
	scanf("%d",&n);
	if(n<3||n>45){//���Ʒ�Χ
		printf("��������ȷ��ֵ��");
		return 1;
	}
	printf("쳲���������ǰ%d�0 1",n);
	for(i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];//һά����
		printf(" %d",a[i]);
	}
	return 0;
}
