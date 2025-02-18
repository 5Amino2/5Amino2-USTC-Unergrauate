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
char a[1500];//源文本;
int wordnumall=0;//统计总单词数
int libnumall=0;//统计总字典数
struct point{
	char *start;//起始字符地址
	char *end;//终止字符地址
	char wordchart[15];//单词内容
};
struct lib{//字典
	int num;//单词出现次数
	char content[15];//单词内容
};
struct point word[100];
struct lib dict[100];
int main(){
	input();//输入文本
	devide();//拆分单词
	arrange();//单词字母排序
	compile();//单词合并
	arrangement();//单词频率排序
	output();//输出结果
	return 0;
}
void input(void){//输入文本
	FILE *read;
	read=fopen("text.txt","r");
	fgets(a,500,read);
	fclose(read);
	return;
}
void devide(void){//拆分单词
	int state=0,input=0,j=0;
	for(int i=0;a[i]!='\0';i++){
		input=getInput(a[i]);
		if(state==0&&input==0){//单词未开始，输入未开始
			state=0;
		}
		else if(state==0&&input==1){//单词未开始，输入开始
			word[j].start=&a[i];
			wordnumall++;
			state=1;
		}
		else if(state==1&&input==1){//单词未结束，输入未结束
			state=1;
		}
		else{//单词未结束，输入结束
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
void arrange(void){//单词字母排序
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
void compile(void){//单词合并
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
void arrangement(void){//单词频率排序
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
void output(void){//输出结果
	for(int m=0;m<10;m++) printf("%s出现了%d次\n",dict[m].content,dict[m].num);
}
int getInput(char c){
	if(isalpha(c)==0) return 0;//不是英文字母，返回值为0
	if(isalpha(c)==1||isalpha(c)==2) return 1;//是英文字母（小写或大写），返回值为1
	return -1;
}
