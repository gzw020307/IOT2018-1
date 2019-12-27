#include<stdio.h>
#include<iostream>
#include<string>
using namespace std;
typedef int ElemType;
typedef struct LNode{
   ElemType data;  //存放元素值
   struct LNode *next;//指针域指向后继结点
}LinkList;

void CreateListHead(LinkList *&L,ElemType a[],int n);//头插法建表
void CreateListTail(LinkList *&L,ElemType a[],int n);//尾插法建表
void DispList(LinkList *L);//输出
int main();