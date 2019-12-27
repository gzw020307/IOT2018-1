#include"head.h"
int main()
{
	int key,count=2;
	BSTree T = NULL,p=NULL;

	T=CreateBST(T);//printf("root=%d\n",root->data);
	printf("中序遍历的结果为:");
	InOrder(T);

	printf("\n");
	printf("请输入要删除的元素:");
	scanf_s("%d", &key);
	DeleteBST(T,p,count, key);
	printf("\n删除成功！\n");
	printf("中序遍历的结果为:");
	InOrder(T);
	DestoryBST(T);
	return 0;

}
