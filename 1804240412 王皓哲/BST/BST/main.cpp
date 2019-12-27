#include"bst.h"

int main (void)
{
	int choice;
	BSTree T=NULL;
	BSTree *t= new BSTree;
	while(1)
	{	
		menu();
		printf(" ‰»Î—°‘Ò£∫\n");
		scanf("%d",&choice);
		if(!choice)
			break;
		switch (choice)
		{
		case 1:
			CreateBSTree(T);
			break;
		case 2:
			Inorder(T,Visit);
			break;
		case 3:
			DeleteBST(T,54);
			break;
		case 4:
			*t=T;
			Destroy(t);
		}
	}
	return 0;
}
