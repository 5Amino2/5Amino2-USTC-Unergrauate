#include<stdio.h>
void swap(void *a,void *b,int size){//实现通用数据交换
	char t;
	int i;
	for(i=0;i<size;i++){
		t=*((char *)a+i);
		*((char *)a+i)=*((char *)b+i);
		*((char *)b+i)=t;
	}
}
int intcomp(void *a,void *b){//比较整形数据大小
	return (*(int *)a-*(int *)b);
}
int doublecomp(void *a,void *b){//比较浮点型数据大小
	return (*(double *)a-*(double *)b);
}
int main(){
	
}
