//试编写一个判定二叉树是否为二叉排序树的算法
int Issearch(BITree T)
{
	if(T->left!==NULL&&flag)
	{
		Issearch(T->left);

	}
	if(T->data<pvre)
		flag=false;
	prev=T->data;
	if(T->right!==NULL && flag)
		Issearch(T->right);
	return flag;
}