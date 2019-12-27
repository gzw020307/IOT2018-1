#include "stdlib.h"
#include "stdio.h"
#define LIST_INIT_SIZE 100  //线性表的最大长度
#define LISTINCREMENT 10
#define OK 0
#define TURE 1
#define FALSE 0
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int ElemType;
typedef int Status;

typedef struct LNode
{
    ElemType date;
	struct LNode *next;
}LNode,*LinkList;//建立单链表结构体
 
void InitList(LinkList &L);//初始化
Status GetElem_L(LinkList L,int i,ElemType &e);//存取
Status ListInsert_L(LinkList &L,int i,ElemType e);//插入
Status ListDelete_L(LinkList &L,int i,ElemType &e);//删除
void Create_L(LinkList &L,int n);//头插法创建单链表
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc);//归并(未使用)
void TailCreate_L(LinkList &L,int n);//尾插法创建单链表
void menu(int choose);//主菜单
 static LinkList L;



