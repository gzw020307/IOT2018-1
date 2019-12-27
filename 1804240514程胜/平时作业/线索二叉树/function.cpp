#include"head.h"
BiThrTree pre;
//����һ�����������涨��ǰ������ķ�ʽ��������
void CreateBiThrTree(BiThrTree &T)
{
	char ch;

	scanf_s("%c", &ch);

	if (ch == ' ')
	{
		T = NULL;
	}
	else
	{
		T = (BiThrTree)malloc(sizeof(BiThrNode));
		T->Data = ch;
		T->ltag = Link;
		T->rtag = Link;

		CreateBiThrTree(T->lchild);
		CreateBiThrTree(T->rchild);
	}
}
//�������������
void InThreading(BiThrTree T)
{
	if (T)
	{
		InThreading(T->lchild);		//�ݹ�����������

		if (!T->lchild)			//����ýڵ�û�����ӣ�����ltagΪThread������lchild
		{							//����ָ��ǰ��
			T->ltag = Thread;
			T->lchild = pre;
		}
		if (!pre->rchild)
		{
			pre->rtag = Thread;
			pre->rchild = T;
		}
		pre = T;

		InThreading(T->rchild);		//�ݹ��Һ���������
	}
}
void InOrderThreading(BiThrTree &p,BiThrTree T)
{
	p = (BiThrTree)malloc(sizeof(BiThrNode));
	p->ltag = Link;
	p->rtag = Thread;
	p->rchild = p;
	if (!T)
	{
		p->lchild = p;
	}
	else
	{
		p->lchild = T;
		pre = p;
		InThreading(T);
		pre->rchild = p;
		pre->rtag = Thread;
		p->rchild = pre;
	}
}

void visit(char ch)
{
	printf("%c", ch);
}
void ThreadingThrTree(BiThrTree T)			//�����������ı���
{
	BiThrTree p;
	p = T->lchild;			     		  // p ָ��������ĸ����
	if (!T)
	{
		printf("Ϊ��");
	}
	while (p != T)						  // �������������ʱ
	{
		while (p->ltag == Link)
		{
			p = p->lchild;
		}
		printf("%c", p->Data);
		while (p->rtag == Thread && p->rchild != T)
		{
			p = p->rchild;
			printf("%c", p->Data);
		}
		p = p->rchild;

	}
}
void TraverseBT(BiThrTree T)
{
	if (T)
	{
		TraverseBT(T->lchild);
		printf("%c", T->Data);
		TraverseBT(T->rchild);
	}
}
