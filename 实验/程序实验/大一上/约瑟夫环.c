#include<stdio.h>
void josephus(int man[],int n,int m){//����Լɪ�򻷵��㷨
	int i,k,pos;//k:kill order,pos:josephus circle
	for(i=0;i<=n;i++){
		man[i]=0;
	}
	i=k=0;//i�Ǳ����õļ�ʱ��
	for(pos=0;k<n;pos=(pos+1)%n){
		if(man[pos]==0) i++;
		if(i==m){//��������Ϊm��ɱ
			i=0;
			k++;
			man[pos]=k;//��ɱ��˳����k��¼����ǰ��ɱ�ĳ�ʼλ��Ϊpos
		}
	}
}
int sq_find(int a[],int n,int key){//˳������㷨��n��ʾ��������keyΪ��ɱ˳��ֵ
	int i;
	for(i=0;i<n;i++){
		if(key==a[i]) return i;
	}
	return -1;
}
int main(){
	int i,m,n,c;
	int man[100]={0};
	printf("�������ͱ��������");
	scanf("%d%d",&n,&m);
	josephus(man,n,m);
	printf("Լɪ�򻷣�\n");
	for(i=0;i<n;i++){
		printf("%4d%c",man[i],((i+1)%15)==0?'\n':' ');
	}
	printf("\n����Ҫ������������");
	scanf("%d",&c);
	printf("����������Ӧ�����ڣ�");
	for(i=0;i<c;i++){
		printf("%5d",1+sq_find(man,n,(n-i)));
	}
		
}
