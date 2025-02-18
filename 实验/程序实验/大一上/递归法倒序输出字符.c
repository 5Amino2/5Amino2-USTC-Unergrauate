#include<stdio.h>
int main(){
	char i=getchar();
	if(i!='\n') main();
	printf("%c",i);
}
