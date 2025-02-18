#include<stdio.h>
int main(){
	float data[8];
	float sum=0,ave;
	int i,a;
	FILE*fp;
	printf("Please set a file d:\\data.txt and put 8 stastics in\n");
	printf("If you have set the file,press 0 to start the program\n");
	printf("Otherwise,press 1 to end the program\n");
	printf("What's your choice?\n");
	scanf("%d",&a);
	if(a==0){
		fp=fopen("d:\\data.txt","r");
	for(i=0;i<8;i++)
	{
		fscanf(fp,"%f",&data[i]);
		sum=sum+data[i];
	}
	ave=sum/8;
	printf("the average is %.2f",ave);
	return 0;
	}
	else return 1;		
} 
