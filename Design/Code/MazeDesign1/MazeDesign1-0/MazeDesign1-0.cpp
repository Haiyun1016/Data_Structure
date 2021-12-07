//ջʵ��
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 8
#define MaxSize 100

//���巽������
typedef struct
{
	int i;  //��ǰ������к�
	int j;  //��ǰ������к�
	int di; //�¸��������ڷ�λ�ķ�λ��
}Box;

//����˳��ջ����
typedef struct
{
	Box data[MaxSize];
	int top; //ջ��ָ��
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

//��ʼ��ջ
void InitStack(StType *&st)
{
	st = (StType *)malloc(sizeof(StType));
	st -> top = -1;
}

//ȡ��ջ��Ԫ��
void GetTop(StType *&st,Box &e)
{
	e = st -> data[st->top];
}

//��ջ
void Push(StType *&st,Box &e)
{
	st -> top++;
	st -> data[st->top] = e;
}

//��ջ
void Pop(StType *&st,Box &e)
{
	e = st -> data[st->top];
	st -> top--;
}

//����ջ
void DestroyStack(StType *&st)
{
	free(st);
}

//����ջ�Ƿ�Ϊ��
bool StackEmpty(StType *&st)
{
	if (st->top == -1)
		return true;
	return false;
}

bool mgpath(int xi,int yi,int xe,int ye)
{
	Box path[10000],e; //path����������¼�Թ�·����e������¼ջ��Ԫ��
	StType *st;  //����ջst
	int i,j,di;  //i��j��di���ڼ�¼ջ��Ԫ��
	int in,jn;   //���ڼ�¼��һ��Ϊ�ķ�����������
	int k;
	int find;    //��¼�Ƿ��ҵ����ڿ���Ԫ��
	InitStack(st); //��ʼ��ջ
	e.i = xi,e.j = yi,e.di = -1;
	Push(st,e);
	mg[xi][yi] = -1;

	while (!StackEmpty(st))
	{
		GetTop(st,e); //ȡ��ջ��Ԫ��
		i = e.i,j = e.j,di = e.di;
		if (i == xe && j == ye) //�ѵ����յ�
		{
			printf("һ���Թ�·�����£�\n"); 
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
					printf("\n"); //ÿ���5���������
			}
			printf("\n");
			DestroyStack(st);  //����ջ
			return true;
		}

		find = 0; //��ʼ��Ϊ0��δ�ҵ��������ڷ���
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

		if (find)  //�ҵ��������ڷ���
		{
			st->data[st->top].di = di; //�޸�ԭջ��Ԫ�ص�diֵ
			e.i = in,e.j = jn,e.di = -1;
			Push(st,e);  //��ջ����
			mg[in][jn] = -1;
		}
		else            //û�п������ڷ���
		{
			Pop(st,e);  //��ջ����
			mg[e.i][e.j] = 0; //����ջ����λ�õ�ֵ�ָ�Ϊ0
		}
	}
	DestroyStack(st);  //����ջ
	return false;      //��ʾû�п���·��������false
}

int main()
{
	if (!mgpath(1,1,M,N))
		printf("���Թ�����û�н�");
	return 0;
}
