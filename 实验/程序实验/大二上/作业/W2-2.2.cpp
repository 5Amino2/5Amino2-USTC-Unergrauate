//ȡ2������Ľ�������lb���
#include<stdio.h>
#define MAXSIZE 12
typedef struct{//���Ա�ṹ
	int e[MAXSIZE];//Ԫ��
	int Length;//����
}LIST;
int ListDelete(LIST &L,int n);//ɾ��Ԫ��
int intersection(LIST la,LIST &lb);//ȡ����
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
	for(int i=0;i<lb.Length;i++){//��ӡlb
		printf("%d ",lb.e[i]);
	}
	return 0;
}
int intersection(LIST la,LIST &lb){
	for(int i=0;i<lb.Length;i++){
		int n=1;//��ǣ�n=1��ɾ��lbԪ��
		for(int j=0;j<la.Length;j++){
			if(lb.e[i]==la.e[j]){//������ͬԪ����n=0����ɾ��
				n=0;
				break;
			}
		}
		if(n){
			ListDelete(lb,i);
			i--;//lb�Ѿ������̣�iҪ-1
		}
	}
	return 0;
}
int ListDelete(LIST &L,int n){
	if(n<0||n>=L.Length) return 0;
	for(int i=n;i<L.Length-1;i++){
		L.e[i]=L.e[i+1];
	}
	L.Length--;//���̳���
	return 1;
}
