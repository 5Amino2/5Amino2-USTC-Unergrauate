#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>
#define MAX_TEXT_SIZE 2000
#define ALPHANUM 26
typedef struct BTNode{
	char alpha;
	int alphanum;
	char Code[ALPHANUM];
	BTNode *LeftChild;
	BTNode *RightChild;
}BTNode;
typedef BTNode* TREE;
void input_text(char *Text);//���ļ���ȡ�ı������뵽�ַ���
void alpha_number(char *Text,int *alphanum);//ͳ����ĸ������Ȩֵ
int rank(BTNode *Node);//����ڵ�Ȩֵ
BTNode *initnode(char Alpha,int number,BTNode *Left,BTNode *Right);//��ʼ���ڵ�
void generate_node(int *alphanum,BTNode **Nodeline);//�����ڵ�����
int Conbine(BTNode **Nodeline);//�ϲ��ڵ㣬���طǿսڵ���
TREE Haffman(BTNode **Nodeline);//�������㷨�����Ϻϲ�ֱ��ֻ��һ���ڵ�
void Output(BTNode **Nodeline);//��ӡ�������������ļ���ʽ���
void addcode(BTNode *Node,int n);//���ڵ����
void Reversecode(BTNode *Node);//���뵹��
BTNode *Search(TREE Tree,char c);//Ѱ��ָ���ڵ�
void alphaline(TREE Tree,BTNode **Nodeline);//������õĽڵ��ٴ����Դ洢
BTNode *initnode(char Alpha,int number,BTNode *Left,BTNode *Right);//��ʼ���ڵ�
int main(){
	int alphanum[ALPHANUM]={0};
	BTNode *nodeline[ALPHANUM]={NULL};
	char Text[MAX_TEXT_SIZE];
	input_text(Text);//
	alpha_number(Text,alphanum);//
	generate_node(alphanum,nodeline);//
	TREE Tree=Haffman(nodeline);//
	Reversecode(Tree);
	alphaline(Tree,nodeline);
	Output(nodeline);
	return 0;
}
void input_text(char *Text){//���ļ���ȡ�ı������뵽�ַ���
	FILE *read;
	read=fopen("Text.txt","r");
	fgets(Text,MAX_TEXT_SIZE,read);
	fclose(read);
}
void alpha_number(char *Text,int *alphanum){//ͳ����ĸ������Ȩֵ
	for(int i=0;Text[i]!='\0';i++){
		if(!islower(Text[i])) continue;//�ж��Ƿ�ΪСд��ĸ
		alphanum[Text[i]-'a']++;
	}
}
BTNode *initnode(char Alpha,int number,BTNode *Left,BTNode *Right){//��ʼ���ڵ�
	BTNode *p=(BTNode *)malloc(sizeof(BTNode));
	p->alpha=Alpha;
	p->alphanum=number;
	p->Code[0]='\0';
	p->LeftChild=Left;
	p->RightChild=Right;
	return p;
}
void generate_node(int *alphanum,BTNode **Nodeline){//�����ڵ�����
	for(int i=0;i<ALPHANUM;i++){
		Nodeline[i]=initnode('a'+i,alphanum[i],NULL,NULL);
	}
}
int Conbine(BTNode **Nodeline){//�ϲ��ڵ㣬���طǿսڵ���
	int nodenum=0;//�ǿսڵ���
	int min1=-1,min2=-1;
	//Ѱ��Ȩֵ��С�������ǿսڵ�
	for(int i=0;i<ALPHANUM;i++){//Ѱ�ҷǿսڵ�
		if(Nodeline[i]==NULL) continue;
		nodenum++;
		if(min1==-1){//��ʼ��
			min1=i;
			continue;
		}
		if(min2==-1){
			if(min1<min2){
				min2=i;
				continue;
			}
			else{
				min2=min1;
				min1=i;
				continue;
			}
		}
		if(rank(Nodeline[i])<rank(Nodeline[min1])){
			min1=i;
			continue;
		}
		if(rank(Nodeline[i])<rank(Nodeline[min2])){
			min2=i;
			continue;
		}
	}
	//�ϲ���ɾ���ڵ�,���ڵ����
	addcode(Nodeline[min1],0);
	addcode(Nodeline[min2],1);
	Nodeline[min1]=initnode('\0',0,Nodeline[min1],Nodeline[min2]);
	Nodeline[min2]=NULL;
	nodenum--;
	return nodenum;
}
TREE Haffman(BTNode **Nodeline){//�������㷨�����Ϻϲ�ֱ��ֻ��һ���ڵ�
	while(Conbine(Nodeline)>1);
	for(int i=0;i<ALPHANUM;i++){
		if(Nodeline[i]!=NULL) return Nodeline[i];
	}
	return NULL;
}
void addcode(BTNode *Node,int n){//���ڵ����
	if(Node==NULL) return;
	if(n==0){
		strcat(Node->Code,"0");
	}
	if(n==1){
		strcat(Node->Code,"1");
	}
	addcode(Node->LeftChild,n);
	addcode(Node->RightChild,n);
	return;
}
int rank(BTNode *Node){//����ڵ�Ȩֵ
	if(Node==NULL) return 0;
	return (Node->alphanum+rank(Node->LeftChild)+rank(Node->RightChild));
}
void Reversecode(BTNode *Node){//���뵹��
	if(Node==NULL) return;
	Reversecode(Node->LeftChild);
	Reversecode(Node->RightChild);
	char string[ALPHANUM];
	strcpy(string,Node->Code);
	int i;
	for(i=0;string[i]!='\0';i++);
	i--;
	int j;
	for(j=0;i>=0;i--,j++){
		Node->Code[j]=string[i];
	}
	Node->Code[j]='\0';
	return;
}
void alphaline(TREE Tree,BTNode **Nodeline){//������õĽڵ��ٴ����Դ洢
	for(int n=0;n<ALPHANUM;n++){
		Nodeline[n]=Search(Tree,'a'+n);
	}
}
BTNode *Search(TREE Tree,char c){//Ѱ��ָ���ڵ�
	if(Tree==NULL) return NULL;
	BTNode *p;
	p=Search(Tree->LeftChild,c);
	if(p!=NULL) return p;
	p=Search(Tree->RightChild,c);
	if(p!=NULL) return p;
	if(Tree->alpha==c) return Tree;
	return NULL;
}
void Output(BTNode **Nodeline){//��ӡ���������룬���ļ���ʽ���
	FILE *write;
	write=fopen("Output.txt","w");
	for(int n=0;n<ALPHANUM;n++){
		fprintf(write,"%c������Ϊ��%d,����������Ϊ��%s\n",Nodeline[n]->alpha,Nodeline[n]->alphanum,Nodeline[n]->Code);
	}
	fclose(write);
}
