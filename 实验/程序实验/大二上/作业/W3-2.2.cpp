#include<stdio.h>
#include<stdlib.h>
typedef struct NODE{//
	int x;
	NODE *next;
}NODE;
int main(){
	
}
NODE *lc(NODE *la,NODE *lb,int i,int j){//la��ȥ��iԪ�ؼ���֮�󣬲��lb��jԪ��֮ǰ
	NODE *p=la;
	NODE *q,*t;
	for(int k=1;k<i-1;k++){
		p=p->next;
	}
	t=p;
	p=p->next;
	while(p->next!=NULL){
		q=p;
		p=p->next;
		free(q);
	}
	free(p);
	p=lb;
	for(int k=1;k<j-1;k++){
		p=p->next;
	}
	t->next=p->next;
	p->next=la;
	return lb;
}
