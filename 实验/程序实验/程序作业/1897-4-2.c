#include<stdio.h>
int main(){
	int n,i,max=0;
	int a[20]={0};//暂且假设输入的整数不会大于20
	printf("有几个整数？");
	scanf("%d",&n);
	if(n<=0){//n是正整数
		printf("输入错误！");
		return -1;
	}
	if(n>20){//超出范围
		printf("超出范围！");
		return -2;
	}
	printf("输入%d个整数：",n);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){//选择数组中的最大项
		if(a[max]<a[i]){
			max=i;
		}
	}
	printf("最大数位于最后：");
	for(i=0;i<n;i++){
		if(i==max) continue;//continue语句结束一次循环
		printf("%d ",a[i]);
	}
	printf("%d",a[max]);
	return 0;
}
