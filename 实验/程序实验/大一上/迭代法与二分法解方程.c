#include<stdio.h>
#include<math.h>
int main(){
	int step1=0,step2=0;//���ַ�ʽ�ĵ�������
	double x,y,k,y1;
	double max,min,mid;
	double a,b,c,d,e,f;
	printf("��ax^5+bx^4+cx^3+dx^2+ex+f=0�Ľ�");
	printf("\n������a��");
    scanf("%lf",&a);
    printf("������b��");
    scanf("%lf",&b);
    printf("������c��");
    scanf("%lf",&c);
    printf("������d��");
    scanf("%lf",&d);
    printf("������e��");
    scanf("%lf",&e);
    printf("������f��");
    scanf("%lf",&f);
	printf("����ţ�ٵ������Ľ��ƽ⣺");
	scanf("%lf",&x);
	do{//ţ�ٵ�����
		y=a*x*x*x*x*x+b*x*x*x*x+c*x*x*x+d*x*x+e*x+f;
		k=5*a*x*x*x*x+4*b*x*x*x+3*c*x*x+2*d*x+e;
		x-=y/k;
		step1++;
		if(step1>=100){
			printf("�޽�����ֹ���");
			return -3;
		}
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
			printf("�޽�����ֹ���");
			return -3;
		}
	}
	while(fabs(y)>1e-6);
	printf("x=%lf,��������Ϊ%d",x,step2);
	return 0;
}
