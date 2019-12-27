#include"head.h"

int main()
{
	/*
	int option;
	int sign=1;
	Elemtype n;
	BiTree T=NULL;
	while (sign)
	{
		cout << "--------------------菜单--------------------" << endl;
		cout << " 1.输入树中元素      2.中序序列输出树中元素 " << endl;
		cout << " 3.层次遍历          4.退出			     " << endl;
		cout << "请输入功能（1-2）： ";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "请输入元素： ";
			cin >> n;
			InsertTree(T, n);
			break;

		case 2:
			cout << "树中按照中序遍历为——>" ;
			ShowTree(T);
			cout << endl;
			break;
		case 3:
			cengci(T);
			break;
		case 4:
		    sign=0;
			break;

		}
	}*/
	/*
	BiThrTree Root;
	BiThrTree head;
	Root = (BiThrTree)malloc(sizeof(BiThrNode));
	head = (BiThrTree)malloc(sizeof(BiThrNode));
	Root = Insert_BiTHrTree(Root);
	Print_BiTHrTree(Root);
	InOrderThreading(head,Root);
	read(head);
	*/
	
	HuffmanTree ht = NULL;
	int w[6] = { 4,5,6,7,8,9};
	CreateHuffmanTree(ht,6, w);
	return 0;

}