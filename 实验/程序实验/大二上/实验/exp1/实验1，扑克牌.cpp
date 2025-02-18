#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define M 52//�����˿��Ƶ�����
#define N 52//ѡ�����˿�������
int initial(int *poke);//��ʼ��
int PrintPoke(int *poke);//��ӡ��ǰ�˿�
int Devide(int *poke);//����,�����зֵ�
int Wash(int *poke);//ϴ��
int group(int a);//�����ַ���ֵ�������ֻ�ɫ
int Mark(int *poke);//��ֺ��������ؿ۷�����
int AllPoke[M]={
	1,2,3,4,5,6,7,8,9,10,11,12,13,
	21,22,23,24,25,26,27,28,29,30,31,32,33,
	41,42,43,44,45,46,47,48,49,50,51,52,53,
	61,62,63,64,65,66,67,68,69,70,71,72,73
};
int main(){
	int poke[N];//�����˿˶�
	initial(poke);//��ʼ��
	PrintPoke(poke);//��ӡ��ǰ�˿�
	int D=0,W=0;//D��WΪ���ơ�ϴ�ƴ���
	char n;//����
	while(1){
		printf("��ѡ�������\n");
		printf("ϴ�ƣ�1\n");
		printf("���ƣ�2\n");
		printf("�˳���0\n");
		scanf("%c",&n);
		fflush(stdin);
		if(n=='0') break;
		switch(n){
			case '1':
				printf("��%d��ϴ�ƣ���%d�����ƣ�\n",++W,D);
				Wash(poke);//ϴ��
				PrintPoke(poke);//��ӡ��ǰ�˿�
				break;
			case '2':
				printf("��%d��ϴ�ƣ���%d�����ƣ�\n",W,++D);
				printf("�зֵ�Ϊ��%d\n",Devide(poke));
				PrintPoke(poke);//��ӡ��ǰ�˿�
				break;
			default:
				break;
		}
	}
}
int initial(int *poke){//��ʼ��
	for(int i=0;i<N;i++){//��ʼΪ˳����
		poke[i]=AllPoke[i];
	}
	return 0;
}
int PrintPoke(int *poke){//��ӡ��ǰ�˿�
	printf("��ǰ�˿�Ϊ��");
	for(int i=0;i<N;i++){
		printf("%d ",poke[i]);
	}
	printf("\n");
	printf("����ϴ�ƿ۷֣�%d��\n",Mark(poke));
	return 0;
}
int Devide(int *poke){//����,�����зֵ�
	srand(rand()+165+time(NULL));//�����
	int n=rand()%(N-1)+1;//nΪ�зֵ�
	int a[N];//��ʱ�洢������
	for(int i=0;i<N-n;i++){
		a[i]=poke[i+n];
	}
	for(int i=N-n;i<N;i++){
		a[i]=poke[i-N+n];
	}
	for(int i=0;i<N;i++){
		poke[i]=a[i];
	}
	return n;
}
int Wash(int *poke){//ϴ��
	int a[N];//��ʱ�洢������
	for(int i=0;i<(N+1)/2;i++){
		a[i]=poke[i*2];
	}
	for(int i=(N+1)/2;i<N;i++){
		a[i]=poke[(i-((N+1)/2))*2+1];
	}
	for(int i=0;i<N;i++){
		poke[i]=a[i];
	}
	return 0;
}
int group(int a){//�����ַ���ֵ�������ֻ�ɫ
	if(a>=1&&a<=13) return 1;
	if(a>=21&&a<=33) return 2;
	if(a>=41&&a<=53) return 3;
	if(a>=61&&a<=73) return 4;
	return -1;
}
int Mark(int *poke){//��ֺ��������ؿ۷�����
	int m=0;//mΪ�۷�����
	for(int i=0;i<N-2;i++){
		if((group(poke[i])==group(poke[i+1]))&&(group(poke[i])==group(poke[i+2]))) m++;
	}
	return m;
}
