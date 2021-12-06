#include <stdio.h>

int main()
{
	int a[4][4]={1,2,3,4,5,6,7,8,9,10,11,12,23,3,2,12};
	int i,j,s=0;
	for (i=0;i<4;i++)
	  for (j=0;j<4;j++)
	    s = s + a[i][j];
	printf("%d",s);
	return 0;
} 
