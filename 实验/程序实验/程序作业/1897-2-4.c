#include<stdio.h>
#include<math.h>
int main(){
	long long int a;
	printf("请输入一个整数（-10000000~10000000）：\n");
	scanf("%d",&a);
	if (fabs(a)>1e+7) {
		printf("您输入的数字超出范围！");
		return 1;
	}
	if ((a%3==0)&&(a%5==0)){
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}
