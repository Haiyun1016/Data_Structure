#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define M 8
#define N 8

int mg[M + 2][N + 2] = {        //M=8，N=8     

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


int main()
{
	initgraph(1024, 960);	         // 创建绘图窗口，大小为 1024x960 像素
	int left_top_x = 20;             //矩形左部 x 坐标
	int left_top_y = 20;             //矩形顶部 y 坐标
	int right_bottom_x = 60;         //矩形右部 x 坐标
	int right_bottom_y = 60;         //矩形底部 y 坐标

	int i = 0, j = 0;

	while (right_bottom_x <= 420 && j <= 9)
	{
		if (mg[i][j] == 1)
		{
			setfillcolor(DARKGRAY);
			fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}
		else
			rectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		while (right_bottom_y <= 380 && i <= 9)
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
		i = 0;
		j++;

	}


	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}