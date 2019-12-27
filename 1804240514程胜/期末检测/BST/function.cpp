#include"head.h"
BSTree SearchBST(BSTree T, int key, BSTree f, BSTree& p)
{//�����㷨��TΪ���ڵ�ʱ��f=NULL;����ʱ��fָ��T��˫��
	if (!T)				//����ʧ��
	{
		p = f;
		return 0;
	}
	else
	{
		if (key == T->data)
		{					//���ҳɹ�
			return T;
		}
		else if (key < T->data)
		{				//����������������
			return SearchBST(T->lchild, key, T, p);
		}
		else
		{				//����������������
			return SearchBST(T->rchild, key, T, p);
		}
	}

}

BSTree InsertBST(BSTree T, int key)
{
	BSTree p, s;
	if (NULL == T)
	{
		T = (BSTree)malloc(sizeof(BSTNode));
		T->data = key;
		T->lchild = T->rchild = NULL;
		return T;
	}
	if (!SearchBST(T, key, NULL, p))//���Ҳ��ɹ�
	{
		s = (BSTree)malloc(sizeof(BSTNode));
		s->data = key;
		s->lchild = s->rchild = NULL;
		if (!p)
			T = p;
		else if (key < p->data)
			p->lchild = s;
		else
			p->rchild = s;
		return T;
	}
	else
		return T;
}
BSTree CreateBST(BSTree T)
{
	int a;
	printf("�������ݹ������������������-1����:");
	scanf_s("%d", &a);
	while (a != -1)
	{
		T = InsertBST(T, a);
		scanf_s("%d", &a);
	}
	return T;
}
void InOrder(BSTree T)//�������������
{
	if (T)
	{
		InOrder(T->lchild);
		printf("%d ", T->data);
		InOrder(T->rchild);
	}
}
void DeleteBST(BSTree T, BSTree p, int count, int key)
{						//ɾ����㣬pָ��T����һ�����
	if (!T)				//count��һ����ʾ���ã�Ϊ0��ʾ
	{			//p������ΪT��Ϊ1��ʾp���Һ���ΪT
		if (T->data == key)	//ɾ���Ľ��Ϊ��ʱ
		{
			if (count == 0)
			{
				BSTree q=T;
				p->lchild = NULL;
				free(q);
			}
			else if (count == 1)
			{
				BSTree q = T;
				p->rchild = NULL;
				free(T);
			}
			else {				//��ʾ��Ϊ��
				free(T);
			}
		}
		else
		{				//û���ҵ��ùؼ���
			printf("�Ҳ���Ҫɾ���Ĺؼ��֣�");
			return;
		}
	}
	else
	{
		if (T->data == key)
		{				//�ҵ��ؼ��ֽ���ɾ������
			Delete(T,p,count);
		}
		else if (key < T->data)
		{
			count = 0;		//�ȹؼ��ִ�������
			DeleteBST(T->lchild,T,count,key);
		}
		else
		{					//�ȹؼ���С���Һ���
			count = 1;
			DeleteBST(T->rchild,T,count,key);
		}
	}
}

void Delete(BSTree T,BSTree p,int count)
{				//�����ɾ������
	BSTree s, q;
	if (T->rchild == NULL)
	{				//ɾ���Ĺؼ���������û��������ʱ
		if (p == T)
		{
			q = T;
			T = T->lchild;
			free(q);
		}
		else
		{
			if (count == 0)
			{
				q = T;
				p->lchild = q->lchild;
				free(q);
			}
			else
			{
				q = T;
				p->rchild = q->lchild;
				free(q);
			}
		}
	}
	else if (T->lchild == NULL)
	{			//ɾ���Ĺؼ���������û��������ʱ
		if (p == T)
		{
			q = T;
			T = T->rchild;
			free(q);
		}
		else
		{
			if (count == 0)
			{
				q = T;
				p->lchild = q->rchild;
				free(q);
			}
			else
			{
				q = T;
				p->rchild = q->rchild;
				free(q);
			}
		}
	}
	else
	{				//�����Ӷ���ʱ
		q = T;
		s = T->lchild;
		while (s->rchild)//�ҵ������������ֵ
		{
			q = s;
			s = s->rchild;
		}
		if (q != T)		//������������
		{
			if (s == NULL)	//���ֵû����
			{
				T->data = s->data;
				q->rchild = NULL;
			}
			else	//���ֵ������	
			{
				T->data = s->data;
				q->rchild = s->lchild;
			}
		}
		else		//����û������
		{
			if (s == NULL)			//���ֵû����
			{
				T->data = s->data;
				q->lchild = NULL;
			}
			else					//���ֵ������
			{
				T->data = s->data;
				q->lchild = s->lchild;
			}
		}
		free(s);
	}
}
void DestoryBST(BSTree T)		//���ٺ���
{
	if (T)
	{
		free(T);
		printf("\n���ٳɹ�!");
	}

}