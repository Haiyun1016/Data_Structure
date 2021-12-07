//����ʵ��
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
	int pre; //��¼��·����һ�����ڶ����е��±� 
}Box;

//����˳��ջ����
typedef struct
{
	Box data[MaxSize];
	int front,rear;   //��ͷ��βָ�� 
}Que;

int mg[M+2][N+2]=
{
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

//��ʼ������ 
void InitQue(Que *&qu)
{
	qu = (Que *)malloc(sizeof(Que));
	qu->front = qu->rear = -1;
}

bool EmptyQue(Que *&qu)
{
	return (qu->front == qu->rear);
}

bool Push(Que *&qu,Box &e)
{
	if (qu->rear > 999)
	  return false;
	e.pre = qu->front;
	qu->rear++; 
	qu->data[qu->rear] = e;
	return true;
}

bool Pop(Que *&qu,Box &e)
{
	if (EmptyQue(qu))
	  return false;
	qu->front++;
	e = qu->data[qu->front];
	return true;
}

void print(Que *&qu,int k)
{
	int j;   //����Ѱ�����·��
	while (k!=-1)
	{
		j = k;
		k = qu->data[k].pre;
		qu->data[j].pre = -1;
		//���ҵ���·���ϵķ����pre��Ա��Ϊ-1 
	}
	
	k = 0;
	int ns = 0;
	while (k<1000) //���������������pre��ԱΪ-1�ķ������� 
	{
		if (qu->data[k].pre == -1)
		{
			ns++;
			printf("\t(%d,%d)",qu->data[k].i,qu->data[k].j);
			if (ns%5 == 0)
			  printf("\n"); //ÿ���5��Ԫ�غ��� 
		}
		k++;
	} 
	printf("\n");
}

void DestroyQue(Que *&qu)
{
	free(qu);
}

bool mgpath(int xi,int yi,int xe,int ye)
{
	Box e; 
	int i,j,pre;  
	Que *qu;
	InitQue(qu);    //��ʼ������
	
	//������ 
	e.i = xi,e.j = yi,e.pre = -1;
	mg[xi][yi] = -1;
	Push(qu,e);

	while (!EmptyQue(qu))  //���в�����ѭ�� 
	{
		Pop(qu,e); //����Ԫ�س��� 
		i = e.i,j = e.j,pre = e.pre; //��¼��ǰ����Ԫ�صķ����� 
		if (i == xe && j == ye) //����Ԫ��Ϊ���������·�� 
		{
			print(qu,qu->front);  //���·������
			return true; 
		}

        int d = -1;
        int in,jn;
		while (d<4) //ÿ����λ������̽ 
		{
			d++;
			switch(d)
			{
			    case 0:{in=i-1,jn=j;break;}
			    case 1:{in=i,jn=j+1;break;}
			    case 2:{in=i+1,jn=j;break;}
			    case 3:{in=i,jn=j-1;break;}
			}
			if (mg[in][jn] == 0)
			{
				e.i = in,e.j = jn,e.pre = qu->front;
				Push(qu,e);
				mg[in][jn] = -1;//���丳ֵΪ-1���Ա��������ظ����� 
			}
		}
	}
	DestroyQue(qu);    //���ٶ��� 
	return false;
}

int main()
{
	if (!mgpath(1,1,M,N))
		printf("���Թ�����û�н�");
	return 0;
}
