#include"head.h"
int main()
{
	BiThrTree p,T=NULL;
	printf("按前序遍历创建二叉树！\n");
	CreateBiThrTree(T);
	printf("二叉树遍历结果为：");
	TraverseBT(T);
	InOrderThreading(p, T);
	printf("\n线索化成功！");
	printf("\n遍历结果为:");
	//ThreadingThrTree(T);
	//DestoryBiThrTree(T);
	ThreadingThrTree(p);
	return 0;

}