#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
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
	initgraph(1024, 960);	         // ������ͼ���ڣ���СΪ 1024x480 ����
	int left_top_x = 20;             //������ x ����
	int left_top_y = 20;             //���ζ��� y ����
	int right_bottom_x = 60;         //�����Ҳ� x ����
	int right_bottom_y = 60;         //���εײ� y ����

	//setfillcolor(RED);
	//fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);


	while (right_bottom_x <= 420)
	{
		setfillcolor(LIGHTGRAY);
		fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		while (right_bottom_y <= 380)
		{
			left_top_y = left_top_y + 40;
			right_bottom_y = right_bottom_y + 40;
			fillrectangle(left_top_x, left_top_y, right_bottom_x, right_bottom_y);
		}
		left_top_x = left_top_x + 40;
		right_bottom_x = right_bottom_x + 40;
		left_top_y = 20;
		right_bottom_y = 60;

	}


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}