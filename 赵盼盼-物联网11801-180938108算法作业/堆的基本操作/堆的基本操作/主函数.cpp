#include "test.h"

void test_Heap()
{
	int ret = 0;
	HPDataType top = 0;
	int arr[] = {53, 17, 78, 9, 45, 65, 87, 23, 31};
	Heap hp;
	CreateHeap (&hp, arr, sizeof(arr)/sizeof(arr[0]), Less);

	ret = SizeHeap(&hp);
	printf ("堆的大小为：%d\n", ret);
	ret = IsHeapEmpty(&hp);
	if (ret == 1)
	{
		printf ("这是空堆！\n");
	}
	else
	{
		printf ("不是空堆！\n");
	}
	top = HeapTop(&hp);
	printf ("堆顶元素是：%d\n", top);

	InsertHeap(&hp, 5);
	RemoveHeap(&hp);
	DestroyHeap (&hp);
}

int main ()

{
	test_Heap();
	return 0;
}