#include<stdio.h>
int main(){
	int n,i,max=0;
	int a[20]={0};//���Ҽ�������������������20
	printf("�м���������");
	scanf("%d",&n);
	if(n<=0){//n��������
		printf("�������");
		return -1;
	}
	if(n>20){//������Χ
		printf("������Χ��");
		return -2;
	}
	printf("����%d��������",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){//ѡ�������е������
		if(a[max]<a[i]){
			max=i;
		}
	}
	printf("�����λ�����");
	for(i=0;i<n;i++){
		if(i==max) continue;//continue������һ��ѭ��
		printf("%d ",a[i]);
	}
	printf("%d",a[max]);
	return 0;
}
