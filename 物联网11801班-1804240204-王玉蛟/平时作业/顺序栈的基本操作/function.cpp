#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include "header.h"
//初始化
Status InitStack(SqStack &S)
{//构造一个空栈
	S.base=(SElemType*)malloc(STACK_INIT_SIZE*sizeof(SElemType));
	if(!S.base){
		printf("分配失败\n");
		return 0;
	}
	S.top=S.base;
	S.stacksize=STACK_INIT_SIZE;
	return 1;
}

//销毁
Status DestroyStack_Sq(SqStack &S)
{
    free(S.base);
    S.base = NULL;
	S.stacksize = 0;
	return OK;
}





//入栈
bool Push(SqStack &S, SElemType e)
{
    if (S.top - S.base >= STACK_INIT_SIZE)//检测是否还有空余
	{
		S.base = (SElemType*)realloc(S.base, (S.stacksize + STACKINCREMENT) * sizeof(SElemType));
        if(!S.base) 
		{   
			printf("栈已满！\n");
			return false;}//存储分配空间失败
        S.top = S.base + STACK_INIT_SIZE;//栈底地址可能改变，重新定位栈顶元素
		S.stacksize = S.stacksize + STACKINCREMENT;
	}
    *S.top = e;//重新赋值给新的栈顶元素
	S.top++;
	return OK;
}
//入栈（菜单）
void Push_Sq(SqStack &S)
{	
	int n;
	SElemType e;
	int flag;
	printf("请输入入栈元素个数(>=1)：\n");	
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("请输入第%d个元素的值:",i+1);
		scanf("%d",&e);
		flag=Push(S,e);	
		if(flag)
			printf("%d个已入栈\n",e);	
		else{
			printf("栈已满！！！\n");
			break;
		}
	}
}



//出栈
bool Pop(SqStack &S, SElemType &e)//删除顺序栈栈顶元素，并让e返回其值
{

   if(S.top==S.base) 
	   return ERROR;
   else
	{
		S.top--;
		e = *S.top;//元素仍在S.top中，但是如果插入元素，就会被更新，就像是删除了一样
		return e;//用e带回被删除的元素
	}
   return TURE;
}

//出栈（菜单）
void Pop_Sq(SqStack &S)
{
	int n;
	SElemType e;
	int flag;
	printf("请输入出栈元素个数(>=1):\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		flag=Pop(S,e);
		if(flag)
			printf("%d已出栈\n",e);	
		else {
			printf("栈已空！！！\n");
			break;
		}	
	}
}


//取栈顶元素
bool    GetTop_Sq(SqStack S,SElemType e)//取顺序栈顶元素，并让e返回其值
{
  if (S.top == S.base)
		return FALSE;//空栈
	else
		e = *(S.top - 1);//用e返回栈顶元素，此时指针减1
	return e;
}


//求长
int StackLength(SqStack S)  //返回S的元素个数，即栈的长度
{
	if (S.top == S.base)
		return FALSE;//栈为空栈
	else
		return (S.top - S.base);

}
//判断栈空
bool StackEmpty_Sq(SqStack S)
{
    if(S.top==S.base) 
	    return TURE;
    else
        return FALSE;
}


//遍历
bool StackTraverse(SqStack S)

{
	if (S.base == NULL)
		return ERROR;//错误
	if (S.top == S.base)
		printf("栈中没有元素……\n");//空栈
	SElemType *p;
	p = S.top;
	while (p > S.base)//输出栈中元素
	{
		p--;
		printf("%d ", *p);
	}

	return OK;
}

//菜单
void menu(int choose)
{
   SqStack S;
	InitStack(S);
	int i, e,n;
	printf("输入栈的长度:\n");
	scanf("%d", &n);//确定需要输入的元素数量
	for (i = 1; i <= n; i++)//循环输入元素
	{
		printf("输入栈的第%d个元素\n", i);
		++S.top;
		scanf("%d", S.top - 1);
	}
	StackTraverse(S);
		printf("\n");
   switch(choose)
   {
   case 1:
	   Push_Sq(S);
	   StackTraverse(S);
	   printf("\n");
	   break;//入栈
   case 2:
		Pop_Sq(S);
		StackTraverse(S);
		printf("\n");
		break; //出栈
   case 3:
	   e=GetTop_Sq(S,e);
	   printf("栈顶元素为:%d\n",e);
	   break;//取栈顶元素
   case 4:
	   	printf("栈元素个数为%d:\n",StackLength(S));
		break;//求栈长
   case 5:
	   if(StackEmpty_Sq(S)==0)
		   printf("栈不为空！\n");
	   else
		   printf("栈为空！\n");
	   break;//判空
   case 6:
	   DestroyStack_Sq(S);
	   printf("已销毁\n");
	   break; //销毁
   }
}