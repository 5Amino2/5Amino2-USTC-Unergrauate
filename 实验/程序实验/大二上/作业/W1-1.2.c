//数组中出现重复数字返回TURE，否则返回FALSE
#include<stdio.h>
#define N 4
int same(int *nums,int n);
int main(){
	int a[N]={1,2,2,2};
	printf("%d",same(a,N));
	return 0;
}
int same(int *nums,int n){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nums[i]==nums[j]) return 1;
		}
	}
	return 0;
}
