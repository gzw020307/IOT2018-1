#include "header.h"
//主函数
int main(void)
{
	
    int choose;

    while(1)
	{
	printf("*******************************\n");
	printf("1-入栈                       2-出栈\n");
	printf("3-取栈顶                     4-栈的长度\n");
	printf("5-判空                       6-销毁\n");
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