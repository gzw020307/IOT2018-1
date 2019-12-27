#include"head.h"


//创建二叉树
Node* createBinaryTree()
{
	Node* p;
	TelemType ch;
	cin >> ch;
	if (ch == 0)     //我这个算法是默认按有孩子结点来写的，如果没有，接下来的左、右子树分别赋值为0
	{
		p = NULL;
	}
	else
	{
		p = (Node*)malloc(sizeof(Node));
		p->data = ch;                   //先创建中间结点
		p->Left = createBinaryTree();  //而后递归创建左子树
		p->Right = createBinaryTree();  //最后递归创建右子树
	}
	return p;
}

//先序遍历
void preOrderTraverse(Node* root)
{
	if (root)
	{
		cout << root->data << ' ';//先序遍历根结点
		preOrderTraverse(root->Left);//先序遍历左子树
		preOrderTraverse(root->Right);//先序遍历右子树
	}
}

//中序遍历
void inOrderTraverse(Node* root)
{
	if (root)
	{
		inOrderTraverse(root->Left);//中序遍历左子树
		cout << root->data << ' ';//中序遍历根结点
		inOrderTraverse(root->Right); // 中序遍历右子树
	}
}

//后序遍历
void lastOrderTraverse(Node* root)
{
	if (root)
	{
		lastOrderTraverse(root->Left);//后序遍历左子树
		lastOrderTraverse(root->Right);// 后序遍历右子树
		cout << root->data << ' ';//后序遍历根结点
	}
}
