#include<stdio.h>
int main(){
	int x,y;//y为行数，x为列数
	for(x=1;x<=9;x++){
		for(y=1;y<=x;y++){
			printf("%d*%d=%d ",y,x,y*x);//多加空格比较美观
		}
		printf("\n");//换行
	}
	return 0;
}
