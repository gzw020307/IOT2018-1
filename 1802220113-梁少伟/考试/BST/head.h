#include"stdio.h"
#include"malloc.h"
#include"iostream"
using namespace std;


typedef int elemtype;
typedef struct Node
{
	elemtype data;
	struct Node* Lchild, *Rchild;

}BISTreeNode,*BISTree;

bool SearchBSTree(BISTree T, elemtype key, BISTree pre, BISTree& p);/////搜索树中是否有该元素
bool InsertNode(BISTree& T, elemtype KEY);//////插入元素
void Show(BISTree T);////打印树
void deletdata(BISTree& q);////删除树树中元素
void DestroyBiTree(BISTree& T);/////摧毁树
void panduan(BISTree T);////判断树是否为空
