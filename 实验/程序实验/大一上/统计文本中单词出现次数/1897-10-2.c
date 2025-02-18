#include<stdio.h>
#include<string.h>
#include<ctype.h>
void input(void);
void devide(void);
void arrange(void);
void compile(void);
void arrangement(void);
void output(void);
int getInput(char c);
char a[1500];//Դ�ı�;
int wordnumall=0;//ͳ���ܵ�����
int libnumall=0;//ͳ�����ֵ���
struct point{
	char *start;//��ʼ�ַ���ַ
	char *end;//��ֹ�ַ���ַ
	char wordchart[15];//��������
};
struct lib{//�ֵ�
	int num;//���ʳ��ִ���
	char content[15];//��������
};
struct point word[100];
struct lib dict[100];
int main(){
	input();//�����ı�
	devide();//��ֵ���
	arrange();//������ĸ����
	compile();//���ʺϲ�
	arrangement();//����Ƶ������
	output();//������
	return 0;
}
void input(void){//�����ı�
	FILE *read;
	read=fopen("text.txt","r");
	fgets(a,500,read);
	fclose(read);
	return;
}
void devide(void){//��ֵ���
	int state=0,input=0,j=0;
	for(int i=0;a[i]!='\0';i++){
		input=getInput(a[i]);
		if(state==0&&input==0){//����δ��ʼ������δ��ʼ
			state=0;
		}
		else if(state==0&&input==1){//����δ��ʼ�����뿪ʼ
			word[j].start=&a[i];
			wordnumall++;
			state=1;
		}
		else if(state==1&&input==1){//����δ����������δ����
			state=1;
		}
		else{//����δ�������������
			word[j].end=&a[i-1];
			j++;
			state=0;
		}
	}
	for(int i=0;i<j;i++){
		strncpy(word[i].wordchart,word[i].start,(word[i].end-word[i].start)+1);
	}
	return;
}
void arrange(void){//������ĸ����
	struct point temp;
	for(int i=0;i<wordnumall;i++){
		for(int j=wordnumall-1;j>i;j--){
			if(strcmp(word[j-1].wordchart,word[j].wordchart)>0){
				temp=word[j-1];
				word[j-1]=word[j];
				word[j]=temp;
			}
		}
	}
}
void compile(void){//���ʺϲ�
	int flag,i,j;
	for(i=0;i<wordnumall;i++){
		flag=0;
		for(j=0;j<libnumall;j++){
			if(strcmp(word[i].wordchart,dict[j].content)==0){
				flag=1;
				break;
			}
		}
		if(flag){
			dict[j].num++;
		}
		else{
			strncpy(dict[libnumall].content,word[i].wordchart,15);
			dict[libnumall].num++;
			libnumall++;
		}
	}
}
void arrangement(void){//����Ƶ������
	struct lib temp;
	for(int i=0;i<libnumall;i++){
		for(int j=libnumall-1;j>i;j--){
			if(dict[j-1].num<dict[j].num){
				temp=dict[j-1];
				dict[j-1]=dict[j];
				dict[j]=temp;
			}
		}
	}
}
void output(void){//������
	for(int m=0;m<10;m++) printf("%s������%d��\n",dict[m].content,dict[m].num);
}
int getInput(char c){
	if(isalpha(c)==0) return 0;//����Ӣ����ĸ������ֵΪ0
	if(isalpha(c)==1||isalpha(c)==2) return 1;//��Ӣ����ĸ��Сд���д��������ֵΪ1
	return -1;
}
