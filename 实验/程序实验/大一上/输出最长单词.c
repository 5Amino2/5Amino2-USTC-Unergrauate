#include<stdio.h>
#include<ctype.h>
int getInput(char c){
	if(isalpha(c)==0) return 0;//����Ӣ����ĸ������ֵΪ0
	if(isalpha(c)==1||isalpha(c)==2) return 1;//��Ӣ����ĸ��Сд���д��������ֵΪ1
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
	printf("������һ�����֣�\n");
	gets(a);
	for(int i=0;a[i]!='\0';i++){
		input=getInput(a[i]);
		if(state==0&&input==0){//����δ��ʼ������δ��ʼ
			state=0;
		}
		else if(state==0&&input==1){//����δ��ʼ�����뿪ʼ
			state=1;
			word[j].frtal=&a[i];
			word[j].num++;
		}
		else if(state==1&&input==1){//����δ����������δ����
			state=1;//state״̬�仯
			word[j].num++;
		}
		else{//����δ�������������
			state=0;//state״̬�仯
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
