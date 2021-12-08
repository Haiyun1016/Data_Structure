#include <malloc.h>
#include<stdio.h>
#include <graphics.h>      // ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include<windows.h>
#include<math.h>
#define M 8    //����
#define N 8     //����
#define MaxSize    100     //ջ���Ԫ�ظ���
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
void show_rectangle()//�����Թ�
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
void show_1rectangle()//��ʼ���Թ�
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
int mg[M + 2][N + 2] = //һ���Թ���������Ҫ���Ͼ�Ϊ1�����0��ʾ���߽ڵ㣬1��ʾ�ϰ���
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
	int i;      //·��������
	int j;      //·��������
	int di;     //����ֵ��ʼΪ-1��0,1,2,3�ֱ��ʾ�ĸ�Ҫ���ҵķ���
}Stack[MaxSize], Path[MaxSize];      //����ջ�ʹ�����·��������

int top = -1;     //ջ��ָ�룬��ʼֵΪ-1
int count = 1;    //·��������
int minlen = MaxSize;     //���·������

void mgpath() //·��Ϊ:(1,1)->(M,N)
{
	int i, j, di, nextfound, k;
	char c_1 = '(';
	char c_3 = ')';
	char c_2 = ',';
	char c_4 = '->';
	char buff_1[2] = { 0 };
	char buff_2[2] = { 0 };
	//��ʼ����ջ
	top++;
	Stack[top].i = 1;
	Stack[top].j = 1;
	Stack[top].di = -1;  //�õ�ĳ�ʼ����ֵ-1����ʾ��û���ҹ��Ӵ˳���������4������
	mg[1][1] = -1;     //-1��ʾ�ýڵ�λ�ý�ջ��(�����������������ʾ)
	int x = 0;
	int y = 440;
	int z;
	settextstyle(16, 0, _T("����"));
	RECT r2 = { 700, 0, 900, 20 };
	drawtext(_T("����Թ�·������"), &r2, DT_SINGLELINE | DT_RTLREADING | DT_CENTER);
	RECT r1 = { 0, 420, 1000, 1000 };
	drawtext(_T("�����Թ�·������"), &r1, DT_SINGLELINE | DT_RTLREADING | DT_CENTER);
	RECT r3 = { 700, 40, 900, 60 };
	drawtext(_T("����ͼ�Թ�·��"), &r3, DT_SINGLELINE | DT_RTLREADING | DT_CENTER);
	while (top > -1) //ջ����ʱѭ��
	{
		//1 -----��ȡջ��
		i = Stack[top].i;
		j = Stack[top].j;
		di = Stack[top].di;  //ջ��Ԫ�صĲ��ҷ���
		z = 0;
		//2 -----����ҵ��˳��ڣ�M,N�������������·��������ջ�����µ�ջ������ֵȡ����ǰ�Ĳ��ҷ���
		if (i == M && j == N)
		{
			printf("M:  ", count++);
			for (k = 0; k <= top; k++, z++) //���·��
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
				if ((k + 1) % 5 == 0)      //���ʱÿ5����㻻һ��
					printf("\n\t");
			}
			printf("\n");
			if (top + 1 < minlen) //�Ƚ�������·��
			{
				for (k = 0; k <= top; k++)
				{
					Path[k] = Stack[k]; //�������·��
				}
				minlen = top + 1;
			}

			mg[Stack[top].i][Stack[top].j] = 0;   //0��ʾ�ø�λ�ñ�Ϊ����·���Ŀ��߽��

			//��Ԫ�س�ջ
			top--;
			//i=Stack[top].i;
			//j=Stack[top].j;
			di = Stack[top].di;  //��¼��һ�εĲ��ҷ���Ϊ��ջ���ĵĲ��ҷ���
			//Sleep(900);
			show_1rectangle();
		}

		//3 -------�ڵ�ǰջ���Ļ������ҵ���һ�����߽ڵ㣬�����ǰջ����4�����������ˣ�����ջ���µ�ջ��
		nextfound = 0;
		while (di < 8 && nextfound == 0) //����һ�����߽��
		{
			di++; //��һ�����ҷ���
			switch (di) //������һ�����ҷ��������
			{
			case 0:	i = Stack[top].i - 1;	j = Stack[top].j;		break;   //����
			case 1:	i = Stack[top].i;		j = Stack[top].j + 1;	break;   //�ұ�
			case 2:	i = Stack[top].i + 1;	j = Stack[top].j;		break;   //����
			case 3:	i = Stack[top].i;		j = Stack[top].j - 1;	break;   //���
			}
			if (mg[i][j] == 0)  //�����һ�����߽ڵ�û�н�ջ�������findΪ1��ʾ�ҵ�����һ�����߽ڵ�
			{
				nextfound = 1;
			}
		}

		if (nextfound == 1) //�ӵ�ǰջ�����ҵ�����һ�����߽��
		{
			Stack[top].di = di;   //����ջ��Ԫ�ص�diֵΪ���µĲ��ҷ���

			//��һ�����߽���ջ
			top++;
			Stack[top].i = i;
			Stack[top].j = j;
			Stack[top].di = -1;
			mg[i][j] = -1;
		}
		else  //�����ǰջ����4�������Ѿ�������
		{
			mg[Stack[top].i][Stack[top].j] = 0;   //0��ʾ�ø�λ�ñ�Ϊ����·���Ŀ��߽��
			top--;  //��ǰջ���Ѿ������꣬������ջ
		}
	}
	printf("���·������:\n");
	printf("����:  %d\n", minlen);
	printf("·��:  ");
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
		if ((k + 1) % 5 == 0)      //���ʱÿ5����㻻һ��
			printf("\n\t");
	}
	printf("\n");
}

int main()
{
	show_rectangle();
	mgpath();
	_getch();              // �����������
	closegraph();          // �رջ�ͼ����
	return 0;
}