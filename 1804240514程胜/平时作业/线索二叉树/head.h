#include<stdio.h>
#include<stdlib.h>
#include <iostream>
typedef char ElemType;


typedef enum				//线索存储标志位，Link表示0指向左右孩子的指针
{							//Thread表示1，表示指向前驱后继的线索
	Link,Thread
}PointerTag;

typedef struct BiThrNode
{
	char Data;
	struct BiThrNode* lchild, * rchild;
	PointerTag ltag;
	PointerTag rtag;
}BiThrNode,*BiThrTree;

void CreateBiThrTree(BiThrTree &T);
void InThreading(BiThrTree T);
void InOrderThreading(BiThrTree& p, BiThrTree T);
void TraverseBT(BiThrTree T);
void visit(char ch);
void ThreadingThrTree(BiThrTree T);