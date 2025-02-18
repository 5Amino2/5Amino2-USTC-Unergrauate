#include<stdio.h>
#include<ctype.h>
int getInput(char c){
	if(isalpha(c)==0) return 0;//不是英文字母，返回值为0
	if(isalpha(c)==1||isalpha(c)==2) return 1;//是英文字母（小写或大写），返回值为1
	return -1;
}
int main(){
	struct words{
		char *frtal;
		int num;
	};
	struct words word[200];
	int state=0,input=0,j=0,max=0;
	char a[200];
	for(int i=0;i<200;i++){
		word[i].frtal='\0';
		a[i]='\0';
		word[i].num=0;
	}
	printf("请输入一行文字：\n");
	gets(a);
	for(int i=0;a[i]!='\0';i++){
		input=getInput(a[i]);
		if(state==0&&input==0){//单词未开始，输入未开始
			state=0;
		}
		else if(state==0&&input==1){//单词未开始，输入开始
			state=1;
			word[j].frtal=&a[i];
			word[j].num++;
		}
		else if(state==1&&input==1){//单词未结束，输入未结束
			state=1;//state状态变化
			word[j].num++;
		}
		else{//单词未结束，输入结束
			state=0;//state状态变化
			word[j].num++;
			j++;
		}
	}
	for(int i=0;i<200;i++){
		if(word[max].num<word[i].num) max=i;
	}
	for(;getInput(*word[max].frtal);word[max].frtal++) printf("%c",*word[max].frtal);
	return 0;
}
