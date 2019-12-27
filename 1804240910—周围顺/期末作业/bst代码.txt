#include <stdio.h>
#include <stdlib.h>
 
typedef struct tagBST
{
    struct tagBST *lchild;
    struct tagBST *rchild;
    int val;
    int height; //高度
}BST;
 
//生成结点
BST *makeNode(int key)
{
    BST *pBST = (BST*)malloc(sizeof(BST));
    pBST->lchild = NULL;
    pBST->rchild = NULL;
    pBST->height = 1;
    pBST->val = key;
    return pBST;
}
//获取BST树的高度
int getHeight(BST *root)
{
    return (root == NULL)? 0: root->height;
}
 
int max(int a, int b)
{
    return a > b ? a : b;
}
 
//在树中新增一个结点
BST *insertNode(BST *root, int key)
{
    if (root == NULL)
    {
        return makeNode(key);
    }
 
    if (root->val == key)
    {
        return root;
    }
    else if (key < root->val) //插入的值比根节点小，插入左子树
    {
        root->lchild = insertNode(root->lchild ,key);
    }
    else
    {
        root->rchild = insertNode(root->rchild, key);
    }
//递归函数后面的求值，一般是自底向上一层层计算，这里从根节点开始计算高度
 
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
 
    return root;
 
}
 
BST *removeNode(BST *root, int key)
{
    if (root == NULL)
    {
        return NULL;
    }
 
    if (key == root->val)
    {
        if(root->rchild == NULL)
        {
            BST* temp = root;
            root = root->lchild;
            free(temp);
            return root;
        }
        else
        {
            BST* temp = root->rchild;
            while(temp->lchild)
            {
                temp = temp->lchild;
            }
            root->val = temp->val;
            root->rchild = removeNode(root->rchild, temp->val);
        }
    }
    else if (key < root->val)
    {
        root->lchild = removeNode(root->lchild, key);
    }
    else
    {
        root->rchild = removeNode(root->rchild, key);
    }
    root->height = max(getHeight(root->lchild), getHeight(root->rchild)) + 1;
    return root;
}
//遍历所有元素，默认是排序好的
void traverse(BST *root)
{
    if (root == NULL)//假设已经到栈底，一般设为叶子结点的孩子
    {
        return;
    }
 
    traverse(root->lchild);
    printf("结点: %d; 深度: %d\n", root->val, root->height);
    traverse(root->rchild);
 
}
 
void print_tree_indent(BST *node, int indent)
{
    for (int ix = 0; ix < indent; ix++)
    {
        printf(" ");
    }
    if (node == NULL)
    {
        printf("空孩子结点\n");
    }
    else
    {
        printf("结点: %d; 深度: %d\n", node->val, node->height);
        print_tree_indent(node->lchild, indent + 4);
        print_tree_indent(node->rchild, indent + 4);
    }
}
 
void print_tree(BST *node)
{
    print_tree_indent(node, 0);
}
int main(void)
{
    BST* root = NULL;
    int arr[] = {15, 6, 18, 3, 7, 17, 20, 2, 4, 13, 9};
 
    const int length = sizeof(arr) / sizeof(int);
    for(int i = 0; i< length;i++)
    {
        root = insertNode(root, arr[i]);
    }
 
    root = removeNode(root, 7);
 
    printf("打印BST树:\n");
    print_tree(root);
    printf("==================================\n");
    traverse(root);
}