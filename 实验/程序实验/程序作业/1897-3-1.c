#include<stdio.h>
#include<math.h>
int main(){
	float x,y,z,p,s;//x��y��zΪ�����ߣ�sΪ���
	int m=0,n=0;//mΪ�ȱ߱���
	printf("�����������ε�3���ߣ�");
	scanf("%f%f%f",&x,&y,&z);
	if(x<=1e-6||y<=1e-6||z<=1e-6){//�����߶�������
		printf("Error");
		return 1;
	}
	if(x+y-z<=0||x+z-y<=1e-6||y+z-x<=1e-6){//������֮�ʹ��ڵ�����
        printf("Error");
		return 2;
	}
	if((fabs(x-z)<=(1e-6)))m++;
	if((fabs(x-y)<=(1e-6)))m++;
	if((fabs(y-z)<=(1e-6)))m++;
	if((fabs(x*x+y*y-z*z)<1e-6)||(fabs(x*x+z*z-y*y)<1e-6)||(fabs(z*z+y*y-x*x)<1e-6))n++;
	p=0.5*(x+y+z);
	s=sqrt(p*(p-x)*(p-y)*(p-z));
	printf("�߳�Ϊ%f,%f,%f����������",x,y,z);
	if(m==3){//�ȱ�������
		printf("�ȱ�������");
		goto end;
	}
	if((m==1)&&(n==1)){//����ֱ��������
		printf("����ֱ��������");
		goto end;
	}
	if(m==1){//����������
		printf("����������");
		goto end;
	}
	if(n==1){//ֱ��������
		printf("ֱ��������");
		goto end;
	}
	if((n==0)&&(m==0)){//һ��������
		printf("һ��������");
		goto end;
	}
end:	printf("�������Ϊ��%f",s);
	    return 0;
}
