#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define Lengthmax 50//最大数组长度
void clearCache(void);//去回车
void set(void);//配置系统参数
void printMenu(void);//主菜单
void printMenu1(void);//子菜单
void randbuild(int a[],int arrayLength);//产生随机样本数据
void keyinput(int a[],int arrayLength);//键盘输入
void inputsame(int a[],int arrayLength);//整个数组填同一个值
void inputdengcha(int a[],int arrayLength);//用等差序列填充数组
void printarray(int a[],int arrayLength,int numsPreline,char splitChar);//打印数组
void deletearray(void);//删除数组
void deleteone(int a[],int arrayLength);//删除指定下标的元素
void deletevalue(int a[],int arrayLength);//删除指定值的元素
void deleterange(int a[],int arrayLength);//删除指定下标区间的元素
void insert(void);//插入数组元素
void insertone(int a[],int arrayLength);//插入指定下标的元素
void insertarranged(int a[],int arrayLength);//在有序数组中插入新元素
void menuanalyze(void);//统计数组菜单
void analyze(int a[],int arrayLength);//统计数组
void findmenu(void);//查找菜单
void find(int a[],int arrayLength);//普通查找
void halffind(int a[],int arrayLength);//二分查找
void decide(int a[],int arrayLength);//判断顺序
void arrangemenu(void);//排序菜单
void arrange(void);//排序数组
void back(int a[],int arrayLength);//逆置数组
void left(int a[],int arrayLength);//左旋数组
void right(int a[],int arrayLength);//右旋数组
void bubble(int a[],int arrayLength);//冒泡法
void choice(int a[],int arrayLength);//选择法
void exchanges(int a[],int arrayLength);//交换法
int a[Lengthmax]={0};//数组
int arrayLength=10;//数组长度
int numsPreline=5;//每行打印字数
char splitChar='\t';//元素分隔符
int main(){
	printMenu();//主菜单
	return 0;
}
void clearCache(void){//去回车
	while(getchar()!='\n');
}
void printMenu(void){//主菜单
	char ch;
	while(1){
		printf("*********************************\n");
		printf("\t数组运算器功能菜单\t\n");
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、配置系统参数\n");
		printf("2、处理数组\n");
		printf("3、显示数组\n");
		printf("4、统计数组\n");
		//以下省略，自行补充完成
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		if(ch=='0') break;
		switch(ch){
			case '1':
				set();//配置系统参数
				break;
			case '2':
				printMenu1();//子菜单
				break;
			case '3':
				printarray(a,arrayLength,numsPreline,splitChar);//打印数组
				break;
			case '4':
				menuanalyze();//统计数组菜单
			default:
				break;
		}
	}
}
void set(void){//配置系统参数
	printf("请输入配置数值[数组长度、每行打印字数]:");
	scanf("%d%d",&arrayLength,&numsPreline);
	while(arrayLength>Lengthmax){
		printf("数组长度过大！请重新输入[数组长度、每行打印字数]:");
		scanf("%d%d",&arrayLength,&numsPreline);
	}
	printf("请输入元素分隔符:");
	clearCache();
	splitChar=getchar();
	clearCache();
}
void printMenu1(void){//子菜单
	char ch1;
	while(1){
		clearCache();
		printf("++++++请选择菜单子选项++++++\n");
		printf("0)退出子菜单\n");
		printf("1)用指定范围的随机数填充数组\n");
		printf("2)键盘输入\n");
		printf("3)整个数组填同一个值\n");
		printf("4)用等差序列填充数组\n");
		printf("5)删除数组元素\n");
		printf("6)插入数组元素\n");
		printf("7)排序菜单\n");
		printf("++++++++++++++++++++++++++++\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch1);
		clearCache();
		if(ch1=='0') break;
		switch(ch1){
			case '1':
				randbuild(a,arrayLength);//产生的随机样本数据
				break;
			case '2':
				keyinput(a,arrayLength);//键盘输入
				break;
			case '3':
				inputsame(a,arrayLength);//整个数组填同一个值
				break;
			case '4':
				inputdengcha(a,arrayLength);//用等差序列填充数组
				break;
			case '5':
				deletearray();//删除数组
				break;
			case '6':
				insert();//插入数组元素
				break;
			case '7':
				arrangemenu();//排序菜单
				break;
			default:
				break;
				
		}
	}
}
void randbuild(int a[],int arrayLength){//产生随机样本数据
	int min,max,mid;
	printf("请输入随机数产生的范围：");
	scanf("%d%d",&min,&max);
	if(min>max){//交换大小
		mid=max;
		max=min;
		min=mid;
	}
	srand(time(NULL));
	for(int i=0;i<arrayLength;i++){
		a[i]=rand()%(max-min+1)+min;
	}
	return;
}
void keyinput(int a[],int arrayLength){//键盘输入
	printf("请输入%d个数：",arrayLength);
	for(int i=0;i<arrayLength;i++){
		scanf("%d",&a[i]);
	}
	printf("输入完成！\n");
	return;
}
void inputsame(int a[],int arrayLength){//整个数组填同一个值
	int m;
	printf("请输入值：");
	scanf("%d",&m);
	for(int i=0;i<arrayLength;i++){
		a[i]=m;
	}
	printf("输入完成！\n");
	return;
}
void inputdengcha(int a[],int arrayLength){//用等差序列填充数组
	int start,m;
	printf("请输入输入序列的起始值、每项的差值：");
	scanf("%d%d",&start,&m);
	for(int i=0;i<arrayLength;i++){
		a[i]=start+i*m;
	}
	printf("输入完成！\n");
	return;
}
void printarray(int a[],int arrayLength,int numsPreline,char splitChar){//打印数组
	for(int i=0;i<arrayLength;i++){
		printf("%d%c",a[i],splitChar);
		if(i%numsPreline==numsPreline-1){
			printf("\n");
		}
	}
	return;
}
void deletearray(void){
	char ch2;
	while(1){
		clearCache();
		printf("//////请选择删除子选项//////\n");
		printf("0)退出子菜单\n");
		printf("1)删除指定下标的元素\n");
		printf("2)删除指定值的元素\n");
		printf("3)删除指定下标区间的元素\n");
		printf("////////////////////////////\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch2);
		clearCache();
		if(ch2=='0') break;
		switch(ch2){
			case '1':
				deleteone(a,arrayLength);//删除指定下标的元素
				break;
			case '2':
				deletevalue(a,arrayLength);//删除指定值的元素
				break;
			case '3':
				deleterange(a,arrayLength);//删除指定下标区间的元素
				break;
			default:
				break;
		}
	}
}
void deleteone(int a[],int arrayLength){//删除指定下标的元素
	int m;
	printf("请输入你要删除的数（第几个）：");
	scanf("%d",&m);
	for(int i=m-1;i<arrayLength-1;i++){
		a[i]=a[i+1];
	}
	arrayLength--;
	printf("删除成功！\n");
	return;
}
void deletevalue(int a[],int arrayLength){//删除指定值的元素
	int value,deletenum=0;
	printf("请输入你要删除的值：");
	scanf("%d",&value);
	for(int i=0;i<arrayLength;i++){
		if(a[i]==value){
			deletenum++;
			for(int j=i;j<arrayLength;j++){
				a[j]=a[j+1];
			}
		}
	}
	arrayLength-=deletenum;
	printf("删除成功！\n");
	return;
}
void deleterange(int a[],int arrayLength){//删除指定下标区间的元素
	int min,max,mid,deletenum=0;
	printf("请输入你要删除的下标区间：");
	scanf("%d%d",&min,&max);
	while(min<=0||max<=0||min>arrayLength||max>arrayLength){
		printf("输入错误！请重新输入下标区间:");
		scanf("%d%d",&min,&max);
	}
	if(min>max){//交换大小
		mid=max;
		max=min;
		min=mid;
	}
	for(int i=min-1;i<max;i++){
		for(int j=i;j<arrayLength;j++){
			a[j]=a[j+1];
		}
		deletenum++;
	}
	arrayLength-=deletenum;
	printf("删除成功！\n");
	return;
}
void insert(void){//插入数组元素
	char ch3;
	while(1){
		clearCache();
		printf("//////请选择插入子选项//////\n");
		printf("0)退出子菜单\n");
		printf("1)插入指定下标的元素\n");
		printf("2)在有序数组中插入新元素\n");
		printf("////////////////////////////\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				insertone(a,arrayLength);//插入指定下标的元素
				break;
			case '2':
				insertarranged(a,arrayLength);//在有序数组中插入新元素
				break;
			default:
				break;
		}
	}
}
void insertone(int a[],int arrayLength){//插入指定下标的元素
	int m,value;
	arrayLength++;
	printf("请输入你要插入的数（第几个）：");
	scanf("%d",&m);
	printf("请输入你要插入的数的值：");
	scanf("%d",&value);
	for(int i=arrayLength-1;i>m-1;i--){
		a[i]=a[i-1];
	}
	a[m-1]=value;
	printf("插入成功！\n");
	return;
}
void insertarranged(int a[],int arrayLength){//在有序数组中插入新元素
	int arrangenum1=0,arrangenum2=0;
	for(int i=0;i<arrayLength-1;i++){
		if(a[i]<=a[i+1]){
			arrangenum1++;
		}
		if(a[i]>=a[i+1]){
			arrangenum2++;
		}
	}
	if(arrangenum1==arrayLength-1){
		
	}
	if(arrangenum2==arrayLength-1){
		
	}
	else{
		
	}
}
void menuanalyze(void){//统计数组菜单
	char ch3;
	while(1){
		clearCache();
		printf("//////请选择插入子选项//////\n");
		printf("0)退出子菜单\n");
		printf("1)统计数组\n");
		printf("2)查找数组值\n");
		printf("3)判断顺序\n");
		printf("////////////////////////////\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				analyze(a,arrayLength);//统计数组
				break;
			case '2':
				find(a,arrayLength);//查找数组值
				break;
			case '3':
				decide(a,arrayLength);//判断顺序
				break;
			default:
				break;
		}
	}
}
void analyze(int a[],int arrayLength){//统计数组
	int max,min;
	double sum=0,ave,sqr=0,sigma;
	max=a[0];min=a[0];
	for(int i=0;i<arrayLength;i++){
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
		sum+=a[i];
	}
	ave=sum/arrayLength;
	for(int i=0;i<arrayLength;i++){
		sqr+=(ave-a[i])*(ave-a[i]);
	}
	sigma=sqrt(sqr/arrayLength);
	printf("最大值为：%d\n",max);
	printf("最小值为：%d\n",min);
	printf("平均值为：%lf\n",ave);
	printf("方差为：%lf\n",sqr);
	printf("均方差为：%lf\n",sigma);
	return;
}
void findmenu(void){//查找菜单
	char ch3;
	while(1){
		clearCache();
		printf("//////请选择插入子选项//////\n");
		printf("0)退出子菜单\n");
		printf("1)普通查找\n");
		printf("2)二分查找\n");
		printf("////////////////////////////\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				find(a,arrayLength);//普通查找
				break;
			case '2':
				halffind(a,arrayLength);//二分查找
				break;
			default:
				break;
		}
	}
}
void find(int a[],int arrayLength){//普通查找
	int value,t=0;
	printf("请输入你要查找的数组值：");
	scanf("%d",&value);
	for(int i=0;i<arrayLength;i++){
		if(a[i]==value){
			t++;
			printf("该值在第%d位\n",i+1);
		}
	}
	if(t==0) printf("无结果！\n");
	return;
}
void halffind(int a[],int arrayLength){//二分查找
	int b[arrayLength],value,max=arrayLength-1,min=0,t=0;
	double mid2,mid1;
	printf("请输入你要查找的数组值：");
	scanf("%d",&value);
	for(int i=0;i<arrayLength;i++){
		b[i]=a[i];
	}
	bubble(b,arrayLength);
	while(t<50){
		mid1=b[(max+min)/2];
		mid2=b[(max+min)/2+1];
		if(value<=mid1) max=(max+min)/2;
		if(value>=mid2) min=(max+min)/2;
		if(value==b[max]||value==b[min]) break;
		t++;
	}
	if(t>=50) printf("无结果！\n");
	else printf("该数存在\n");
	return;
}
void decide(int a[],int arrayLength){//判断顺序
	int up=0,down=0;
	for(int i=0;i<arrayLength-1;i++){
		if(a[i]<a[i+1]) down++;
		if(a[i]>a[i+1]) up++;
	}
	if(up==0&&down==0) printf("该数列为常数列\n");
	else{
		if(up==0) printf("该数列为升序数列\n");
		if(down==0) printf("该数列为降序数列\n");
		if(up!=0&&down!=0) printf("该数列不为升序或降序数列\n");
	}
	return;
}
void arrangemenu(void){//排序菜单
	char ch3;
	while(1){
		clearCache();
		printf("//////请选择插入子选项//////\n");
		printf("0)退出子菜单\n");
		printf("1)排序数组\n");
		printf("2)逆置数组\n");
		printf("3)左旋数组\n");
		printf("4)右旋数组\n");
		printf("////////////////////////////\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				arrange();//排序数组
				break;
			case '2':
				back(a,arrayLength);//逆置数组
				break;
			case '3':
				left(a,arrayLength);//左旋数组
				break;
			case '4':
				right(a,arrayLength);//右旋数组
				break;
			default:
				break;
		}
	}
}
void arrange(void){//排序数组
	char ch3;
	while(1){
		clearCache();
		printf("//////请选择插入子选项//////\n");
		printf("0)退出子菜单\n");
		printf("1)冒泡法\n");
		printf("2)选择法\n");
		printf("3)交换法\n");
		printf("////////////////////////////\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				bubble(a,arrayLength);//冒泡法
				break;
			case '2':
				choice(a,arrayLength);//选择法
				break;
			case '3':
				exchanges(a,arrayLength);//交换法
				break;
			default:
				break;
		}
	}
}
void back(int a[],int arrayLength){//逆置数组
	int b[arrayLength];
	for(int i=0;i<arrayLength;i++){
		b[arrayLength-1-i]=a[i];
	}
	for(int i=0;i<arrayLength;i++){
		a[i]=b[i];
	}
	return;
}
void left(int a[],int arrayLength){//左旋数组
	int m,b[arrayLength];
	printf("请输入你要左旋的位数：");
	scanf("%d",&m);
	for(int i=0;i<arrayLength-m;i++){
		b[i]=a[m+i];
	}
	for(int i=arrayLength-m;i<arrayLength;i++){
		b[i]=a[m+i-arrayLength];
	}
	for(int i=0;i<arrayLength;i++){
		a[i]=b[i];
	}
	return;
}
void right(int a[],int arrayLength){//右旋数组
	int m,b[arrayLength];
	printf("请输入你要右旋的位数：");
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		b[i]=a[i+arrayLength-m];
	}
	for(int i=m;i<arrayLength;i++){
		b[i]=a[i-m];
	}
	for(int i=0;i<arrayLength;i++){
		a[i]=b[i];
	}
	return;
}
void bubble(int a[],int arrayLength){//冒泡法
	int t,mid;
	for(int i=0;i<arrayLength-1;i++){
		t=0;
		for(int j=arrayLength-1;j>i;j--){
			if(a[j-1]>a[j]){
				mid=a[j];
				a[j]=a[j-1];
				a[j-1]=mid;
				t++;
			}
		}
		if(t==0) break;
	}
	return;
}
void choice(int a[],int arrayLength){//选择法
	int n,min,mid;
	for(int i=0;i<arrayLength-1;i++){
		n=i;min=a[i];
		for(int j=i+1;j<arrayLength;j++){
			if(min>a[j]){
				n=j;min=a[j];
			}
		}
		mid=a[n];
		a[n]=a[i];
		a[i]=mid;
	}
	return;
}
void exchanges(int a[],int arrayLength){//交换法
	int mid;
	for(int i=0;i<arrayLength-1;i++){
		for(int j=i+1;j<arrayLength;j++){
			if(a[i]>a[j]){
				mid=a[i];
				a[i]=a[j];
				a[j]=mid;
			}
		}
	}
	return;
}
/*
Programed by Li Xiaoyi
All rights reserved
*/
