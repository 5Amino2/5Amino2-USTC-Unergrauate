#include<stdio.h>
int main(){
	int a=5;
	double b=23.54;
	printf("sizeof(short int)=%lld\n",sizeof(short int));
	printf("sizeof(unsigned short int)=%lld\n",sizeof(unsigned short int));
	printf("sizeof(int)=%lld\n",sizeof(int));
	printf("sizeof(unsigned int)=%lld\n",sizeof(unsigned int));
	printf("sizeof(long int)=%lld\n",sizeof(long int));
	printf("sizeof(long long int)=%lld\n",sizeof(long long int));
	printf("sizeof(float)=%lld\n",sizeof(float));
	printf("sizeof(double)=%lld\n",sizeof(double));
	printf("sizeof(long double)=%lld\n",sizeof(long double));
	printf("sizeof()=%lld\n",sizeof(""));//('\0'（未显示）占据一个字节)
	printf("sizeof(Hello World!)=%lld\n",sizeof("Hello World!"));
	printf("sizeof(int [3])=%lld\n",sizeof(int [3]));
	printf("sizeof(5/3.4)=%lld\n",sizeof(5/3.4));
	printf("sizeof(a=a+b)=%lld(int a;double b)\n",sizeof(a=a+b));
	printf("sizeof(b=a+b)=%lld(int a;double b)\n",sizeof(b=a+b));
	printf("b=%lf(double b)\n",b);
	printf("sizeof(b++)=%lld(double b)\n",sizeof(b++));
	printf("b=%lf(double b)\n",b);//b值不变
	getchar();
}
