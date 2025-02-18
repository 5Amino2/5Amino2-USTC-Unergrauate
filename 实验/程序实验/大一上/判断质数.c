#include<stdio.h>
#include<math.h>
int IsPrime(int n);
int main(){
	int m;
	printf("请输入一个数：");
	scanf("%d",&m);
	printf("%d",IsPrime(m));
	return 0;
}
int IsPrime(int n){
	for(int i=2;i*i<n;){
		if(n%i==0) return 0;
		else i++;
	}
	return 1;
}
