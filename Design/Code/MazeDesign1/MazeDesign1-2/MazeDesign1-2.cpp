//递归实现 
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 8
#define MaxSize 100

typedef struct
{
	int i;//行
	int j;//列
}Box;

typedef struct
{
	Box data[MaxSize];
	int length;       //记录路径长度 
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
{           //  xi,yi为迷宫入口，xe和ye是迷宫出口 
	int i,j,di,k;
	if (xi == xe && yi == ye) 
	{
		path.data[path.length].i = xi;
		path.data[path.length].j = yi;
		path.length++;
		printf("迷宫路径%d如下：\n", ++count);
		for (k=0; k<path.length;k++) 
		{
			printf("\t(%d, %d)",path.data[k].i,path.data[k].j);
		}
		printf("\n");
		printf("路径长度为%d\n",path.length);
		printf("----------------------------------------------------------\n");
		if (path.length < minPath) 
		{
			minPath = path.length;   //得出最短路径 
		}
	}
	else  
	{
		if (mg[xi][yi] == 0)   //==1是墙 
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
				mg[xi][yi] = 0;                 //恢复可走
				path.length--;                  //回退一个方块
				di++;                           //继续寻找下一条可走路径
			}
		}
	}
}

int main() 
{
	PathType path;    //PathType相当于一个类，path相当于这个类的对象 
	path.length = 0;
	int minPath = MaxSize;
	mgpath(1,1,M,N,path,minPath);
	printf("最短路径长度为%d", minPath);
	return 0;
}
