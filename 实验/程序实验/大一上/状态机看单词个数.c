#include<stdio.h>
#include<ctype.h>
int words=0,state=0,input=0;//wordsͳ�Ƶ��ʸ�����stateΪ����״̬��inputΪ����״̬
char ch;
int getInput(char c){
	if(isalpha(c)==0) return 0;//����Ӣ����ĸ������ֵΪ0
	if(isalpha(c)==1||isalpha(c)==2) return 1;//��Ӣ����ĸ��Сд���д��������ֵΪ1
	return -1;
}
int getwords(){//����չ˼������������main��ѭ������Ĳ���д�ɺ���
	while((ch=getchar())!='#'){
		input=getInput(ch);//��ȡ����״̬
		if(state==0&&input==0){//����δ��ʼ������δ��ʼ
			state=0;
		}
		else if(state==0&&input==1){//����δ��ʼ�����뿪ʼ
			state=1;//state״̬�仯
			words++;//ͳ�Ƶ��ʸ���
		}
		else if(state==1&&input==1){//����δ����������δ����
			state=1;//state״̬�仯
		}
		else{//����δ�������������
			state=0;//state״̬�仯
		}
	}
	return words;
}
int main(){//������������������
	printf("�����ַ����а������ʸ�����%d\n",getwords());
	return 0;
}
