#include <stdio.h>
#include <stdlib.h>
#include "head1.h"
int main(void)
{
	int *key;
	int n, i=0;
	int num,del_key;
	printf("输入要构建的二叉树的长度\n");
	scanf("%d", &n);
	key = (int *)malloc(sizeof(int)*n);
	printf("输入%d个结点:\n",n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &key[i]);
	}
	BST *bst = NULL;
	create(&bst, key, n);//创建 
	printf("二叉排序树已成功创建!\n");
	getchar();
	getchar();
	printf("中序遍历构建的二叉排序树:\n");	//中序遍历 
	inorder(bst);
	getchar();getchar();
	printf("输入要删除的元素：\n");
	scanf("%d", &del_key); 
	del(&bst, del_key);//删除
	printf("中序遍历：\n");
	inorder(bst);
	getchar();
	getchar();
	destroy(bst);
	printf("树已成功删除!\n");
	getchar();
	return 0;
}
