//�ݹ�ʵ��
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 8
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

int mg[M+2][N+2]={        //M=8��N=8     
        
	{1,N,1,1,1,1,1,1,1,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,1,0,0,0,1,0,1},
    {1,0,0,0,0,1,1,0,0,1},
    {1,0,1,1,1,0,0,0,0,1},
    {1,0,0,0,1,0,0,0,0,1},
    {1,0,1,0,0,0,1,0,0,1},
    {1,0,1,1,1,0,1,1,0,1},
    {1,1,0,0,0,0,0,0,0,0},
	{1,1,1,1,1,1,1,1,1,1}
};

int count=0;	//��¼��ǰΪ�ڼ����Թ�·��
 
void mgpath(int xi,int yi,int xe,int ye,PathType path)
{
	int i,j,di,k;
	int clo = 1;
	while (clo != 0)
	{
		if(xi==xe && yi==ye)        //�ҵ��˳��ڣ����һ���Թ�·�� 
		{
			path.data[path.length].i = xi;    //��(xi,yi)��ӵ�path�� 
			path.data[path.length].j = yi;
			path.length++;	
		
			printf("�Թ�·�� %d ���£�\n",++count);
			for(k=0;k<path.length;k++)
			{
				printf("\t(%d,%d)",path.data[k].i,path.data[k].j);
			    if((k+1)%5==0)		//ÿ���5��������� 
					printf("\n");
			}
			printf("\n");
			clo = 0;
		}
		
		else        //(xi,yi)���ǳ���ʱ 
		{
			if (mg[xi][yi] == 0 || mg[xi][yi] == N)   //(xi,yi)��һ�����߷��� 
			{
				di = 0;	       //�����ĸ���λ�ƶ��ı���
				while (di<4)
				{
					path.data[path.length].i = xi;   //1.��(xi,yi)��ӵ�path��  
					path.data[path.length].j = yi;    
					path.length++;                   //·��������1 
				
					if (mg[xi][yi] == N)             //����ڵ��ж� 
					   di = 2;
					switch (di)                      //���ĸ���λѰ�����ڷ���
					{
						case 0:{i=xi-1,j=yi;break;}
						case 1:{i=xi,j=yi+1;break;}
						case 2:{i=xi+1,j=yi;break;}
						case 3:{i=xi,j=yi-1;break;}
					} 
					
					if (mg[i][j] == 1)
					{
						path.length--;
						di++;
					}
				
				
				
			//		mg[xi][yi] = -1;	      //2.��mg[xi][yi]=-1�����������߶�
			//		mgpath(i,j,xe,ye,path);   //3.�ݹ�����Թ��������С����
			//		mg[xi][yi]=0;             //4.�ָ�(xi,yi)Ϊ���� 		 
			//		path.length--;		      //����һ������ 
			//		di++;                     //��������(xi,yi)��һ�����ڷ��� 
				} 
			}
		}
	}






	
		
} 

int main()
{
	PathType path;
	path.length=0;
	mgpath(0,1,M,N,path);
	
	return 0;
}
