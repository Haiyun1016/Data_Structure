#include <graphics.h>		// ����ͼ�ο�ͷ�ļ�
#include <conio.h>

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