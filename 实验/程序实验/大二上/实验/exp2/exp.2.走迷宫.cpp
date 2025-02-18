#include<stdio.h>
#define N 8//�Թ���С
#define MAXSIZE 64//ջ������С
int Block[N+2][N+2]={//����
	1,1,1,1,1,1,1,1,1,1,
	1,0,1,0,0,1,0,0,0,1,
	1,0,1,0,1,0,0,1,1,1,
	1,0,1,0,1,0,0,0,0,1,
	1,0,1,0,0,0,0,1,0,1,
	1,0,1,0,1,1,1,0,0,1,
	1,0,1,0,0,1,0,0,0,1,
	1,0,1,1,0,1,1,1,0,1,
	1,0,0,0,0,1,0,0,0,1,
	1,1,1,1,1,1,1,1,1,1
};
int Find[N+2][N+2]={0};//���ڱ�ǣ���ֹ�߻�ͷ·
typedef struct{//����
	int x;
	int y;
}CURPOS;
typedef struct{//ջ������ÿһ��������
	CURPOS e[MAXSIZE];
	int top;
}STACK;
int Initial(CURPOS &p,CURPOS start,STACK &sta);
int Ifend(CURPOS &p,CURPOS end);
int Search(CURPOS &p,STACK &sta);
int IfMove(CURPOS p,int i,STACK sta);
int Move(CURPOS &p,int i,STACK &sta);
int Back(CURPOS &p,STACK &sta);
int Push(STACK &sta,CURPOS p);
CURPOS Pop(STACK &sta);
int StepPrint(STACK &sta);
int main(){
	CURPOS p,end,start;//pΪ�ƶ����꣬start��endΪ��㡢�յ�����
	STACK sta;//����ջ
	start.x=1;start.y=1;end.x=N;end.y=N;
	Initial(p,start,sta);//��ʼ��������������꣬ͬʱ��ʼ������ջ
	do{
		Search(p,sta);//����ÿһ����ŵ��λ�ã������������ƶ���û�ѵ��������
	}while(Ifend(p,end)==0&&sta.top>=0);//p�����յ㣬�Ҳ���ջ
	StepPrint(sta);//��ӡ��������

}

int Initial(CURPOS &p,CURPOS start,STACK &sta){//��ʼ��������������꣬ͬʱ��ʼ������ջ
	p.x=start.x;p.y=start.y;
	sta.top=(-1);
	return 1;
}
int Ifend(CURPOS &p,CURPOS end){//�����յ����꣬�ж�p�Ƿ����յ�
	if(p.x==end.x&&p.y==end.y) return 1;
	else return 0;
}
int Search(CURPOS &p,STACK &sta){//����ÿһ����ŵ��λ�ã������������ƶ���û�ѵ��������
	for(int i=0;i<4;i++){
		if(IfMove(p,i,sta)){
			Move(p,i,sta);
			return 1;
		}
	}
	Back(p,sta);
	return 0;
}
int IfMove(CURPOS p,int i,STACK sta){//������ŵ�λ��
	if(i==0){//��i�����ĸ�����ֱ�����
		p.x++;
	}
	else if(i==1){
		p.y++;
	}
	else if(i==2){
		p.x--;
	}
	else if(i==3){
		p.y--;
	}
	for(int j=0;j<=sta.top;j++){//��ջ�в��������غϣ������߻�ͷ·
		if(p.x==sta.e[j].x&&p.y==sta.e[j].y) return 0;
	}
	if(Block[p.x][p.y]==0&&Find[p.x][p.y]==0) return 1;//û�������ϰ������ظ���·����������
	else return 0;
}
int Move(CURPOS &p,int i,STACK &sta){//�ƶ�p,ѹջ
	if(i==0){//��i�����ĸ�����ֱ��ƶ�
		p.x++;
	}
	else if(i==1){
		p.y++;
	}
	else if(i==2){
		p.x--;
	}
	else if(i==3){
		p.y--;
	}
	Push(sta,p);//ѹջ
	return 1;
}
int Back(CURPOS &p,STACK &sta){//������һ������ջ��������߹���·��
	Find[p.x][p.y]=1;
	Pop(sta);
	p=sta.e[sta.top];
	return 1;
}
int Push(STACK &sta,CURPOS p){//ѹջ
	if(sta.top>=MAXSIZE) return 0;//�Ϸ��Լ��
	sta.top++;
	sta.e[sta.top]=p;
	return 1;
}
CURPOS Pop(STACK &sta){//��ջ
	if(sta.top<0) return sta.e[0];//�Ϸ��Լ��
	sta.top--;
	return sta.e[sta.top+1];
}
int StepPrint(STACK &sta){//��ӡ��������
	if(sta.top<0){
		printf("�޽⣡");
		return 0;
	}
	for(int i=0;i<=sta.top;i++){
		printf("��%d��:\n",i);
		printf("(%d,%d)\n",sta.e[i].x,sta.e[i].y);
	}
	return 1;
}
