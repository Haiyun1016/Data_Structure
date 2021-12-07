//递归实现
#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 10
#define MaxSize 100

typedef struct
{
	int i;       //方块的行号 
	int j;       //方块的列号
}Box;            //方块的类型

typedef struct
{
	Box data[MaxSize];        //存放一条路径上的所有方块 
	int length;		     //路径的长度 
}PathType;               //路径的类型  

int mg[M+2][N+2]={        //M=10，N=10     
        
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

int count=0;	//记录当前为第几号迷宫路径
 
void mgpath(int xi,int yi,int xe,int ye,PathType path)
{
	int i,j,di,k;

	if(xi==xe && yi==ye)        //找到了出口，输出一个迷宫路径 
	{
		path.data[path.length].i = xi;    //将(xi,yi)添加到path中 
		path.data[path.length].j = yi;
		path.length++;
		
		printf("迷宫路径 %d 如下：\n",++count);
		for(k=0;k<path.length;k++)
		{
			printf("\t(%d,%d)",path.data[k].i-1,path.data[k].j-1);
		    if((k+1)%5==0)		//每输出5个方块后换行 
				printf("\n");
		}
		printf("\n");
	}
	else        //(xi,yi)不是出口时 
	{
		if (mg[xi][yi] == 0)   //(xi,yi)是一个可走方块 
		{
			di = 0;	       //用于四个方位移动的变量
			while (di<4)
			{
				path.data[path.length].i = xi;   //1.将(xi,yi)添加到path中  
				path.data[path.length].j = yi;    
				path.length++;                 //路径长度增1 
				
				switch (di)//对四个方位寻找相邻方块
				{
					case 0:{i=xi-1,j=yi;break;}
					case 1:{i=xi,j=yi+1;break;}
					case 2:{i=xi+1,j=yi;break;}
					case 3:{i=xi,j=yi-1;break;}
				} 
				
				mg[xi][yi] = -1;	      //2.将mg[xi][yi]=-1，避免来回走动
				mgpath(i,j,xe,ye,path);   //3.递归调用迷宫函数求解小问题
				mg[xi][yi]=0;             //4.恢复(xi,yi)为可走 		 
				path.length--;		      //回退一个方块 
				di++;                     //继续处理(xi,yi)下一个相邻方块 
			} 
		}
	}	
} 

int main()
{
	PathType path;
	path.length=0;
	mgpath(1,2,9,10,path);
	
	return 0;
}
