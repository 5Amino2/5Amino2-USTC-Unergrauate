#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void userregister(void);//�û�ע��
int signin(void);//�û���¼
void create(int);//�ճ̷���?
void revise(int);//�ճ��޸�
void userdelete(int);//�ճ�ɾ��
void inquiry(int);//�ճ̲�ѯ
void usersort(int);//�ճ�����
void useroutput(int userid,char name[]);//�ճ̵���
int usernumbernow(void);//��ȡ�����û���
int schedulenumbernow(void);//��ȡ�����ճ���
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
int main(void){//���˵�
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
		printf("\t�ճ̹������\t\n");
		printf("\t��ǰ�û���%s\t\n",nowname);
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1���û�ע��\n");
		printf("2���û���¼\n");
		printf("3���ճ̷���\n");
		printf("4���ճ��޸�\n");
		printf("5���ճ�ɾ��\n");
		printf("6���ճ̲�ѯ\n");
		printf("7���ճ�����\n");
		printf("8���ճ̵���\n");
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���\n");
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
void userregister(void){//�û�ע��
	char name[10],password[10];
	FILE *newuser;
	printf("����������û�����");
	scanf("%s",name);
	printf("������������룺");
	scanf("%s",password);
	newuser=fopen("user.txt","a");
	fprintf(newuser,"%d %s %s\n",usernumbernow(),name,password);
	fclose(newuser);
	printf("�û�ע��ɹ���\n");
	return;
}
int signin(void){//�û���¼
	FILE *read;
	char namesign[10],passwordsign[10];
	read=fopen("user.txt","r");
	struct userinfo id[50];
	for(int i=0;i<usernumbernow();i++){
		fscanf(read,"%d%s%s",&id[i].userid,id[i].username,id[i].userpassword);
	}
	fclose(read);
	printf("�������û�����");
	scanf("%s",namesign);
	printf("���������룺");
	scanf("%s",passwordsign);
	for(int i=0;i<usernumbernow();i++){
		if(strcmp(namesign,id[i].username)==0&&strcmp(passwordsign,id[i].userpassword)==0){
			printf("�û���¼�ɹ���\n");
			return i;
		}
	}
	printf("�û���¼ʧ�ܣ�\n");
	return 0;
}
void create(int userid){//�ճ̷���
	int year,month,day;
	char place[40],tag[200];
	FILE *newschedule;
	printf("�������ճ�ʱ�䣺���� �� �գ�");
	scanf("%d%d%d",&year,&month,&day);
	printf("�������ճ̵ص㣺");
	scanf("%s",place);
	printf("�������ճ����ݣ�");
	scanf("%s",tag);
	newschedule=fopen("schedule.txt","a");
	fprintf(newschedule,"%d %d %d %d %d %s %s\n",schedulenumbernow(),userid,year,month,day,place,tag);
	fclose(newschedule);
	printf("�ճ̷����ɹ���\n");
	return;
}
void revise(int userid){//�ճ��޸�
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
    printf("��ǰ�û��������ճ����£�\n");
	printf("�ճ�id �û�id ��   �� �� �ص�       �¼�\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	printf("��������Ҫ�޸ĵ��ճ�id��");
	scanf("%d",&idin);
	printf("��������Ҫ�޸ĵ��ճ��ճ�ʱ�䣺���� �� �գ�");
	scanf("%d%d%d",&yearin,&monthin,&dayin);
	printf("��������Ҫ�޸ĵ��ճ̵ص㣺");
	scanf("%s",placein);
	printf("��������Ҫ�޸ĵ��ճ����ݣ�");
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
void userdelete(int userid){//�ճ�ɾ��
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
    printf("��ǰ�û��������ճ����£�\n");
	printf("�ճ�id �û�id ��   �� �� �ص�       �¼�\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	printf("��������Ҫɾ�����ճ�id��");
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
void inquiry(int userid){//�ճ̲�ѯ
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
    printf("��ǰ�û��������ճ����£�\n");
	printf("�ճ�id �û�id ��   �� �� �ص�       �¼�\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	return;
}
void usersort(int userid){//�ճ�����
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
    printf("��ǰ�û��������ճ����£�\n");
	printf("�ճ�id �û�id ��   �� �� �ص�       �¼�\n");
	for(int i=0;i<j;i++){
		printf("%-7d%-7d%-5d%-3d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	return;
}
void useroutput(int userid,char name[]){//�ճ̵���
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
	fprintf(write,"%s���ճ̣�\n",name);
	fprintf(write,"�ճ�id �û�id ��      �� �� �ص�       �¼�\n");
	fprintf(write,"****************************************\n");
	for(int i=0;i<j;i++){
		fprintf(write,"%-10d%-9d%-5d%-4d%-3d%-11s%s\n",sch[i].id,sch[i].infomation.userid,sch[i].date.year,sch[i].date.month,sch[i].date.day,sch[i].place,sch[i].tag);
	}
	fclose(write);
	return;
}
int usernumbernow(void){//��ȡ�����û���
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
int schedulenumbernow(void){//��ȡ�����ճ���
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
