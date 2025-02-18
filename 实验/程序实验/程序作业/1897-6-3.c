#include<stdio.h>
int gcd();//gcd函数原型声明，不带形参名
int pcm(int m,int n);//pcm函数原型声明，带形参名
int main(){
	int num1,num2;
	scanf("%d %d",&num1,&num2);
	printf("%d和%d的最大公约数是：%d，最小公倍数是：%d\n",num1,num2,gcd(num1,num2),pcm(num1,num2));
	return 0;
}
int gcd(int m,int n){//求最大公约数的函数与实现
	int s;
	if(m>n){//保证m<n，实现辗转相除法
		s=m;
		m=n;
		n=s;
	}
	while((m!=0)&&(m!=1)){//辗转相除法
		s=m;
		m=n%m;
		n=s;
	}
	if(m==0) return n;//不互质
	if(m==1) return 1;//互质
	return -1;
}
int pcm(int m,int n){//求最小公倍数的函数定义与实现
	return (m*n/gcd(m,n));//调用gcd函数求解最小公倍数
}
