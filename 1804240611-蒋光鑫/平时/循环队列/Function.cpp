#include"head.h"
int  menu_select()
{
	int sn;
	printf("###################----");
	printf("\n");
	printf("      menu\n");
	printf("\n");
	printf("1:构建循环队列Q\n");
	printf("2:输出队列长度\n");
	printf("3:插入元素\n");
	printf("4:遍历队列\n");
	printf("5:出栈元素\n");
	printf("6:\n");
	printf("7:\n");

	printf("0:退出\n");
	printf("###################");

	printf("\n");
	printf("enter your choice:");
	for(;;)
	{
		scanf("%d",&sn);
		if(sn<0||sn>9)
			printf("\n error!");
		else
			break;
	}
	return sn;
}

Status InitQueue(SqQueue &Q)
{
	Q.base=(QElemType*)malloc(MAXQSIZE* sizeof (QElemType));
	if(!Q.base)
		exit(OVERFLOW);
	Q.front=Q.rear=0;
	printf("创建成功！\n");
	return OK;
}

int QueueLength(SqQueue Q)	//计算队列长度
{
	int Length;
	Length=(Q.front-Q.rear+MAXQSIZE)%MAXQSIZE;
	printf("队列长度为:%d\n",Length);
	return 0;
}

Status InQueue(SqQueue &Q)
{
	int i,n,e;//输入元素个数
	printf("输入插入元素个数\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("输入要插入的第%d个元素\n",i+1);
		scanf("%d",&e);
		if((Q.rear+1)%MAXQSIZE==Q.front)
			return ERROR;
		Q.base[Q.rear]=e;
		Q.rear=(Q.rear+1)%MAXQSIZE;
		
	}
	return OK;
}

/*void Browser(SqQueue Q)
{
	while(Q.front<=Q.rear)
	{
		printf(" %d ",Q.front);
		Q.front++;
	}
}*/
int  Gethead(SqQueue Q)
{
	if(Q.front!=Q.rear)
		return Q.base[Q.front];
}
Status DelQueue(SqQueue &Q)	//删除，e返回值
{
	int e;
	if(Q.front=Q.rear)
		return ERROR;
	e=Q.base[Q.front];
	Q.front=(Q.front+1)%MAXQSIZE;
	printf("删除元素为%d",e);

		return OK;
}