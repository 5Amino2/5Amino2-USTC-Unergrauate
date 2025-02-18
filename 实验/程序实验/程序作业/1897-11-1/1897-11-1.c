#include<stdio.h>
#include<stdlib.h>
struct _studinfo{
	int num;
	char name[10];
	int gender;
	int age;
	float grade;
	struct _studinfo *next;
};
struct _studinfo *head,*rear,*p,*read;
void CreateMenu(void);//创建学生记录链表
void PrintAll(void);//打印全部学生记录
void InsertMenu(void);//插入一条新的学生记录
void DeleteMenu(void);//按条件删除一条学生记录
void FindMenu(void);//查找菜单
void FindNum(void);//按学号查找学生记录
void FindGrade(void);//按成绩查找学生记录
void FindAge(void);//按年龄查找学生记录
void FindGender(void);//按性别查找学生记录
void AnalyzeMenu(void);//统计菜单
void DeleteAll(void);//销毁学生链表
void RewriteMenu(void);//将学生信息重新写入磁盘文件
void Headin(void);//头插法
void Rearin(void);//尾插法
void Arrayin(void);//创建按学号有序链表
void Filein(void);//打开学生信息文件创建链表
void InsertNamed(void);//按指定位序插入
void InsertArray(void);//在有序链表中插入
void DeleteNamed(void);//按指定位序删除
void DeleteNum(void);//删除指定学号
char *PrintGender(int);//转换数字至性别
void AnalyzeStunum(void);//统计学生人数
void AnalyzeAveMax(void);//统计学生的平均成绩和最高分
void AnalyzeFail(void);//统计不及格人数
void RewriteW(void);//重写学生文件
void RewriteA(void);//追加学生文件
void RewriteC(void);//清空学生文件
int main(){
	head=NULL;
	rear=NULL;
	p=NULL;
	char ch;
	while(1){
		printf("\n*******************************************\n");
		printf("\t学生信息管理系统功能菜单\t\n");
		printf("*******************************************\n");
		printf("0、退出\n");
		printf("1、创建学生记录链表\n");
		printf("2、打印全部学生记录\n");
		printf("3、插入一条新的学生记录\n");
		printf("4、按条件删除一条学生记录\n");
		printf("5、查找\n");
		printf("6、统计\n");
		printf("7、销毁学生链表\n");
		printf("8、将学生信息重新写入磁盘文件\n");
		printf("*******************************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				CreateMenu();//创建学生记录链表
				break;
			case '2':
				PrintAll();//打印全部学生记录
				break;
			case '3':
				InsertMenu();//插入一条新的学生记录
				break;
			case '4':
				DeleteMenu();//按条件删除一条学生记录
				break;
			case '5':
				FindMenu();//查找菜单
				break;
			case '6':
				AnalyzeMenu();//统计菜单
				break;
			case '7':
				DeleteAll();//销毁学生链表
				break;
			case '8':
				RewriteMenu();//将学生信息重新写入磁盘文件
				break;
			default:
				break;
		}
	}
	return 0;
}
void CreateMenu(void){//创建学生记录链表
	char ch;
	while(1){
		printf("\n*******************************************\n");
		printf("\t创建学生记录链表菜单\t\n");
		printf("*******************************************\n");
		printf("0、退出\n");
		printf("1、头插法\n");
		printf("2、尾插法\n");
		printf("3、创建按学号有序链表\n");
		printf("4、打开学生信息文件创建链表\n");
		printf("*******************************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				Headin();//头插法
				break;
			case '2':
				Rearin();//尾插法
				break;
			case '3':
				Arrayin();//创建按学号有序链表
				break;
			case '4':
				Filein();//打开学生信息文件创建链表
				break;
			default:
				break;
		}
	}
	return;
}
void PrintAll(void){//打印全部学生记录
	for(p=head;p!=NULL;p=p->next){
		printf("学号：%d\n姓名：%s\n性别：%s\n年龄：%d\n成绩：%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
	}
	return;
}
void InsertMenu(void){//插入一条新的学生记录
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t插入菜单\t\n");
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、按指定位序插入\n");
		printf("2、在有序链表中插入\n");
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				InsertNamed();//按指定位序插入
				break;
			case '2':
				InsertArray();//在有序链表中插入
				break;
			default:
				break;
		}
	}
	return;
}
void DeleteMenu(void){//按条件删除一条学生记录
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t删除菜单\t\n");
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、按指定位序删除\n");
		printf("2、删除指定学号\n");
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				DeleteNamed();//按指定位序删除
				break;
			case '2':
				DeleteNum();//删除指定学号
				break;
			default:
				break;
		}
	}
	return;
}
void FindMenu(void){//查找菜单
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t查找菜单\t\n");
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、按学号查找学生记录\n");
		printf("2、按成绩查找学生记录\n");
		printf("3、按年龄查找学生记录\n");
		printf("4、按性别查找学生记录\n");
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				FindNum();//按学号查找学生记录
				break;
			case '2':
				FindGrade();//按成绩查找学生记录
				break;
			case '3':
				FindAge();//按年龄查找学生记录
				break;
			case '4':
				FindGender();//按性别查找学生记录
				break;
			default:
				break;
		}
	}
	return;
}
void FindNum(void){//按学号查找学生记录
	int n;
	printf("请输入你要查找的学号：");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->num==n){
			printf("学号：%d\n姓名：%s\n性别：%s\n年龄：%d\n成绩：%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void FindGrade(void){//按成绩查找学生记录
	int n;
	printf("请输入你要查找的成绩：");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->grade==n){
			printf("学号：%d\n姓名：%s\n性别：%s\n年龄：%d\n成绩：%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void FindAge(void){//按年龄查找学生记录
	int n;
	printf("请输入你要查找的年龄：");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->age==n){
			printf("学号：%d\n姓名：%s\n性别：%s\n年龄：%d\n成绩：%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void FindGender(void){//按性别查找学生记录
	int n;
	printf("请输入你要查找的性别：(男性为1，女性为0)");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->gender==n){
			printf("学号：%d\n姓名：%s\n性别：%s\n年龄：%d\n成绩：%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void AnalyzeMenu(void){//统计菜单
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t插入菜单\t\n");
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、统计学生人数\n");
		printf("2、统计学生的平均成绩和最高分\n");
		printf("3、统计不及格人数\n");
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				AnalyzeStunum();//统计学生人数
				break;
			case '2':
				AnalyzeAveMax();//统计学生的平均成绩和最高分
				break;
			case '3':
				AnalyzeFail();//统计不及格人数
				break;
			default:
				break;
		}
	}
	return;
}
void DeleteAll(void){//销毁学生链表
	int n;
	printf("你确定要销毁链表吗？\n");
	printf("1、是\n");
	printf("0、否\n");
	scanf("%d",&n);
	if(n==1){
		head=NULL;
		rear=NULL;
		p=NULL;
	}
	return;
}
void RewriteMenu(void){//将学生信息重新写入磁盘文件
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t写入磁盘文件菜单\t\n");
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、重写学生文件\n");
		printf("2、追加学生文件\n");
		printf("3、清空学生文件\n");
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				RewriteW();//重写学生文件
				break;
			case '2':
				RewriteA();//追加学生文件
				break;
			case '3':
				RewriteC();//清空学生文件
				break;
			default:
				break;
		}
	}
	return;
}
void Headin(void){//头插法
	int n;
	printf("请输入你要插入的元素个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		printf("请输入学号：");
		scanf("%d",&p->num);
		printf("请输入姓名：");
		scanf("%s",p->name);
		printf("请输入性别：(男性为1，女性为0)");
		scanf("%d",&p->gender);
		printf("请输入年龄：");
		scanf("%d",&p->age);
		printf("请输入成绩：");
		scanf("%f",&p->grade);
		p->next=NULL;
		if(head==NULL){
			p->next=head;
			head=p;
			rear=p;
		}
		else{
			p->next=head;
			head=p;
		}
	}
	return;
}
void Rearin(void){//尾插法
	int n;
	printf("请输入你要插入的元素个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		printf("请输入学号：");
		scanf("%d",&p->num);
		printf("请输入姓名：");
		scanf("%s",p->name);
		printf("请输入性别：(男性为1，女性为0)");
		scanf("%d",&p->gender);
		printf("请输入年龄：");
		scanf("%d",&p->age);
		printf("请输入成绩：");
		scanf("%f",&p->grade);
		p->next=NULL;
		if(head==NULL){
			p->next=head;
			head=p;
			rear=p;
		}
		else{
			rear->next=p;
			rear=p;
		}
	}
	return;
}
void Arrayin(void){//创建按学号有序链表
	int n;
	printf("请输入你要插入的元素个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		printf("请输入学号：");
		scanf("%d",&p->num);
		printf("请输入姓名：");
		scanf("%s",p->name);
		printf("请输入性别：(男性为1，女性为0)");
		scanf("%d",&p->gender);
		printf("请输入年龄：");
		scanf("%d",&p->age);
		printf("请输入成绩：");
		scanf("%f",&p->grade);
		p->next=NULL;
		if(head==NULL){//空链表
			p->next=head;
			head=p;
			rear=p;
		}
		else if((p->num)<=(head->num)){//最前面用头插法
			p->next=head;
			head=p;
		}
		else if((p->num)>=(rear->num)){//最后面用尾插法
			rear->next=p;
			rear=p;
		}
		else{
			for(read=head;read->next!=NULL;read=read->next){//学号在中间
				if((read->num)<=(p->num)&&(p->num)<=((read->next)->num)){
					p->next=read->next;
					read->next=p;
					break;
				}
			}
		}
	}
	return;
}
void Filein(void){//打开学生信息文件创建链表
	FILE *readf;
	int n=0;
	readf=fopen("text.txt","rb");
	p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
	n=fscanf(readf,"%d%s%d%d%f",&p->num,p->name,&p->gender,&p->age,&p->grade);
	p->next=NULL;
	while(n!=EOF){
		if(head==NULL){
			p->next=head;
			head=p;
			rear=p;
		}
		else{
			rear->next=p;
			rear=p;
		}
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		n=fscanf(readf,"%d%s%d%d%f",&p->num,p->name,&p->gender,&p->age,&p->grade);
		p->next=NULL;
	}
	return;
}
void InsertNamed(void){//按指定位序插入
	int i,j,n=0;//i:当前学生人数
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	while(n<1||n>i+1){
		printf("请输入你要插入的位序：");
		scanf("%d",&n);
	}
	p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
	printf("请输入学号：");
	scanf("%d",&p->num);
	printf("请输入姓名：");
	scanf("%s",p->name);
	printf("请输入性别：(男性为1，女性为0)");
	scanf("%d",&p->gender);
	printf("请输入年龄：");
	scanf("%d",&p->age);
	printf("请输入成绩：");
	scanf("%f",&p->grade);
	p->next=NULL;
	if(head==NULL){
		p->next=head;
		head=p;
		rear=p;
		return;
	}
	if(n==1){
		p->next=head;
		head=p;
		return;
	}
	if(n==i+1){
		rear->next=p;
		rear=p;
		return;
	}
	else{
		for(read=head,j=1;j<n-1;read=read->next,j++);
		p->next=read->next;
		read->next=p;
		return;
	}
	return;
}
void InsertArray(void){//在有序链表中插入
	p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
	printf("请输入学号：");
	scanf("%d",&p->num);
	printf("请输入姓名：");
	scanf("%s",p->name);
	printf("请输入性别：(男性为1，女性为0)");
	scanf("%d",&p->gender);
	printf("请输入年龄：");
	scanf("%d",&p->age);
	printf("请输入成绩：");
	scanf("%f",&p->grade);
	p->next=NULL;
	if(head==NULL){//空链表
		p->next=head;
		head=p;
		rear=p;
		return;
	}
	else if((p->num)<=(head->num)){//最前面用头插法
		p->next=head;
		head=p;
		return;
	}
	else if((p->num)>=(rear->num)){//最后面用尾插法
		rear->next=p;
		rear=p;
		return;
	}
	else{
		for(read=head;read->next!=NULL;read=read->next){//学号在中间
			if((read->num)<=(p->num)&&(p->num)<=((read->next)->num)){
				p->next=read->next;
				read->next=p;
				break;
			}
		}
	}
	return;
}
char *PrintGender(int n){//转换数字至性别
	if(n==0) return "女";
	if(n==1) return "男";
	else return "未知";
}
void AnalyzeStunum(void){//统计学生人数
	int i;
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	printf("当前学生人数：%d",i);
	return;
}
void AnalyzeAveMax(void){//统计学生的平均成绩和最高分
	int i=0;
	float sum=0,max=head->grade;
	for(read=head;read!=NULL;read=read->next){
		sum+=read->grade;
		i++;
		if((read->grade)>max) max=read->grade;
	}
	printf("当前学生平均成绩：%f\n最高分：%f\n",sum/i,max);
	return;
}
void AnalyzeFail(void){//统计不及格人数
	int i;
	for(read=head,i=0;read!=NULL;read=read->next){
		if(read->grade<60) i++;
	}
	printf("当前不及格学生人数：%d",i);
}
void RewriteW(void){//重写学生文件
	FILE *write;
	write=fopen("text.txt","wb");
	for(p=head;p!=NULL;p=p->next){
		fprintf(write,"%d\n%s\n%d\n%d\n%f\n\n",p->num,p->name,p->gender,p->age,p->grade);
	}
	fclose(write);
	return;
}
void RewriteA(void){//追加学生文件
	FILE *write;
	write=fopen("text.txt","ab");
	for(p=head;p!=NULL;p=p->next){
		fprintf(write,"%d\n%s\n%d\n%d\n%f\n\n",p->num,p->name,p->gender,p->age,p->grade);
	}
	fclose(write);
	return;
}
void RewriteC(void){//清空学生文件
	FILE *write;
	write=fopen("text.txt","wb");
	fclose(write);
}
void DeleteNamed(void){//按指定位序删除
	int n=0,i,j;//i为当前学生个数
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	if(i==0){
		printf("当前链表为空!\n");
		return;
	}
	while(n<1||n>i){
		printf("请输入你要删除的位序：");
		scanf("%d",&n);
	}
	if(i==1){
		head=NULL;
		rear=NULL;
		p=NULL;
		return;
	}
	else if(n==1){
		head=head->next;
		return;
	}
	else if(n==i){
		for(p=head,j=0;j<i-2;p=p->next,j++);
		rear=p;
		rear->next=NULL;
	}
	else{
		for(p=head,j=0;j<n-2;p=p->next,j++);
		p->next=(p->next)->next;
	}
}
void DeleteNum(void){//删除指定学号
	int n,i,j;
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	if(i==0){
		printf("当前链表为空!\n");
		return;
	}
	printf("请输入你要删除的学号：");
	scanf("%d",&n);
	if(head->num==n){
		head=head->next;
		return;
	}
	else if(rear->num==n){
		for(p=head,j=0;j<i-2;p=p->next,j++);
		rear=p;
		rear->next=NULL;
		return;
	}
	else{
		for(p=head;(p->next)!=NULL;p=p->next){
			if((p->next)->num==n){
				p->next=(p->next)->next;
			}
		}
	}
	return;
}
