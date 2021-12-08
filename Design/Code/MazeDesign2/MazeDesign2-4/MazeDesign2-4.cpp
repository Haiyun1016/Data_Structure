#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>

#define M 8
#define N 8

int mg[M + 2][N + 2] = {        //M=8��N=8     

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
	initgraph(1024, 960);	         // ������ͼ���ڣ���СΪ 1024x960 ����
	int left_top_x = 20;             //������ x ����
	int left_top_y = 20;             //���ζ��� y ����
	int right_bottom_x = 60;         //�����Ҳ� x ����
	int right_bottom_y = 60;         //���εײ� y ����

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


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}