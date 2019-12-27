#include"head.h"


BiThrTree Insert_BiTHrTree(BiThrTree Root)
{
	char ch;
	ch = getchar();
	Root = (BiThrTree)malloc(sizeof(BiThrNode));
	if (ch != '#')
	{
		Root->data = ch;
		Root->LTag = Root->RTag = Link;
		Root->Lchild = Insert_BiTHrTree(Root->Lchild);
		Root->Rchild = Insert_BiTHrTree(Root->Rchild);
	}
	else {
		return NULL;
	}
	return Root;
}
void Print_BiTHrTree(BiThrTree Root)
{
	if (Root)
	{
		Print_BiTHrTree(Root->Lchild);
		cout << Root->data;
		Print_BiTHrTree(Root->Rchild);
	}
}

void InThreading(BiThrTree p, BiThrTree &pre)
{
	if (p)
	{
		InThreading(p->Lchild, pre);
		if (!(p->Lchild))
		{
			p->LTag = THread;
			p->Lchild = pre;
		}
		if (!(pre->Rchild))
		{
			pre->RTag = THread;
			pre->Rchild = p;
		}
		pre = p;
		InThreading(p->Rchild, pre);
	}
	
}
void InOrderThreading(BiThrTree &head,BiThrTree Root)
{
	BiThrTree pre;
   
	head = (BiThrTree)malloc(sizeof(BiThrNode));
	pre = head;
	head->LTag = Link;
	head->RTag = THread;
	head->Rchild = head;

	if (!Root)
	{
		head->Lchild = head;
	}
	else
	{
		head->Lchild = Root;
		
		InThreading(Root, pre);
		pre->RTag = THread;
		pre->Rchild = head;
		head->Rchild = pre;
	}
	
}




void read(BiThrTree t)
{
	BiThrTree p;
	p = t->Rchild;
	while (p !=t)
	{
		cout << p->data;
		while (p->LTag == THread && p->Lchild != t)
		{
			p = p->Lchild;
			if(p!=t)
				cout << p->data;
		}
		if (p->LTag == THread && p->Lchild == t) 
			break;
		if (p->LTag == Link &&p->Lchild!=t)
		{
			p=p->Lchild;
			while (p->RTag==Link)
			{
				p = p->Rchild;
			}
		}
	}
}
