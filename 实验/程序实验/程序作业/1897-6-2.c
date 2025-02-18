/*
*�����ܣ�ʵ��ƽ������ϵ��ƽ��ͼ�ε�����任
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.141592657//pi����ѧֵ�궨��
struct point{
	double x;//��ĺ�����
	double y;//���������
};
void translation(struct point pt[],double tl_x,double tl_y,int num){
	for(int i=0;i<num;i++){//ѭ���������е�
		pt[i].x+=tl_x;//�������ƽ��
		pt[i].y+=tl_y;//�������ƽ��
	}
}
void scale(struct point pt[],double s_x,double s_y,int num){
	for(int i=0;i<num;i++){//ѭ���������е�
		pt[i].x*=s_x;//ˮƽx������
		pt[i].y*=s_y;//��ֱy������
	}
}
void rotation(struct point pt[],double angle,int num){
	double a[2][2];
	struct point temp;
	angle=angle*PI/180;//�Ƕ���תΪ������
	a[0][0]=cos(angle);
	a[0][1]=-sin(angle);
	a[1][0]=sin(angle);
	a[1][1]=cos(angle);
	for(int i=0;i<num;i++){
		temp.x=pt[i].x;
		temp.y=pt[i].y;
		pt[i].x=temp.x*a[0][0]+a[0][1]*temp.y;
		pt[i].y=temp.x*a[1][0]+a[1][1]*temp.y;
	}
}
int main(){
	int i=0,num=0;
	char mode,action[10];
	double angle,tl_x,tl_y,s_x,s_y;
	struct point pt[10];
	do{
		printf("���������������>=2��");
		scanf("%d",&num);
	}while(num<2);
	for(i=0;i<num;i++){
		printf("�����롾��%d������ĺ�x����y���꣺\n",i+1);
		scanf("%lf%lf",&pt[i].x,&pt[i].y);
	}
	do{
		getchar();
		printf("��ѡ����ʽ��ƽ�ƣ�t�������ţ�s������ת��r����");
		mode=getchar();
	}while(mode!='t'&&mode!='s'&&mode!='r');
	switch(mode){
			case 't':
				printf("������ˮƽ����ֱ��ƽ������");
				scanf("%lf%lf",&tl_x,&tl_y);
				translation(pt,tl_x,tl_y,num);//����ƽ�ƺ���
				strcpy(action,"ƽ��");
				break;
			case 's':
				printf("������ˮƽ����ֱ�����ű�����");
				scanf("%lf%lf",&s_x,&s_y);
				scale(pt,s_x,s_y,num);//�������ź���
				strcpy(action,"����");
				break;
			case 'r':
				printf("��������ת�Ƕȣ����Ƕ��ƣ���ʱ�룩");
				scanf("%lf",&angle);
				rotation(pt,angle,num);//������ת����
				strcpy(action,"��ת");
				break;
	}
	printf("������%s�����������ֵ���£�\n",action);
	for(i=0;i<num;i++){
		printf("��%d���������Ϊ��(%lf,%lf)\n",i+1,pt[i].x,pt[i].y);
	}
	return 0;
}
