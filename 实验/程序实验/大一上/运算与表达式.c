#include<stdio.h>
int main(){
	int a=2,b=3,c=4;
	float x=3.5,y=4.8;
	int choice;
loop:	printf("1.算术运算\n");//1.算术运算
	    printf("a)");//a
  	    printf("%f\n",3.5+1/2+56%10);
	    printf("b)");//b
	    printf("%f\n",(float)a++*1/3);
	    printf("c)");//c
	    printf("%f\n",x+a%3*(int)(x+y)%2/4);	
	    printf("d)");//d
	    printf("%f\n",(float)(a+b)/2+(int)x%(int)y);
	printf("2.关系、逻辑运算\n");//2.关系、逻辑运算
	    printf("a)");//a
	    printf("%d\n",b>c&&b==c);
	    printf("b)");//b
	    printf("%d\n",!(a>b)&&!c||1);
	    printf("c)");//c
	    printf("%d\n",!(x=a)&&(y=b)&&0);	
	    printf("d)");//d
	    printf("%d\n",!(a+b)+c-1&&b+c/2);
	    printf("e)");//e
	    printf("%d\n",1&&30%10>=0&&30%10<=3);
	printf("3.赋值、条件表达式\n");//3.赋值、条件表达式
	    printf("a)");//a
	    printf("%d\n",a+=a+b);
	    printf("b)");//b
	    printf("%d\n",a*=b%c);
	    printf("c)");//c
	    printf("%d\n",a/=c-a);	
	    printf("d)");//d
	    printf("%d\n",a+=a-=a*=a);
	    printf("e)");//e
	    printf("%d\n",a=(a=++b,a+5,a/5));
	    printf("f)");//f
	    printf("%d\n",(a>=b>=2)?1:0);
	printf("你还要继续吗？\n");//再次赋值
	printf("0.结束\n");
	printf("1.继续\n");
	scanf("%d",&choice);
	if (choice==0){
		return 0;
	}
	if (choice==1){
		printf("请输入a、b、c的值（整型）\n");
		scanf("%d%d%d",&a,&b,&c);
		printf("请输入x、y的值（浮点型）\n");
		scanf("%f%f",&x,&y);
		goto loop;//goto语句再次回到之前
		}
	if (choice!=0&&choice!=1){
		printf("请输入正确的值！");
		return 2;
	}
	return 1;
}
