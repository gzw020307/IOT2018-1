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

typedef struct
{
    ElemType *elem;
	int length;
	int listsize;
  
}SqList;//建立线性表结构体

void menu(int choose);//主菜单
Status InitList_Sq(SqList &L);//构建空线性表
void InputList(SqList &L);//按顺序从最后输入数据
Status LocateElem_Sq(SqList La,ElemType i);//查找
Status ListInsert_Sq(SqList &L,int i,ElemType e);//插入
Status ListDelete_Sq(SqList &L,int i,ElemType &e);//删除
void Mergelist_Sq(SqList La,SqList Lb,SqList &Lc);//合并
static	SqList La,Lb,Lc;
