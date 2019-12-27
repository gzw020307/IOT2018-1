#include<stdio.h>
#include<stdlib.h>


#define TRUE 1
#define FALSE 0
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
typedef int QElemType;
typedef int Status;

#define MAXQSIZE 100
typedef struct
{	
	QElemType *base;
	int front;
	int rear;
}SqQueue;

int  menu_select();
Status InitQueue(SqQueue &Q);
int QueueLength(SqQueue Q);
Status InQueue(SqQueue &Q);
//void Browser(SqQueue Q);
int Gethead(SqQueue Q);
Status DelQueue(SqQueue &Q);
