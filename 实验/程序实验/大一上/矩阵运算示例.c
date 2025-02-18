#include<stdio.h>
#define M 2
#define N 2
#define P 3
int main(){
	static int c[M][N]={0};
	static int a[M][P]={{5,8,3},{11,0,5}};
	static int b[P][N]={{1,18},{2,11},{10,3}};
	int i,j,k;
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			for(k=0;k<P;k++){
				c[i][j]+=a[i][k]*b[k][i];
			}
		}
	}
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			printf("%6d%c",c[i][j],((j+1)%N==0)?'\n':' ');
		}
	}
}
