#include<stdio.h>
int main(){
	int n,i;
	int a[45]={0,1};
	printf("������Ҫ���쳲���������������3~45����");
	scanf("%d",&n);
	if(n<3||n>45){//���Ʒ�Χ
		printf("��������ȷ��ֵ��");
		return 1;
	}
	printf("쳲���������ǰ%d�\n",n);
	printf("%-15d ",a[0]);
	printf("%-15d ",a[1]);
	for(i=2;i<=n-1;i++){
		a[i]=a[i-1]+a[i-2];//һά����
		printf("%-15d ",a[i]);
		if(i%8==7) printf(":\n");
	}
	return 0;
}
