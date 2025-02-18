#include<stdio.h>
#include<stdlib.h>
#define SIZE 10480
#define NUM 10
struct pool{
	char *blkst;//指向每块内存的首地址
	int state;//状态：0为空闲，1为使用
	struct pool *next;
}head,rear,a[NUM];
void initMenPool(void);//初始化缓存池
char *getBlock(void);//分配内存块
void putBlock(char *recycle);//回收内存块
void deleteBlock(void);//销毁内存块
int numavb(void);//现有空闲块
int main(){
	char *p=NULL;
	initMenPool();//初始化缓存池
	p=getBlock();//分配内存块
	putBlock(p);//回收内存块
	p=NULL;
	deleteBlock();//销毁内存块
}
void initMenPool(void){//初始化缓存池
	head.blkst=malloc(SIZE);
	head.state=0;
	for(int i=0;i<NUM;i++){
		a[i].state=0;
		a[i].blkst=head.blkst+SIZE/NUM*i;
		a[i].next=&a[i+1];
	}
	a[NUM-1].next=NULL;
	head=a[0];
	rear=a[NUM-1];
	return;
}
char *getBlock(void){//分配内存块
	if(numavb()){
		for(int i=0;i<NUM;i++){
			if(a[i].state==0){
				a[i].state=1;
				return a[i].blkst;
			}
		}
	}
	else{
		printf("内存不足！\n");
		return NULL;
	}
	return NULL;
}
void putBlock(char *recycle){//回收内存块
	for(int i=0;i<NUM;i++){
		if(recycle==a[i].blkst) a[i].state=0;
	}
	return;
}
void deleteBlock(void){//销毁内存块
	free(head.blkst);
}
int numavb(void){//现有空闲块
	int n=0;
	for(int i=0;i<NUM;i++){
		if(a[i].state==0) n++;
	}
	return n;
}
