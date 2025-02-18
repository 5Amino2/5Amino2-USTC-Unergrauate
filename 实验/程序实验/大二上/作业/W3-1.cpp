#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{//
	int x;
	NODE *next;
}NODE;
NODE *reverse(NODE *Head);//Á´±íÄæÖÃ
int exchange(NODE *Head);//Á½Á½ÄæÖÃ
int main(){
	NODE *Head=(NODE *)malloc(sizeof(NODE));
	NODE *p=Head;
	for(int i=1;i<7;i++){
		p->x=i;
		p->next=(NODE *)malloc(sizeof(NODE));
		p=p->next;
	}
	p->next=NULL;
	//Head=reverse(Head);
	exchange(Head);
	for(p=Head;p->next!=NULL;p=p->next){
		printf("%d ",p->x);
	}
}
NODE *reverse(NODE *Head){
	NODE *p,*q,*t;
	if(Head->next==NULL||Head==NULL){
		return NULL;
	}
	p=Head->next;
	q=p->next;
	p->next=Head;
	Head->next=NULL;
	if(q==NULL){
		Head=p;
		return 0;
	}
	while(q->next!=NULL){
		t=p;
		p=q;
		q=q->next;
		p->next=t;
	}
	q->next=p;
	Head=q;
	return Head;
}
int exchange(NODE *Head){
	int count;
	NODE *p,*q;
	for(p=Head,q=Head->next;p!=NULL&&q!=NULL;p=q->next,q=p->next){
		count=p->x;
		p->x=q->x;
		q->x=count;
	}
	return 0;
}
