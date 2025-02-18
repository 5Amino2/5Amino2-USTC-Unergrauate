#include <stdio.h>
#include <stdlib.h>
#define FRAME_LENGTH 180
#define HEADER_LENGTH 44
int main(){
	FILE *fp1,*fp2;
	fp1 = fopen("bluesky1.wav","rb");//打开音频文件
	if(!fp1){
	    printf("输入音频打开错误");
	}
	fp2 = fopen("outsp1.dat","wb");//打开输出文件
	if(!fp2){
	    printf("输出文件打开错误");
	}
	short header[HEADER_LENGTH];//音频头文件
	if(fread(header,1,HEADER_LENGTH,fp1)!=HEADER_LENGTH){//读取头文件
		printf("头部信息读取错误");
	}
	
	
}
