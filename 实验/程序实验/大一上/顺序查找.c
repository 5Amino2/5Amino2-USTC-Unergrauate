#include<stdio.h>
int SequenceSearch(int a[],int value,int n){
	int i;
	for(i=0;i<n;i++){
		if(a[i]==value) return i;
	}
	return -1;
}
void main(){
	int a[10],num,t,i;
	printf("Input 10 numbers:\n");
	for(i=0;i<=9;i++){
		scanf("%d",&a[i]);
	}
	putchar('\n');
	printf("Input research number:\n");
	scanf("%d",&num);
	t=SequenceSearch(a,num,10);
	if(t!=-1)
		printf("num is a[%d]:%d",t,a[t]);
	else
		printf("num is not exist");
	return;
}
