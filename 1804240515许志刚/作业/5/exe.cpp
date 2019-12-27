//求叶子结点
int LeftBiTree(BiTree T)
{
	int m,n;
	if(!T)
		return 0;
	else if(!T->lchild && T->rchild)
		return 1;
	else{
		m=LeftBiTree(T->lchild);
		n=LeftBiTree(T->rchild);
		return (m+n);

	}
}