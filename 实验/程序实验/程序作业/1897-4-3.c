#include<stdio.h>
#include<math.h>
int main(){
	int step1=0,step2=0;//���ַ�ʽ�ĵ�������
	double x,y,k,y1;
	double max,min,mid;
	printf("����ţ�ٵ������Ľ��ƽ⣺");
	scanf("%lf",&x);
	do{//ţ�ٵ�����
		y=3*x*x*x-3*x*x+x-6;
		k=9*x*x-6*x+1;
		x-=y/k;
		step1++;
	}
	while(fabs(y)>=1e-6);
	printf("x=%lf,��������Ϊ%d",x,step1);
	x=0;y=0;k=0;
	printf("\n������ַ���ķ�Χ��");
	scanf("%lf",&min);
	scanf("%lf",&max);
	if(min>max){//�Ƚϴ�С�������ֵС����Сֵ�򻥻�
		mid=min;
		min=max;
		max=mid;
	}
	x=(max+min)/2;
	do{//���ַ�
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
	printf("x=%lf,��������Ϊ%d",x,step2);
	return 0;
}
