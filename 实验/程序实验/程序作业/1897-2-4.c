#include<stdio.h>
#include<math.h>
int main(){
	long long int a;
	printf("������һ��������-10000000~10000000����\n");
	scanf("%d",&a);
	if (fabs(a)>1e+7) {
		printf("����������ֳ�����Χ��");
		return 1;
	}
	if ((a%3==0)&&(a%5==0)){
		printf("YES");
	}
	else {
		printf("NO");
	}
	return 0;
}
