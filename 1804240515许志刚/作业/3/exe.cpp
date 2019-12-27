//试写一递归算法，从大到小输出二叉排序树中所有其值不小于x的关键字
void PrintfBT(BiTree &T,keytype X)
{
	if(!T)
		return;
	PrintfBT(T->right,X);
	if(T->data,key<X)
		return;
	printf("%d",T->data.key);
	PrintfBT(T->left,X);
}