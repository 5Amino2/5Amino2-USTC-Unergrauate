#include<stdio.h>
#include<math.h>
int primenumber(int min,int max,int rank);
int main(){
	int min,max,rank;
	printf("��������������Χ��");
	scanf("%d%d",&min,&max);
	printf("������ÿ�д�ӡ������");
	scanf("%d",&rank);
	primenumber(min,max,rank);
	return 0;
}
int primenumber(int min,int max,int rank){
	int count=0;
	for(int i=min,j,k;i<=max;i++){
		k=sqrt(i);
		for(j=2;j<=k;j++){
			if(i%j==0) break;
		}
		if(j==k+1){
			printf("%8d",i);
			count++;
			if(count%rank==0) printf("\n");
		}
	}
	return count;
}
