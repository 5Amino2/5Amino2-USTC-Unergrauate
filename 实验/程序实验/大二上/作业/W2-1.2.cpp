//找出不同值打印出来
#include<stdio.h>
#define SIZE 5
int PrintDifferent(int n,int *nums);
int main(){
	int la[SIZE]={1,1,3,4,1};
	PrintDifferent(SIZE,la);
	return 0;
}
int PrintDifferent(int n,int *nums){
	int m;//记录相同的数
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nums[i]==nums[j]){
				m=nums[i];
				break; break;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(nums[i]!=m){
			printf("%d ",nums[i]);
		}
	}
	return 0;
}
