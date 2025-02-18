//数组原地逆置
#include<stdio.h>
#define SIZE 5
int reverse(int n,int *num);
int main(){
	int m[SIZE]={3,4,5,7,1};
	reverse(SIZE,m);
	for(int i=0;i<SIZE;i++){
		printf("%d ",m[i]);
	}
	return 0;
}
int reverse(int n,int *num){
	if(n<1) return 0;
	int a[n];//中间临时数组变量
	for(int i=0;i<n;i++){
		a[i]=num[n-1-i];
	}
	for(int i=0;i<n;i++){
		num[i]=a[i];
	}
	return 1;
}
