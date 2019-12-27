#include<stdio.h>
#include "quick_sort.h"

int main()
{
	int a[8] = {1,3,5,4,2,6,9,7};
	int p = 0;
	int q = 7;	
	qSort(a,p,q);
	print_qSort(7,a);
 } 