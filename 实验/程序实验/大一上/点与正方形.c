#include<stdio.h>
#include<math.h>
int main(){
	int x,y;
	printf("请输入x、y的值（整数）：\n");
	scanf("%d%d",&x,&y);
	if (fabs(x)<=2&&fabs(y)<=2){
		printf("Yes");	
	}
	else printf("No");
	return 0;
}
