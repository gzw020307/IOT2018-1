#include "bst.h"  // 多.c文件的使用
#include <stdlib.h>//库函数的头文件吧，好像是我也不是很记得

struct node *newNode(int n) //创建二叉树
{
    struct node *p = (struct node *)malloc(sizeof(struct node));//申请一个存储结点p的空间
    if (p == NULL) //如果结点值为空
    {
        printf("Error!\n");// 输出error 报错
        exit(-1); //返回-1
    }
    p->key = n;  //生成根结点
    p->left = p->right = NULL; //左右子树都为空
    return p;
}

struct node *insert(struct node *root, int n)  //在bst树中插入关键字
{
    if (root == NULL) //若根结点为空
    {
        return newNode(n);//将新结点作为根结点返回
    }
    if (root->key > n)//若根结点大于插入值
    {
        root->left = insert(root->left, n);//将该值作为根结点的左子树插入
    }
    else if (root->key < n)//若根结点小于插入值
    {
        root->right = insert(root->right, n);//将该值作为根结点的右子树插入
    }
    else
    {
        return root;//返回根结点值
    }
}

void inOrder(struct node *root)//中序遍历（嵌套 调用自身）
{
    if (root != NULL)//若根结点不为空
    {
        inOrder(root->left);//中序遍历左子树
        printf("%d ", root->key);//输出根结点
        inOrder(root->right);//中序遍历右子树
    }
}

void preOrder(struct node *root)//先序遍历（嵌套 调用自身）
{
    if (root != NULL)//若根结点不为空
    {
        printf("%d ", root->key);//输出根结点
        preOrder(root->left);//先序遍历左子树
        preOrder(root->right);/先序遍历右子树
    }
}

void postOrder(struct node *root)//后序遍历（嵌套 调用自身）
{
    if (root != NULL)//若根结点不为空
    {
        postOrder(root->left);//后序遍历左子树
        postOrder(root->right);//后序遍历右子树
        printf("%d ", root->key);//输出根结点
    }
}
struct node *maxValue(struct node *root)//查找最大关键字
{
    struct node *p;//定义指针p
    if(root == NULL)//若根结点为空
    {
        return root;//返回根结点
    }
    p = root;//p指向根结点
    while (p->right)//当p指向右子树时成立（就是说只要根结点p有右子树就执行这个循环）
    {
        p = p->right;//把右子树的值赋给p（bst树的特点是左子树小于根结点，右子树大于根结点，所以找最大值，就是找最后一个右子树）
    }
    return p; //返回p为最大关键字 
    
    
}


struct node *delete(struct node *root, int n)//删除关键字（跟插入原理是一样的，都是比较根结点和要删除的关键字的大小，比根结点大，就删右子树，比它小，就删左子树）
{
    if (root == NULL)//根结点为空
    {
        return root;//返回根结点
    }
    if (n < root->key)//若要删除的值n小于根结点
    {
        root->left = delete(root->left, n);//则删除根结点的左子树
    }
    else if (n > root->key)//若要删除的值n大于根结点
    {
        root->right = delete(root->right, n);//则删除根结点的右子树
    }
    else
    {
        if(root->left == NULL)//若根结点左子树为空
       {
            struct node *tmp = root->right;//把右子树赋给tmp
            free(root);//释放根结点值
            return tmp;//返回tmp
        }
        if(root->right == NULL)//若根结点右子树为空
       {
            struct node *tmp = root->left;把左子树赋给tmp
            free(root);//释放根结点值
            return tmp;//返回tmp
        }

        struct node *tmp = maxValue(root->left);//左子树中的最大值赋给tmp
        root->key = tmp->key;//tmp的值赋给根结点
        root->left = delete(root->left, tmp->key);//删除tmp（其实就是删除根结点，然后把左子树的最大值作为新的根结点返回，还有一种写法是把右子树的最小值作为新的根结点返回，都差不多的）
    }
    return root; //返回根结点
}
