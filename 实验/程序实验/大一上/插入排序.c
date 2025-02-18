#include<stdio.h>
void InsertSort(int r[],int n){
	int i,j,temp;
	for(i=1;i<n;i++){
		temp=r[i];
		for(j=i;j>0;j--){
			if(temp<r[j-1]) r[j]=r[j-1];
			else break;
		}
		r[j]=temp;
	}
}
int main(){
	int num[]={5,4,90,0,-3,113,65,783,-80,35},i;
	InsertSort(num,10);
	for(i=0;i<10;i++){
		printf("%d",num[i]);
		putchar('\n');
	}
	return 0;
}
