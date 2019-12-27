
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#include <sys/timeb.h>

#define MAXSIZE 1000000

//交换值

void Swap(int* a, int* b)

{

	int temp = *a;

	*a = *b;

	*b = temp;

}

//打印数组元素

void PrintArr(int* arr, int length)

{

	for (int i = 0; i < length; i++)

	{

		printf("%d ", arr[i]);

	}

	printf("\n");

	return;

}

long GetSysTime()

{

	struct timeb tb;

	ftime(&tb);

	return tb.time * 1000 + tb.millitm;

}

 

//堆调整 大堆顶，将最大值放在根结点

void BigHeadAdjust(int *arr,int index,int length)

{

	int lchild = 2 * index + 1;

	int rchild = 2 * index + 2;

	int max = index;

	if (lchild<length&&arr[lchild]>arr[max])

	{

		max = lchild;

	}

	if (rchild<length&&arr[rchild]>arr[max])

	{

		max = rchild;

	}

	if (max != index)

	{

		Swap(&arr[max], &arr[index]);

		BigHeadAdjust(arr, max, length);

	}

	return;

}

 

//堆排序，采用大顶堆 升序

void HeapSort_Up(int *arr, int length)

{

	//初始化堆，将每个非叶子结点倒叙进行大顶堆调整。

	//循环完毕 初始大顶堆（每个根结点都比它孩子结点值大）形成

	for (int i = length / 2 - 1; i >= 0; i--)

	{

		BigHeadAdjust(arr, i, length);

	}

	//printf("大堆顶初始化顺序：");

	//PrintArr(arr, length);

	//将堆顶值放到数组尾部，然后又进行大堆顶调整，一次堆调整最值就到堆顶了。 

	for (i = length-1; i >= 0; i--)

	{

		Swap(&arr[0], &arr[i]);

		BigHeadAdjust(arr, 0, i);

	}

	return;

}

 

//堆调整 小堆顶，将最小值放在根结点

void SmallHeadAdjust(int *arr, int index, int length)

{

	int lchild = 2 * index + 1;

	int rchild = 2 * index + 2;

	int min = index;

	if (lchild<length&&arr[lchild]<arr[min])

	{

		min = lchild;

	}

	if (rchild<length&&arr[rchild]<arr[min])

	{

		min = rchild;

	}

	if (min != index)

	{

		Swap(&arr[min], &arr[index]);

		SmallHeadAdjust(arr, min, length);

	}

	return;

}

 

//堆排序，采用小顶堆 降序

void HeapSort_Down(int *arr, int length)

{

	for (int i = length / 2 - 1; i >= 0; i--)

	{

		SmallHeadAdjust(arr, i, length);

	}

	for (i=length-1;i>=0;i--)

	{

		Swap(&arr[0], &arr[i]);

		SmallHeadAdjust(arr, 0, i);

	}

	return;

}



int main(int argc, char *argv[])

{

	srand((size_t)time(NULL));//设置随机种子

	int arr[15] = {19,38,12,40,41,39,54,76,35,47,80,14,9,44,19 };
	printf("排序前:\n");
	PrintArr(arr, 10);
	printf("堆排序升序:\n");
	HeapSort_Up(arr, 10);	
	PrintArr(arr, 10);
	printf("堆排序降序:\n");	
	HeapSort_Down(arr, 10);	
	PrintArr(arr, 10);
	return 0;
}
