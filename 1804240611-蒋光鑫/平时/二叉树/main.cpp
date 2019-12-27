#include"head.h"

int main()
{
	printf("请输入你要建立的二叉树的各个结点: \n");
	Node* root = NULL;
	root = createBinaryTree();
	printf("二叉树建立成功");
	cout << endl;

	cout << "前序遍历结果:" << endl;
	preOrderTraverse(root);
	cout << endl;

	cout << "中序遍历结果:" << endl;
	inOrderTraverse(root);
	cout << endl;

	cout << "后序遍历结果:" << endl;
	lastOrderTraverse(root);
	cout << endl;

	return 0;
}
