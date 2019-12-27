#include"头文件.h"
#include"stdio.h"

//初始化
void InitList(LinkList &L)//创建一个带头结点的空链表L，为指向头结点的指针
{
    L=new LNode;
	if(!L)
		exit(1);//储存空间分配失败
	L->next=NULL;

}


//存取
Status GetElem_L(LinkList L,int i,ElemType &e)
{
	LNode *p;
    p=L->next;//初始化p指向第一个结点
	int j=1;//j为计数器
	while(p&&j<i)
	{
	   p=p->next;
	   ++j;
	}
	if(!p||j>i)
		return ERROR;//第i个元素不存在
	e=p->date;//取第i个元素
	return OK;

}



//插入
Status ListInsert_L(LinkList &L,int i,ElemType e)//在带头结点的单链线性表L中第i个位置之前插入元素e
{
	LNode *p;
    LNode *s;
    p=L;
    int j=0;
    while(p&&j<i-1)
    {
      p=p->next;
	  ++j;
    }//寻找第i-1个结点
   if(!p||j>i-1)//参数不合法，i小于1或者大于表长加1
	   return ERROR;
   s=new LNode;//生成新结点
   s->date=e;
   s->next=p->next;
   p->next=s;//插入L中
   return OK;

}

//删除
Status ListDelete_L(LinkList &L,int i,ElemType &e)
{
	LNode *p,*q;
   p=L;
   int j=0;
   while(p->next&&j<i-1)
   {
      p=p->next;
	  ++j;
   }
   if(!(p->next)||j>i-1)
	   return ERROR;//删除位置不合理
   q=p->next;
   p->next=q->next;
   e=q->date;//删除结点
   free(q);//释放结点
   return OK;

}
//头插法创建单链表
void HeadCreate_L(LinkList &L,int n)
{
	LinkList p;
	int a;
     for(int i=0;i<n;i++)
	 {
	    p=new LNode;
		scanf("%d",&a);
		p->date=a;
		p->next=L->next;//p指向下一个
		L->next=p;//再将p给单链表L的表头
	 }

}

//归并（未使用）
void MergeList_L(LinkList &La,LinkList &Lb,LinkList &Lc)
{
	LNode *pa;
	LNode *pb;
	LNode *pc;
    pa=La->next;
	pb=Lb->next;
	Lc=pc=La;
	while(pa&&pb)
	{
	   if(pa->date<=pb->date)
	   {
	      pc->next=pa;
		  pc=pa;
		  pa=pa->next;
	   }//
	   else 
	   {
	      pc->next=pb;
		  pc=pb;
		  pb=pb->next;
	   }
	}
	pc->next=pa?pa:pb;//插入剩余段
	free(Lb);//释放b的头结点
}





//删除冗余
void purge_L(LinkList &L)
{
	//删除单链表中的冗余元素，即使操作后的单链表中只保留
	//操作之前表中所有值不相同的元素
	LinkList q,c;
	LNode *p;
	p=L->next;
	L->next=NULL;
	while(p)
	{
		c=p->next;
		q=L->next;
		while(q&&p->date!=q->date)
			q=q->next;

		if(!q)
		{
			p->next=L->next;
			L->next=p;
		}
		else
			delete p;
		p=c;
	}
}


//尾插法创建单链表
void TailCreate_L(LinkList &L,int n)
{
    LinkList p,r;
    int i,a;
    L=new LNode; // L为整个线性表
    r=L;//r为指向尾部的结点
    for(i=0; i<n; i++)
	{
       p=new LNode; //生成新结点
	   scanf("%d",&a);
       p->date = a;//
       r->next=p; //将表尾终端结点的指针指向新结点
       r =p;//将当前的新结点定义为表尾终端结点
	}
    r->next = NULL ;//表示当前链表结束
}

//输出单链表
void print (LinkList L)
{
	LinkList p;
	p=L->next;
	while(p)
	{		
		printf("%d,",p->date );
		p=p->next;
	}
	printf("\n");
}


//主菜单
void menu(int choose)
{
	int n;
	int i;
	ElemType e;
    switch(choose)
	{
	case 1:
		printf("Enter n:");
		scanf("%d",&n);
		InitList(L);
        HeadCreate_L(L,n);
        print(L);
	    printf("\n");
		break;
	case 2:
        printf("Enter n:");
		scanf("%d",&n);
		InitList(L);
        TailCreate_L(L,n);
		print(L);
		printf("\n");
		break;
	case 3:
		printf("输入位置:");
		scanf("%d",&i);
        printf("Enter number:");
		scanf("%d",&e);
		ListInsert_L(L,i,e);
		print(L);
		printf("\n");
		break;
	case 4:
        printf("Enter i:");
		scanf("%d",&i);
		ListDelete_L(L,i,e);
		print(L);
		printf("\n");
		break;
	case 5:
        printf("输入位置：");
	    scanf("%d",&i);
		GetElem_L(L,i,e);
		printf("%d",e);
		printf("\n");
		break;
	case 6:
		purge_L(L);
	    print(L);
		printf("\n");
		break;

	
	}

}
