#include<stdio.h>
int main(){
	int n,i;
	int a[45]={0,1};
	printf("请输入一个正整数（3~45）：");
	scanf("%d",&n);
	if(n<3||n>45){//限制范围
		printf("请输入正确的值！");
		return 1;
	}
	printf("斐波那契数列前%d项：0 1",n);
	for(i=3;i<=n;i++){
		a[i]=a[i-1]+a[i-2];//一维数组
		printf(" %d",a[i]);
	}
	return 0;
}
