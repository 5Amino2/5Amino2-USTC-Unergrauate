#include<stdio.h>
int gcd();//gcd����ԭ�������������β���
int pcm(int m,int n);//pcm����ԭ�����������β���
int main(){
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	printf("%d��%d�����Լ���ǣ�%d����С�������ǣ�%d\n",num1,num2,gcd(num1,num2),pcm(num1,num2));
	return 0;
}
int gcd(int m,int n){//�����Լ���ĺ�����ʵ��
	int s;
	if(m>n){//��֤m<n��ʵ��շת�����
		s=m;
		m=n;
		n=s;
	}
	while((m!=0)&&(m!=1)){//շת�����
		s=m;
		m=n%m;
		n=s;
	}
	if(m==0) return n;//������
	if(m==1) return 1;//����
	return -1;
}
int pcm(int m,int n){//����С�������ĺ���������ʵ��
	return (m*n/gcd(m,n));//����gcd���������С������
}
