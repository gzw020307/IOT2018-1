#include"head.h"
void InitQueue(LinkQueue* q)
{
	q->front = q->rear = (QueuePrt)malloc(sizeof(QNode));
	if (!q->front)
	{
		printf("分配失败");
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

void DeleteQueue(LinkQueue* q, ElemType* e)		//出队列操作
{
	QueuePrt p;
	p = (QueuePrt)malloc(sizeof(QNode));
	if (q->front == q->rear)
	{
		printf("队列为空！\n");
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
		printf("队列为空！\n");
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