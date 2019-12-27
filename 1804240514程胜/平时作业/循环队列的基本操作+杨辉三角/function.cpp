#include"head.h"
void InitQueue(cycleQueue* q)	//���еĳ�ʼ��
{
	q->base = (ElemType*)malloc(MAXQSIZE * sizeof(ElemType));
	if (!q->base)
	{
		printf("�洢�ռ����ʧ��\n");
		exit(0);
	}
	q->front = q->rear = 0;
}
void InsertQueue(cycleQueue* q, ElemType e)		//��Ӳ���	
{
	if ((q->rear + 1) % MAXQSIZE == q->front)
	{
		printf("��������\n");
		return;
	}
	q->base[q->rear] = e;
	q->rear = (q->rear + 1) % MAXQSIZE;
}

void DeleteQueue(cycleQueue* q, ElemType* e)	//���Ӻ���
{
	if (q->front == q->rear)
	{
		printf("����Ϊ��\n");
		return;
	}
	*e = q->base[q->front];
	q->front = (q->front + 1) % MAXQSIZE;
}

void DestoryQueue(cycleQueue* q) {//���ٶ���
	if (q->base)
	{
		free(q->base);
	}
	q->base = NULL;
	q->front = q->rear = 0;
}

Status LengthQueue(cycleQueue* q)//����г���
{
	if ((q->rear + 1) == MAXQSIZE)
		return MAXQSIZE;
	else if (q->rear == q->front)
		return 0;
	else
		return((q->rear - q->front) % MAXQSIZE);
}

Status EmptyQueue(cycleQueue* q)		//�ж϶����Ƿ�Ϊ��
{
	if (q->base)
		return 1;
	else
		return 0;
}

void headQueue(cycleQueue* q,ElemType* e)	//���ض���ͷԪ��
{

	if (q->front == q->rear)
	{
		printf("����Ϊ��\n");
		return ;
	}
	*e = q->base[q->front];
}
int factorial(int n) {		//��׳˵ĺ���
	int sum = 1;
	if (n == 0)
		return 1;
	for (int i = 1; i <= n; i++)
	{
		sum = sum * i;
	}
	return sum;
}

void Ptriangle(int n)		//����������
{
	int i, k = 0;
	for (i = 1; i <= n; i++)
	{
		if (i == 1)
		{
			for (int j = 1; j <= 3 * (n - 1); j++)
			{
				printf(" ");		//�����ո���
			}
			printf("1\n");			//��Ϊ��һ��ֻ��Ԫ��1������ֱ�����
		}
		else
		{
			for (int j = 1; j <= 3 * (n - i); j++)
			{
				printf(" ");			//�����ո�ʹ�������
			}
			printf("1");
			for (int k = 1; k < i; k++)
			{
				if (factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)) >= 10 && factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)) <= 100)
					printf("    %d", factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)));	//����������ϼ���������ǵ�ĳ��ĳ�е�����
				else if (factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)) >= 100)		//if���Ϊ�˵����ո񣬶���
					printf("   %d", factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)));
				else
					printf("     %d", factorial(i - 1) / (factorial(k) * factorial(i - 1 - k)));

			}
			printf("\n");
		}
	}
}