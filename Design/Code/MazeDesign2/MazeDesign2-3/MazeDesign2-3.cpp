#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define M 10
#define N 10

int mg[M + 2][N + 2] = {        //M=10，N=10     

	{N,0,1,2,3,4,5,6,7,8,9,N},
	{0,1,0,1,1,1,1,1,1,1,1,0},
	{1,1,0,0,1,0,0,0,1,0,1,1},
	{2,1,0,0,1,0,0,0,1,0,1,2},
	{3,1,0,0,0,0,1,1,0,0,1,3},
	{4,1,0,1,1,1,0,0,0,0,1,4},
	{5,1,0,0,0,1,0,0,0,0,1,5},
	{6,1,0,1,0,0,0,1,0,0,1,6},
	{7,1,0,1,1,1,0,1,1,0,1,7},
	{8,1,1,0,0,0,0,0,0,0,0,8},
	{9,1,1,1,1,1,1,1,1,1,1,9},
	{N,0,1,2,3,4,5,6,7,8,9,N}
};


int main()
{
	initgraph(1024, 960);	         // 创建绘图窗口，大小为 1024x960 像素
	int left_top_x = 20;             //矩形左部 x 坐标
	int left_top_y = 20;             //矩形顶部 y 坐标
	int right_bottom_x = 60;         //矩形右部 x 坐标
	int right_bottom_y = 60;         //矩形底部 y 坐标

	int i = 1, j = 1;
	srand(time(0));	                 //初始化种子

	int RandomMaze[8][8];            //随机迷宫数组,从mg[2][2]开始

	for (int i1 = 0; i1 < 8; i1++)   //对随机迷宫数组进行赋值
	{
		for (int j1 = 0; j1 < 8; j1++)
		{
			RandomMaze[i1][j1] = rand() % 2;
		}
	}

	RandomMaze[0][0] = 0;    //出口和入口添加几个固定通道
	RandomMaze[1][0] = 0;    //防止随机很久也没有可行路径
	RandomMaze[2][0] = 0;
	RandomMaze[3][0] = 0;
	RandomMaze[7][4] = 0;
	RandomMaze[7][5] = 0;
	RandomMaze[7][6] = 0;
	RandomMaze[7][7] = 0;

	for (int i2 = 0; i2 < 8; i2++)   //把随机迷宫的值传给数组mg[][]
	{
		for (int j2 = 0; j2 < 8; j2++)
		{
			mg[i2+2][j2+2] = RandomMaze[i2][j2];    //从mg[2][2]开始
		}
	}


	while (right_bottom_x <= 420 && j <= 10)
	{
		if (mg[i][j] == 1)
		{
			setfillcolor(DARKGRAY);
			fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}
		else
			rectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		while (right_bottom_y <= 380 && i <= 10)
		{
			left_top_y = left_top_y + 40;
			right_bottom_y = right_bottom_y + 40;
			i++;
			if (mg[i][j] == 1)
			{
				setfillcolor(DARKGRAY);
				fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
			}
			else
				rectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}

		left_top_x = left_top_x + 40;
		right_bottom_x = right_bottom_x + 40;
		left_top_y = 20;
		right_bottom_y = 60;
		i = 1;
		j++;

	}


	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}