#include<stdio.h>
#include"fb_qSort.h"

void rec_quick(int a[],int i,int j)
{
	int left = i;
	int right = j;
	int key = a[i];
	if(i < j)
	{
		while(i < j)
		{
			while(a[j] >= key && i < j)
			{
				j--;
				
			}
			
			a[i] = a[j];
			
			while(a[i] <=key && i <j)
			{
				i++;
			}
			
			a[j] = a[i];
		}
		a[i] = key;
		rec_quick(a,left,i-1);
		rec_quick(a,i+1,right);
	}
}

void quick_sort(int a[]){
	int i,j;
	i = 0; j = 7;
	rec_quick(a,i,j);
}
