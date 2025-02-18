#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
void draw(int t);
void grow(void);
void set(void);
char def(int input);
int state(int now,int srd);
int life[42][42];
int prelife[42][42];
int main(){
	int n;
	printf("请输入你要生长的次数：");
	scanf("%d",&n);
	set();//初始化
	draw(0);//绘图
	for(int i=0;i<n;i++){
		grow();//生长
		Sleep(1000);
		draw(i+1);//绘图
	}
	return 0;
}
void draw(int t){
	system("cls");
	for(int i=1;i<41;i++){
		for(int j=1;j<41;j++){
			putchar(def(life[i][j]));
			putchar(32);
		}
		putchar('\n');
	}
	printf("第%d次生长",t);
}
void grow(void){
	for(int i=1;i<41;i++){
		for(int j=1;j<41;j++){
			prelife[i][j]=life[i][j];
		}
	}
	for(int i=1;i<41;i++){
		for(int j=1;j<41;j++){
			life[i][j]=state(prelife[i][j],prelife[i+1][j]+prelife[i][j+1]+prelife[i-1][j]+prelife[i][j-1]);
		}
	}
}
void set(void){
	for(int i=1;i<41;i++){
		for(int j=1;j<41;j++){
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
	return 0;
}
