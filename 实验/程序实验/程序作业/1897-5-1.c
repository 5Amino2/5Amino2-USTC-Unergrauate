#include<stdio.h>
#include<stdlib.h>
int main(){
	int max,min,seed,guess,random,money,seed2,i;
	printf("������������ӣ�");
	scanf("%d",&seed);
	printf("����������������Сֵ��");
	scanf("%d",&min);
	printf("�����������������ֵ��");
	scanf("%d",&max);
	if(max<min){//���ֵ����С����Сֵ
		printf("�������");
		return -1;
	}
	printf("����%d-%d��Χ�ڲ�����һ����������²´�����",min,max);
	scanf("%d",&guess);
	srand(seed);//��һ�ֲ���������ķ�����srand����
	random=rand()%(max-min+1)+min;
	seed2=random;
	seed2=seed2*1103515245+12345;
	money=(unsigned)(seed2/65536)%114514+1;//�ڶ��ֲ���������ķ�������Ҫ�µ��������ɽ�������
	for(i=0;i<5;i++){
		if(guess==random){//������
			printf("��ϲ������ˣ������%dԪ�����",money);
			return 0;
		}
		if(guess<random){
			printf("��µ���С�ˣ��������%d-%d��Χ�ڲ����֣�",min,max);
			scanf("%d",&guess);
		} 
		if(guess>random){
			printf("��µ������ˣ��������%d-%d��Χ�ڲ����֣�",min,max);
			scanf("%d",&guess);
		}
	}
	printf("\n��������ȷ����ֵ��");
	return -1;
}
