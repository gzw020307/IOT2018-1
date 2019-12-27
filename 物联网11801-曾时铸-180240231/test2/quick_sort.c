#include<stdio.h>
#include"quick_sort.h"

 void qSort(int a[], int p, int q)                  //快速排序的函数 
{
	int r;
	if(p < q)
	{
		r = rec_quickSort(a,p,q);
		qSort(a,p,r);                               //递归调用自己，不断拆分 
		qSort(a,r+1,q);
	}
}


int rec_quickSort(int a[],int p,int q)
{
	int x = a[p];
	int i = p;
	int temp;
	for(int j = p+1 ; j <= q; j++)
	{
		if(a[j] <= x)
		{
			i++;
			temp = a[i];                            //排序过程 
			a[i] = a[j];
			a[j] = temp;
		}
	}
	temp = a[i];
	a[i] = a[p];
	a[p] = temp;
	
	return i;
} 



void print_qSort(int n,int a[])
{
	for(int i = 0 ; i <= n ; i++)
	{
		printf("%d",a[i]);
	 } 
}