#include<stdio.h>
#include<stdlib.h>
int main(){
	int max,min,seed,guess,random,money,seed2,i;
	printf("输入随机数种子：");
	scanf("%d",&seed);
	printf("输入产生随机数的最小值：");
	scanf("%d",&min);
	printf("输入产生随机数的最大值：");
	scanf("%d",&max);
	if(max<min){//最大值不能小于最小值
		printf("输入错误！");
		return -1;
	}
	printf("已在%d-%d范围内产生了一个随机数，猜猜此数：",min,max);
	scanf("%d",&guess);
	srand(seed);//第一种产生随机数的方法：srand函数
	random=rand()%(max-min+1)+min;
	seed2=random;
	seed2=seed2*1103515245+12345;
	money=(unsigned)(seed2/65536)%114514+1;//第二种产生随机数的方法，用要猜的数当生成金额的种子
	for(i=0;i<5;i++){
		if(guess==random){//猜中了
			printf("恭喜你猜中了！并获得%d元红包。",money);
			return 0;
		}
		if(guess<random){
			printf("你猜的数小了，请继续在%d-%d范围内猜数字：",min,max);
			scanf("%d",&guess);
		} 
		if(guess>random){
			printf("你猜的数大了，请继续在%d-%d范围内猜数字：",min,max);
			scanf("%d",&guess);
		}
	}
	printf("\n请输入正确的数值！");
	return -1;
}
