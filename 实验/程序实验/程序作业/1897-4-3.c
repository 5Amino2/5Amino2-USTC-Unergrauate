#include<stdio.h>
#include<math.h>
int main(){
	int step1=0,step2=0;//两种方式的迭代次数
	double x,y,k,y1;
	double max,min,mid;
	printf("输入牛顿迭代法的近似解：");
	scanf("%lf",&x);
	do{//牛顿迭代法
		y=3*x*x*x-3*x*x+x-6;
		k=9*x*x-6*x+1;
		x-=y/k;
		step1++;
	}
	while(fabs(y)>=1e-6);
	printf("x=%lf,迭代次数为%d",x,step1);
	x=0;y=0;k=0;
	printf("\n输入二分法解的范围：");
	scanf("%lf",&min);
	scanf("%lf",&max);
	if(min>max){//比较大小，若最大值小于最小值则互换
		mid=min;
		min=max;
		max=mid;
	}
	x=(max+min)/2;
	do{//二分法
		y=3*x*x*x-3*x*x+x-6;
		y1=3*min*min*min-3*min*min+min-6;
		step2++;
		if(y*y1>0){
			mid=x;
			x=(x+max)/2;
			min=mid;
		}
		else{
			mid=x;
			x=(x+min)/2;
			max=mid;
		}
	}
	while(fabs(y)>1e-6);
	printf("x=%lf,迭代次数为%d",x,step2);
	return 0;
}
