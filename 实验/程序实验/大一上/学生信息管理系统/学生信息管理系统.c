#include<stdio.h>
#include<stdlib.h>
struct _studinfo{
	int num;
	char name[10];
	int gender;
	int age;
	float grade;
	struct _studinfo *next;
};
struct _studinfo *head,*rear,*p,*read;
void CreateMenu(void);//����ѧ����¼����
void PrintAll(void);//��ӡȫ��ѧ����¼
void InsertMenu(void);//����һ���µ�ѧ����¼
void DeleteMenu(void);//������ɾ��һ��ѧ����¼
void FindMenu(void);//���Ҳ˵�
void FindNum(void);//��ѧ�Ų���ѧ����¼
void FindGrade(void);//���ɼ�����ѧ����¼
void FindAge(void);//���������ѧ����¼
void FindGender(void);//���Ա����ѧ����¼
void AnalyzeMenu(void);//ͳ�Ʋ˵�
void DeleteAll(void);//����ѧ������
void RewriteMenu(void);//��ѧ����Ϣ����д������ļ�
void Headin(void);//ͷ�巨
void Rearin(void);//β�巨
void Arrayin(void);//������ѧ����������
void Filein(void);//��ѧ����Ϣ�ļ���������
void InsertNamed(void);//��ָ��λ�����
void InsertArray(void);//�����������в���
void DeleteNamed(void);//��ָ��λ��ɾ��
void DeleteNum(void);//ɾ��ָ��ѧ��
char *PrintGender(int);//ת���������Ա�
void AnalyzeStunum(void);//ͳ��ѧ������
void AnalyzeAveMax(void);//ͳ��ѧ����ƽ���ɼ�����߷�
void AnalyzeFail(void);//ͳ�Ʋ���������
void RewriteW(void);//��дѧ���ļ�
void RewriteA(void);//׷��ѧ���ļ�
void RewriteC(void);//���ѧ���ļ�
int main(){
	head=NULL;
	rear=NULL;
	p=NULL;
	char ch;
	while(1){
		printf("\n*******************************************\n");
		printf("\tѧ����Ϣ����ϵͳ���ܲ˵�\t\n");
		printf("*******************************************\n");
		printf("0���˳�\n");
		printf("1������ѧ����¼����\n");
		printf("2����ӡȫ��ѧ����¼\n");
		printf("3������һ���µ�ѧ����¼\n");
		printf("4��������ɾ��һ��ѧ����¼\n");
		printf("5������\n");
		printf("6��ͳ��\n");
		printf("7������ѧ������\n");
		printf("8����ѧ����Ϣ����д������ļ�\n");
		printf("*******************************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				CreateMenu();//����ѧ����¼����
				break;
			case '2':
				PrintAll();//��ӡȫ��ѧ����¼
				break;
			case '3':
				InsertMenu();//����һ���µ�ѧ����¼
				break;
			case '4':
				DeleteMenu();//������ɾ��һ��ѧ����¼
				break;
			case '5':
				FindMenu();//���Ҳ˵�
				break;
			case '6':
				AnalyzeMenu();//ͳ�Ʋ˵�
				break;
			case '7':
				DeleteAll();//����ѧ������
				break;
			case '8':
				RewriteMenu();//��ѧ����Ϣ����д������ļ�
				break;
			default:
				break;
		}
	}
	return 0;
}
void CreateMenu(void){//����ѧ����¼����
	char ch;
	while(1){
		printf("\n*******************************************\n");
		printf("\t����ѧ����¼����˵�\t\n");
		printf("*******************************************\n");
		printf("0���˳�\n");
		printf("1��ͷ�巨\n");
		printf("2��β�巨\n");
		printf("3��������ѧ����������\n");
		printf("4����ѧ����Ϣ�ļ���������\n");
		printf("*******************************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				Headin();//ͷ�巨
				break;
			case '2':
				Rearin();//β�巨
				break;
			case '3':
				Arrayin();//������ѧ����������
				break;
			case '4':
				Filein();//��ѧ����Ϣ�ļ���������
				break;
			default:
				break;
		}
	}
	return;
}
void PrintAll(void){//��ӡȫ��ѧ����¼
	for(p=head;p!=NULL;p=p->next){
		printf("ѧ�ţ�%d\n������%s\n�Ա�%s\n���䣺%d\n�ɼ���%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
	}
	return;
}
void InsertMenu(void){//����һ���µ�ѧ����¼
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t����˵�\t\n");
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1����ָ��λ�����\n");
		printf("2�������������в���\n");
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				InsertNamed();//��ָ��λ�����
				break;
			case '2':
				InsertArray();//�����������в���
				break;
			default:
				break;
		}
	}
	return;
}
void DeleteMenu(void){//������ɾ��һ��ѧ����¼
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\tɾ���˵�\t\n");
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1����ָ��λ��ɾ��\n");
		printf("2��ɾ��ָ��ѧ��\n");
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				DeleteNamed();//��ָ��λ��ɾ��
				break;
			case '2':
				DeleteNum();//ɾ��ָ��ѧ��
				break;
			default:
				break;
		}
	}
	return;
}
void FindMenu(void){//���Ҳ˵�
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t���Ҳ˵�\t\n");
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1����ѧ�Ų���ѧ����¼\n");
		printf("2�����ɼ�����ѧ����¼\n");
		printf("3�����������ѧ����¼\n");
		printf("4�����Ա����ѧ����¼\n");
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				FindNum();//��ѧ�Ų���ѧ����¼
				break;
			case '2':
				FindGrade();//���ɼ�����ѧ����¼
				break;
			case '3':
				FindAge();//���������ѧ����¼
				break;
			case '4':
				FindGender();//���Ա����ѧ����¼
				break;
			default:
				break;
		}
	}
	return;
}
void FindNum(void){//��ѧ�Ų���ѧ����¼
	int n;
	printf("��������Ҫ���ҵ�ѧ�ţ�");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->num==n){
			printf("ѧ�ţ�%d\n������%s\n�Ա�%s\n���䣺%d\n�ɼ���%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void FindGrade(void){//���ɼ�����ѧ����¼
	int n;
	printf("��������Ҫ���ҵĳɼ���");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->grade==n){
			printf("ѧ�ţ�%d\n������%s\n�Ա�%s\n���䣺%d\n�ɼ���%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void FindAge(void){//���������ѧ����¼
	int n;
	printf("��������Ҫ���ҵ����䣺");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->age==n){
			printf("ѧ�ţ�%d\n������%s\n�Ա�%s\n���䣺%d\n�ɼ���%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void FindGender(void){//���Ա����ѧ����¼
	int n;
	printf("��������Ҫ���ҵ��Ա�(����Ϊ1��Ů��Ϊ0)");
	scanf("%d",&n);
	for(p=head;p!=NULL;p=p->next){
		if(p->gender==n){
			printf("ѧ�ţ�%d\n������%s\n�Ա�%s\n���䣺%d\n�ɼ���%f\n\n",p->num,p->name,PrintGender(p->gender),p->age,p->grade);
		}
	}
	return;
}
void AnalyzeMenu(void){//ͳ�Ʋ˵�
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\t����˵�\t\n");
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1��ͳ��ѧ������\n");
		printf("2��ͳ��ѧ����ƽ���ɼ�����߷�\n");
		printf("3��ͳ�Ʋ���������\n");
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				AnalyzeStunum();//ͳ��ѧ������
				break;
			case '2':
				AnalyzeAveMax();//ͳ��ѧ����ƽ���ɼ�����߷�
				break;
			case '3':
				AnalyzeFail();//ͳ�Ʋ���������
				break;
			default:
				break;
		}
	}
	return;
}
void DeleteAll(void){//����ѧ������
	int n;
	printf("��ȷ��Ҫ����������\n");
	printf("1����\n");
	printf("0����\n");
	scanf("%d",&n);
	if(n==1){
		head=NULL;
		rear=NULL;
		p=NULL;
	}
	return;
}
void RewriteMenu(void){//��ѧ����Ϣ����д������ļ�
	char ch;
	while(1){
		printf("\n*********************************\n");
		printf("\tд������ļ��˵�\t\n");
		printf("*********************************\n");
		printf("0���˳�\n");
		printf("1����дѧ���ļ�\n");
		printf("2��׷��ѧ���ļ�\n");
		printf("3�����ѧ���ļ�\n");
		printf("*********************************\n");
		printf("��ѡ��˵���ţ��˵�ǰ�����֣���");
		scanf("%c",&ch);
		fflush(stdin);
		if(ch=='0') break;
		switch(ch){
			case '1':
				RewriteW();//��дѧ���ļ�
				break;
			case '2':
				RewriteA();//׷��ѧ���ļ�
				break;
			case '3':
				RewriteC();//���ѧ���ļ�
				break;
			default:
				break;
		}
	}
	return;
}
void Headin(void){//ͷ�巨
	int n;
	printf("��������Ҫ�����Ԫ�ظ�����");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		printf("������ѧ�ţ�");
		scanf("%d",&p->num);
		printf("������������");
		scanf("%s",p->name);
		printf("�������Ա�(����Ϊ1��Ů��Ϊ0)");
		scanf("%d",&p->gender);
		printf("���������䣺");
		scanf("%d",&p->age);
		printf("������ɼ���");
		scanf("%f",&p->grade);
		p->next=NULL;
		if(head==NULL){
			p->next=head;
			head=p;
			rear=p;
		}
		else{
			p->next=head;
			head=p;
		}
	}
	return;
}
void Rearin(void){//β�巨
	int n;
	printf("��������Ҫ�����Ԫ�ظ�����");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		printf("������ѧ�ţ�");
		scanf("%d",&p->num);
		printf("������������");
		scanf("%s",p->name);
		printf("�������Ա�(����Ϊ1��Ů��Ϊ0)");
		scanf("%d",&p->gender);
		printf("���������䣺");
		scanf("%d",&p->age);
		printf("������ɼ���");
		scanf("%f",&p->grade);
		p->next=NULL;
		if(head==NULL){
			p->next=head;
			head=p;
			rear=p;
		}
		else{
			rear->next=p;
			rear=p;
		}
	}
	return;
}
void Arrayin(void){//������ѧ����������
	int n;
	printf("��������Ҫ�����Ԫ�ظ�����");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		printf("������ѧ�ţ�");
		scanf("%d",&p->num);
		printf("������������");
		scanf("%s",p->name);
		printf("�������Ա�(����Ϊ1��Ů��Ϊ0)");
		scanf("%d",&p->gender);
		printf("���������䣺");
		scanf("%d",&p->age);
		printf("������ɼ���");
		scanf("%f",&p->grade);
		p->next=NULL;
		if(head==NULL){//������
			p->next=head;
			head=p;
			rear=p;
		}
		else if((p->num)<=(head->num)){//��ǰ����ͷ�巨
			p->next=head;
			head=p;
		}
		else if((p->num)>=(rear->num)){//�������β�巨
			rear->next=p;
			rear=p;
		}
		else{
			for(read=head;read->next!=NULL;read=read->next){//ѧ�����м�
				if((read->num)<=(p->num)&&(p->num)<=((read->next)->num)){
					p->next=read->next;
					read->next=p;
					break;
				}
			}
		}
	}
	return;
}
void Filein(void){//��ѧ����Ϣ�ļ���������
	FILE *readf;
	int n=0;
	readf=fopen("text.txt","rb");
	p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
	n=fscanf(readf,"%d%s%d%d%f",&p->num,p->name,&p->gender,&p->age,&p->grade);
	p->next=NULL;
	while(n!=EOF){
		if(head==NULL){
			p->next=head;
			head=p;
			rear=p;
		}
		else{
			rear->next=p;
			rear=p;
		}
		p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
		n=fscanf(readf,"%d%s%d%d%f",&p->num,p->name,&p->gender,&p->age,&p->grade);
		p->next=NULL;
	}
	return;
}
void InsertNamed(void){//��ָ��λ�����
	int i,j,n=0;//i:��ǰѧ������
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	while(n<1||n>i+1){
		printf("��������Ҫ�����λ��");
		scanf("%d",&n);
	}
	p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
	printf("������ѧ�ţ�");
	scanf("%d",&p->num);
	printf("������������");
	scanf("%s",p->name);
	printf("�������Ա�(����Ϊ1��Ů��Ϊ0)");
	scanf("%d",&p->gender);
	printf("���������䣺");
	scanf("%d",&p->age);
	printf("������ɼ���");
	scanf("%f",&p->grade);
	p->next=NULL;
	if(head==NULL){
		p->next=head;
		head=p;
		rear=p;
		return;
	}
	if(n==1){
		p->next=head;
		head=p;
		return;
	}
	if(n==i+1){
		rear->next=p;
		rear=p;
		return;
	}
	else{
		for(read=head,j=1;j<n-1;read=read->next,j++);
		p->next=read->next;
		read->next=p;
		return;
	}
	return;
}
void InsertArray(void){//�����������в���
	p=(struct _studinfo *)malloc(sizeof(struct _studinfo));
	printf("������ѧ�ţ�");
	scanf("%d",&p->num);
	printf("������������");
	scanf("%s",p->name);
	printf("�������Ա�(����Ϊ1��Ů��Ϊ0)");
	scanf("%d",&p->gender);
	printf("���������䣺");
	scanf("%d",&p->age);
	printf("������ɼ���");
	scanf("%f",&p->grade);
	p->next=NULL;
	if(head==NULL){//������
		p->next=head;
		head=p;
		rear=p;
		return;
	}
	else if((p->num)<=(head->num)){//��ǰ����ͷ�巨
		p->next=head;
		head=p;
		return;
	}
	else if((p->num)>=(rear->num)){//�������β�巨
		rear->next=p;
		rear=p;
		return;
	}
	else{
		for(read=head;read->next!=NULL;read=read->next){//ѧ�����м�
			if((read->num)<=(p->num)&&(p->num)<=((read->next)->num)){
				p->next=read->next;
				read->next=p;
				break;
			}
		}
	}
	return;
}
char *PrintGender(int n){//ת���������Ա�
	if(n==0) return "Ů";
	if(n==1) return "��";
	else return "δ֪";
}
void AnalyzeStunum(void){//ͳ��ѧ������
	int i;
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	printf("��ǰѧ��������%d",i);
	return;
}
void AnalyzeAveMax(void){//ͳ��ѧ����ƽ���ɼ�����߷�
	int i=0;
	float sum=0,max=head->grade;
	for(read=head;read!=NULL;read=read->next){
		sum+=read->grade;
		i++;
		if((read->grade)>max) max=read->grade;
	}
	printf("��ǰѧ��ƽ���ɼ���%f\n��߷֣�%f\n",sum/i,max);
	return;
}
void AnalyzeFail(void){//ͳ�Ʋ���������
	int i;
	for(read=head,i=0;read!=NULL;read=read->next){
		if(read->grade<60) i++;
	}
	printf("��ǰ������ѧ��������%d",i);
}
void RewriteW(void){//��дѧ���ļ�
	FILE *write;
	write=fopen("text.txt","wb");
	for(p=head;p!=NULL;p=p->next){
		fprintf(write,"%d\n%s\n%d\n%d\n%f\n\n",p->num,p->name,p->gender,p->age,p->grade);
	}
	fclose(write);
	return;
}
void RewriteA(void){//׷��ѧ���ļ�
	FILE *write;
	write=fopen("text.txt","ab");
	for(p=head;p!=NULL;p=p->next){
		fprintf(write,"%d\n%s\n%d\n%d\n%f\n\n",p->num,p->name,p->gender,p->age,p->grade);
	}
	fclose(write);
	return;
}
void RewriteC(void){//���ѧ���ļ�
	FILE *write;
	write=fopen("text.txt","wb");
	fclose(write);
}
void DeleteNamed(void){//��ָ��λ��ɾ��
	int n=0,i,j;//iΪ��ǰѧ������
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	if(i==0){
		printf("��ǰ����Ϊ��!\n");
		return;
	}
	while(n<1||n>i){
		printf("��������Ҫɾ����λ��");
		scanf("%d",&n);
	}
	if(i==1){
		head=NULL;
		rear=NULL;
		p=NULL;
		return;
	}
	else if(n==1){
		head=head->next;
		return;
	}
	else if(n==i){
		for(p=head,j=0;j<i-2;p=p->next,j++);
		rear=p;
		rear->next=NULL;
	}
	else{
		for(p=head,j=0;j<n-2;p=p->next,j++);
		p->next=(p->next)->next;
	}
}
void DeleteNum(void){//ɾ��ָ��ѧ��
	int n,i,j;
	for(read=head,i=0;read!=NULL;read=read->next,i++);
	if(i==0){
		printf("��ǰ����Ϊ��!\n");
		return;
	}
	printf("��������Ҫɾ����ѧ�ţ�");
	scanf("%d",&n);
	if(head->num==n){
		head=head->next;
		return;
	}
	else if(rear->num==n){
		for(p=head,j=0;j<i-2;p=p->next,j++);
		rear=p;
		rear->next=NULL;
		return;
	}
	else{
		for(p=head;(p->next)!=NULL;p=p->next){
			if((p->next)->num==n){
				p->next=(p->next)->next;
			}
		}
	}
	return;
}
