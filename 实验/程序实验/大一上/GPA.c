#include<stdio.h>
int main(){
	float gpa;
	printf("your GPA?\n");
	scanf("%f",&gpa);
	while(gpa>0){
		if(gpa<=4.3) printf("good\n");
		else printf("are you kidding me?\nI give you a chance again\n");
		scanf("%f",&gpa);
	}
	if(gpa<=0){
		printf("I have nothing to say...");
		return 1;
	}
	return 0; 
}
