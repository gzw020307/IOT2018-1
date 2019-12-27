#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct bstnode{
	int key;
	struct bstnode *left;
	struct bstnode *right;
}bstnode,*bstree;
bstree insert(bstree tree,int key);
bstree create();
bstree search(bstree tree,int key);
void traverse(bstree tree);
bstree Delete(bstree tree,int key);


bstree create()
{
	int key;
	bstree tree=NULL;
	scanf("%d",&key);
	while(key!=0)
	{
		tree=insert(tree,key);
		scanf("%d",&key);
	}
	return tree;
}


bstree insert(bstree tree,int key)
{
	bstree p=tree;
	bstree s,f;
	while(p!=NULL)
	{
		f=p;
		if(key==p->key)
			return tree;
		if(key<p->key)
			p=p->left;
		else
			p=p->right;
	}
	s=(bstree)malloc(sizeof(bstnode));
	s->key=key;
	s->left=NULL;
	s->right=NULL;
	if(tree==NULL)
		return s;
	if(key<f->key)
		f->left=s;
	else
		f->right=s;
	return tree;
}

bstree search(bstree tree,int key)
{
	bstree p=tree;
	int flag=0;
	while(p!=NULL)
	{
		if(p->key==key)
		{
			printf("已查询到该结点");
			flag=1;
			return (p);
			break;
		}
		if(key<p->key)
			p=p->left;
		else
			p=p->right;
	}
	if(flag==0)
	{
		printf("查询不到关键字为%d的结点",key);
		return NULL;
	}

}

void traverse(bstree tree)
{
	if(tree)
	{
		traverse(tree->left);
		printf("%4d",tree->key);
		traverse(tree->right);

	}
}
bstree Delete(bstree tree,int key)
{
	bstree p=tree;
	bstree f,s,q;
	f=NULL;
	while(p)
	{
		if(p->key==key)
			break;
		if(p->key>key)
			p=p->left;
		else
			p=p->right;
	}
	if(p==NULL)
		return tree;
	if((p->left==NULL)||(p->right==NULL))
	{
		if(f==NULL)
			if(p->left==NULL)
				tree=p->right;
			else tree=p->left;
		else if(p->left==NULL)
			if(f->left==p)
				f->left=p->right;
			else f->right=p->right;
			else if(f->left==p)
				f->left=p->left;
			else f->left=p->left;
			free(p);

	}
	else{
		q=p;
		s=p->left;
		while(s->right)
		{
			q=s;
			s=s->right;
		}
		if(q==p)
			q->left=s->left;
		p->key=s->key;
		free(s);
	}
	return tree;
}

void main()
{
	bstree tree,p;
	int key1,key2,key3;
	int select,flag;
	printf("#####################################\n");
	printf("|*        *1.创建二叉排序树        *|\n");
	printf("|*        *2.插入                  *|\n");
	printf("|*        *3.查找                  *|\n");
	printf("|*        *4.遍历                  *|\n");
	printf("|*        *5.删除                  *|\n");
	printf("|*        *6.退出                  *|\n");
	printf("*************************************\n");
	while(select!=6)
	{
		printf("请选择功能");
		scanf("%d",&select);
		switch(select)
		{
		case 1:
			printf("请输入结点信息（输入0停止）");
			tree=create();
			printf("\n");
			break;
		case 2:
			printf("插入一个新的结点：");
			scanf("%d",&key1);
			insert(tree,key1);
			printf("插入后的序列为：\n");
			traverse(tree);
			printf("\n");
			break;
		case 3:
			printf("请输入查找的数据:");
			scanf("%d",&key2);
			p=search(tree,key2);
			printf("\n");
			break;

		case 4:
			printf("遍历所得序列为：");
			traverse(tree);
			printf("\n");
			break;
		case 5:
			printf("请输入删除的数据：");
			scanf("%d",&key3);
			tree=Delete(tree,key3);
			printf("删除后的序列为:\n");
			traverse(tree);
			printf("\n");
			break;
		case 6:
			printf("感谢使用！！！");
			flag=0;
			break;
		default:printf("输入错误，请重新输入");
			break;


		}
	}
}
