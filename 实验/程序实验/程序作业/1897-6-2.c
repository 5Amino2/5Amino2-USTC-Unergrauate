/*
*程序功能：实现平面坐标系中平面图形的坐标变换
*/
#include<stdio.h>
#include<math.h>
#include<string.h>
#define PI 3.141592657//pi的数学值宏定义
struct point{
	double x;//点的横坐标
	double y;//点的纵坐标
};
void translation(struct point pt[],double tl_x,double tl_y,int num){
	for(int i=0;i<num;i++){//循环处理所有点
		pt[i].x+=tl_x;//横坐标的平移
		pt[i].y+=tl_y;//纵坐标的平移
	}
}
void scale(struct point pt[],double s_x,double s_y,int num){
	for(int i=0;i<num;i++){//循环处理所有点
		pt[i].x*=s_x;//水平x的缩放
		pt[i].y*=s_y;//垂直y的缩放
	}
}
void rotation(struct point pt[],double angle,int num){
	double a[2][2];
	struct point temp;
	angle=angle*PI/180;//角度制转为弧度制
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
		printf("请输入坐标个数（>=2）");
		scanf("%d",&num);
	}while(num<2);
	for(i=0;i<num;i++){
		printf("请输入【第%d个】点的横x，纵y坐标：\n",i+1);
		scanf("%lf%lf",&pt[i].x,&pt[i].y);
	}
	do{
		getchar();
		printf("请选择处理方式：平移（t）、缩放（s）、旋转（r）：");
		mode=getchar();
	}while(mode!='t'&&mode!='s'&&mode!='r');
	switch(mode){
			case 't':
				printf("请输入水平及垂直的平衡量：");
				scanf("%lf%lf",&tl_x,&tl_y);
				translation(pt,tl_x,tl_y,num);//调用平移函数
				strcpy(action,"平移");
				break;
			case 's':
				printf("请输入水平及垂直的缩放比例：");
				scanf("%lf%lf",&s_x,&s_y);
				scale(pt,s_x,s_y,num);//调用缩放函数
				strcpy(action,"缩放");
				break;
			case 'r':
				printf("请输入旋转角度：（角度制，逆时针）");
				scanf("%lf",&angle);
				rotation(pt,angle,num);//调用旋转函数
				strcpy(action,"旋转");
				break;
	}
	printf("经过【%s】处理后，坐标值如下：\n",action);
	for(i=0;i<num;i++){
		printf("第%d个点的坐标为：(%lf,%lf)\n",i+1,pt[i].x,pt[i].y);
	}
	return 0;
}
