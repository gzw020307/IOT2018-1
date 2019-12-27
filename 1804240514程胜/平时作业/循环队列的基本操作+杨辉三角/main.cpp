#include"head.h"
int main()
{
	cycleQueue* q;
	char* c,b;
	int a;
	q = (cycleQueue*)malloc(MAXQSIZE * sizeof(cycleQueue));
	c = &b;
	InitQueue(q);
	char ch;
	printf("请输入一串字符，输入'#'结束！(长度最大为20)\n");
	scanf("%c", &ch);
	while (ch != '#')
	{

		InsertQueue(q, ch);
		scanf("%c", &ch);
	}
	printf("\n队列的长度为:%d", LengthQueue(q));
	headQueue(q, c);
	printf("\n对头元素为%c", *c);
	printf("\n输入的数据为:");
	while (q->front != q->rear)
	{
		DeleteQueue(q,c);
		printf("%c ", *c);
	}

/*	printf("\n\r\r\r------------------菜单-------------------\n");
	printf("\n\r\r\r1.循环队列初始化      2.入队             \n");
	printf("\n\r\r\r3.求队列长度          4.取对头元素       \n");
	printf("\n\r\r\r5.出队                6.判断队列是否为空 \n");
	printf("\n\r\r\r7.销毁                8.输出杨辉三角     \n");
	while (1)
	{
		printf("请输入要进行的操作: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			InitQueue(q);
			printf("初始化成功！\n");
			break;
		case 2:
			char ch;
			printf("请输入一串字符，输入'#'结束！\n");
			scanf("%c", &ch);
			while (ch != '#')
			{

				InsertQueue(q, ch);
				scanf("%c", &ch);
			}
			printf("入队成功！\n");
			break;
		case 3:
			printf("队列的长度为:%d\n", LengthQueue(q));
			break;
		case 4:
			*c=headQueue(q);
			printf("对头元素为:%c\n",*c);
			break;
		case 5:
			printf("循环队列中的元素为:");
			while (q->front != q->rear)
			{
				DeleteQueue(q,c);
				printf("%c ", *c);
			}
			break;
		case 6:
			if (EmptyQueue(q))
				printf("队列不为空！\n");
			else
				printf("队列为空！\n");
			break;
		case 7:
			DestoryQueue(q);
			printf("销毁成功!\n");
			break;
		case 8:
			int a;
			printf("\n请输入想要输出的杨辉三角的长度:\n");
			a = getchar();
			Ptriangle(a);
			break;

		}
	}
	*/
	printf("\n请输入想要输出的杨辉三角的长度:\n");
	scanf("%d", &a);
	Ptriangle(a);
	DestoryQueue(q);
	return 0;
}