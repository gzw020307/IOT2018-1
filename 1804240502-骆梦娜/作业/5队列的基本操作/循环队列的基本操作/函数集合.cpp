#include"start.h"


/* 创建一个循环队列
 *		返回值 : 返回创建的循环队列的结构体指针
 */
Queue* queue_create(void)
{
	Queue* q = new Queue;	// 分配一个队列空间
	if (NULL == q)	// 分配失败
	{
		return NULL;
	}
	else	// 分配成功
	{
		q->front = 0;
		q->rear = 0;
		return q;
	}
}

/*	销毁一个循环队列
 *		q : 表示要销毁的循环队列
 */
void queue_destroy(Queue* q)
{
	if (NULL != q)
	{
		free(q);	// 执行销毁操作
	}
}

/* 初始化循环队列
 *		q : 要初始化的循环队列
 */
void queue_init(Queue* q)
{
	q->front = 0;
	q->rear = 0;
}

/*	判断循环队列是否为空
 *		q : 表示要判断的循环队列
 *		返回值: TRUE为空，FALSE为非空
 */
int queue_empty(Queue* q)
{
	if (q->front == q->rear) return 1;
	else return 0;
}

/*	判断循环队列是否为满
 *		q : 表示要判断的循环队列
 *		返回值: TRUE表示满，FALSE表示非满
 */
int queue_full(Queue* q)
{
	if ((q->rear + 1) % MAX_ITEMS == q->front) return 1;
	else return 0;
}

/*	向队列尾部插入一个元素
 *		q : 要插入的循环队列
 *		item : 要掺入的元素
 *		返回值: TRUE成功，FALSE失败
 */
boolean queue_rear_insert(Queue* q, int item)
{
	if (queue_full(q)) return FALSE;
	else	// 如果循环队列未满
	{
		// 先将元素插入到循环队列的尾部，然后循环队列尾部的rear指针加一
		q->base[q->rear] = item;
		q->rear = (q->rear + 1) % MAX_ITEMS;
		return TRUE;
	}
}

/*	将循环队列头部元素删除
 *		q : 要操作的堆栈
 *		返回值: 成功返回要删除的元素值，为0表示删除失败
 */
int queue_front_delete(Queue* q)
{
	int temp_item;

	if (queue_empty(q)) return 0;
	else	// 如果堆栈不为空
	{
		// 先将循环队列头部的元素取出，然后将头部指针加一
		temp_item = q->base[q->front];
		q->front = (q->front + 1) % MAX_ITEMS;
		return temp_item;
	}
}

/*	获取循环队列头部元素
 *		q : 要操作的循环队列
 *		返回值 : 成功返回元素值，失败则返回0
 */
int queue_get_front(Queue* q)
{
	if (queue_empty(q)) return 0;
	else	// 如果不为空，返回堆栈的值
	{
		return q->base[q->front];
	}
}

/*	打印循环队列的元素
 *		q : 要打印的循环队列
 */
void queue_items_print(Queue* q)
{
	int front = q->front;
	int rear = q->rear;

	printf("Queue : ");
	while (!(front == rear))		// 判断是否读取完循环队列中所有元素
	{
		printf("%d ", q->base[front]);
		front = (front + 1) % MAX_ITEMS;
	}
	printf("\n");
}