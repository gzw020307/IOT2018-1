#include"header.h"
#include "stdio.h"
//查找
Status SearchBST(BSTree T,KeyType kval,BSTree f,BSTree *p)
{
    if(!T)
	{
		*p=f;
		return ERROR;
	}
	else if(kval==T->data)
	{
	     *p=T;
		 return OK;
	}
	else if(kval<T->data)
		return SearchBST(T->lchild,kval,T,p);
	else
		return SearchBST(T->rchild,kval,T,p);
}

//插入
void InsertBST(BSTree T,int key)
{
	BSTree p,s;
    if(!SearchBST(T,key,NULL,&p))
	{
	    s=new BiTNode;
		s->data=key;
		s->lchild=s->rchild=NULL;
		if(!p)
		{
		   T=s;
		}
		else if(key<p->data)
			p->lchild=s;
		else
			p->rchild=s;
	}
	else printf("抱歉，元素重复\n");
}

//删除子函数
void Delete (BSTree p)
{
   BSTree q,s;
   if(p->rchild==NULL)
   {
       q=p;
	   p=p->lchild;
	   free(q);
   }
   else if(p->lchild==NULL)
   {
      q=p;
	  p=p->rchild;
	  free(q);   
   }
   else
   {
       q=p;
	   s=p->lchild;
	   while(s->rchild)
	   {
	      q=s;
		  s=s->rchild;
	   }
	   p->data=s->data;
	   if(q!=p)
		   q->rchild=s->lchild;
	   else
		   q->lchild=s->lchild;
	   free(s);
   }
}

//删除
void DeleteBST(BSTree T,KeyType key)
{
   BSTree p;
   if(!SearchBST(T,key,NULL,&p))
   {
      if(key==T->data)
		  Delete(T);
	  else if(key<T->data)
		  DeleteBST(T->lchild,key);
	  else
		  DeleteBST(T->rchild,key);
   }
   else
	   printf("抱歉，没有你所要删除的元素\n");

}

//中序遍历
void InOrder(BSTree T)
{
    if(T)
	{
	   InOrder(T->lchild);
	   printf("%d",T->data);
	   InOrder(T->rchild);
	}
	else 
		return;
}


//菜单
void menu(int choose)
{
   int i,num,n;
   KeyType kval;
   BSTree T=NULL,f,*p;
p   int a[n];
   switch(choose)
   {
   case(1):
	   printf("输入 n\n");
	   scanf("%d",&n);
	   printf("输入n个元素\n");
	   for(i=0;i<n;i++)
	   {
	       InsertBST(T,a[i]);  
	   }
	   printf("构造完成!\n");
	   break;
   case(2):
	   printf("请输入你要插入的元素：");
	   scanf("%d",&num);
	   InsertBST(T,num);
	   printf("插入完成！\n");
	   break;
   case(3):
	   printf("请输入要删除的元素:\n");
	   scanf("%d",&num);
	   DeleteBST(T,num);
	   printf("删除完成！\n");
	   break;
   case(4):
	   InOrder(T);
	   break;
   case(5):
	   SearchBST(T,kval,f,*p);
	   break;





}
 
