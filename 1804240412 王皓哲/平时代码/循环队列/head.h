#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>

using namespace std;

#define Status int
#define QElemType int
#define MaxQSize 100//循环队列数据结构

typedef struct
{
	QElemType data[MaxQSize];//数据域
	int front,rear;          //队头队尾指针
}SqQueue;

void menu();
int main();
Status InitQueue(SqQueue &Q);
bool QueueEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q,QElemType e);
bool DeQueue(SqQueue &Q,QElemType &e);
bool GetHead(SqQueue &Q,QElemType &e);
void EnterToQueue(SqQueue &Q);
void DeleteFromQueue(SqQueue &Q);
void GetHeadOfQueue(SqQueue Q);

