#include<stdio.h>
#define accuracy 20//定义小数点的精度
int main(){
	float m,n;
	int q,i;
	int a[accuracy]={0};
	printf("请输入一个浮点数：");
	scanf("%f",&m);
	printf("二进制为：");
	if(m<0){//符号,如果是负数顺便转正
		printf("-");
		m=(-m);
	}
	q=(int)m;//q是整数
	n=m-q;//n是小数
	for(i=0;q>1;i++){//整数的处理
		a[i]=q%2;//一维数组存储
		q=q/2;
	}
	a[i]=q;
	for(;i>=0;i--){
		printf("%d",a[i]);//一维数组输出（倒序）
	}
	if(n<1e-6){//如果输入的是整数则小数省略
		return 2;
	}
	printf(".");//小数点
	for(i=1;i<=accuracy;i++){//小数的处理
	n*=2;
	if(n>=1){
		printf("1");
		n-=1;
		if(n<1e-6){//如果是有限小数则停止
			return 1;
		}
	}
	else{
		printf("0");
	}	
	}
	return 0;
}
