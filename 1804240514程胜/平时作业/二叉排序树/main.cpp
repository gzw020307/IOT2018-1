#include"head.h"
int main()
{
	int key,count=2;
	BSTree T = NULL,p=NULL;

	T=CreateBST(T);//printf("root=%d\n",root->data);
	printf("��������Ľ��Ϊ:");
	InOrder(T);

	printf("\n");
	printf("������Ҫɾ����Ԫ��:");
	scanf_s("%d", &key);
	DeleteBST(T,p,count, key);
	printf("\nɾ���ɹ���\n");
	printf("��������Ľ��Ϊ:");
	InOrder(T);
	DestoryBST(T);
	return 0;

}
