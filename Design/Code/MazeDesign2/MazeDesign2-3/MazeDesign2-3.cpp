#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#define M 10
#define N 10

int mg[M + 2][N + 2] = {        //M=10��N=10     

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
	initgraph(1024, 960);	         // ������ͼ���ڣ���СΪ 1024x960 ����
	int left_top_x = 20;             //������ x ����
	int left_top_y = 20;             //���ζ��� y ����
	int right_bottom_x = 60;         //�����Ҳ� x ����
	int right_bottom_y = 60;         //���εײ� y ����

	int i = 1, j = 1;
	srand(time(0));	                 //��ʼ������

	int RandomMaze[8][8];            //����Թ�����,��mg[2][2]��ʼ

	for (int i1 = 0; i1 < 8; i1++)   //������Թ�������и�ֵ
	{
		for (int j1 = 0; j1 < 8; j1++)
		{
			RandomMaze[i1][j1] = rand() % 2;
		}
	}

	RandomMaze[0][0] = 0;    //���ں������Ӽ����̶�ͨ��
	RandomMaze[1][0] = 0;    //��ֹ����ܾ�Ҳû�п���·��
	RandomMaze[2][0] = 0;
	RandomMaze[3][0] = 0;
	RandomMaze[7][4] = 0;
	RandomMaze[7][5] = 0;
	RandomMaze[7][6] = 0;
	RandomMaze[7][7] = 0;

	for (int i2 = 0; i2 < 8; i2++)   //������Թ���ֵ��������mg[][]
	{
		for (int j2 = 0; j2 < 8; j2++)
		{
			mg[i2+2][j2+2] = RandomMaze[i2][j2];    //��mg[2][2]��ʼ
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


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}