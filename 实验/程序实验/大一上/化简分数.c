#include<stdio.h>
int main(){
	int m,n,p,q,s;
	printf("请输入两个正整数（分子 分母）：");//m、p为分子，n、q为分母
again:	scanf("%d %d",&m,&n);
	if(m<=0||n<=0){//正整数
		printf("请输入两个正整数！");
		goto again;//再次输入
	}
	if(m>n){//分子大于分母
		printf("分子大于分母！");
		goto again;//再次输入
	}
	for(p=m,q=n;(p!=0)&&(p!=1);){//辗转相除法求最大公约数
		s=p;
		p=q%p;
		q=s;
	}
	if(p==0){//分子分母可化简
		printf("分数%d/%d 化简后为%d/%d",m,n,m/q,n/q);
	}
	if(p==1){//分子分母互质
		printf("分数%d/%d 化简后为%d/%d",m,n,m,n);
	}
	return 0;
}
