#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>
#define OK 1;
#define ERROR -1;

typedef char ElemType;

typedef struct QNode {
	ElemType Data;
	struct QNode* next;
}Queue,*QueuePrt;
typedef struct {
	QueuePrt front;
	QueuePrt rear;
}LinkQueue;

void InitQueue(LinkQueue* q);
void InsertQueue(LinkQueue* q, ElemType e);
void DeleteQueue(LinkQueue* q, ElemType* e);
void DestroyQueue(LinkQueue* q);
void GetHead(LinkQueue* q, ElemType* e);
int QueueLength(LinkQueue* q);