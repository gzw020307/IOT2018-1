#include"start.h"



/* 程序的入口 */
int main(int argc, char* argv[])
{
	Queue* q;
	int a[10];
	int i,t,c,d;

	/* 通过控制台输入10个整形元素 */
	printf("Input 10 numbers :\n");
	for (i = 0; i < 10; i++)
	{
		scanf_s("%d", &a[i]);
	}

	/* 创建一个循环队列 */
	q = queue_create();
	if (NULL == q)
	{
		printf("queue_create error!\n");
		return -1;
	}

	/* 把这个数组中的元素插入到队列当中 */
	for (i = 0; i < 10; i++)
	{
		queue_rear_insert(q, a[i]);
	}

	printf("*******************************************************\n");

	/* 把循环队列中所有元素都打印出来 */
	queue_items_print(q);

	printf("*******************************************************\n");
	t = queue_get_front(q);
	printf("队头元素为:%d\n", t);
	/* 把循环队列中头元素都打印出来 */

	printf("*******************************************************\n");

	/* 向队列中尾部再插入两个元素 */
	queue_rear_insert(q, 200);
	queue_rear_insert(q, 300);
	queue_items_print(q);

	printf("*******************************************************\n");
	c = queue_full(q);
	printf("%d(1为满,0为非满)\n", c);
	/*判满*/

	printf("*******************************************************\n");

	/* 从队列头部删除三个元素 */
	queue_front_delete(q);
	queue_front_delete(q);
	queue_front_delete(q);
	queue_items_print(q);

	printf("*******************************************************\n");
	d = queue_empty(q);
	printf("%d(1为空,0为非空)\n", d);
	/*判空*/

	printf("*******************************************************\n");

	/* 销毁一个循环队列 */
	queue_destroy(q);

	return 0;
}