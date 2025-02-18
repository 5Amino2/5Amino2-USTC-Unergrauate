#include<stdio.h>
int comma(char a[],int length);
int main(){
	char a[200];
	char ch;
	int num=0,n;
	printf("请输入带有括号的字符串：\n");
	while((ch=getchar())!='\n'){
		a[num]=ch;
		num++;
	}
	n=comma(a,num);
	if(n==0) printf("FALSE");
	if(n==1) printf("TRUE");
}
int comma(char a[],int length){
	int rank=0;
	for(int i=0;i<length;i++){
		if((*a)=='(') rank++;
		if((*a)==')') rank--;
		if(rank<0) return 0;
		a++;
	}
	if(rank==0) return 1;
	else return 0;
}
