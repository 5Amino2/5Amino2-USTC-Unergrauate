//ɾ��nums�е��ظ���ֵ��������1��
#include<stdio.h>
#define SIZE 5
int single(int &n,int *nums);
int main(){
	int la[SIZE]={1,1,1,3,2};
	int n=SIZE;
	single(n,la);
	for(int i=0;i<n;i++){
		printf("%d ",la[i]);
	}
	return 0;
}
int single(int &n,int *nums){
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(nums[i]==nums[j]){
				for(int k=j;k<n-1;k++){
					nums[k]=nums[k+1];
				}
				n--;
				single(n,nums);//�ٴμ�顢ɾ��
			}
		}
	}
	return 0;
}
