#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int main(){
	int a,b;
	for (a=0;a<=10;a++){
		system("cls");
		for(b=1;b<a;b++)printf("��");
		printf("%2d%%",(b-1)*10);
		Sleep(100*(a+1));	 
	}
	Sleep(500);
	system("cls");
	printf("��������������������99%%");
	Sleep(2000);
	system("cls");
	printf("��������������������99.9%%");
	Sleep(4000);
	printf("\n��װʧ������\n");
} 
