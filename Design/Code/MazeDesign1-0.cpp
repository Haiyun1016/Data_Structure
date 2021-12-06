//栈实现
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 8
#define MaxSize 100

//定义方块类型
typedef struct
{
	int i;  //当前方块的行号
	int j;  //当前方块的列号
	int di; //下个可走相邻方位的方位号
}Box;

//定义顺序栈类型
typedef struct
{
	Box data[MaxSize];
	int top; //栈顶指针
}StType;

int mg[M+2][N+2]={
	
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

//初始化栈
void InitStack(StType *&st)
{
	st = (StType *)malloc(sizeof(StType));
	st -> top = -1;
}

//取出栈顶元素
void GetTop(StType *&st,Box &e)
{
	e = st -> data[st->top];
}

//入栈
void Push(StType *&st,Box &e)
{
	st -> top++;
	st -> data[st->top] = e;
}

//出栈
void Pop(StType *&st,Box &e)
{
	e = st -> data[st->top];
	st -> top--;
}

//销毁栈
void DestroyStack(StType *&st)
{
	free(st);
}

//检验栈是否为空
bool StackEmpty(StType *&st)
{
	if (st->top == -1)
		return true;
	return false;
}

bool mgpath(int xi,int yi,int xe,int ye)
{
	Box path[10000],e; //path数组用来记录迷宫路径，e用来记录栈顶元素
	StType *st;  //定义栈st
	int i,j,di;  //i，j，di用于记录栈顶元素
	int in,jn;   //用于记录下一方为的方块行列坐标
	int k;
	int find;    //记录是否找到相邻可走元素
	InitStack(st); //初始化栈
	e.i = xi,e.j = yi,e.di = -1;
	Push(st,e);
	mg[xi][yi] = -1;

	while (!StackEmpty(st))
	{
		GetTop(st,e); //取出栈顶元素
		i = e.i,j = e.j,di = e.di;
		if (i == xe && j == ye) //已到达终点
		{
			printf("一条迷宫路径如下：\n"); 
			k = 0;
		    while (!StackEmpty(st))
			{
				Pop(st,e);
				path[k++] = e;
			}
			while (k>=1)
			{
				k--;
				printf("\t(%d,%d)",path[k].i,path[k].j);
				if ((k+2)%5 == 0)
					printf("\n"); //每输出5个方块后换行
			}
			printf("\n");
			DestroyStack(st);  //销毁栈
			return true;
		}

		find = 0; //初始化为0，未找到可走相邻方块
		while (di<4 && find==0)
		{
			di++;
			switch(di)
			{
			    case 0:{in=i-1,jn=j;break;}
			    case 1:{in=i,jn=j+1;break;}
			    case 2:{in=i+1,jn=j;break;}
			    case 3:{in=i,jn=j-1;break;}
			}
			if (mg[in][jn] == 0)
				find = 1;
		}

		if (find)  //找到可走相邻方块
		{
			st->data[st->top].di = di; //修改原栈顶元素的di值
			e.i = in,e.j = jn,e.di = -1;
			Push(st,e);  //入栈操作
			mg[in][jn] = -1;
		}
		else            //没有可走相邻方块
		{
			Pop(st,e);  //退栈操作
			mg[e.i][e.j] = 0; //将退栈方块位置的值恢复为0
		}
	}
	DestroyStack(st);  //销毁栈
	return false;      //表示没有可走路径，返回false
}

int main()
{
	if (!mgpath(1,1,M,N))
		printf("该迷宫问题没有解");
	return 0;
}
