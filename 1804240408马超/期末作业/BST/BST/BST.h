#ifndef BST_H

#define BST_H

#include<iostream>
#include<iomanip>

using namespace std;

typedef int ElemType;

typedef struct BSTNode {
	ElemType data;
	BSTNode* Lchild, * Rchild;
}*BST;

void menu();						//菜单
void InsertBST(BST& T, ElemType n);	//插入节点
void VisitBST(BST T);				//遍历二叉排序树
void DeleteBST(BST& T,ElemType n);	//删除节点
void DestroyBST(BST& T);			//销毁二叉排序树


#endif 

