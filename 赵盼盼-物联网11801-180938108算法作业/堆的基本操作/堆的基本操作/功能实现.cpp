#include "test.h"

void CreateHeap(Heap *hp, HPDataType* arr, int size, Compare Com)
{
	int cur = 0;
	assert(hp!=NULL);
	hp->_hp = (HPDataType*)malloc (size * sizeof (HPDataType));
	if (hp->_hp == NULL)
	{
		assert(0);
		return;
	}
	memcpy (hp->_hp, arr, size*sizeof (HPDataType));
	hp->size=size;
	hp->capacity=size;
	hp->_com=Com;

	cur=((size-1)>>1);
	for(;cur>=0;cur--)
	{
		AdjustDown (hp, cur);
	}
}

void AdjustDown (Heap* hp, int parent)
{
	int child=0;
	assert(hp !=NULL);
	child=(parent<<1)+1;
	while(child < hp->size)
	{
		if (child+1 < hp->size)
		{
			if (hp->_com (hp->_hp[child], hp->_hp[child+1]))

			{

				child += 1;

			}
		}
		if (hp->_com(hp->_hp[parent], hp->_hp[child]))
		{

			Swap (&hp->_hp[parent], &hp->_hp[child]);
		}
		else

		{

			return;

		}

		parent = child;

		child = (parent<<1) + 1;
	}

}

void InsertHeap (Heap* hp, HPDataType data)
{
	assert (hp != NULL);
	CheakHeap (hp);
	hp->_hp[hp->size] = data;
	hp->size++;

	AdjustUp (hp, (hp->size)-1);
}

void RemoveHeap (Heap* hp)

{

	assert (hp != NULL);

	Swap (&hp->_hp[0], &hp->_hp[hp->size-1]);

	hp->size--;

	AdjustDown (hp,0, hp->_com);

}

int SizeHeap (Heap* hp)	
{
	assert (hp != NULL);
	return hp->size;
}

int IsHeapEmpty (Heap* hp)
{
	assert (hp != NULL);
	return (hp->size == 0);
}

HPDataType HeapTop (Heap* hp)
{
	assert (hp != NULL);
	return hp->_hp[0];
}

void AdjustUp (Heap* hp, int child)
{
	int parent = 0;
	assert (hp != NULL);
	parent = (child - 1)/2;
	while (child)
	{
		if (!(hp->_com(hp->_hp[child], hp->_hp[parent])))
		{
			Swap (&hp->_hp[child], &hp->_hp[parent]);
		}
		child = parent;
		parent = (child - 1)/2;
	}
}

void Swap (HPDataType*p, HPDataType* q)
{
	HPDataType tmp;
	assert (p != NULL && q != NULL);
	tmp = *p;
	*p = *q;
	*q = tmp;
}

void  CheakHeap (Heap* hp)
{
	int newCapacity = 0;
	int i = 0;
	HPDataType* temp;
	assert (hp != NULL);
	if (hp->capacity > hp->size)
	{
		return ;
	}
	newCapacity = 2 * (hp->capacity)+3;
	temp = (HPDataType*)malloc (newCapacity * sizeof (HPDataType));
	if (temp == NULL)
	{
		perror ("CheakHeap::malloc>>");
		return ;
	}
	for (; i<hp->size; ++i)	
	{
		temp[i] = hp->_hp[i];
	}
	free (hp->_hp);
	hp->_hp = NULL;

	hp->_hp = temp;
	hp->capacity = newCapacity;
}

void DestroyHeap (Heap* hp)
{
	assert (hp != NULL);
	free (hp->_hp);
	hp->_hp = NULL;
	hp->capacity = 0;
	hp->size = 0;
	printf ("Ïú»Ù³É¹¦\n");
}

int Less (HPDataType pLeft, HPDataType pRight)
{
	assert (pLeft != NULL && pRight != NULL);
	if (pLeft > pRight)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int Greater (HPDataType pLeft, HPDataType pRight)
{
	if(pLeft > pRight)
	{
		return 1;
	}
	else 
	{
		return 0;
	}
}

