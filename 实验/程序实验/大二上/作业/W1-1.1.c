//�ҳ�nums�����к�Ϊtarget������ֵ�������±�
#include<stdio.h>
#define N 4
int plus(int *nums,int n,int target,int *output);//output�����¼�±�
int main(){
	int nums[N]={74,12,66,34};
	int n=N;
	int target=46;
	int output[2];
	plus(nums,n,target,output);
	printf("%d %d",output[0],output[1]);
	return 0;
}
int plus(int *nums,int n,int target,int *output){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nums[i]+nums[j]==target){//��¼�±�
				output[0]=i;
				output[1]=j;
				return 1;
			}
		}
	}
	output[0]=-1;
	output[1]=-1;
	return 0;
}
