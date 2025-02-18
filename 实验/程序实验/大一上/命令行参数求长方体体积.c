#include<stdio.h>
#include<stdlib.h>
int main(int argc,char **argv){
	double a,b,c;
	if(argc!=4){
		printf("Error!");
	}
	else{
	a=atof(argv[1]);
	b=atof(argv[2]);
	c=atof(argv[3]);
	printf("%lf",a*b*c);
	}
	return 0;
}
