#include "head.h"

void CreateListHead(LinkList *&L, ElemType a[], int n)
{
	LinkList *s;
	L=(LinkList *)malloc(sizeof(LinkList));//创建头结点
	L->next=NULL;//将头结点next域置空
	for(int i=0;i<n;i++)
	{   
	    s=(LinkList *)malloc(sizeof(LinkList));//循环建立数据结点，创建数据结点*s
		s->data=a[i];//将结点s插在原开始节点之前，头结点之后
		s->next=L->next;
		L->next=s;
	}
}

void CreateListTail(LinkList *&L, ElemType a[], int n)
{
    LinkList *s,*r;
	L=(LinkList *)malloc(sizeof(LinkList));//创建头结点
	r=L;//r始终指向尾结点，开始时头结点和尾结点是同一个
	for(int i=0;i<n;i++)
	{
	  s=(LinkList *)malloc(sizeof(LinkList));//创建数据结点
	  s->data=a[i];//数据域
	  r->next=s;//将s插入到r后
	  r=s;//使r指向尾结点
	}
	r->next=NULL;//尾指针指针域置空
 
}

void DispList(LinkList *L)
{
	LinkList *p=L->next;//p指向开始结点
	while(p!=NULL)
	{
		cout<<p->data<<" "; //输出数据域
		p=p->next;
	}
	cout<<endl;
}

int main()
{
    LinkList *L;
	int n;
	cout<<"n:";
	cin>>n;
	int *a=new int(n);
	for(int i=0;i<n;i++)
	{
	  cin>>a[i];
	}

	CreateListHead(L,a,n);	
	cout<<"头插法建表：";
	DispList(L);//输出
 
	CreateListTail(L,a,n);	
	cout<<"尾插法建表：";
	DispList(L);//输出
}