#include"head.h"
BSTree SearchBST(BSTree T, int key, BSTree f, BSTree& p)
{//查找算法，T为根节点时，f=NULL;其余时候f指向T的双亲
	if (!T)				//查找失败
	{
		p = f;
		return 0;
	}
	else
	{
		if (key == T->data)
		{					//查找成功
			return T;
		}
		else if (key < T->data)
		{				//在左子树继续查找
			return SearchBST(T->lchild, key, T, p);
		}
		else
		{				//在右子树继续查找
			return SearchBST(T->rchild, key, T, p);
		}
	}

}

BSTree InsertBST(BSTree T, int key)
{
	BSTree p, s;
	if (NULL == T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return T;
	}
	if (!SearchBST(T, key, NULL, p))//查找不成功
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			T = p;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return T;
	}
	else
		return T;
}
BSTree CreateBST(BSTree T)
{
	int a;
	printf("输入数据构造二叉排序树，输入-1结束:");
	scanf_s("%d", &a);
	while (a != -1)
	{
		T = InsertBST(T, a);
		scanf_s("%d", &a);
	}
	return T;
}
void InOrder(BSTree T)//中序遍历二叉树
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}
void DeleteBST(BSTree T, BSTree p, int count, int key)
{						//删除结点，p指向T的上一个结点
	if (!T)				//count起到一个提示作用，为0表示
	{			//p的左孩子为T，为1表示p的右孩子为T
		if (T->data == key)	//删除的结点为空时
		{
			if (count == 0)
			{
				BSTree q=T;
				p->lchild = NULL;
				free(q);
			}
			else if (count == 1)
			{
				BSTree q = T;
				p->rchild = NULL;
				free(T);
			}
			else {				//表示树为空
				free(T);
			}
		}
		else
		{				//没有找到该关键字
			printf("找不到要删除的关键字！");
			return;
		}
	}
	else
	{
		if (T->data == key)
		{				//找到关键字进行删除操作
			Delete(T,p,count);
		}
		else if (key < T->data)
		{
			count = 0;		//比关键字大找左孩子
			DeleteBST(T->lchild,T,count,key);
		}
		else
		{					//比关键字小找右孩子
			count = 1;
			DeleteBST(T->rchild,T,count,key);
		}
	}
}

void Delete(BSTree T,BSTree p,int count)
{				//具体的删除操作
	BSTree s, q;
	if (T->rchild == NULL)
	{				//删除的关键字左子树没有右子树时
		if (p == T)
		{
			q = T;
			T = T->lchild;
			free(q);
		}
		else
		{
			if (count == 0)
			{
				q = T;
				p->lchild = q->lchild;
				free(q);
			}
			else
			{
				q = T;
				p->rchild = q->lchild;
				free(q);
			}
		}
	}
	else if (T->lchild == NULL)
	{			//删除的关键字右子树没有左子树时
		if (p == T)
		{
			q = T;
			T = T->rchild;
			free(q);
		}
		else
		{
			if (count == 0)
			{
				q = T;
				p->lchild = q->rchild;
				free(q);
			}
			else
			{
				q = T;
				p->rchild = q->rchild;
				free(q);
			}
		}
	}
	else
	{				//左右子都有时
		q = T;
		s = T->lchild;
		while (s->rchild)//找到左子树的最大值
		{
			q = s;
			s = s->rchild;
		}
		if (q != T)		//左孩子有右子树
		{
			if (s == NULL)	//最大值没左孩子
			{
				T->data = s->data;
				q->rchild = NULL;
			}
			else	//最大值有左孩子	
			{
				T->data = s->data;
				q->rchild = s->lchild;
			}
		}
		else		//左孩子没右子树
		{
			if (s == NULL)			//最大值没左孩子
			{
				T->data = s->data;
				q->lchild = NULL;
			}
			else					//最大值有左孩子
			{
				T->data = s->data;
				q->lchild = s->lchild;
			}
		}
		free(s);
	}
}
void DestoryBST(BSTree T)		//销毁函数
{
	if (T)
	{
		free(T);
		printf("\n销毁成功!");
	}

}