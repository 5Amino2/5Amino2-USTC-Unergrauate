#include<stdio.h>
#include<ctype.h>
int words=0,state=0,input=0;//words统计单词个数，state为单词状态，input为输入状态
char ch;
int getInput(char c){
	if(isalpha(c)==0) return 0;//不是英文字母，返回值为0
	if(isalpha(c)==1||isalpha(c)==2) return 1;//是英文字母（小写或大写），返回值为1
	return -1;
}
int getwords(){//【拓展思考】将主函数main中循环处理的部分写成函数
	while((ch=getchar())!='#'){
		input=getInput(ch);//获取输入状态
		if(state==0&&input==0){//单词未开始，输入未开始
			state=0;
		}
		else if(state==0&&input==1){//单词未开始，输入开始
			state=1;//state状态变化
			words++;//统计单词个数
		}
		else if(state==1&&input==1){//单词未结束，输入未结束
			state=1;//state状态变化
		}
		else{//单词未结束，输入结束
			state=0;//state状态变化
		}
	}
	return words;
}
int main(){//真正的主函数在这里
	printf("输入字符串中包含单词个数：%d\n",getwords());
	return 0;
}
