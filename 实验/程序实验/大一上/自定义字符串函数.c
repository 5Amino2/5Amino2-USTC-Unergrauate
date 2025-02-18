#include<stdio.h>
int mystrcmp(char *s1,char *s2){
	while(*s1==*s2&&*s1!='\0'){
		s1++;s2++;
	}
	return *s1-*s2;
}
char *mystrcpy(char *dest,char *src){
	char *pd=dest;
	while(*pd++=*src++)
		;
	return dest;
}
int main(){
	
}
