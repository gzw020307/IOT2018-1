#include"head.h"

void InitQueue(Queue& Q)//////初始化
{
	Q.front = Q.rear = (QueuePtr)malloc(sizeof(node));
	if (!Q.front) exit(1);
	Q.front->next = NULL;
	Q.length = 0;
}

void EnQueue(Queue& Q, BiTree e)/////入队操作
{
	QueuePtr s;
	s = (QueuePtr)malloc(sizeof(node));
	s->data = e;
	s->next = NULL;
	Q.rear->next = s;
	Q.rear = s;
	Q.length++;
}

void DeQueue(Queue& Q, BiTree& e)//////出队操作
{
	QueuePtr p;
	p = Q.front->next;//////头指针为空
	e = p->data;
	Q.front->next = p->next;
	if (Q.rear == p)
		Q.rear = Q.front;
	free(p);
	Q.length--;
}
int QueueEmpty(Queue& Q)////////层次遍历
{
	if (Q.front == Q.rear)
		return 0;
	else
	{
		return 1;
	}
}