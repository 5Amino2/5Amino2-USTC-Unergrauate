//取2个数组的交集，用lb输出
#include<stdio.h>
#define MAXSIZE 12
typedef struct{//线性表结构
	int e[MAXSIZE];//元素
	int Length;//长度
}LIST;
int ListDelete(LIST &L,int n);//删除元素
int intersection(LIST la,LIST &lb);//取交集
int main(){
	LIST la,lb;
	la.Length=5;
	lb.Length=5;
	la.e[0]=1;
	la.e[1]=2;
	la.e[2]=5;
	la.e[3]=6;
	la.e[4]=8;
	lb.e[0]=1;
	lb.e[1]=3;
	lb.e[2]=4;
	lb.e[3]=6;
	lb.e[4]=8;
	intersection(la,lb);
	for(int i=0;i<lb.Length;i++){//打印lb
		printf("%d ",lb.e[i]);
	}
	return 0;
}
int intersection(LIST la,LIST &lb){
	for(int i=0;i<lb.Length;i++){
		int n=1;//标记，n=1则删除lb元素
		for(int j=0;j<la.Length;j++){
			if(lb.e[i]==la.e[j]){//存在相同元素则n=0，不删除
				n=0;
				break;
			}
		}
		if(n){
			ListDelete(lb,i);
			i--;//lb已经被缩短，i要-1
		}
	}
	return 0;
}
int ListDelete(LIST &L,int n){
	if(n<0||n>=L.Length) return 0;
	for(int i=n;i<L.Length-1;i++){
		L.e[i]=L.e[i+1];
	}
	L.Length--;//缩短长度
	return 1;
}
