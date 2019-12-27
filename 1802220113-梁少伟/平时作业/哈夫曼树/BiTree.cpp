#include"head.h"

void NewTree(BiTree &T,Elemtype n)
{
	T = (BiTree)malloc(sizeof(BiTNode));
	T->data = n;
	T->Lchild = T->Rchild = NULL;
}
void InsertTree(BiTree& T, Elemtype n)
{
	if (T == NULL)
	{
		NewTree(T, n);
	}
	
	if (n > T->data)
	{
		InsertTree(T->Rchild, n);
	}
	else if (n < T->data)
	{
		InsertTree(T->Lchild, n);
	}
}

void ShowTree(BiTree& T)
{
	if (T!=NULL)
	{
		ShowTree(T->Lchild);
		cout << " " << T->data<<" ";
		ShowTree(T->Rchild);
	}
	
}

void cengci(BiTree& Root)
{
	Queue Q;
	InitQueue(Q);
	if (Root == NULL) return; //树为空则返回
	BiTNode* p = Root;          // 临时保存树根Root到指针p中
	cout << p->data;      // 访问根节点
	if (p->Lchild)        EnQueue(Q, p->Lchild);   // 若存在左孩子，左孩子进队列
	if (p->Rchild)         EnQueue(Q, p->Rchild); // 若存在右孩子，右孩子进队列

	while (QueueEmpty(Q)) // 若队列不空，则层序遍历    
	{
		DeQueue(Q, p); // 出队列
		cout << p->data; // 访问当前节点
		if (p->Lchild)                EnQueue(Q, p->Lchild); // 若存在左孩子，左孩子进队列
		if (p->Rchild)                EnQueue(Q, p->Rchild); // 若存在右孩子，右孩子进队列

	}
}
               

	
