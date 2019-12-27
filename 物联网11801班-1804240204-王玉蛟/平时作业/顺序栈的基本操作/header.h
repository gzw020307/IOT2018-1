#include <stdlib.h>
#include <stdio.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

#define OK 1
#define ERROR 0
#define TURE 1
#define FALSE 0

#define INFEASIBLE -1
#define OVERFLOW -2
typedef int Status;
typedef int SElemType;

typedef struct
{
   SElemType *base;
   SElemType *top;
   int stacksize;
}SqStack;

Status InitStack(SqStack &S);//初始化
Status DestroyStack_Sq(SqStack &S);//销毁
bool Push(SqStack &S, SElemType e);//入栈
void Push_Sq(SqStack &S);//入栈（菜单）
bool Pop(SqStack &S, SElemType &e);//出栈
void Pop_Sq(SqStack &S);//出栈（菜单）
bool GetTop_Sq(SqStack S,SElemType e);//取栈顶元素
int StackLength(SqStack S);//求长
bool StackEmpty_Sq(SqStack S);//判断栈空
bool StackTraverse(SqStack S);//遍历
void menu(int choose);//菜单
