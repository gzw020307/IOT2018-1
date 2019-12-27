#include"head.h"

int main()
{
	int n[15] = {19,38,12,40,41,39,54,76,35,47,80,14,9,44,60};
	BISTree t;
	t= (BISTree)malloc((16)*sizeof(BISTree));
	t->data = n[0];
	t->Lchild = t->Rchild = NULL;
	for (int i = 1; i < 15; i++)
	{
		InsertNode(t, n[i]);
	}
	panduan(t);
	Show(t);
	cout << endl;
	BISTree p;
	SearchBSTree(t, 54, NULL, p);
	deletdata(p);
	panduan(t);
	Show(t);
	cout << endl;
	DestroyBiTree(t);
	panduan(t);
	Show(t);
	return 0;
}