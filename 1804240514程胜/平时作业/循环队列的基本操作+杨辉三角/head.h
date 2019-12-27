#pragma warning(disable:4996)
#include<stdio.h>
#include<stdlib.h>

#define MAXQSIZE  20
#define OK		  1

typedef  char ElemType;
typedef  int Status;

typedef struct{
	ElemType* base;

	int front;
	int rear;
}cycleQueue;

void InitQueue(cycleQueue* q);
void InsertQueue(cycleQueue* q, ElemType e);
void DeleteQueue(cycleQueue* q, ElemType* e);
void DestoryQueue(cycleQueue* q);
Status LengthQueue(cycleQueue* q);
Status EmptyQueue(cycleQueue* q);
void headQueue(cycleQueue* q, ElemType* e);
void Ptriangle(int n);
int factorial(int n);



