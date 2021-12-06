#include <stdio.h>

int fun(int a[],int n)
{
	int j,max=a[0];
	for (j=1;j<=n-1;j++)
	  if (a[j]>max)
	    max = a[j];
    return max;
}

int main()
{
	int m,b[5]={1,2,3,4,5};
	int s=5;
	m = fun(b,s);
	printf("%d",m);
	return 0;
}
