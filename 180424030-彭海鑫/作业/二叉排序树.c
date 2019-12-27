#include<stdio.h>
#include<malloc.h>
typedef struct node
{
	int key;//关键字的值
	struct node *lchild,*rchild;//左右指针
}BSTNode,*BSTree;
void InsertBST(BSTree *bst,int key)//二叉树的插入结点
{
	BSTree s;
	if(*bst==NULL)
	{
	s=(BSTree)malloc(sizeof(BSTNode));
	s->key=key;
	s->lchild=NULL;
	s->rchild=NULL;
	*bst=s;
	}
else if(key<(*bst)->key)
InsertBST(&((*bst)->lchild),key);//将s插入左子串
else if(key>(*bst)->key)
InsertBST(&((*bst)->rchild),key);//将s插入右子串
}
void CreateBST(BSTree *bst)//创建二叉排序树
{
	int key;
	*bst=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		InsertBST(bst,key);
		scanf("%d",&key);
	}
}
void inorder(BSTree bt)
{
	if(bt!=NULL)
	{
		inorder(bt->lchild);
			printf("%3d",bt->key);
		inorder(bt->rchild);
	}
}
main()
{
	BSTree bt;
	printf("please insert the numbers(以0为结束标志):\n");
	CreateBST(&bt);
	printf("\n中序遍历结果是:");
	inorder(bt);
	printf("\n");
	getchar();
	return 0;
}
