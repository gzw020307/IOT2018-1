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
	printf("������һ���ַ�������'#'������(�������Ϊ20)\n");
	scanf("%c", &ch);
	while (ch != '#')
	{

		InsertQueue(q, ch);
		scanf("%c", &ch);
	}
	printf("\n���еĳ���Ϊ:%d", LengthQueue(q));
	headQueue(q, c);
	printf("\n��ͷԪ��Ϊ%c", *c);
	printf("\n���������Ϊ:");
	while (q->front != q->rear)
	{
		DeleteQueue(q,c);
		printf("%c ", *c);
	}

/*	printf("\n\r\r\r------------------�˵�-------------------\n");
	printf("\n\r\r\r1.ѭ�����г�ʼ��      2.���             \n");
	printf("\n\r\r\r3.����г���          4.ȡ��ͷԪ��       \n");
	printf("\n\r\r\r5.����                6.�ж϶����Ƿ�Ϊ�� \n");
	printf("\n\r\r\r7.����                8.����������     \n");
	while (1)
	{
		printf("������Ҫ���еĲ���: ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			InitQueue(q);
			printf("��ʼ���ɹ���\n");
			break;
		case 2:
			char ch;
			printf("������һ���ַ�������'#'������\n");
			scanf("%c", &ch);
			while (ch != '#')
			{

				InsertQueue(q, ch);
				scanf("%c", &ch);
			}
			printf("��ӳɹ���\n");
			break;
		case 3:
			printf("���еĳ���Ϊ:%d\n", LengthQueue(q));
			break;
		case 4:
			*c=headQueue(q);
			printf("��ͷԪ��Ϊ:%c\n",*c);
			break;
		case 5:
			printf("ѭ�������е�Ԫ��Ϊ:");
			while (q->front != q->rear)
			{
				DeleteQueue(q,c);
				printf("%c ", *c);
			}
			break;
		case 6:
			if (EmptyQueue(q))
				printf("���в�Ϊ�գ�\n");
			else
				printf("����Ϊ�գ�\n");
			break;
		case 7:
			DestoryQueue(q);
			printf("���ٳɹ�!\n");
			break;
		case 8:
			int a;
			printf("\n��������Ҫ�����������ǵĳ���:\n");
			a = getchar();
			Ptriangle(a);
			break;

		}
	}
	*/
	printf("\n��������Ҫ�����������ǵĳ���:\n");
	scanf("%d", &a);
	Ptriangle(a);
	DestoryQueue(q);
	return 0;
}