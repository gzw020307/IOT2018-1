typedef struct BST
{
	int key;
	struct BST *lchild;
	struct BST *rchild;
}BST;
int insert(BST **bt, int key)
{
	if(*bt == NULL){
		*bt = (BST*)malloc(sizeof(BST));
		if(*bt == NULL){
			printf("分配内存失败\n");
			return 0;
		}
		(*bt)->key = key;
		(*bt)->lchild = (*bt)->rchild = NULL;
		return 1;
	}
	if(key == (*bt)->key)
	{ 
		printf("%d已存在！\n", key);
		return 0;
	}
	else if(key < (*bt)->key)
		insert(&(*bt)->lchild, key);
	else
		insert(&(*bt)->rchild, key);	
	return 0;
}
void create(BST **bst, int *key, int n)//创建
{
	int i=0;
	for(i=0; i<n; i++){
		insert(bst, key[i]);	
	}
}

int delnode(BST **p)//删除节点
 {
	BST *s, *q;
	if((*p)->lchild == NULL && (*p)->rchild == NULL)//左右子树都为空!
	{ 
		*p = NULL;
		return 1; 	
	}
	else if(!(*p)->lchild)//左子树为空
	{ 
		q = *p; 
		*p = (*p)->rchild; 
		free(q); 
		return 1;
	}
	else if(!(*p)->rchild)//右子树为空 
	{
		q = *p;
		*p = (*p)->lchild;
		free(q);
		return 1;	
	}
	else//左右子树都不为空 
	{   
		s = (*p)->lchild;
		q = *p;
		while(s->rchild)
		{ 
			q = s;
			s = s->rchild;
		}
		(*p)->key = s->key; 
	
		if(q != (*p)) 
			q->rchild = s->lchild; 
		else
			q->lchild = s->lchild;
			
		free(s);			
	} 
	return 1;
} 
int del(BST **bt, int key)//删除
{
	if(*bt == NULL)
	{
		printf("未找到%d\n", key);
		return 0;
	}	
	if((*bt)->key == key)
	{
		if(delnode(&(*bt)))
			printf("已删除%d\n", key);
		return 1;
	}
	else if((*bt)->key > key)
		return del(&(*bt)->lchild, key);
	else
		return del(&(*bt)->rchild, key);
} 
void inorder(BST *bt)//中序遍历
{
	if(bt!=NULL){
		inorder(bt->lchild);
		printf("%d\n",bt->key);
		inorder(bt->rchild);
	}
}
int destroy(BST *bst)//销毁
{
	if(bst == NULL){
		printf("树为空！\n");
		return 0;
	}
	while(bst){
		del(&bst, bst->key);	
	}
	free(bst);
	printf("树已摧毁！\n");
	return 1;
}