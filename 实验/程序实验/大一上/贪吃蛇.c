#include <stdio.h>  //��׼�������������
#include <stdlib.h> //����system����
#include <windows.h>//����Sleep�������������ٶ�
#include <time.h>   //����ʳ��ʱ������������õ�time������
#define DOWN_WALL 20	 //�±߿�  (�����ǽ)   //ʹ�ú궨�� ���Ƿ����Ժ�����߿��С
#define RIGHT_WALL 58 //�ұ߿� (�����ǽ)
//����typedef �Ժ����������͵Ľṹ�岻��Ҫstruct�ؼ��֣��������������� Snake s1;(ԭ����struct s_snake s1)
typedef struct s_snake //�����洢ÿһ�����������λ��
{
	int x; //x����
	int y; //y����
	struct s_snake *next; //��һ������
}Snake;
/*��������*/
void SetPos(int x,int y);//�ƶ���꺯��
int IsHitWall();//�ж�ײǽ����
int IsBiteYouself();//�ж�ҧ���Լ��ĺ���
void DrawFrame();//���߿���
void InitSnake();//��ʼ���ߺ���
void CreateFood();//����ʳ�ﺯ��
void PlayGame();//��Ϸ�ƶ�ѭ������
int Move();//�ƶ�����,�������
void Welcome();//��ӭ����
void free_snake(Snake *head);//�ͷ���Դ

Snake *head,*end;//��ͷ����β
Snake *p;//����ָ��
int speed=310;//����ʱ�䣬���������ƶ��ٶ�
int level = 0,score = 0;//����
int foodx,foody;//ʳ��ģ�x��y������
char key;//������ͣ/���� ����״̬

int main()
{
    Welcome(); //��ӭ����
	DrawFrame();//���߿�
	InitSnake();//��ʼ������
	CreateFood();//����ʳ��
	//�Ҳ���ʾ��Ϣ
	SetPos(60,7);
	printf("�÷�:%d",score);
	SetPos(60,8);
	printf("��ǰ�ٶ�:%d����",speed);
	SetPos(60,9);
	printf("ÿ+30���ٶȱ��");
	SetPos(60,10);
	printf("����ײǽ/ҧ���Լ�");
	SetPos(60,11);
	printf("���ո���ͣ/����");

	PlayGame();//��������������������Ϸ
	free_snake(head);
    return 0;
}

void SetPos(int x,int y)//���ù��λ��(���������ʾ�Ŀ�ʼλ��)
{
	/*  COORD��Windows API�ж����һ�ֽṹ��
	 *	typedef struct _COORD
	 *	{
	 *		SHORT X;
	 *		SHORT Y;
	 *	} COORD;
	 *
	 */
	COORD pos = {x,y};
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);//��� ��׼����ľ��
    SetConsoleCursorPosition(output,pos); //���ÿ���̨���λ��
}

int IsHitWall()//�ж��Ƿ�ײǽ
{
	if (head->x==0||head->x==RIGHT_WALL||head->y==0||head->y==DOWN_WALL)
	{  //��Ϊ��ͷ���ȶ������������һ����һ������ǰһ�Σ�����ֻҪ��ͷ��ײǽ����ô��������Ͳ��� ײǽ
		SetPos(DOWN_WALL,14);
		printf("��Ϸ������ײ��ǽ��\n");
		SetPos(DOWN_WALL,15);//�� �������������...��������ʾ
		return 1;
	}
	return 0;
}

int IsBiteYouself()//�ж��Ƿ�ҧ���Լ�
{
	while(p->next!=NULL)
	{
		p=p->next;
		if (head->x==p->x&&head->y==p->y)//�ж���ͷ�Ƿ������������غ�
		{
			SetPos(DOWN_WALL,14);
		    printf("��Ϸ��������ҧ���Լ���\n");
		    SetPos(DOWN_WALL,15);//�� ���밴�����������������ʾ
		    return 1;
		}
	}
	return 0;
}

void DrawFrame()//���߿�
{
	int i = 0;
	for(i=0;i<60;i+=2)//��ӡ���±߿� ע��i һ������ռ�� x 2����λ�� y 1����λ
    {
        SetPos(i,0);   //�ϱ߿�
        printf("��");
        SetPos(i,DOWN_WALL);//�±߿�
        printf("��");
    }
    for(i=1;i<DOWN_WALL;i++)//��ӡ���ұ߿�
    {
        SetPos(0,i); //��߿�
        printf("��");
        SetPos(RIGHT_WALL,i); //�ұ߿�
        printf("��");
    }
}

void InitSnake()//��ʼ������  ͷ�巨	��ʼ����(20,15)��ʼ���Ķ����� (��������)
{
	int i = 0;
	//����һ������λ�� ��β
	end=(Snake*)malloc(sizeof(Snake));
	end->x=20;
	end->y=15;
	end->next=NULL;
	//������������λ��
	for (i=1;i<=3;i++)
	{
		head = (Snake*)malloc(sizeof(Snake));
		head->x = 20+2*i; //ÿ������ x��� 2����λ
		head->y = 15;
		head->next=end;  //ͷ�巨
		end = head;
	}
	//����ͷ��ʼ��̰����
	while (end->next!=NULL)
	{
		SetPos(end->x,end->y);
		printf("��");
		end = end->next;
	}
}

void CreateFood()//����ʳ��
{
	srand(time(0));//�������������
	flag:
	while(1)//����food��x�������Ϊż������������ѭ���ж��Ƿ�Ϊż��
	{
		//rand()%num���� 0~num-1
		//rand������Χ����ʽrand()%(m+1-n)+n;��Ч��Χ�� [n,m]
		foody=rand()%(DOWN_WALL-1+1-1)+1;//foody����Ч��Χ�� [1,DOWN_WALL-1 ]
		foodx=rand()%(RIGHT_WALL-2+1-3)+3;//foodx����Ч��Χ��    [3,RIGHT_WALL-2] ע��x����2Ϊ��λ��
		if (foodx%2==0) break;
	}
	p=head;
	while(1)
	{
		if(p->x==foodx&&p->y==foody)//��������������ص��ˣ��ص���������ѭ��
		{
			goto flag;
		}
		if(p->next==NULL) //��ÿһ������Ƚ���ϣ�����ѭ��
		{
			break;
		}
		p=p->next;
	}
	SetPos(foodx,foody);
	printf("��");  //��ʾʳ��
}

void PlayGame()//̰�����ƶ�����ͣ
{
	int mv_ret = 0;//�ƶ���ķ���ֵ�����ײǽ�����ҧ���Լ�����Ϊ1

	key = 'd';//�տ�ʼ��̰����Ĭ�������ƶ�
	while (1)
	{
		//GetAsyncKeyState(VK_UP) �ж�VK_UP������״̬�����Ǳ����£���λ15��Ϊ1����̧����Ϊ0
		//����Ҫ ����0x8000 ȡ����15λ �����ж�
		if ((GetAsyncKeyState(VK_UP)&& 0x8000)&& key != 's')//��key!='s'����Ϊ���ܺ���
		{
			key='w';//��������������µģ��������ϼ�����key����Ϊw
		}
		else if ((GetAsyncKeyState(VK_DOWN)&& 0x8000)&& key != 'w')
		{
			key='s';
		}
		else if ((GetAsyncKeyState(VK_RIGHT) && 0x8000)&& key != 'a')
		{
			key='d';
		}
		else if ((GetAsyncKeyState(VK_LEFT)&& 0x8000) && key != 'd')
		{
			key='a';
		}
		else if (GetAsyncKeyState(VK_SPACE)&& 0x8000) //��ͣ/��������
		{
			//������������β(��β����)  ԭ��δ֪
			while(p->next!=NULL) p=p->next;
			SetPos(p->x,p->y);
			printf("��");
			while(1)//��ͣ���
			{
				Sleep(100); //��Ҫ��ʱ(����) Sleep(����)
				if (GetAsyncKeyState(VK_SPACE)&& 0x8000)
				{
					break;
				}
			}
			//�������ϵ���β
			SetPos(p->x,p->y);
			printf("  ");
		}
		else if(GetAsyncKeyState(VK_ESCAPE)&& 0x8000)//����ESC�˳���Ϸ��VK_ESCAPE == 27
		{
			return ;
		}
		//ʵʱˢ���ٶ�  �÷�ÿ+30�� �ƶ��ٶȱ��
		if (score==level && speed > 10)//�жϵ÷�
		{
			speed -=10; //˯��ʱ�䣬�ı��ƶ��ٶȣ�Խ��Խ��
			level +=30; //�ٶȱ������ �仯

			SetPos(60,8);
			printf("��ǰ�ٶ�:%d����",speed);
		}
		mv_ret = Move();//�ƶ�����
		if( mv_ret == 1)
		{
			break;
		}
	}
}

int Move()//�ƶ�������wǰ s�� a�� d�ң�ʵ���ƶ�:ͷ������һ����β������һ��
{
	int ret;
	//���ǰ��¿��Ʒ���� a,s,d,w ��
	if( (key != 'a') && (key != 's') && (key != 'd') && (key != 'w') )
	{
		return 0;
	}
	ret = IsHitWall(); //�Ƿ�ײǽ
	ret += IsBiteYouself(); //�Ƿ�ҧ���Լ�
	if(ret == 1)
	{
		return 1;
	}
	p = (Snake*)malloc(sizeof(Snake));//ͷ�����ӵ��Ǹ�
	p->next=head;//��ӵ�ͷ��

	switch(key)
	{
		case 'd'://����
		    p->x = head->x+2;//�ұ�
		    p->y = head->y;
	        break;
		case 'w'://����
			p->x=head->x;
			p->y=head->y-1;//����
			break;
		case 's'://����
			p->x=head->x;
			p->y=head->y+1;//����
			break;
		case 'a'://����
			p->x=head->x-2;//����
			p->y=head->y;
			break;
	}
	//�����µ�ͷ��
	SetPos(p->x,p->y);
    printf("��");
    head = p;//��̰���ߵ�ͷ�����һ����Ϊ�µ�ͷ ���൱����̰�����ƶ�һ��
    		//��� �ƶ���һ��պ���ʳ���λ��,�����ĳ�Ϊ��ͷ������ȥ����β
			//��� �ƶ���һ��պ���ʳ���λ�ã������ĳ�Ϊ��ͷ��ȥ����β������̰�����ƶ�һ���Ч��
    Sleep(speed);//�ƶ��ٶȵĿ���
	if (p->x==foodx && p->y==foody)//�ƶ���һ��պ���ʳ���λ��
	{
		CreateFood();
		score +=10;
		SetPos(60,7);
		printf("�÷�:%d",score);
	}
	else   //�Բ���ʳ�ͷ�����һ����β��ȥ��һ��
	{
		//�ƶ���һ��պ���ʳ���λ��,�����ĳ�Ϊ��ͷ������ȥ����β
		while(p->next->next!=NULL) p=p->next;//ָ����βǰһ����Ϊ��Ҫ�ͷ���β����Լ�ڴ�
		SetPos(p->x,p->y);//Ϊʲô����POS(p->next->x,p->next->y)?
		printf("  ");//������β(��ͷ��һ����β��һ��ʵ���ƶ�Ч��)

		free(p->next);//�ͷ���β
		p->next=NULL;
		p=head;//��pָ��head
	}
	return 0;
}

void Welcome()//��ӭ����
{
	SetPos(25,8);
	printf("��̰���ߡ� C���԰�");
	SetPos(25,11);
	printf("����Ϸ����");
	SetPos(25,12);
	printf("1������ײǽ��ҧ���Լ�");
	SetPos(25,13);
	printf("2�����ո���ͣ/������Ϸ");
	printf("\n");
	SetPos(30,15);
	system("pause");//��ͣ
	system("cls");//����
}

void free_snake(Snake *head)//�ͷ���Դ���ͷ�����ռ�
{
	if(head == NULL || head->next == NULL)
	{
		return ;
	}
    //��ͷ����ʼ����ڵ��ͷ�
	while( (p=head) != NULL)
	{
		head = head->next;
		free(p);
	}
}
