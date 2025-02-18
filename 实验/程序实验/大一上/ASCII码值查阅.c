#include<stdio.h>
int main(){
	int m;
	for(int i=0;i<128;i++){
		printf("%d	=	%c(ASCII)\n",i,i);
	}
	printf("请输入你要查询的ASCII码值：");
	scanf("%d",&m);
	printf("%d	=	%c(ASCII)\n",m,m);
}
