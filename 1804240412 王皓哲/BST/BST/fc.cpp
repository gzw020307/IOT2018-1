#include"bst.h"

void menu()														
{
	printf ("\n");
	printf ("*19,38,12,40,41,39,54,76,35,47,80,14,9,44,60\n");
	printf ("1、创建二叉排序树\n");
	printf ("2、中序遍历二叉排序树\n");
	printf ("3、删除54\n");
	printf ("4、销毁\n");
	printf ("0、退出\n");
	printf ("请输入要执行的操作编号：\n");
}

void CreateBSTree(BSTree &T)
{
	int i,a[15]={19,38,12,40,41,39,54,76,35,47,80,14,9,44,60};
	T=NULL;
	for(i=0;i<15;i++)
	{
		InsertBST(T,a[i]);
	}
}

bool InsertBST (BSTree &T,ElemType e)
{
	BSTree p,s;
	if(!SearchBST(T,e,NULL,p))
	{
		s= new BiTNode;
		if(!s)
			exit(1);
		s->data=e;
		s->lchild=s->rchild=NULL;
		if(!p)
			T=s;		
		else if(e<p->data)
			p->lchild=s;
		else
			p->rchild=s;
		return true;
	}
	else
		return false;
}

bool SearchBST (BSTree T, ElemType kval, BSTree f, BSTree &p )	//p为该元素结点，f指向其双亲，初始为NULL
{// 根指针T所指二叉查找树中递归查找关键字等于kval的数据元素,若查找成功,则指针p指向该数据元素结点,并返回TRUE,否则指针p指向查找路径上访问的最后一个结点并返回FALSE,指针f指向T的双亲,其初始调用值为NULL
	if (!T)
	{
		p = f;
		return false;		// 查找不成功
	}
	else if ( kval == T->data)
	{
		p = T;
		return true; // 查找成功
	}
	else if ( kval < T->data)
		return SearchBST (T->lchild, kval, T, p ); 	// 返回在左子树中继续查找所得结果
	else 
		return SearchBST (T->rchild, kval, T, p );// 返回在右子树中继续查找所得结果
} 	

void Inorder (BSTree T,void (*Visit)(BSTree))
{
	if(T)
	{
		Inorder(T->lchild,Visit);
		Visit(T);
		Inorder(T->rchild,Visit);
	}
}

void Visit(BSTree T)
{
	if(T)
		printf("%3d",T->data);
}

bool DeleteBST (BSTree &T, int kval)
{
	if(!T)
		return false;
	else
	{
		if(kval==T->data)
		{
			DeleteNode(T);
			return true;
		}
		else if(kval<T->data)
			return DeleteBST(T->lchild,kval);
		else
			return DeleteBST(T->rchild,kval);
	}
}

void DeleteNode(BSTree &p)
{
	BSTree s=NULL,q=NULL;
	if(!p->rchild)
	{
		q=p;
		p=p->lchild;
		delete q;
	}
	else if(!p->lchild)
	{
		q=p;
		p->rchild;
		delete q;
	}
	else
	{
		q=p;
		s=p->lchild;
		while(!s)
		{
			q=s;
			s=s->rchild;
		}
		p->data=s->data;
		if(q!=p)
			q->rchild=s->lchild;
		else
			q->lchild=s->lchild;
		delete s;
	}
}

void Destroy(BSTree *T)
{
	if(T==NULL)
		return ;
	if(*T==NULL)
		return ;
	Destroy(&(*T)->lchild);
	Destroy(&(*T)->rchild);
	DestroyNode(*T);
	*T=NULL;
	return ;
}

void DestroyNode (BSTree T)
{
	delete T;
	return ;
}