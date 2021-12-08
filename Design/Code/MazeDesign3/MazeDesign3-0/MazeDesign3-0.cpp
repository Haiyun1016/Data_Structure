//����ʵ��
#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#define M 8
#define N 8
#define MaxSize 100

//���巽������
typedef struct
{
	int i;  //��ǰ������к�
	int j;  //��ǰ������к�
	int pre; //��¼��·����һ�����ڶ����е��±� 
}Box;

//����˳��ջ����
typedef struct
{
	Box data[MaxSize];
	int front, rear;   //��ͷ��βָ�� 
}Que;

int mg[M + 2][N + 2] =
{
	{1,N,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1}
};

int newmg[M + 2][N + 2] =
{
	{1,N,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1}
};

//��ʼ������ 
void InitQue(Que*& qu)
{
	qu = (Que*)malloc(sizeof(Que));
	qu->front = qu->rear = -1;
}

bool EmptyQue(Que*& qu)
{
	return (qu->front == qu->rear);
}

bool Push(Que*& qu, Box& e)
{
	if (qu->rear > 999)
		return false;
	e.pre = qu->front;
	qu->rear++;
	qu->data[qu->rear] = e;
	return true;
}

bool Pop(Que*& qu, Box& e)
{
	if (EmptyQue(qu))
		return false;
	qu->front++;
	e = qu->data[qu->front];
	return true;
}

void print(Que*& qu, int k)
{
	int j;   //����Ѱ�����·��
	int i1=0, j1=1;
	while (k != -1)
	{
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre = -1;
		//���ҵ���·���ϵķ����pre��Ա��Ϊ-1 
	}

	k = 0;
	int ns = 0;
	while (k < 1000) //���������������pre��ԱΪ-1�ķ������� 
	{
		if (qu->data[k].pre == -1)
		{
			ns++;
			newmg[i1][j1] = 2;
			string str;
			string str1, str2, str3, str4, str5;
		//	str1 = "\t(";
		//	str2 = qu->data[k].i;
			str3 = ',';
		//	str4 = qu->data[k].j;
		//	str5 = ")";
			char abc[20] = "abcde";
		//	str = str1 + str2 + str3 + str4 + str5;

			outtextxy(450,20,abc);
		//	printf("\t(%d,%d)", qu->data[k].i, qu->data[k].j);
		//	if (ns % 5 == 0)
		//		printf("\n"); //ÿ���5��Ԫ�غ��� 
		}
		k++;
	}
	printf("\n");
}

void DestroyQue(Que*& qu)
{
	free(qu);
}

bool mgpath(int xi, int yi, int xe, int ye)
{
	Box e;
	int i, j, pre;
	Que* qu;
	InitQue(qu);    //��ʼ������

	//������ 
	e.i = xi, e.j = yi, e.pre = -1;
	mg[xi][yi] = -1;
	Push(qu, e);

	while (!EmptyQue(qu))  //���в�����ѭ�� 
	{
		Pop(qu, e); //����Ԫ�س��� 
		i = e.i, j = e.j, pre = e.pre; //��¼��ǰ����Ԫ�صķ����� 
		if (i == xe && j == ye) //����Ԫ��Ϊ���������·�� 
		{
			print(qu, qu->front);  //���·������
			return true;
		}

		int d = -1;
		int in, jn;
		while (d < 4) //ÿ����λ������̽ 
		{
			d++;
			switch (d)
			{
			case 0: {in = i - 1, jn = j; break; }
			case 1: {in = i, jn = j + 1; break; }
			case 2: {in = i + 1, jn = j; break; }
			case 3: {in = i, jn = j - 1; break; }
			}
			if (mg[in][jn] == 0)
			{
				e.i = in, e.j = jn, e.pre = qu->front;
				Push(qu, e);
				mg[in][jn] = -1;//���丳ֵΪ-1���Ա��������ظ����� 
			}
		}
	}
	DestroyQue(qu);    //���ٶ��� 
	return false;
}

int main()
{
	if (!mgpath(1, 0, M, N+1))
		printf("���Թ�����û�н�");

	initgraph(600, 600);	         //������ͼ���ڣ���СΪ 1024x960 ����
	int left_top_x = 20;             //������ x ����
	int left_top_y = 20;             //���ζ��� y ����
	int right_bottom_x = 60;         //�����Ҳ� x ����
	int right_bottom_y = 60;         //���εײ� y ����

	int i = 0, j = 0;

	while (right_bottom_x <= 420 && j <= 9)
	{
		if (newmg[i][j] == 1)
		{
			setfillcolor(DARKGRAY);
			fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}
		if (newmg[i][j] == 2)
		{
			setfillcolor(YELLOW);
			fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}
		else
			rectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		while (right_bottom_y <= 380 && i <= 9)
		{
			left_top_y = left_top_y + 40;
			right_bottom_y = right_bottom_y + 40;
			i++;
			if (newmg[i][j] == 1)
			{
				setfillcolor(DARKGRAY);
				fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
			}
			if (newmg[i][j] == 2)
			{
				setfillcolor(YELLOW);
				fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
			}
			else
				rectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}

		left_top_x = left_top_x + 40;
		right_bottom_x = right_bottom_x + 40;
		left_top_y = 20;
		right_bottom_y = 60;
		i = 0;
		j++;

	}


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}