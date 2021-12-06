#include <stdio.h>

void fun(double &y,double x,int n)
{
	y = x;
	while(n>1)
	{
		y = y * x;
		n--;
	}
}

int main()
{
	double s;
	fun(s,2,4);
	printf("%f",s);
	return 0;
} 
