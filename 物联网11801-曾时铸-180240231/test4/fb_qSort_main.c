#include<stdio.h>
#include"fb_qSort.h"

int main(){
	int a[8] = {7,3,1,9,5,4,6,8};
	quick_sort(a);
	for(int i = 0 ; i < 8 ; i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
} 
