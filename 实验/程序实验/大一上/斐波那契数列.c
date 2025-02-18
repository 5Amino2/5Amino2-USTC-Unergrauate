#include<stdio.h>
int main(){
	int n,i;
	int a[45]={0,1};
	printf("请输入要求的斐波那契数列项数（3~45）：");
	scanf("%d",&n);
	if(n<3||n>45){//限制范围
		printf("请输入正确的值！");
		return 1;
	}
	printf("斐波那契数列前%d项：\n",n);
	printf("%-15d ",a[0]);
	printf("%-15d ",a[1]);
	for(i=2;i<=n-1;i++){
		a[i]=a[i-1]+a[i-2];//一维数组
		printf("%-15d ",a[i]);
		if(i%8==7) printf(":\n");
	}
	return 0;
}
