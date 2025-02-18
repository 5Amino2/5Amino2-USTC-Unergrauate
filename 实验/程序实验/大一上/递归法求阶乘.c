#include<stdio.h>
int fac(int n){
	int f;
	if(n<0) return -1;
	if(n==0||n==1) f=1;
	else f=fac(n-1)*n;
	return f;
}
int main(){
	int m;
	printf("请输入你要求的阶乘：");
	scanf("%d",&m);
	printf("%d!=",m);
	printf("%d",fac(m));
}
