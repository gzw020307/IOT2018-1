#include"head.h"
int main()
{
	LinkQueue* q;
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	ElemType* c;
	int len=0;
	char ch;
	c = &ch;
	InitQueue(q);
	printf("������һ�����֣�����#������\n");
	ch=getchar();
	//scanf("%c", &ch);
	while (ch != '#')
	{
		InsertQueue(q, ch);
		ch=getchar();
		//scanf("%c", &ch);
	}
	while (!(q->front == q->rear))
	{
		DeleteQueue(q, c);
		len++;
		printf("%c ",*c);
	}
	printf("���еĳ���Ϊ%d\n", len);
	DestroyQueue(q);
	return 0;
}
