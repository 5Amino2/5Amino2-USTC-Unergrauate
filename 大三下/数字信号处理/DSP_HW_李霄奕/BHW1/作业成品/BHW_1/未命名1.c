#include <stdio.h>
#include <stdlib.h>
#define FRAME_LENGTH 180
#define HEADER_LENGTH 44
int main(){
	FILE *fp1,*fp2;
	fp1 = fopen("bluesky1.wav","rb");//����Ƶ�ļ�
	if(!fp1){
	    printf("������Ƶ�򿪴���");
	}
	fp2 = fopen("outsp1.dat","wb");//������ļ�
	if(!fp2){
	    printf("����ļ��򿪴���");
	}
	short header[HEADER_LENGTH];//��Ƶͷ�ļ�
	if(fread(header,1,HEADER_LENGTH,fp1)!=HEADER_LENGTH){//��ȡͷ�ļ�
		printf("ͷ����Ϣ��ȡ����");
	}
	
	
}
