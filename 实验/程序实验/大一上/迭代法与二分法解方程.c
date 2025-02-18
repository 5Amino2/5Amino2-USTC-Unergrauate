#include<stdio.h>
#include<math.h>
int main(){
	int step1=0,step2=0;//两种方式的迭代次数
	double x,y,k,y1;
	double max,min,mid;
	double a,b,c,d,e,f;
	printf("求ax^5+bx^4+cx^3+dx^2+ex+f=0的解");
	printf("\n请输入a：");
    scanf("%lf",&a);
    printf("请输入b：");
    scanf("%lf",&b);
    printf("请输入c：");
    scanf("%lf",&c);
    printf("请输入d：");
    scanf("%lf",&d);
    printf("请输入e：");
    scanf("%lf",&e);
    printf("请输入f：");
    scanf("%lf",&f);
	printf("输入牛顿迭代法的近似解：");
	scanf("%lf",&x);
	do{//牛顿迭代法
		y=a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+f;
		k=5*a*x*x*x*x+4*b*x*x*x+3*c*x*x+2*d*x+e;
		x-=y/k;
		step1++;
		if(step1>=100){
			printf("无解或数字过大！");
			return -3;
		}
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
		y=a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+f;
		y1=a*min*min*min*min*min+b*min*min*min*min+c*min*min*min+d*min*min+e*min+f;
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
		if(step1>=100){
			printf("无解或数字过大！");
			return -3;
		}
	}
	while(fabs(y)>1e-6);
	printf("x=%lf,迭代次数为%d",x,step2);
	return 0;
}
