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
	int di;
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
		for (k=0;k<path.length;k++) 
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
				//进入后，
				//if是判定出口的，一般不运行
				//else里的if (mg[xi][yi] == 0)  xi和yi由于是形参，此时实参是i和j，
				//在（1，1）运行时（首次）经过switch（0）变成（0，1）
				//显然（0，1）处不等0，则退出递归。
				//第二次运行，经过switch（1）变成（1，2）
				//显然（1，2）处等于0，则再次进入递归 
				
				
				
				
				
				 
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


