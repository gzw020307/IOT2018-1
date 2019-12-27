#include "头文件.h"
//主函数
int main(void)
{
   
    int choose;

	while(1)
	{
	printf("*******************************\n");
	printf("1-用头插法构建L                       2-用尾插法构建L\n");
	printf("3-在L中插入一个元素                   4-删除L中的一个元素\n");
	printf("5-查找L中的一个元素的位置             6-删除L中的冗余元素\n");
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