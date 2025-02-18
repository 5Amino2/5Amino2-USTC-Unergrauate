#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#define LEN 50
#define WID 50
#define SPEED 10
#define TIMES 50
void draw(void);
void grow(void);
void set(void);
char def(int input);
int state(int now,int srd);
int life[LEN+2][WID+2];
int prelife[LEN+2][WID+2];
int main(){
	set();//初始化
	draw();//绘图
	for(int i=0;i<TIMES;i++){
		grow();//生长
		Sleep(SPEED);
		draw();//绘图
	}
	return 0;
}
void draw(void){
	system("cls");
	for(int i=1;i<LEN+1;i++){
		for(int j=1;j<WID+1;j++){
			putchar(def(life[i][j]));
			putchar(32);
		}
		putchar('\n');
	}
}
void grow(void){
	for(int i=1;i<LEN+1;i++){
		for(int j=1;j<WID+1;j++){
			prelife[i][j]=life[i][j];
		}
	}
	for(int i=1;i<LEN+1;i++){
		for(int j=1;j<WID+1;j++){
			life[i][j]=state(prelife[i][j],prelife[i+1][j]+prelife[i][j+1]+prelife[i-1][j]+prelife[i][j-1]);
		}
	}
}
void set(void){
	for(int i=1;i<LEN+1;i++){
		for(int j=1;j<WID+1;j++){
			srand(time(NULL)*i+j*i*j);
			life[i][j]=rand()%2;
		}
	}
}
char def(int input){
	if(input==0) return '-';
	if(input==1) return '*';
	else return '?';
}
int state(int now,int srd){
	if(now==0&&srd==3) return 1;
	if(now==1){
		if(srd<2) return 0;
		if(srd>=2&&srd<=3) return 1;
		if(srd>3) return 0;
	}
//	if(now==0&&srd==0){
//		srand(rand());
///		if(rand()%20==0) return 1;
//		else return 0;
//	}
	return 0;
}
