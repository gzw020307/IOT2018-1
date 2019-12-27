#include<stdio.h>
#include<stdlib.h>
#define OK 0
#define TURE 1
#define FALSE 0
#define ERROR 0
#define MAXSIZE 20
typedef int ElemType;
typedef int Status;
typedef int KeyType;


typedef struct BiTNode{
        ElemType data;
		struct BiTNode *lchild,*rchild;
}BiTNode,*BSTree;
Status SearchBST(BSTree T,KeyType kval,BSTree f,BSTree *p);//查找
void InsertBST(BSTree T,int key);//插入
void Delete (BSTree p);//删除子函数
void DeleteBST(BSTree T,KeyType key);//删除
void InOrder(BSTree T);//中序遍历
void menu(int choose);//菜单