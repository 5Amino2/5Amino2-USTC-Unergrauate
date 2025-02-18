#include<stdio.h>
int main(){
	int n,s1=0,s2=0,i;
	float s3=0;
	printf("请输入一个正整数：");
	scanf("%d",&n);
	if(n<=0){//正整数检验
		printf("输入错误！\n");
		return -1;
	}
	for(i=1;i<=n;i++){//for语句求和
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
	while(i<=n){//while语句求和
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
	do{//do-while语句求和
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
