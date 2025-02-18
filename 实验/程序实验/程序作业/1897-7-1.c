#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#define Lengthmax 50//������鳤��
void clearCache(void);//ȥ�س�
void set(void);//����ϵͳ����
void printMenu(void);//���˵�
void printMenu1(void);//�Ӳ˵�
void randbuild(int a[],int arrayLength);//���������������
void keyinput(int a[],int arrayLength);//��������
void inputsame(int a[],int arrayLength);//����������ͬһ��ֵ
void inputdengcha(int a[],int arrayLength);//�õȲ������������
void printarray(int a[],int arrayLength,int numsPreline,char splitChar);//��ӡ����
void deletearray(void);//ɾ������
void deleteone(int a[],int arrayLength);//ɾ��ָ���±��Ԫ��
void deletevalue(int a[],int arrayLength);//ɾ��ָ��ֵ��Ԫ��
void deleterange(int a[],int arrayLength);//ɾ��ָ���±������Ԫ��
void insert(void);//��������Ԫ��
void insertone(int a[],int arrayLength);//����ָ���±��Ԫ��
void insertarranged(int a[],int arrayLength);//�����������в�����Ԫ��
void menuanalyze(void);//ͳ������˵�
void analyze(int a[],int arrayLength);//ͳ������
void findmenu(void);//���Ҳ˵�
void find(int a[],int arrayLength);//��ͨ����
void halffind(int a[],int arrayLength);//���ֲ���
void decide(int a[],int arrayLength);//�ж�˳��
void arrangemenu(void);//����˵�
void arrange(void);//��������
void back(int a[],int arrayLength);//��������
void left(int a[],int arrayLength);//��������
void right(int a[],int arrayLength);//��������
void bubble(int a[],int arrayLength);//ð�ݷ�
void choice(int a[],int arrayLength);//ѡ��
void exchanges(int a[],int arrayLength);//������
int a[Lengthmax]={0};//����
int arrayLength=10;//���鳤��
int numsPreline=5;//ÿ�д�ӡ����
char splitChar='\t';//Ԫ�طָ���
int main(){
	printMenu();//���˵�
	return 0;
}
void clearCache(void){//ȥ�س�
	while(getchar()!='\n');
}
void printMenu(void){//���˵�
	char ch;
	while(1){
		printf("*********************************\n");
		printf("\t�������������ܲ˵�\t\n");
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1������ϵͳ����\n");
		printf("2����������\n");
		printf("3����ʾ����\n");
		printf("4��ͳ������\n");
		//����ʡ�ԣ����в������
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		if(ch=='0') break;
		switch(ch){
			case '1':
				set();//����ϵͳ����
				break;
			case '2':
				printMenu1();//�Ӳ˵�
				break;
			case '3':
				printarray(a,arrayLength,numsPreline,splitChar);//��ӡ����
				break;
			case '4':
				menuanalyze();//ͳ������˵�
			default:
				break;
		}
	}
}
void set(void){//����ϵͳ����
	printf("������������ֵ[���鳤�ȡ�ÿ�д�ӡ����]:");
	scanf("%d%d",&arrayLength,&numsPreline);
	while(arrayLength>Lengthmax){
		printf("���鳤�ȹ�������������[���鳤�ȡ�ÿ�д�ӡ����]:");
		scanf("%d%d",&arrayLength,&numsPreline);
	}
	printf("������Ԫ�طָ���:");
	clearCache();
	splitChar=getchar();
	clearCache();
}
void printMenu1(void){//�Ӳ˵�
	char ch1;
	while(1){
		clearCache();
		printf("++++++��ѡ��˵���ѡ��++++++\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)��ָ����Χ��������������\n");
		printf("2)��������\n");
		printf("3)����������ͬһ��ֵ\n");
		printf("4)�õȲ������������\n");
		printf("5)ɾ������Ԫ��\n");
		printf("6)��������Ԫ��\n");
		printf("7)����˵�\n");
		printf("++++++++++++++++++++++++++++\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch1);
		clearCache();
		if(ch1=='0') break;
		switch(ch1){
			case '1':
				randbuild(a,arrayLength);//�����������������
				break;
			case '2':
				keyinput(a,arrayLength);//��������
				break;
			case '3':
				inputsame(a,arrayLength);//����������ͬһ��ֵ
				break;
			case '4':
				inputdengcha(a,arrayLength);//�õȲ������������
				break;
			case '5':
				deletearray();//ɾ������
				break;
			case '6':
				insert();//��������Ԫ��
				break;
			case '7':
				arrangemenu();//����˵�
				break;
			default:
				break;
				
		}
	}
}
void randbuild(int a[],int arrayLength){//���������������
	int min,max,mid;
	printf("����������������ķ�Χ��");
	scanf("%d%d",&min,&max);
	if(min>max){//������С
		mid=max;
		max=min;
		min=mid;
	}
	srand(time(NULL));
	for(int i=0;i<arrayLength;i++){
		a[i]=rand()%(max-min+1)+min;
	}
	return;
}
void keyinput(int a[],int arrayLength){//��������
	printf("������%d������",arrayLength);
	for(int i=0;i<arrayLength;i++){
		scanf("%d",&a[i]);
	}
	printf("������ɣ�\n");
	return;
}
void inputsame(int a[],int arrayLength){//����������ͬһ��ֵ
	int m;
	printf("������ֵ��");
	scanf("%d",&m);
	for(int i=0;i<arrayLength;i++){
		a[i]=m;
	}
	printf("������ɣ�\n");
	return;
}
void inputdengcha(int a[],int arrayLength){//�õȲ������������
	int start,m;
	printf("�������������е���ʼֵ��ÿ��Ĳ�ֵ��");
	scanf("%d%d",&start,&m);
	for(int i=0;i<arrayLength;i++){
		a[i]=start+i*m;
	}
	printf("������ɣ�\n");
	return;
}
void printarray(int a[],int arrayLength,int numsPreline,char splitChar){//��ӡ����
	for(int i=0;i<arrayLength;i++){
		printf("%d%c",a[i],splitChar);
		if(i%numsPreline==numsPreline-1){
			printf("\n");
		}
	}
	return;
}
void deletearray(void){
	char ch2;
	while(1){
		clearCache();
		printf("//////��ѡ��ɾ����ѡ��//////\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)ɾ��ָ���±��Ԫ��\n");
		printf("2)ɾ��ָ��ֵ��Ԫ��\n");
		printf("3)ɾ��ָ���±������Ԫ��\n");
		printf("////////////////////////////\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch2);
		clearCache();
		if(ch2=='0') break;
		switch(ch2){
			case '1':
				deleteone(a,arrayLength);//ɾ��ָ���±��Ԫ��
				break;
			case '2':
				deletevalue(a,arrayLength);//ɾ��ָ��ֵ��Ԫ��
				break;
			case '3':
				deleterange(a,arrayLength);//ɾ��ָ���±������Ԫ��
				break;
			default:
				break;
		}
	}
}
void deleteone(int a[],int arrayLength){//ɾ��ָ���±��Ԫ��
	int m;
	printf("��������Ҫɾ���������ڼ�������");
	scanf("%d",&m);
	for(int i=m-1;i<arrayLength-1;i++){
		a[i]=a[i+1];
	}
	arrayLength--;
	printf("ɾ���ɹ���\n");
	return;
}
void deletevalue(int a[],int arrayLength){//ɾ��ָ��ֵ��Ԫ��
	int value,deletenum=0;
	printf("��������Ҫɾ����ֵ��");
	scanf("%d",&value);
	for(int i=0;i<arrayLength;i++){
		if(a[i]==value){
			deletenum++;
			for(int j=i;j<arrayLength;j++){
				a[j]=a[j+1];
			}
		}
	}
	arrayLength-=deletenum;
	printf("ɾ���ɹ���\n");
	return;
}
void deleterange(int a[],int arrayLength){//ɾ��ָ���±������Ԫ��
	int min,max,mid,deletenum=0;
	printf("��������Ҫɾ�����±����䣺");
	scanf("%d%d",&min,&max);
	while(min<=0||max<=0||min>arrayLength||max>arrayLength){
		printf("������������������±�����:");
		scanf("%d%d",&min,&max);
	}
	if(min>max){//������С
		mid=max;
		max=min;
		min=mid;
	}
	for(int i=min-1;i<max;i++){
		for(int j=i;j<arrayLength;j++){
			a[j]=a[j+1];
		}
		deletenum++;
	}
	arrayLength-=deletenum;
	printf("ɾ���ɹ���\n");
	return;
}
void insert(void){//��������Ԫ��
	char ch3;
	while(1){
		clearCache();
		printf("//////��ѡ�������ѡ��//////\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)����ָ���±��Ԫ��\n");
		printf("2)�����������в�����Ԫ��\n");
		printf("////////////////////////////\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				insertone(a,arrayLength);//����ָ���±��Ԫ��
				break;
			case '2':
				insertarranged(a,arrayLength);//�����������в�����Ԫ��
				break;
			default:
				break;
		}
	}
}
void insertone(int a[],int arrayLength){//����ָ���±��Ԫ��
	int m,value;
	arrayLength++;
	printf("��������Ҫ����������ڼ�������");
	scanf("%d",&m);
	printf("��������Ҫ���������ֵ��");
	scanf("%d",&value);
	for(int i=arrayLength-1;i>m-1;i--){
		a[i]=a[i-1];
	}
	a[m-1]=value;
	printf("����ɹ���\n");
	return;
}
void insertarranged(int a[],int arrayLength){//�����������в�����Ԫ��
	int arrangenum1=0,arrangenum2=0;
	for(int i=0;i<arrayLength-1;i++){
		if(a[i]<=a[i+1]){
			arrangenum1++;
		}
		if(a[i]>=a[i+1]){
			arrangenum2++;
		}
	}
	if(arrangenum1==arrayLength-1){
		
	}
	if(arrangenum2==arrayLength-1){
		
	}
	else{
		
	}
}
void menuanalyze(void){//ͳ������˵�
	char ch3;
	while(1){
		clearCache();
		printf("//////��ѡ�������ѡ��//////\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)ͳ������\n");
		printf("2)��������ֵ\n");
		printf("3)�ж�˳��\n");
		printf("////////////////////////////\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				analyze(a,arrayLength);//ͳ������
				break;
			case '2':
				find(a,arrayLength);//��������ֵ
				break;
			case '3':
				decide(a,arrayLength);//�ж�˳��
				break;
			default:
				break;
		}
	}
}
void analyze(int a[],int arrayLength){//ͳ������
	int max,min;
	double sum=0,ave,sqr=0,sigma;
	max=a[0];min=a[0];
	for(int i=0;i<arrayLength;i++){
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
		sum+=a[i];
	}
	ave=sum/arrayLength;
	for(int i=0;i<arrayLength;i++){
		sqr+=(ave-a[i])*(ave-a[i]);
	}
	sigma=sqrt(sqr/arrayLength);
	printf("���ֵΪ��%d\n",max);
	printf("��СֵΪ��%d\n",min);
	printf("ƽ��ֵΪ��%lf\n",ave);
	printf("����Ϊ��%lf\n",sqr);
	printf("������Ϊ��%lf\n",sigma);
	return;
}
void findmenu(void){//���Ҳ˵�
	char ch3;
	while(1){
		clearCache();
		printf("//////��ѡ�������ѡ��//////\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)��ͨ����\n");
		printf("2)���ֲ���\n");
		printf("////////////////////////////\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				find(a,arrayLength);//��ͨ����
				break;
			case '2':
				halffind(a,arrayLength);//���ֲ���
				break;
			default:
				break;
		}
	}
}
void find(int a[],int arrayLength){//��ͨ����
	int value,t=0;
	printf("��������Ҫ���ҵ�����ֵ��");
	scanf("%d",&value);
	for(int i=0;i<arrayLength;i++){
		if(a[i]==value){
			t++;
			printf("��ֵ�ڵ�%dλ\n",i+1);
		}
	}
	if(t==0) printf("�޽����\n");
	return;
}
void halffind(int a[],int arrayLength){//���ֲ���
	int b[arrayLength],value,max=arrayLength-1,min=0,t=0;
	double mid2,mid1;
	printf("��������Ҫ���ҵ�����ֵ��");
	scanf("%d",&value);
	for(int i=0;i<arrayLength;i++){
		b[i]=a[i];
	}
	bubble(b,arrayLength);
	while(t<50){
		mid1=b[(max+min)/2];
		mid2=b[(max+min)/2+1];
		if(value<=mid1) max=(max+min)/2;
		if(value>=mid2) min=(max+min)/2;
		if(value==b[max]||value==b[min]) break;
		t++;
	}
	if(t>=50) printf("�޽����\n");
	else printf("��������\n");
	return;
}
void decide(int a[],int arrayLength){//�ж�˳��
	int up=0,down=0;
	for(int i=0;i<arrayLength-1;i++){
		if(a[i]<a[i+1]) down++;
		if(a[i]>a[i+1]) up++;
	}
	if(up==0&&down==0) printf("������Ϊ������\n");
	else{
		if(up==0) printf("������Ϊ��������\n");
		if(down==0) printf("������Ϊ��������\n");
		if(up!=0&&down!=0) printf("�����в�Ϊ�����������\n");
	}
	return;
}
void arrangemenu(void){//����˵�
	char ch3;
	while(1){
		clearCache();
		printf("//////��ѡ�������ѡ��//////\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)��������\n");
		printf("2)��������\n");
		printf("3)��������\n");
		printf("4)��������\n");
		printf("////////////////////////////\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				arrange();//��������
				break;
			case '2':
				back(a,arrayLength);//��������
				break;
			case '3':
				left(a,arrayLength);//��������
				break;
			case '4':
				right(a,arrayLength);//��������
				break;
			default:
				break;
		}
	}
}
void arrange(void){//��������
	char ch3;
	while(1){
		clearCache();
		printf("//////��ѡ�������ѡ��//////\n");
		printf("0)�˳��Ӳ˵�\n");
		printf("1)ð�ݷ�\n");
		printf("2)ѡ��\n");
		printf("3)������\n");
		printf("////////////////////////////\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch3);
		clearCache();
		if(ch3=='0') break;
		switch(ch3){
			case '1':
				bubble(a,arrayLength);//ð�ݷ�
				break;
			case '2':
				choice(a,arrayLength);//ѡ��
				break;
			case '3':
				exchanges(a,arrayLength);//������
				break;
			default:
				break;
		}
	}
}
void back(int a[],int arrayLength){//��������
	int b[arrayLength];
	for(int i=0;i<arrayLength;i++){
		b[arrayLength-1-i]=a[i];
	}
	for(int i=0;i<arrayLength;i++){
		a[i]=b[i];
	}
	return;
}
void left(int a[],int arrayLength){//��������
	int m,b[arrayLength];
	printf("��������Ҫ������λ����");
	scanf("%d",&m);
	for(int i=0;i<arrayLength-m;i++){
		b[i]=a[m+i];
	}
	for(int i=arrayLength-m;i<arrayLength;i++){
		b[i]=a[m+i-arrayLength];
	}
	for(int i=0;i<arrayLength;i++){
		a[i]=b[i];
	}
	return;
}
void right(int a[],int arrayLength){//��������
	int m,b[arrayLength];
	printf("��������Ҫ������λ����");
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		b[i]=a[i+arrayLength-m];
	}
	for(int i=m;i<arrayLength;i++){
		b[i]=a[i-m];
	}
	for(int i=0;i<arrayLength;i++){
		a[i]=b[i];
	}
	return;
}
void bubble(int a[],int arrayLength){//ð�ݷ�
	int t,mid;
	for(int i=0;i<arrayLength-1;i++){
		t=0;
		for(int j=arrayLength-1;j>i;j--){
			if(a[j-1]>a[j]){
				mid=a[j];
				a[j]=a[j-1];
				a[j-1]=mid;
				t++;
			}
		}
		if(t==0) break;
	}
	return;
}
void choice(int a[],int arrayLength){//ѡ��
	int n,min,mid;
	for(int i=0;i<arrayLength-1;i++){
		n=i;min=a[i];
		for(int j=i+1;j<arrayLength;j++){
			if(min>a[j]){
				n=j;min=a[j];
			}
		}
		mid=a[n];
		a[n]=a[i];
		a[i]=mid;
	}
	return;
}
void exchanges(int a[],int arrayLength){//������
	int mid;
	for(int i=0;i<arrayLength-1;i++){
		for(int j=i+1;j<arrayLength;j++){
			if(a[i]>a[j]){
				mid=a[i];
				a[i]=a[j];
				a[j]=mid;
			}
		}
	}
	return;
}
/*
Programed by Li Xiaoyi
All rights reserved
*/
