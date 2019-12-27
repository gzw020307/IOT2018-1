#include"head.h"
BiThrTree pre;
//创建一个二叉树，规定以前序遍历的方式输入数据
void CreateBiThrTree(BiThrTree &T)
{
	char ch;

	scanf_s("%c", &ch);

	if (ch == ' ')
	{
		T = NULL;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		T->Data = ch;
		T->ltag = Link;
		T->rtag = Link;

		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
}
//中序遍历线索化
void InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);		//递归左孩子线索化

		if (!T->lchild)			//如果该节点没有左孩子，设置ltag为Thread，并将lchild
		{							//它的指向前驱
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;

		InThreading(T->rchild);		//递归右孩子线索化
	}
}
void InOrderThreading(BiThrTree &p,BiThrTree T)
{
	p = (BiThrTree)malloc(sizeof(BiThrNode));
	p->ltag = Link;
	p->rtag = Thread;
	p->rchild = p;
	if (!T)
	{
		p->lchild = p;
	}
	else
	{
		p->lchild = T;
		pre = p;
		InThreading(T);
		pre->rchild = p;
		pre->rtag = Thread;
		p->rchild = pre;
	}
}

void visit(char ch)
{
	printf("%c", ch);
}
void ThreadingThrTree(BiThrTree T)			//线索二叉树的遍历
{
	BiThrTree p;
	p = T->lchild;			     		  // p 指向二叉树的根结点
	if (!T)
	{
		printf("为空");
	}
	while (p != T)						  // 空树或遍历结束时
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}
		printf("%c", p->Data);
		while (p->rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c", p->Data);
		}
		p = p->rchild;

	}
}
void TraverseBT(BiThrTree T)
{
	if (T)
	{
		TraverseBT(T->lchild);
		printf("%c", T->Data);
		TraverseBT(T->rchild);
	}
}
