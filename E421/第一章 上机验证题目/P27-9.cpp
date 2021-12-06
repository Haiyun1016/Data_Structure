#include <stdio.h>

void px(int a,int b,int c)
{
	if (a>b)
	{
		if (b>c)
		  printf("%d,%d,%d\n",c,b,a);
		else if (a>c)
		  printf("%d,%d,%d\n",b,c,a);
		else
		  printf("%d,%d,%d\n",b,a,c); 
	}
	else
	{
		if (b>c)
		{
			if (a>c)
			  printf("%d,%d,%d\n",c,a,b);
			else
			  printf("%d,%d,%d\n",a,c,b);
		}
	    else
	      printf("%d,%d,%d\n",a,b,c);
	}
	
}

int main()
{
	int x,y,z;
	scanf("%d%d%d",&x,&y,&z);
	px(x,y,z);
	return 0;
	
} 
