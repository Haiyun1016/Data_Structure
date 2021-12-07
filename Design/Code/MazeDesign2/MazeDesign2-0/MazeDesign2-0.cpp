#include <graphics.h>		// 引用图形库头文件
#include <conio.h>

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