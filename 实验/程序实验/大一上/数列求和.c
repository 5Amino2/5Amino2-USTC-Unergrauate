#include<stdio.h>
int main(){
	int n,s1=0,s2=0,i;
	float s3=0;
	printf("�������������е���ͣ�");
	printf("\ns1=1+2+3+...+n");
	printf("\ns2=1+3+5+...+2n-1");
	printf("\ns3=1-1/2+1/3-1/4+...+1/(n-1)-1/n");
	printf("\n������һ����������");
ed:	scanf("%d",&n);
	if(n<=0){//����������
		printf("�������\n");
		goto ed;
	}
	for(i=1;i<=n;i++){//for������
		s1+=i;
		s2+=2*i-1;
		if(i%2==0){
			s3-=(float)1/i;
		}
		else{
			s3+=(float)1/i;
		}
	}
	printf("for:s1=%d,s2=%d,s3=%.6f",s1,s2,s3);
	s1=0;s2=0;s3=0;i=1;
	while(i<=n){//while������
		s1+=i;
		s2+=2*i-1;
		if(i%2==0){
			s3-=(float)1/i;
		}
		else{
			s3+=(float)1/i;
		}
		i++;
	}
	printf("\nwhile:s1=%d,s2=%d,s3=%.6f",s1,s2,s3);
	s1=0;s2=0;s3=0;i=1;
	do{//do-while������
		s1+=i;
		s2+=2*i-1;
		if(i%2==0){
			s3-=(float)1/i;
		}
		else{
			s3+=(float)1/i;
		}
		i++;
	}
	while(i<=n);
	printf("\ndo while:s1=%d,s2=%d,s3=%.6f",s1,s2,s3);
	return 0;
}
