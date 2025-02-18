#include<stdio.h>
#include<stdlib.h>
#define SIZE 10480
#define NUM 10
struct pool{
	char *blkst;//ָ��ÿ���ڴ���׵�ַ
	int state;//״̬��0Ϊ���У�1Ϊʹ��
	struct pool *next;
}head,rear,a[NUM];
void initMenPool(void);//��ʼ�������
char *getBlock(void);//�����ڴ��
void putBlock(char *recycle);//�����ڴ��
void deleteBlock(void);//�����ڴ��
int numavb(void);//���п��п�
int main(){
	char *p=NULL;
	initMenPool();//��ʼ�������
	p=getBlock();//�����ڴ��
	putBlock(p);//�����ڴ��
	p=NULL;
	deleteBlock();//�����ڴ��
}
void initMenPool(void){//��ʼ�������
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
char *getBlock(void){//�����ڴ��
	if(numavb()){
		for(int i=0;i<NUM;i++){
			if(a[i].state==0){
				a[i].state=1;
				return a[i].blkst;
			}
		}
	}
	else{
		printf("�ڴ治�㣡\n");
		return NULL;
	}
	return NULL;
}
void putBlock(char *recycle){//�����ڴ��
	for(int i=0;i<NUM;i++){
		if(recycle==a[i].blkst) a[i].state=0;
	}
	return;
}
void deleteBlock(void){//�����ڴ��
	free(head.blkst);
}
int numavb(void){//���п��п�
	int n=0;
	for(int i=0;i<NUM;i++){
		if(a[i].state==0) n++;
	}
	return n;
}
