#ifndef __HEAP_H__
#define __HEAP_H__

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef int HPDataType;
typedef int (*Compare) (HPDataType pLeft, HPDataType pRight);
typedef struct Heap
{
	HPDataType* _hp;
	int capacity;
	int size;
	Compare _com;

}Heap;
void CreateHeap(Heap *hp, HPDataType* arr, int size, Compare Com);
void AdjustDown (Heap* hp, int parent);
void InsertHeap (Heap* hp, HPDataType data);	
void RemoveHeap (Heap* hp);
int SizeHeap (Heap* hp);
int IsHeapEmpty (Heap* hp);
HPDataType HeapTop (Heap* hp);
void AdjustUp (Heap* hp, int child);
void Swap (HPDataType* p, HPDataType*q);
void  CheakHeap (Heap* hp);
void DestroyHeap (Heap* hp);
int Less (HPDataType pLeft, HPDataType pRight);
int Greater (HPDataType pLeft, HPDataType pRight);

#endif 