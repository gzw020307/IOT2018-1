#include"head.h"

int main()
{
    BiTree T;
    //测试例子AB#CD##E##F#GH###
    printf("先序遍历输入(以#结束)\n");
    CreateBiTree(T);
	printf("\n");
    printf("中序遍历输出:");
    InOrderTraverse(T);
	printf("\n");
	printf("先序遍历输出:");
    PreOrderTraverse(T);
	printf("\n");
    printf("后序遍历输出:");
    PostOrderTraverse(T);
	printf("\n");

		BiThrTree Tr, Thrt;
        cout << "创建线索二叉树，按先序次序输入线索二叉树中结点的值（以$结束）：\n";
        CreateBiThrTree(Tr);
        if (InOrderThreading(Thrt, Tr) == OK)
				  cout << "成功建立中序线索化链表！\n";
        cout << "中序遍历线索二叉树，结果是：\n";
        InOrderTraverse_Thr(Thrt, PrintElement);
        cout << endl;

	int  w[] = { 5,4,3,2,1 };//用数组w存储各个权值
	int n=5;//表示数组w中的个数
	HuffmanCode HC = NULL;
	HuffmanTree hTree = create_HuffmanTree(w, n);
	int wpl1 = countWPL1(hTree, n);
	printf("从叶子结点开始遍历二叉树求最小带权路径长度WPL=%d\n", wpl1);
	int wpl2 = countWPL2(hTree, n);
	printf("从根结点开始遍历二叉树求最小带权路径长度WPL=%d\n", wpl2);
	printf("\n从叶子到根结点编码结果为：\n");
	HuffmanCoding1(hTree, HC, n);
	printf("\n从根结点到叶子结点编码结果为：\n");
	HuffmanCoding2(hTree, HC, n);
	system("pause");

   return 0;
}
