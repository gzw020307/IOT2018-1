//试编写一算法，删除二叉排序树中所有关键字不小于X的结点，并释放该结点空间
void Delete(BiTree &T,keytype X)
{
	if(!T)
		return;
	Delete(T->right,X);
	if(T->data.key<X)
		return;
	else
		T->prev->right=T->right;
	free(T);
	Delete(T->left,X);
}