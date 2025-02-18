#include<stdio.h>
int bin_search(int a[],int n,int key){
	int low,high,mid;
	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;//二分查找
		mid=low+(key-a[low])/(a[high]-a[low])*(high-low);//差值查找
		if(a[mid]==key) return mid;
		if(a[mid]<key) low=mid+1;
		if(a[mid]>key) high=mid-1;
	}
	return -1;
}
int SearchPlus(int a[],int value,int low,int high){//递归法实现查找
	int mid=low+(value-a[low])/(a[high]-a[low])*(high-low);
	if(a[mid]==value) return mid;
	if(a[mid]<value) return SearchPlus(a,value,low,mid-1);
	if(a[mid]<value) return SearchPlus(a,value,mid+1,high);
	return -1;
}
int main(){
	int a[20],i,k;
	for(i=0;i<20;i++) a[i]=2*i;
	printf("array is:");
	for(i=0;i<20;i++) printf("%3d",a[i]);
	printf("\ninput number:");
	scanf("%d",&k);
	i=bin_search(a,20,k);
	if(i!=-1)
		printf("a[%d]=%d\n",i,a[i]);
	else
		printf("not found!");
}
