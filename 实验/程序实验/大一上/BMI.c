#include<stdio.h>
int main()
{
	float height,bmi;
	int weight;
	printf("your height?(meter):");
	scanf("%f",&height);
	if(height<=0){
		printf("\nare you kidding me?");
		return 1;
	}
	printf("your weight?(kilogram):");
	scanf("%d",&weight);
	if(weight<=0){
		printf("\nare you kidding me?");
		return 2;
	}
	bmi=weight/height/height;
	if(bmi<18.5 && bmi>0){
		printf("your BMI is %.2f",bmi);
		printf("\nthin");
	}
	else if(bmi>=18.5 && bmi<24.9){
		printf("your BMI is %.2f",bmi);
		printf("\nmedium");
	} 
	else if(bmi>=24.9 && bmi<29.9){
		printf("your BMI is %.2f",bmi);
		printf("\nfat");
	}
	else if(bmi>=29.9){
		printf("your BMI is %.2f",bmi);
		printf("\nextermely fat");
	}
		else if(bmi<=0){
		printf("\nare you kidding me?");
		return 3;
	}
	return 0;
}
