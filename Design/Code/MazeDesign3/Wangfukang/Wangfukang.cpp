#include <malloc.h>
#include<stdio.h>
#include <graphics.h>      // 引用图形库头文件
#include <conio.h>
#include<windows.h>
#include<math.h>
#define M 8    //行数
#define N 8     //列数
#define MaxSize    100     //栈最多元素个数
void lineArrow(int x1, int y1, int x2, int y2)
{
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	setlinecolor(RED);
	line(x1, y1, x2, y2);
	double distance = sqrt((y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2) * 1.0);
	double tmpx = double(x1 + (x2 - x1) * (1 - (12 * sqrt(3 * 1.0) / 2) / distance));
	double tmpy = double(y1 + (y2 - y1) * (1 - (12 * sqrt(3 * 1.0) / 2) / distance));
	if (y1 == y2)
	{
		line(x2, y2, int(tmpx), int(tmpy + 6));
		line(x2, y2, int(tmpx), int(tmpy - 6));
	}
	else
	{
		double k = (double(x2) - double(x1)) / (double(y1) - double(y2));
		double increX = 6 / sqrt(k * k + 1);
		double increY = 6 * k / sqrt(k * k + 1);
		line(x2, y2, int(tmpx + increX), int(tmpy + increY));
		line(x2, y2, int(tmpx - increX), int(tmpy - increY));
	}
}
void show_rectangle()//画出迷宫
{
	int i;
	int width = 40;
	initgraph(1500, 1500);
	setfillcolor(WHITE);
	fillrectangle(0, 0, 400, 400);
	setfillcolor(RGB(128, 128, 128));
	fillrectangle(0, 0, 40, 400);
	fillrectangle(120, 0, 160, 120);
	fillrectangle(280, 0, 320, 120);
	fillrectangle(200, 120, 280, 160);
	fillrectangle(80, 160, 200, 200);
	fillrectangle(40, 320, 80, 360);
	fillrectangle(80, 240, 120, 320);
	fillrectangle(120, 280, 200, 320);
	fillrectangle(240, 240, 280, 320);
	fillrectangle(280, 280, 320, 320);
	fillrectangle(160, 160, 200, 240);
	fillrectangle(0, 0, 400, 40);
	fillrectangle(0, 360, 400, 400);
	fillrectangle(360, 0, 400, 400);
	setfillcolor(YELLOW);
	fillrectangle(40, 0, 80, 40);
	fillrectangle(360, 320, 400, 360);
	setlinestyle(PS_DASH | PS_ENDCAP_FLAT, 2);
	setlinecolor(WHITE);
	line(420, 40, 1500, 40);
	line(0, 420, 1500, 420);
	line(420, 0, 420, 420);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	for (i = 0; i <= 10; i++)
	{
		setlinecolor(BLACK);
		line(0, i * width, 400, i * width);
		line(i * width, 0, i * width, 400);
	}
}
void show_1rectangle()//初始化迷宫
{
	int i;
	int width = 40;
	setfillcolor(WHITE);
	fillrectangle(0, 0, 400, 400);
	setfillcolor(RGB(128, 128, 128));
	fillrectangle(0, 0, 40, 400);
	fillrectangle(120, 0, 160, 120);
	fillrectangle(280, 0, 320, 120);
	fillrectangle(200, 120, 280, 160);
	fillrectangle(80, 160, 200, 200);
	fillrectangle(40, 320, 80, 360);
	fillrectangle(80, 240, 120, 320);
	fillrectangle(120, 280, 200, 320);
	fillrectangle(240, 240, 280, 320);
	fillrectangle(280, 280, 320, 320);
	fillrectangle(160, 160, 200, 240);
	fillrectangle(0, 0, 400, 40);
	fillrectangle(0, 360, 400, 400);
	fillrectangle(360, 0, 400, 400);
	setfillcolor(YELLOW);
	fillrectangle(40, 0, 80, 40);
	fillrectangle(360, 320, 400, 360);
	setlinestyle(PS_SOLID | PS_ENDCAP_FLAT, 2);
	for (i = 0; i <= 10; i++)
	{
		setlinecolor(BLACK);
		line(0, i * width, 400, i * width);
		line(i * width, 0, i * width, 400);
	}
}
int mg[M + 2][N + 2] = //一个迷宫，其四周要加上均为1的外框，0表示可走节点，1表示障碍物
{ {1,1,1,1,1,1,1,1,1,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,0,0,1,1,0,0,1},
	{1,0,1,1,1,0,0,0,0,1},
	{1,0,0,0,1,0,0,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,1,1,0,1,1,0,1},
	{1,1,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};
struct migong
{
	int i;      //路径横坐标
	int j;      //路径纵坐标
	int di;     //方向值初始为-1，0,1,2,3分别表示四个要查找的方向
}Stack[MaxSize], Path[MaxSize];      //定义栈和存放最短路径的数组

int top = -1;     //栈顶指针，初始值为-1
int count = 1;    //路径数计数
int minlen = MaxSize;     //最短路径长度

void mgpath() //路径为:(1,1)->(M,N)
{
	int i, j, di, nextfound, k;
	char c_1 = '(';
	char c_3 = ')';
	char c_2 = ',';
	char c_4 = '->';
	char buff_1[2] = { 0 };
	char buff_2[2] = { 0 };
	//初始结点进栈
	top++;
	Stack[top].i = 1;
	Stack[top].j = 1;
	Stack[top].di = -1;  //该点的初始方向值-1，表示还没查找过从此出发的其他4个方向
	mg[1][1] = -1;     //-1表示该节点位置进栈过(最好用其他数组来标示)
	int x = 0;
	int y = 440;
	int z;
	settextstyle(16, 0, _T("宋体"));
	RECT r2 = { 700, 0, 900, 20 };
	drawtext(_T("最短迷宫路径如下"), &r2, DT_SINGLELINE | DT_RTLREADING | DT_CENTER);
	RECT r1 = { 0, 420, 1000, 1000 };
	drawtext(_T("所有迷宫路径如下"), &r1, DT_SINGLELINE | DT_RTLREADING | DT_CENTER);
	RECT r3 = { 700, 40, 900, 60 };
	drawtext(_T("接下图迷宫路径"), &r3, DT_SINGLELINE | DT_RTLREADING | DT_CENTER);
	while (top > -1) //栈不空时循环
	{
		//1 -----获取栈顶
		i = Stack[top].i;
		j = Stack[top].j;
		di = Stack[top].di;  //栈顶元素的查找方向
		z = 0;
		//2 -----如果找到了出口（M,N），则输出查找路径，并退栈，用新的栈顶方向值取代当前的查找方向
		if (i == M && j == N)
		{
			printf("M:  ", count++);
			for (k = 0; k <= top; k++, z++) //输出路径
			{
				int a, b;
				a = Stack[k + 1].i - Stack[k].i;
				b = Stack[k + 1].j - Stack[k].j;
				itoa(Stack[k].i, buff_1, 10);
				itoa(Stack[k].j, buff_2, 10);
				setfillcolor(RED);
				fillrectangle(Stack[k].j * 40, Stack[k].i * 40, (Stack[k].j + 1) * 40, (Stack[k].i + 1) * 40);
				Sleep(500);
				setfillcolor(YELLOW);
				fillrectangle(Stack[k].j * 40, Stack[k].i * 40, (Stack[k].j + 1) * 40, (Stack[k].i + 1) * 40);
				outtextxy(x, y, c_1);
				outtextxy(x + 8, y, buff_1[0]);
				outtextxy(x + 16, y, c_2);
				outtextxy(x + 24, y, buff_2[0]);
				outtextxy(x + 32, y, c_3);
				outtextxy(x + 40, y, c_4);
				x += 50;
				if (b == 0 && a > 0)
				{
					lineArrow(Stack[k].j * 40 + 20, Stack[k].i * 40 + 20, (Stack[k].j) * 40 + 20, (Stack[k].i + 1) * 40);
				}
				if (b == 0 && a < 0)
				{
					lineArrow((Stack[k].j) * 40 + 20, (Stack[k].i + 1) * 40, (Stack[k].j) * 40 + 20, (Stack[k].i) * 40 + 20);
				}
				if (a == 0 && b > 0)
				{
					lineArrow(Stack[k].j * 40 + 20, Stack[k].i * 40 + 20, (Stack[k].j + 1) * 40, (Stack[k].i) * 40 + 20);
				}
				if (a == 0 && b < 0)
				{
					lineArrow((Stack[k].j + 1) * 40 - 20, Stack[k].i * 40 + 20, (Stack[k].j) * 40, (Stack[k].i) * 40 + 20);
				}
				setlinecolor(BLACK);
				if (x >= 1500 && y >= 420)
				{
					y += 20;
					x = 0;
				}
				if (x >= 1300 && y <= 380)
				{
					y += 20;
					x = 440;
				}
				if (z >= top && y >= 420)
				{
					y += 20;
					x = 0;
				}
				if (z >= top && y <= 380)
				{
					y += 20;
					x = 440;
				}
				if (y >= 1500)
				{
					x = 440;
					y = 60;
				}
				printf("(%d,%d)  ", Stack[k].i, Stack[k].j);
				if ((k + 1) % 5 == 0)      //输出时每5个结点换一行
					printf("\n\t");
			}
			printf("\n");
			if (top + 1 < minlen) //比较输出最短路径
			{
				for (k = 0; k <= top; k++)
				{
					Path[k] = Stack[k]; //保存最短路径
				}
				minlen = top + 1;
			}

			mg[Stack[top].i][Stack[top].j] = 0;   //0表示让该位置变为其他路径的可走结点

			//让元素出栈
			top--;
			//i=Stack[top].i;
			//j=Stack[top].j;
			di = Stack[top].di;  //记录下一次的查找方向为新栈顶的的查找方向
			//Sleep(900);
			show_1rectangle();
		}

		//3 -------在当前栈顶的基础上找到下一个可走节点，如果当前栈顶的4个方向都走完了，则退栈找新的栈顶
		nextfound = 0;
		while (di < 8 && nextfound == 0) //找下一个可走结点
		{
			di++; //下一个查找方向
			switch (di) //计算下一个查找方向的坐标
			{
			case 0:	i = Stack[top].i - 1;	j = Stack[top].j;		break;   //上面
			case 1:	i = Stack[top].i;		j = Stack[top].j + 1;	break;   //右边
			case 2:	i = Stack[top].i + 1;	j = Stack[top].j;		break;   //下面
			case 3:	i = Stack[top].i;		j = Stack[top].j - 1;	break;   //左边
			}
			if (mg[i][j] == 0)  //如果下一个可走节点没有进栈过，标记find为1表示找到了下一个可走节点
			{
				nextfound = 1;
			}
		}

		if (nextfound == 1) //从当前栈顶上找到了下一个可走结点
		{
			Stack[top].di = di;   //更新栈顶元素的di值为最新的查找方向

			//下一个可走结点进栈
			top++;
			Stack[top].i = i;
			Stack[top].j = j;
			Stack[top].di = -1;
			mg[i][j] = -1;
		}
		else  //如果当前栈顶的4个方向都已经查找完
		{
			mg[Stack[top].i][Stack[top].j] = 0;   //0表示让该位置变为其他路径的可走结点
			top--;  //当前栈顶已经查找完，让它出栈
		}
	}
	printf("最短路径如下:\n");
	printf("长度:  %d\n", minlen);
	printf("路径:  ");
	x = 440;
	y = 20;
	z = 0;
	for (k = 0; k < minlen; k++, z++)
	{
		itoa(Path[k].i, buff_1, 10);
		itoa(Path[k].j, buff_2, 10);
		outtextxy(x, y, c_1);
		outtextxy(x + 8, y, buff_1[0]);
		outtextxy(x + 16, y, c_2);
		outtextxy(x + 24, y, buff_2[0]);
		outtextxy(x + 32, y, c_3);
		outtextxy(x + 40, y, c_4);
		x += 50;
		if (x >= 1500)
		{
			y += 20;
			x = 0;
		}
		if (z >= minlen)
		{
			y += 20;
			x = 0;
		}
		printf("(%d,%d)  ", Path[k].i, Path[k].j);
		if ((k + 1) % 5 == 0)      //输出时每5个结点换一行
			printf("\n\t");
	}
	printf("\n");
}

int main()
{
	show_rectangle();
	mgpath();
	_getch();              // 按任意键继续
	closegraph();          // 关闭绘图窗口
	return 0;
}