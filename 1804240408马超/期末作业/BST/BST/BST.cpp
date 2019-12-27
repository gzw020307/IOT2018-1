#include"BST.h"


void menu()														//菜单
{
	cout << "=======================================================================" << endl;
	cout << "■-------------------------------主菜单------------------------------■" << endl;
	cout << "|    1、插入节点(创建二叉树)           2、以中序序列遍历二叉树        |" << endl;
	cout << "|    3、删除节点                       4、销毁二叉树                  |" << endl;
	cout << "■-------------------------------0、退出-----------------------------■" << endl;
	cout << "请输入要执行的操作编号：";
}


void InsertBST(BST& T,ElemType n)	//插入节点
{
	if (!T) {									//如果T为空，则新建节点并插入
		T = new BSTNode;
		T->data = n;
		T->Lchild = T->Rchild = NULL;
	}
	else if (n > T->data)						//n>T->data则进入T右子树搜索
		InsertBST(T->Rchild, n);
	else if (n < T->data)						//n<T->data则进入T左子树搜索
		InsertBST(T->Lchild, n);
}

void VisitBST(BST T)				//遍历二叉排序树
{
	if (T) {									//若T存在
		VisitBST(T->Lchild);					//遍历左子树
		cout << setw(6) << T->data;				//输出T
		VisitBST(T->Rchild);					//遍历右子树
	}
}

void DeleteBST(BST& T, ElemType n)	//删除节点
{
	if (!T)										//若T为空
		cout << "未找到该节点。" << endl;
	else {
		if (T->data == n) {
			if (!T->Lchild && !T->Rchild) {		//若删除节点是叶子节点
				BST p = T;
				T = NULL;
				delete p;
			}
			else if (T->Lchild && !T->Rchild) {	//若删除节点只有左子树
				BST p = T;
				T = T->Lchild;
				delete p;
			}
			else if (!T->Lchild && T->Rchild) {	//若删除节点只有右子树
				BST p = T;
				T = T->Rchild;
				delete p;
			}
			else {								//若删除节点有左右子树
				BST p = T, S = T->Lchild;		//S进入T左子树，p指向S前驱
				while (S->Rchild) {				//S在T左子树遍历寻找T前驱节点
					p = S;
					S = S->Rchild;
				}
				T->data = S->data;				//将S节点数据赋给T
				if (p == T)						//p指向T，则将T左孩子指向S左孩子
					p->Lchild = S->Lchild;
				else							//p不指向T，则将p的右孩子指向S的左孩子
					p->Rchild = S->Lchild;
			}
		}
		else if (n > T->data)					//若n>T->data，进入右子树寻找
			DeleteBST(T->Rchild, n);
		else if (n < T->data)					//若n<T->data，进入左子树寻找
			DeleteBST(T->Lchild, n);
	}
}

void DestroyBST(BST& T)				//销毁二叉排序树
{
	if (T) {
		DestroyBST(T->Lchild);					//销毁左子树
		DestroyBST(T->Rchild);					//销毁右子树
		delete T;								//销毁当前节点
		T = NULL;
	}
}
