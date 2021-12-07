#include <graphics.h>		// 引用图形库头文件
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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
	initgraph(1024, 960);	// 创建绘图窗口，大小为 1024x480 像素
	int left = 20;          //矩形左部 x 坐标
	int top = 20;           //矩形顶部 y 坐标
	int right = 60;         //矩形右部 x 坐标
	int bottom = 60;        //矩形底部 y 坐标

	while (right <= 420)
	{
		rectangle(left, top, right, bottom);
		floodfill(left+10, top+10, RGB(255,255,255), 0);
		while (bottom <= 380)
		{
			top = top + 40;
			bottom = bottom + 40;
			rectangle(left, top, right, bottom);
		}
		left = left + 40;
		right = right + 40;
		top = 20;
		bottom = 60;

	}


	_getch();				// 按任意键继续
	closegraph();			// 关闭绘图窗口
	return 0;
}