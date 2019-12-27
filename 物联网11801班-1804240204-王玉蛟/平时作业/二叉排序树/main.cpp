#include"header.h"

int main(void)
{
   int choose;
   while(1)
	{
	printf("*******************************\n");
	printf("1-构造二叉树                           2-插入\n");
	printf("3-删除                                 4-中序遍历\n");
	printf("5-查找                                 6-销毁\n");
	printf("其他-退出程序");
	printf("******************************\n");
	printf("Enter your choose:");
	scanf("%d",&choose);
	if(choose<1||choose>6)
		break;
	else
		menu(choose);
	}
	return 0;
}
