#include <stdio.h>
#include <stdlib.h>
#define FRAME_LENGTH 180
#define HEADER_LENGTH 44
#define FILTER_LENGTH 19
//滤波器系数（浮点型）
static float h[FILTER_LENGTH] = {0.01218354,-0.009012882, -0.02881839, -0.04743239, 
-0.04584568,-0.008692503,0.06446265, 0.1544655, 0.2289794, 0.257883, 
0.2289794, 0.1544655, 0.06446265, -0.008692503, -0.04584568,-0.04743239, 
-0.02881839, -0.009012882, 0.01218354};
static short h_short[FILTER_LENGTH];//定点化的滤波器
static short x1[200];//注意到x1必须为全局变量，因为其中储存着帧之间的数据
void filter(short xin[], short xout[], int n, short h_short[]);
int main(){
	int frame=0;
	short data_in[FRAME_LENGTH];//输入定点数据
	short data_out[FRAME_LENGTH];//输出定点数据
	FILE *fp1,*fp2;
	fp1 = fopen("bluesky2.wav","rb");//打开音频文件
	if(!fp1){
	    printf("输入音频打开错误");
	}
	fp2 = fopen("outsp2.dat","wb");//打开输出文件
	if(!fp2){
	    printf("输出文件打开错误");
	}
	short header[HEADER_LENGTH];//音频头文件
	if(fread(header,1,HEADER_LENGTH,fp1)!=HEADER_LENGTH){//读取头文件
		printf("头部信息读取错误");
	}
	//回写头文件
	//fwrite(&data_out,1,HEADER_LENGTH,fp2);
	//定点化滤波系数
	for(int i=0;i<19;i++){
		h_short[i] = h[i]*32768;
	}
	
	frame=0;
	while(!feof(fp1)){
		frame++;
		printf("frame=%d\n",frame);
		fread(&data_in,sizeof(short),FRAME_LENGTH,fp1);//读取帧
		if(frame==1){//将第一帧具体数据输出
			for(int i=0;i<FRAME_LENGTH;i++){
				printf("frame=1,data[%d]=%d\n",i,data_in[i]);
			}
		}
		filter(data_in,data_out,FILTER_LENGTH,h_short);
		fwrite(&data_out,sizeof(short),FRAME_LENGTH,fp2);
	}
	_fcloseall();
	return 0;
}
void filter(short xin[], short xout[], int n, short h_short[]) {//xin为输入数据，xout为输出数据，n为滤波器长度，h_short为已定点化的滤波器系数
int i, j;
int sum;
for(i=0; i<FRAME_LENGTH; i++) {
x1[n+i-1] = xin[i];//将xin储存至x1的后半段，前半段为之前帧的末端数据
}
for(i=0; i<FRAME_LENGTH; i++) {
sum = 0;
for(j=0; j<n; j++) {
sum += (int)((h_short[j]) * (x1[i-j+n-1]));//由卷积的定义，相乘再累加
}
sum=sum>>15;//反定点化
xout[i] = sum;//将相乘相加的结果直接输出，而不存储，可以看出不是重叠相加法，而是舍去保留法
}
for (i=0; i<(n-1); i++) {
x1[n-i-2] = xin[FRAME_LENGTH-1-i];//将帧末尾数据存储到x1的前半段，为下一帧的卷积结果服务
}
}
