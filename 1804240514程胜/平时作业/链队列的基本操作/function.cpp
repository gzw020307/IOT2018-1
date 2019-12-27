#include"head.h"
void InitQueue(LinkQueue* q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
	{
		printf("����ʧ��");
		exit(0);
	}
		q->front->next = NULL;

}

void InsertQueue(LinkQueue* q, ElemType e)
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (p == NULL)
	{
		exit(0);
	}
	p->Data = e;
	p->next = NULL;
	q->rear->next = p;
	q->rear = p;
}

void DeleteQueue(LinkQueue* q, ElemType* e)		//�����в���
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (q->front == q->rear)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	p = q->front->next;
	*e = p->Data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;
	}
	free(p);
}

void DestroyQueue(LinkQueue* q)
{
	while (q->front)
	{
		q->rear = q->front->next;
		free(q->front);
		q->front = q->rear;
	}
}

void GetHead(LinkQueue* q, ElemType* e)
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (q->front == q->rear)
	{
		printf("����Ϊ�գ�\n");
		return;
	}
	p = q->front->next;
	*e = p->Data;
	free(p);

}

int QueueLength(LinkQueue *q)
{
	QueuePrt p;
	int len=0;
	p = q->front;
	while (p->next)
	{
		len++;
		p = p->next;
		
	}
	free(p);
	return len;

}