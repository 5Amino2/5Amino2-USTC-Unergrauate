#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void userregister(void);//用户注册
int signin(void);//用户登录
void create(int);//日程发布?
void revise(int);//日程修改
void userdelete(int);//日程删除
void inquiry(int);//日程查询
void usersort(int);//日程排序
void useroutput(int userid,char name[]);//日程导出
int usernumbernow(void);//读取现有用户数
int schedulenumbernow(void);//读取现有日程数
struct userinfo{
	int userid;
	char username[10];
	char userpassword[10];
};
struct scheduledate{
	unsigned int year;
	unsigned int month;
	unsigned int day;
};
struct schedule{
	unsigned int id;
	struct userinfo infomation;
	struct scheduledate date;
	char place[40];
	char tag[200];
};
int main(void){//主菜单
	char ch,nowname[10];
	int nowid=0,a;
	FILE *read;
	char b[10],c[10];
	while(1){
		read=fopen("user.txt","r");
		for(int i=0;i<nowid;i++){
			fscanf(read,"%d%s%s",&a,b,c);
		}
		fscanf(read,"%d%s",&a,nowname);
		fclose(read);
		printf("*********************************\n");
		printf("\t日程管理程序\t\n");
		printf("\t当前用户：%s\t\n",nowname);
		printf("*********************************\n");
		printf("0、退出\n");
		printf("1、用户注册\n");
		printf("2、用户登录\n");
		printf("3、日程发布\n");
		printf("4、日程修改\n");
		printf("5、日程删除\n");
		printf("6、日程查询\n");
		printf("7、日程排序\n");
		printf("8、日程导出\n");
		printf("*********************************\n");
		printf("请选择菜单序号（菜单前的数字）：\n");
		scanf("%c",&ch);
		if(ch=='0') break;
		switch(ch){
			case '1':
				userregister();
				break;
			case '2':
				nowid=signin();
				break;
			case '3':
				create(nowid);
				break;
			case '4':
				revise(nowid);
				break;
            case '5':
				userdelete(nowid);
				break;
            case '6':
				inquiry(nowid);
				break;
            case '7':
				usersort(nowid);
				break;
            case '8':
				useroutput(nowid,nowname);
				break;
			default:
				break;
		}
	}
}
void userregister(void){//用户注册
	char name[10],password[10];
	FILE *newuser;
	printf("请输入你的用户名：");
	scanf("%s",name);
	printf("请输入你的密码：");
	scanf("%s",password);
	newuser=fopen("user.txt","a");
	fprintf(newuser,"%d %s %s\n",usernumbernow(),name,password);
	fclose(newuser);
	printf("用户注册成功！\n");
	return;
}
int signin(void){//用户登录
	FILE *read;
	char namesign[10],passwordsign[10];
	read=fopen("user.txt","r");
	struct userinfo id[50];
	for(int i=0;i<usernumbernow();i++){
		fscanf(read,"%d%s%s",&id[i].userid,id[i].username,id[i].userpassword);
	}
	fclose(read);
	printf("请输入用户名：");
	scanf("%s",namesign);
	printf("请输入密码：");
	scanf("%s",passwordsign);
	for(int i=0;i<usernumbernow();i++){
		if(strcmp(namesign,id[i].username)==0&&strcmp(passwordsign,id[i].userpassword)==0){
			printf("用户登录成功！\n");
			return i;
		}
	}
	printf("用户登录失败！\n");
	return 0;
}
void create(int userid){//日程发布
	int year,month,day;
	char place[40],tag[200];
	FILE *newschedule;
	printf("请输入日程时间：（年 月 日）");
	scanf("%d%d%d",&year,&month,&day);
	printf("请输入日程地点：");
	scanf("%s",place);
	printf("请输入日程内容：");
	scanf("%s",tag);
	newschedule=fopen("schedule.txt","a");
	fprintf(newschedule,"%d %d %d %d %d %s %s\n",schedulenumbernow(),userid,year,month,day,place,tag);
	fclose(newschedule);
	printf("日程发布成功！\n");
	return;
}
void revise(int userid){//日程修改
	FILE *read;
	FILE *write;
	int j=0;
	int idin,yearin,monthin,dayin;
	char placein[40],tagin[200];
	read=fopen("schedule.txt","r");
	struct schedule sch[100];
	struct schedule all[500];
	for(int i=0;i<schedulenumbernow();i++){
		fscanf(read,"%d%d%d%d%d%s%s",&all[i].id,&all[i].infomation.userid,&all[i].date.year,&all[i].date.month,&all[i].date.day,all[i].place,all[i].tag);
		if(all[i].infomation.userid==userid){
			sch[j].id=all[i].id;
			sch[j].infomation.userid=all[i].infomation.userid;
			sch[j].date.year=all[i].date.year;
			sch[j].date.month=all[i].date.month;
			sch[j].date.day=all[i].date.day;
			strcpy(sch[j].place,all[i].place);
			strcpy(sch[j].tag,all[i].tag);
			j++;
		}
	}
	fclose(read);
    printf("当前用户的所有日程如下：\n");
	printf("日程id 用户id 年   月 日 地点       事件\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	printf("请输入你要修改的日程id：");
	scanf("%d",&idin);
	printf("请输入你要修改的日程日程时间：（年 月 日）");
	scanf("%d%d%d",&yearin,&monthin,&dayin);
	printf("请输入你要修改的日程地点：");
	scanf("%s",placein);
	printf("请输入你要修改的日程内容：");
	scanf("%s",tagin);
	write=fopen("schedule.txt","r+");
	for(int i=0;i<schedulenumbernow();i++){
		if(i==idin){
			fprintf(write,"%d %d %d %d %d %s %s\n",i,userid,yearin,monthin,dayin,placein,tagin);
			continue;
		}
		fprintf(write,"%d %d %d %d %d %s %s\n",i,all[i].infomation.userid,all[i].date.year,all[i].date.month,all[i].date.day,all[i].place,all[i].tag);
	}
	fclose(write);
	return;
}
void userdelete(int userid){//日程删除
	FILE *read;
	FILE *write;
	int j=0,idin,n;
	read=fopen("schedule.txt","r");
	struct schedule sch[100];
	struct schedule all[500];
	for(int i=0;i<schedulenumbernow();i++){
		fscanf(read,"%d%d%d%d%d%s%s",&all[i].id,&all[i].infomation.userid,&all[i].date.year,&all[i].date.month,&all[i].date.day,all[i].place,all[i].tag);
		if(all[i].infomation.userid==userid){
			sch[j].id=all[i].id;
			sch[j].infomation.userid=all[i].infomation.userid;
			sch[j].date.year=all[i].date.year;
			sch[j].date.month=all[i].date.month;
			sch[j].date.day=all[i].date.day;
			strcpy(sch[j].place,all[i].place);
			strcpy(sch[j].tag,all[i].tag);
			j++;
		}
	}
	fclose(read);
    printf("当前用户的所有日程如下：\n");
	printf("日程id 用户id 年   月 日 地点       事件\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	printf("请输入你要删除的日程id：");
	scanf("%d",&idin);
	write=fopen("schedule.txt","w");
	fclose(write);
	write=fopen("schedule.txt","a+");
	fseek(write,0,0);
	n=schedulenumbernow();
	for(int i=idin;i<n-1;i++) all[i]=all[i+1];
	if(!feof(write)) putchar('$');
	for(int i=0;i<n-1;i++){
		fprintf(write,"%d %d %d %d %d %s %s\n",i,all[i].infomation.userid,all[i].date.year,all[i].date.month,all[i].date.day,all[i].place,all[i].tag);
	}
	fclose(write);
	return;
}
void inquiry(int userid){//日程查询
	FILE *read;
	int j=0;
	read=fopen("schedule.txt","r");
	struct schedule sch[100];
	struct schedule all[500];
	for(int i=0;i<schedulenumbernow();i++){
		fscanf(read,"%d%d%d%d%d%s%s",&all[i].id,&all[i].infomation.userid,&all[i].date.year,&all[i].date.month,&all[i].date.day,all[i].place,all[i].tag);
		if(all[i].infomation.userid==userid){
			sch[j].id=all[i].id;
			sch[j].infomation.userid=all[i].infomation.userid;
			sch[j].date.year=all[i].date.year;
			sch[j].date.month=all[i].date.month;
			sch[j].date.day=all[i].date.day;
			strcpy(sch[j].place,all[i].place);
			strcpy(sch[j].tag,all[i].tag);
			j++;
		}
	}
	fclose(read);
    printf("当前用户的所有日程如下：\n");
	printf("日程id 用户id 年   月 日 地点       事件\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	return;
}
void usersort(int userid){//日程排序
	FILE *read;
	int j=0,t;
	read=fopen("schedule.txt","r");
	struct schedule sch[100];
	struct schedule all[500];
	struct schedule mid;
	for(int i=0;i<schedulenumbernow();i++){
		fscanf(read,"%d%d%d%d%d%s%s",&all[i].id,&all[i].infomation.userid,&all[i].date.year,&all[i].date.month,&all[i].date.day,all[i].place,all[i].tag);
		if(all[i].infomation.userid==userid){
			sch[j].id=all[i].id;
			sch[j].infomation.userid=all[i].infomation.userid;
			sch[j].date.year=all[i].date.year;
			sch[j].date.month=all[i].date.month;
			sch[j].date.day=all[i].date.day;
			strcpy(sch[j].place,all[i].place);
			strcpy(sch[j].tag,all[i].tag);
			j++;
		}
	}
	fclose(read);
	for(int i=0;i<j-1;i++){
		t=0;
		for(int k=j-1,point=0;k>i;k--,point=0){
			if(sch[k-1].date.year>sch[k].date.year) point+=4;
			if(sch[k-1].date.year<sch[k].date.year) point-=4;
			if(sch[k-1].date.month>sch[k].date.month) point+=2;
			if(sch[k-1].date.month<sch[k].date.month) point-=2;
			if(sch[k-1].date.day>sch[k].date.day) point+=1;
			if(sch[k-1].date.day<sch[k].date.day) point-=1;
			if(point>0){
				mid=sch[k-1];
				sch[k-1]=sch[k];
				sch[k]=mid;
				t++;
			}
		}
		if(t==0) break;
	}
    printf("当前用户的所有日程如下：\n");
	printf("日程id 用户id 年   月 日 地点       事件\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	return;
}
void useroutput(int userid,char name[]){//日程导出
	FILE *read;
	FILE *write;
	int j=0;
	read=fopen("schedule.txt","r");
	struct schedule sch[100];
	struct schedule all[500];
	for(int i=0;i<schedulenumbernow();i++){
		fscanf(read,"%d%d%d%d%d%s%s",&all[i].id,&all[i].infomation.userid,&all[i].date.year,&all[i].date.month,&all[i].date.day,all[i].place,all[i].tag);
		if(all[i].infomation.userid==userid){
			sch[j].id=all[i].id;
			sch[j].infomation.userid=all[i].infomation.userid;
			sch[j].date.year=all[i].date.year;
			sch[j].date.month=all[i].date.month;
			sch[j].date.day=all[i].date.day;
			strcpy(sch[j].place,all[i].place);
			strcpy(sch[j].tag,all[i].tag);
			j++;
		}
	}
	fclose(read);
	write=fopen("output.txt","r+");
	fprintf(write,"%s的日程：\n",name);
	fprintf(write,"日程id 用户id 年      月 日 地点       事件\n");
	fprintf(write,"****************************************\n");
	for(int i=0;i<j;i++){
		fprintf(write,"%-10d%-9d%-5d%-4d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	fclose(write);
	return;
}
int usernumbernow(void){//读取现有用户数
	FILE *readline;
	int id=0,a;
	char b[10],c[10];
	readline=fopen("user.txt","r");
	for(;feof(readline)==0;id++){
		fscanf(readline,"%d%s%s",&a,b,c);
	}
	fclose(readline);
	return id-1;
}
int schedulenumbernow(void){//读取现有日程数
	FILE *readline;
	int id=0,a,d,e,f,b;
	char c[40],g[200];
	readline=fopen("schedule.txt","r");
	for(;feof(readline)==0;id++){
		fscanf(readline,"%d%d%d%d%d%s%s",&a,&b,&d,&e,&f,c,g);
	}
	fclose(readline);
	return id-1;
}
