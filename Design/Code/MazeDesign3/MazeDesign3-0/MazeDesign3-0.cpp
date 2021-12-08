//队列实现
#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
using namespace std;

#define M 8
#define N 8
#define MaxSize 100

//定义方块类型
typedef struct
{
	int i;  //当前方块的行号
	int j;  //当前方块的列号
	int pre; //记录本路径上一方块在队列中的下标 
}Box;

//定义顺序栈类型
typedef struct
{
	Box data[MaxSize];
	int front, rear;   //队头队尾指针 
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

//初始化队列 
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
	int j;   //反向寻找最短路径
	int i1=0, j1=1;
	while (k != -1)
	{
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre = -1;
		//将找到的路径上的方块的pre成员置为-1 
	}

	k = 0;
	int ns = 0;
	while (k < 1000) //遍历整个队列输出pre成员为-1的方块坐标 
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
		//		printf("\n"); //每输出5个元素后换行 
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
	InitQue(qu);    //初始化队列

	//起点入队 
	e.i = xi, e.j = yi, e.pre = -1;
	mg[xi][yi] = -1;
	Push(qu, e);

	while (!EmptyQue(qu))  //队列不空则循环 
	{
		Pop(qu, e); //队首元素出列 
		i = e.i, j = e.j, pre = e.pre; //记录当前队首元素的方块类 
		if (i == xe && j == ye) //队首元素为出口则输出路径 
		{
			print(qu, qu->front);  //输出路径函数
			return true;
		}

		int d = -1;
		int in, jn;
		while (d < 4) //每个方位进行试探 
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
				mg[in][jn] = -1;//将其赋值为-1，以避免来回重复搜索 
			}
		}
	}
	DestroyQue(qu);    //销毁队列 
	return false;
}

int main()
{
	if (!mgpath(1, 0, M, N+1))
		printf("该迷宫问题没有解");

	initgraph(600, 600);	         //创建绘图窗口，大小为 1024x960 像素
	int left_top_x = 20;             //矩形左部 x 坐标
	int left_top_y = 20;             //矩形顶部 y 坐标
	int right_bottom_x = 60;         //矩形右部 x 坐标
	int right_bottom_y = 60;         //矩形底部 y 坐标

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


	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}