#include<stdio.h>
int main(){
	int x,y;//yΪ������xΪ����
	for(x=1;x<=9;x++){
		for(y=1;y<=x;y++){
			printf("%d*%d=%d ",y,x,y*x);//��ӿո�Ƚ�����
		}
		printf("\n");//����
	}
	return 0;
}
