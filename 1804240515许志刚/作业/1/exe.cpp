//已知n个节点的完全二叉树已经顺序存储在一维数组中，设计一算法将其变成二叉链表存储的完全二叉树
typedef struct Node{
	ElemType data;
	struct Node *lchild;
	struct Node *rchild;
}BTNode;
BTNode *CreateTree(BTNode *a[],int size)
{
	BTNode *root;
	int i;
	if(size<1)
		return NULL;
	fro(i=0;i<siz;i++)
	{
		if(2*i+1>=size)
			a[i]->lchild=NULL;
		else if(a[2*i+1]->data==")
			a[i]->lchild=NULL;
		else 
			a[i]->lchild=a[2*i+1];
		if(2*i+2>=size)
			a[i]->rchild=NULL;
		else if(a[2*i+2]->data==")
			a[i]->rchild=NULL;
		else
			a[i]->rchild=a[2*i+2];
	
	}
	root=a[0];
	return root;
}
