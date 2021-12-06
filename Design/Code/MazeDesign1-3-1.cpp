//�ݹ�ʵ��
#include <stdio.h>
#include <stdlib.h>
#define M 10
#define N 10
#define MaxSize 100

typedef struct
{
	int i;       //������к� 
	int j;       //������к�
}Box;            //���������

typedef struct
{
	Box data[MaxSize];        //���һ��·���ϵ����з��� 
	int length;		     //·���ĳ��� 
}PathType;               //·��������  

int mg[M+2][N+2]={        //M=10��N=10     
        
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

int count=0;	//��¼��ǰΪ�ڼ����Թ�·��
 
void mgpath(int xi,int yi,int xe,int ye,PathType path)
{
	int i,j,di,k;

	if(xi==xe && yi==ye)        //�ҵ��˳��ڣ����һ���Թ�·�� 
	{
		path.data[path.length].i = xi;    //��(xi,yi)��ӵ�path�� 
		path.data[path.length].j = yi;
		path.length++;
		
		printf("�Թ�·�� %d ���£�\n",++count);
		for(k=0;k<path.length;k++)
		{
			printf("\t(%d,%d)",path.data[k].i-1,path.data[k].j-1);
		    if((k+1)%5==0)		//ÿ���5��������� 
				printf("\n");
		}
		printf("\n");
	}
	else        //(xi,yi)���ǳ���ʱ 
	{
		if (mg[xi][yi] == 0)   //(xi,yi)��һ�����߷��� 
		{
			di = 0;	       //�����ĸ���λ�ƶ��ı���
			while (di<4)
			{
				path.data[path.length].i = xi;   //1.��(xi,yi)��ӵ�path��  
				path.data[path.length].j = yi;    
				path.length++;                 //·��������1 
				
				switch (di)//���ĸ���λѰ�����ڷ���
				{
					case 0:{i=xi-1,j=yi;break;}
					case 1:{i=xi,j=yi+1;break;}
					case 2:{i=xi+1,j=yi;break;}
					case 3:{i=xi,j=yi-1;break;}
				} 
				
				mg[xi][yi] = -1;	      //2.��mg[xi][yi]=-1�����������߶�
				mgpath(i,j,xe,ye,path);   //3.�ݹ�����Թ��������С����
				mg[xi][yi]=0;             //4.�ָ�(xi,yi)Ϊ���� 		 
				path.length--;		      //����һ������ 
				di++;                     //��������(xi,yi)��һ�����ڷ��� 
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
