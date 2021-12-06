#include <stdio.h>

int main()
{
	int x[9]={7,8,1,2,23,34,5,6,8};
	int i,max,min;
	max=min=x[0];
//	max = x[0];
//	min = x[0];
	for (i=1;i<9;i++)
	{
		if (x[i]>max)
		  max=x[i];
		if (x[i]<min)
		  min=x[i]; 
	}
	printf("max=%d\n",max);
	printf("min=%d\n",min);
	return 0;
}
