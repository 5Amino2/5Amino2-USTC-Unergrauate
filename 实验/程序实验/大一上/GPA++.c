#include<stdio.h>
int main(){
	float GPA;
	int score;
	printf("Your score is?\n");
	scanf("%d",&score);
	if(score<=0 || score>=100){
		printf("Are you kidding me?");
	}	
	return 0;
}
