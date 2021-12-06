#include <stdio.h>
#include <malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

void CreateList(SqList *&L,ElemType a[],int n)
{
	L=(SqList *)malloc(sizeof(SqList));
	for (int i=0;i<n;i++)
	  L->data[i]=a[i];
	L->length=n;
}

void InitList(SqList *&L)
{
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}

void DestroyList(SqList *&L)
{
	free(L);
}

bool ListEmpty(SqList *L)
{
	return(L->length==0);
}

int ListLength(SqList *L)
{
	return(L->length); 
} 

void DispList(SqList *L)
{
	for (int i=0;i<L->length;i++)
	  printf("%d",L->data[i]);
	printf("\n");
}

bool GetElem(SqList *L,int i,ElemType &e)
{
	if (i<1 || i>L->length)
	  return false;
	e = L->data[i-1];
	return true;
}

int LocateElem(SqList *L,ElemType e)
{
	int i=0;
	while (i<L->length && L->data[i]!=e) i++;
	if (i>=L->length)
	  return 0;
	else
	  return i+1;
}

bool ListInsert(SqList *&L,int i,ElemType e)
{
	int j;
	if (i<1 || i>L->length+1)
	  return false;
	i--;
	for (j=L->length;j>i;j--)
	  L->data[i]=e;
	  L->length++;
	  return true;
}

bool ListDelete(SqList *&L,int i,ElemType &e)
{
	int j;
	if (i<1 || i>L->length)
	  return false;
	i--;
	e = L->data[i];
	for (j=i;j<L->length-1;j++)
	  L->data[j] = L->data[j+1];
	L->length--;
	return true;
}

int main()
{
	ElemType a[] = {1,2,5,15,9,7,4,6,3,8};
	ElemType x = 2;
	ElemType b = 12;
	ElemType c = 32;
	int m = 5;
	SqList *L;
	CreateList(L,a,10);
	printf("L:");
	DispList(L);
	printf("查找值为%d的元素\n",x);
	printf("查找值为%d的元素是第%d\n",x,LocateElem(L,x));
	printf("删除第四个的元素\n");
	ListDelete(L,m,b);
	printf("L:");DispList(L);
	printf("在第四位置插入元素\n");
	ListInsert(L,4,c);
	printf("L:");DispList(L);
	DestroyList(L);
	return 1;
	 
}
