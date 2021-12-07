//�ݹ�ʵ�� 
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 8
#define MaxSize 100

typedef struct
{
	int i;//��
	int j;//��
}Box;

typedef struct
{
	Box data[MaxSize];
	int length;       //��¼·������ 
}PathType;

int mg[M+2][N+2] = {
	
	{1,1,1,1,1,1,1,1,1,1},
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


int count = 0;

void mgpath(int xi,int yi,int xe,int ye,PathType path,int& minPath)
{           //  xi,yiΪ�Թ���ڣ�xe��ye���Թ����� 
	int i,j,di,k;
	if (xi == xe && yi == ye) 
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("�Թ�·��%d���£�\n", ++count);
		for (k=0; k<path.length;k++) 
		{
			printf("\t(%d, %d)",path.data[k].i,path.data[k].j);
		}
		printf("\n");
		printf("·������Ϊ%d\n",path.length);
		printf("----------------------------------------------------------\n");
		if (path.length < minPath) 
		{
			minPath = path.length;   //�ó����·�� 
		}
	}
	else  
	{
		if (mg[xi][yi] == 0)   //==1��ǽ 
		{
			di = 0;
			while (di < 4) 
			{
				path.data[path.length].i = xi;
				path.data[path.length].j = yi;
				path.length++;
				switch (di) 
				{
			    	case 0:{i=xi-1,j=yi;break;}
			        case 1:{i=xi,j=yi+1;break;}
			        case 2:{i=xi+1,j=yi;break;}
			        case 3:{i=xi,j=yi-1;break;}
				}
				mg[xi][yi] = -1;
				mgpath(i,j,xe,ye,path,minPath);
				mg[xi][yi] = 0;                 //�ָ�����
				path.length--;                  //����һ������
				di++;                           //����Ѱ����һ������·��
			}
		}
	}
}

int main() 
{
	PathType path;    //PathType�൱��һ���࣬path�൱�������Ķ��� 
	path.length = 0;
	int minPath = MaxSize;
	mgpath(1,1,M,N,path,minPath);
	printf("���·������Ϊ%d", minPath);
	return 0;
}
