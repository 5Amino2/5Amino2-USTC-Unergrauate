#include<stdio.h>
#include<math.h>
int main(){
	int x,y;
	printf("������x��y��ֵ����������\n");
	scanf("%d%d",&x,&y);
	if (fabs(x)<=2&&fabs(y)<=2){
		printf("Yes");	
	}
	else printf("No");
	return 0;
}
