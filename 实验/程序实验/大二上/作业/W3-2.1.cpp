#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{//
	int x;
	NODE *next;
}NODE;
int deletecircle(NODE *Head);//给定指针，缩小循环链表
int main(){
	NODE *Head=(NODE *)malloc(sizeof(NODE));
	NODE *p=Head;
	for(int i=1;i<7;i++){
		p->x=i;
		p->next=(NODE *)malloc(sizeof(NODE));
		p=p->next;
	}
	p->next=Head;
	deletecircle(Head);
	for(p=Head;p->next!=NULL;p=p->next){
		printf("%d ",p->x);
	}
}
int deletecircle(NODE *Head){
	NODE *p;
	for(p=Head;p->next->next!=Head;p=p->next);
	free(p->next);
	p->next=Head;
	return 0;
}
