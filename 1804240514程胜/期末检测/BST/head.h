#include<stdio.h>

#include<stdlib.h>

typedef int Status;

typedef struct BitNode
{
	int data;
	struct BitNode* lchild, * rchild;

}BSTNode, * BSTree;

BSTree SearchBST(BSTree T, int key, BSTree parent, BSTree& p);
BSTree InsertBST(BSTree T, int key);
BSTree CreateBST(BSTree T);
void DeleteBST(BSTree T, BSTree p, int count, int key);
void Delete(BSTree T, BSTree p, int count);
void InOrder(BSTree T);
void DestoryBST(BSTree T);