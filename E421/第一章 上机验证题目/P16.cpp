#include <stdio.h>

void swap(int &x,int &y)
{
	int tmp;
	tmp=x;x=y;y=tmp;
}

int main()
{
	int a=3;
	int b=5;
	printf("a=%d,b=%d\n",a,b);
	swap(a,b);
	printf("a=%d,b=%d\n",a,b);
	return 0;
} 
