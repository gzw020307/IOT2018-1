#include"BST.h"

int main() 
{
	int i = 20, n = 0;
	ElemType a[15] = { 19, 38, 12, 40, 41, 39, 54, 76, 35, 47, 80, 14, 9, 44, 60 };
	ElemType data;
	BST T = NULL;

	for (int i = 0; i < 15; i++) {			//依据线性表建立二叉排序树
		InsertBST(T, a[i]);
	}

	cout << "已依据线性表建立二叉排序树" << endl;

	while (i != 0) {
		switch (i)
		{
		case 1:			//插入节点
			cout << "请输入插入的节点数量:";
			cin >> n;
			cout << "请输入数据:";
			for (int k = 0; k < n; k++) {
				cin >> data;
				InsertBST(T, data);
			}
			break;

		case 2:			//遍历二叉排序树
			if (T)
				VisitBST(T);
			else
				cout << "BST为空。";
			cout << endl;
			break;

		case 3:			//删除节点
			cout << "请输入要删除的节点数据：";
			cin >> n;
			DeleteBST(T, n);
			break;

		case 4:			//销毁二叉排序树
			DestroyBST(T);
			break;
		}
		

		menu();
		cin >> i;
	}
	return 0;
}