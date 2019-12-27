// 顺序表的基本操作.cpp : Defines the entry point for the console application.
//
#include "sqhead.h"
//主函数
int main(void)
{
    int choose;

	while(1)
	{
	printf("*******************************\n");
	printf("1-构建La                       2-构建Lb\n");
	printf("3-合并La和Lb得到Lc             4-在Lc中查找一个元素的位置\n");
	printf("5-在Lc中插入一个元素           6-删除Lc中的一个元素\n");
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