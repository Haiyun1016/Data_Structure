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
	initgraph(1024, 960);	// ������ͼ���ڣ���СΪ 1024x480 ����
	int left = 20;          //������ x ����
	int top = 20;           //���ζ��� y ����
	int right = 60;         //�����Ҳ� x ����
	int bottom = 60;        //���εײ� y ����

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


	_getch();				// �����������
	closegraph();			// �رջ�ͼ����
	return 0;
}