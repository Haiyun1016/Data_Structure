#include <stdio.h>

void fun(int a[],int n,int k)
{
	int i;
	if (k==n-1)
	{
		for (i=0;i<n;i++)
		  printf("%d\n",a[i]);
	}
	else
	{
		for (i=k;i<n;i++)
		  a[i] = a[i] + i * i;
		fun(a,n,k+1);
	}
}

int main()
{
	int a[10]={0};
	fun(a,10,0);
	return 1;
}
