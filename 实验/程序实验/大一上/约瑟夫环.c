#include<stdio.h>
void josephus(int man[],int n,int m){//构造约瑟夫环的算法
	int i,k,pos;//k:kill order,pos:josephus circle
	for(i=0;i<=n;i++){
		man[i]=0;
	}
	i=k=0;//i是报数用的计时器
	for(pos=0;k<n;pos=(pos+1)%n){
		if(man[pos]==0) i++;
		if(i==m){//报道人数为m自杀
			i=0;
			k++;
			man[pos]=k;//自杀的顺序用k记录，当前自杀的初始位置为pos
		}
	}
}
int sq_find(int a[],int n,int key){//顺序查找算法，n表示总人数，key为自杀顺序值
	int i;
	for(i=0;i<n;i++){
		if(key==a[i]) return i;
	}
	return -1;
}
int main(){
	int i,m,n,c;
	int man[100]={0};
	printf("总人数和报数间隔：");
	scanf("%d%d",&n,&m);
	josephus(man,n,m);
	printf("约瑟夫环：\n");
	for(i=0;i<n;i++){
		printf("%4d%c",man[i],((i+1)%15)==0?'\n':' ');
	}
	printf("\n你想要保护的人数：");
	scanf("%d",&c);
	printf("被保护的人应该排在：");
	for(i=0;i<c;i++){
		printf("%5d",1+sq_find(man,n,(n-i)));
	}
		
}
