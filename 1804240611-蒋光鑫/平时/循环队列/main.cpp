#include"head.h"
int main()
{
	SqQueue Q;
	for(;;)
	{
		switch(menu_select())
		{
		case 1:
			InitQueue(Q);
			printf("\n");
			break;
		case 2:
			printf("队列长度为:%d\n",QueueLength(Q));
			break;
		case 3:
			InQueue(Q);
			printf("success!\n");
			break;
		case 4:
			//Browser(Q);
			printf("Success!\n");
			break;
		case 5:
			DelQueue(Q);
			//printf("删除元素为%d",e);
			break;
		case 0:
			printf("程序结束，谢谢！\n");
			exit(0);
		}
		
	}
	return 0;
}
