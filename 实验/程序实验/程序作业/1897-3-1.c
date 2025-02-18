#include<stdio.h>
#include<math.h>
int main(){
	float x,y,z,p,s;//x，y，z为三条边，s为面积
	int m=0,n=0;//m为等边边数
	printf("请输入三角形的3个边：");
	scanf("%f%f%f",&x,&y,&z);
	if(x<=1e-6||y<=1e-6||z<=1e-6){//三条边都是正数
		printf("Error");
		return 1;
	}
	if(x+y-z<=0||x+z-y<=1e-6||y+z-x<=1e-6){//两条边之和大于第三边
        printf("Error");
		return 2;
	}
	if((fabs(x-z)<=(1e-6)))m++;
	if((fabs(x-y)<=(1e-6)))m++;
	if((fabs(y-z)<=(1e-6)))m++;
	if((fabs(x*x+y*y-z*z)<1e-6)||(fabs(x*x+z*z-y*y)<1e-6)||(fabs(z*z+y*y-x*x)<1e-6))n++;
	p=0.5*(x+y+z);
	s=sqrt(p*(p-x)*(p-y)*(p-z));
	printf("边长为%f,%f,%f的三角形是",x,y,z);
	if(m==3){//等边三角形
		printf("等边三角形");
		goto end;
	}
	if((m==1)&&(n==1)){//等腰直角三角形
		printf("等腰直角三角形");
		goto end;
	}
	if(m==1){//等腰三角形
		printf("等腰三角形");
		goto end;
	}
	if(n==1){//直角三角形
		printf("直角三角形");
		goto end;
	}
	if((n==0)&&(m==0)){//一般三角形
		printf("一般三角形");
		goto end;
	}
end:	printf("，其面积为：%f",s);
	    return 0;
}
