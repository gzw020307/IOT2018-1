#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100

typedef int ElemType;
typedef struct BiTNode
{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BSTree;

bool SearchBST (BSTree T, ElemType kval, BSTree f, BSTree &p );
bool InsertBST (BSTree &T,ElemType e);
void menu ();
void Inorder (BSTree T,void (*Visit)(BSTree));
void Visit(BSTree T);
void CreateBSTree(BSTree &T);
bool DeleteBST (BSTree &T, int kval);
void DeleteNode(BSTree &p);
void Destroy(BSTree *T);
void DestroyNode (BSTree T);