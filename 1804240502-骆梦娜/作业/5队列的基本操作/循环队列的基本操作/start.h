#include <stdio.h>
#include <stdlib.h>

/* 定义循环队列的缓冲区的大小 */
#define	MAX_ITEMS		256

/* 定义循环队列的数据结构体 */
typedef enum { FALSE, TRUE } boolean;
typedef struct
{
	int base[MAX_ITEMS];	// 循环队列的缓冲区
	int front;				// 循环队列的头指针
	int rear;				// 循环队列的尾指针
} Queue;


Queue* queue_create(void);
void queue_destroy(Queue* q);
void queue_init(Queue* q);
int queue_empty(Queue* q);
int queue_full(Queue* q);
boolean queue_rear_insert(Queue* q, int item);
int queue_front_delete(Queue* q);
int queue_get_front(Queue* q);
void queue_items_print(Queue* q);
