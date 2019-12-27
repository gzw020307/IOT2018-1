#include<stdio.h>
#include<stdlib.h>
int *Array;              /*Array是一个int 型地址，指向数组的首地址。*/
int Count;               /*Count用来存储所要排序的数字的数目。*/
/*建立未排序数组*/
void CreateArray()
{
	int i;
    /*创建数组必须用常量分配，而我们事先并不知道要处理的数据个数，所以用malloc动态分配数组单元。*/
	Array = (int *)malloc(sizeof(int)*Count);   
	for (i = 0; i < Count; i++)
	{

		printf("Please enter an integer of NO.%d to sort:\n",i+1);
	    scanf("%d",&Array[i]);
	}

}

/*输出已排序数组*/
void Print()
{
	int i;
	for (i = 0; i < Count; i++)
	{
		printf(" %d ",Array[i]);
	}
	printf("\n");
}
/*折半插入排序升序排列*/
void BinaryInsertSortup()
{
	int i,j,x,m;      /*i,j均为循环变量，x用来存储当前待排序的数据，m充当比较区间的中点*/

	int low,high;     /*low代表要与Array[i]进行比较的有序区间的第一个元素所在位置。
	                    high代表要与Array[i]进行比较的有序区间的最后一个元素所在位置。*/
	for (i = 1; i < Count; i++)
	{
		x = Array[i];
		low = 0;      /*第一次划分有序比较区间，比较区间的第一个元素所在位置为0*/
		high = i-1;   /*第一次划分有序比较区间，比较区间的最后一个元素所在位置为n-1*/
		/*比较查找Array[i]合适插入的位置*/
		while (low <= high)

		{
			m = (low + high)/2;
			if (x >= Array[m])
			{
				low = m+1;
			}
			else
			{
				high = m-1;
			}
		}
		/*确定好位置后，将位置之后的数据后移，插入待排序数据*/
	for (j = i-1;j > high; j--)

		{
			Array[j+1] = Array[j];
		}
		Array[j+1] = x;
	}
}
 

/*折半插入排序降序排列*/
void BinaryInsertSortdown()
{
	int i,j,x,m;      /*i,j均为循环变量，x用来存储当前待排序的数据，m充当比较区间的中点*/
	int low,high;     /*low代表要与Array[i]进行比较的有序区间的第一个元素所在位置。
	                    high代表要与Array[i]进行比较的有序区间的最后一个元素所在位置。*/
	for (i = 1; i < Count; i++)
	{
		x = Array[i];
low = 0;      /*第一次划分有序比较区间，比较区间的第一个元素所在位置为0*/
		high = i-1;   /*第一次划分有序比较区间，比较区间的最后一个元素所在位置为n-1*/
		/*比较查找Array[i]合适插入的位置*/
		while (low <= high)
		{
			m = (low + high)/2;
			if (x <= Array[m])
			{
				low = m+1;
			}
	else
			{
				high = m-1;
			}
		}
		/*确定好位置后，将位置之后的数据后移，插入待排序数据*/
		for (j = i-1;j > high; j--)
		{
			Array[j+1] = Array[j];
		}
		Array[j+1] = x;
	}
 
}
 
int main(void)
{
	int i;
	printf("Please enter the number of Numbers to sort:\n ");
	scanf("%d",&Count);
	CreateArray();      /*创建数组用来存储将要排序的数。*/
	/*插入排序法*/
	BinaryInsertSortup();         /*折半插入排序*/
	printf("升序排列\n");
	Print();
	BinaryInsertSortdown();         /*折半插入排序*/
	printf("降序排列\n");
	Print();
	return 0;
}

