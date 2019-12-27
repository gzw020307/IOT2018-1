#include"head.h"
void InitQueue(cycleQueue* q)	//队列的初始化
{
	q->base = (ElemType*)malloc(MAXQSIZE * sizeof(ElemType));
	if (!q->base)
	{
		printf("存储空间分配失败\n");
		exit(0);
	}
	q->front = q->rear = 0;
}
void InsertQueue(cycleQueue* q, ElemType e)		//入队操作	
{
	if ((q->rear + 1) % MAXQSIZE == q->front)
	{
		printf("队列已满\n");
		return;
	}
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXQSIZE;
}

void DeleteQueue(cycleQueue* q, ElemType* e)	//出队函数
{
	if (q->front == q->rear)
	{
		printf("队列为空\n");
		return;
	}
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXQSIZE;
}

void DestoryQueue(cycleQueue* q) {//销毁队列
	if (q->base)
	{
		free(q->base);
	}
	q->base = NULL;
	q->front = q->rear = 0;
}

Status LengthQueue(cycleQueue* q)//求队列长度
{
	if ((q->rear + 1) == MAXQSIZE)
		return MAXQSIZE;
	else if (q->rear == q->front)
		return 0;
	else
		return((q->rear - q->front) % MAXQSIZE);
}

Status EmptyQueue(cycleQueue* q)		//判断队列是否为空
{
	if (q->base)
		return 1;
	else
		return 0;
}

void headQueue(cycleQueue* q,ElemType* e)	//返回队列头元素
{

	if (q->front == q->rear)
	{
		printf("队列为空\n");
		return ;
	}
	*e = q->base[q->front];
}
int factorial(int n) {		//求阶乘的函数
	int sum = 1;
	if (n == 0)
		return 1;
	for (int i = 1; i <= n; i++)
	{
		sum = sum * i;
	}
	return sum;
}

void Ptriangle(int n)		//输出杨辉三角
{
	int i, k = 0;
	for (i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			for (int j = 1; j <= 3 * (n - 1); j++)
			{
				printf(" ");		//调整空格数
			}
			printf("1\n");			//因为第一行只有元素1，所以直接输出
		}
		else
		{
			for (int j = 1; j <= 3 * (n - i); j++)
			{
				printf(" ");			//调整空格，使输出整齐
			}
			printf("1");
			for (int k = 1; k < i; k++)
			{
				if (factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)) >= 10 && factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)) <= 100)
					printf("    %d", factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)));	//利用排列组合计算杨辉三角的某行某列的数据
				else if (factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)) >= 100)		//if语句为了调整空格，对齐
					printf("   %d", factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)));
				else
					printf("     %d", factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)));

			}
			printf("\n");
		}
	}
}