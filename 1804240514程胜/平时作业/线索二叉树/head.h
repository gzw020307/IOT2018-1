#include<stdio.h>
#include<stdlib.h>
#include <iostream>
typedef char ElemType;


typedef enum				//�����洢��־λ��Link��ʾ0ָ�����Һ��ӵ�ָ��
{							//Thread��ʾ1����ʾָ��ǰ����̵�����
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