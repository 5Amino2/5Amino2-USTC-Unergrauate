#include<stdio.h>
int main(){
	int m,n,p,q,s;
	printf("���������������������� ��ĸ����");//m��pΪ���ӣ�n��qΪ��ĸ
again:	scanf("%d %d",&m,&n);
	if(m<=0||n<=0){//������
		printf("������������������");
		goto again;//�ٴ�����
	}
	if(m>n){//���Ӵ��ڷ�ĸ
		printf("���Ӵ��ڷ�ĸ��");
		goto again;//�ٴ�����
	}
	for(p=m,q=n;(p!=0)&&(p!=1);){//շת����������Լ��
		s=p;
		p=q%p;
		q=s;
	}
	if(p==0){//���ӷ�ĸ�ɻ���
		printf("����%d/%d �����Ϊ%d/%d",m,n,m/q,n/q);
	}
	if(p==1){//���ӷ�ĸ����
		printf("����%d/%d �����Ϊ%d/%d",m,n,m,n);
	}
	return 0;
}
