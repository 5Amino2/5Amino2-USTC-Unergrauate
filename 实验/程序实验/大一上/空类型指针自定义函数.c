#include<stdio.h>
void swap(void *a,void *b,int size){//ʵ��ͨ�����ݽ���
	char t;
	int i;
	for(i=0;i<size;i++){
		t=*((char *)a+i);
		*((char *)a+i)=*((char *)b+i);
		*((char *)b+i)=t;
	}
}
int intcomp(void *a,void *b){//�Ƚ��������ݴ�С
	return (*(int *)a-*(int *)b);
}
int doublecomp(void *a,void *b){//�Ƚϸ��������ݴ�С
	return (*(double *)a-*(double *)b);
}
int main(){
	
}
