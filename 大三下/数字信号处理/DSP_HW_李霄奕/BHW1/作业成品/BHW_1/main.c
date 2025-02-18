#include <stdio.h>
#include <stdlib.h>
#define FRAME_LENGTH 180
#define HEADER_LENGTH 44
#define FILTER_LENGTH 19
//�˲���ϵ���������ͣ�
static float h[FILTER_LENGTH] = {0.01218354,-0.009012882, -0.02881839, -0.04743239, 
-0.04584568,-0.008692503,0.06446265, 0.1544655, 0.2289794, 0.257883, 
0.2289794, 0.1544655, 0.06446265, -0.008692503, -0.04584568,-0.04743239, 
-0.02881839, -0.009012882, 0.01218354};
static short h_short[FILTER_LENGTH];//���㻯���˲���
static short x1[200];//ע�⵽x1����Ϊȫ�ֱ�������Ϊ���д�����֮֡�������
void filter(short xin[], short xout[], int n, short h_short[]);
int main(){
	int frame=0;
	short data_in[FRAME_LENGTH];//���붨������
	short data_out[FRAME_LENGTH];//�����������
	FILE *fp1,*fp2;
	fp1 = fopen("bluesky2.wav","rb");//����Ƶ�ļ�
	if(!fp1){
	    printf("������Ƶ�򿪴���");
	}
	fp2 = fopen("outsp2.dat","wb");//������ļ�
	if(!fp2){
	    printf("����ļ��򿪴���");
	}
	short header[HEADER_LENGTH];//��Ƶͷ�ļ�
	if(fread(header,1,HEADER_LENGTH,fp1)!=HEADER_LENGTH){//��ȡͷ�ļ�
		printf("ͷ����Ϣ��ȡ����");
	}
	//��дͷ�ļ�
	//fwrite(&data_out,1,HEADER_LENGTH,fp2);
	//���㻯�˲�ϵ��
	for(int i=0;i<19;i++){
		h_short[i] = h[i]*32768;
	}
	
	frame=0;
	while(!feof(fp1)){
		frame++;
		printf("frame=%d\n",frame);
		fread(&data_in,sizeof(short),FRAME_LENGTH,fp1);//��ȡ֡
		if(frame==1){//����һ֡�����������
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
void filter(short xin[], short xout[], int n, short h_short[]) {//xinΪ�������ݣ�xoutΪ������ݣ�nΪ�˲������ȣ�h_shortΪ�Ѷ��㻯���˲���ϵ��
int i, j;
int sum;
for(i=0; i<FRAME_LENGTH; i++) {
x1[n+i-1] = xin[i];//��xin������x1�ĺ��Σ�ǰ���Ϊ֮ǰ֡��ĩ������
}
for(i=0; i<FRAME_LENGTH; i++) {
sum = 0;
for(j=0; j<n; j++) {
sum += (int)((h_short[j]) * (x1[i-j+n-1]));//�ɾ���Ķ��壬������ۼ�
}
sum=sum>>15;//�����㻯
xout[i] = sum;//�������ӵĽ��ֱ������������洢�����Կ��������ص���ӷ���������ȥ������
}
for (i=0; i<(n-1); i++) {
x1[n-i-2] = xin[FRAME_LENGTH-1-i];//��֡ĩβ���ݴ洢��x1��ǰ��Σ�Ϊ��һ֡�ľ���������
}
}
