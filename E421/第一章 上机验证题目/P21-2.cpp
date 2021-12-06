#include <stdio.h>

int func(int n)
{
	int i=0,s=0;
	while (s<n)
	{
		i++;
		s = s + i;
	}
	return s; 
}

int main()
{
	int m,b;
	scanf("%d",&b);
	m = func(b);
	printf("%d",m);
	return 0;
}
