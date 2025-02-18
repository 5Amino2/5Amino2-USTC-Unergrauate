#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_TEXT_SIZE 2000
#define MAX_WORD_NUM 1000
#define MAX_WORD_SIZE 20
#define N 50
#define M (int)(1.15*N)
typedef struct{//���ʱ���¼���ݺ͵��ʸ���
	char list[MAX_WORD_NUM][MAX_WORD_SIZE];
	int listnum;
}LIST;
void input_text(char *Text);//���ļ���ȡ�ı������뵽�ַ���
void wordlist_generate(char *Text,LIST &Wordlist);//�ַ���ת���ʱ�
unsigned long int SquMid(int a);//ƽ��ȡ�з�
int Hash(char *s);//������תΪhashֵ
void hashlist_generate(LIST Wordlist,char Hashlist[M][MAX_WORD_SIZE]);//���ʱ�תHash��
double Search(LIST Wordlist,char Hashlist[M][MAX_WORD_SIZE]);//ƽ�����Ҵ���
int main(){
	char text[MAX_TEXT_SIZE];
	LIST wordlist;
	char hashlist[M][MAX_WORD_SIZE];
	input_text(text);
	wordlist_generate(text,wordlist);
	hashlist_generate(wordlist,hashlist);
	printf("ƽ�����Ҵ���Ϊ��%lf",Search(wordlist,hashlist));
	return 0;
}
void input_text(char *Text){//���ļ���ȡ�ı������뵽�ַ���
	FILE *read;
	read=fopen("Text.txt","r");
	fread(Text,sizeof(char),MAX_TEXT_SIZE,read);
	fgets(Text,MAX_TEXT_SIZE,read);
	fclose(read);
	return;
}
void wordlist_generate(char *Text,LIST &Wordlist){//�ַ���ת���ʱ�
	int last=0,next=0;//lastΪ��һ���ַ��Ƿ�Ϊ��ĸ��nextΪ��һ���ַ��Ƿ�Ϊ��ĸ
	int n=0;//����д��ĵ�n������
	int m=0;//����д�뵥�ʵĵ�m����ĸ
	Wordlist.listnum=0;
	for(int i=0;Text[i]!='\0';i++){
		if(islower(Text[i])||isupper(Text[i])){//nextΪ��һ���ַ��Ƿ�Ϊ��ĸ
			next=1;
		}
		else next=0;
		//����״̬����Ӧ���ֲ���
		if(last==0&&next==0){//����δ��ʼ
			
		}
		else if(last==0&&next==1){//���ʿ�ʼ
			Wordlist.list[n][m]=Text[i];//д��
			m++;//����
			Wordlist.listnum++;//������+1
		}
		else if(last==1&&next==1){//����δ����
			Wordlist.list[n][m]=Text[i];//д��
			m++;//����
		}
		else if(last==1&&next==0){//���ʽ���
			Wordlist.list[n][m]='\0';//��β
			n++;m=0;
			
		}
		//�ı�״̬
		last=next;
	}
	Wordlist.list[n][m]='\0';
}
unsigned long int SquMid(int a){//ƽ��ȡ�з�
	if(a==1||a==0) return SquMid(a+1);
	if(a<10000) return SquMid(a*a);
	return (a/100)%M;
}
int Hash(char *s){//������תΪhashֵ
	long int sum=0;
	for(int i=0;s[i]!='\0';i++){
		sum+=s[i];
	}
	return SquMid(sum);
}
void hashlist_generate(LIST Wordlist,char Hashlist[M][MAX_WORD_SIZE]){//���ʱ�תHash��
	for(int i=0;i<M;i++){//��ʼ�����
		Hashlist[i][0]='\0';
	}
	for(int i=0;i<Wordlist.listnum;i++){
		int hash=Hash(Wordlist.list[i]);
		while(Hashlist[hash][0]!='\0'&&strcmp(Hashlist[hash],Wordlist.list[i])!=0){//��hashֵ��ͻʱ��ʹ�ñ�ɢ�з�����hash++
			hash++;
			hash=hash%M;
		}
		strcpy(Hashlist[hash],Wordlist.list[i]);//�����ʸ��Ƶ���Ӧ��hashֵ��
	}
}
double Search(LIST Wordlist,char Hashlist[M][MAX_WORD_SIZE]){//ƽ�����Ҵ���
	int Num=0;//ͳ�Ʋ��Ҵ���
	for(int i=0;i<Wordlist.listnum;i++){
		int hash=Hash(Wordlist.list[i]);
		int CompareNum=0;//�Ƚϴ�������ֹ��ѭ��
		Num++;
		while(strcmp(Wordlist.list[i],Hashlist[hash])!=0&&CompareNum<M){//��ʼ�Ƚϣ��Կ�ɢ�еķ�ʽ����
			hash++;
			hash=hash%M;
			Num++;
			CompareNum++;
		}
	}
	return ((double)Num/(double)Wordlist.listnum);
}
