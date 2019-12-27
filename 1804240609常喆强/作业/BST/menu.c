#include <stdio.h>

#include "bst.h"

int main(int argc, char const *argv[])
{
    struct node *root = NULL;
    int term, n,m,k;
    
    printf("请输入你要插入的节点个数:\n");
    scanf("%d", &n);

    printf("Enter node:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &term);
        root = insert(root, term);
    }


    inOrder(root); 
    printf("\n");
   /*
    printf("%d\n", maxValue(root)->key);
    printf("\n");
*/

    printf("请输入你要删除的节点个数:\n");
    scanf("%d",&m);
    printf("请输入你要删除的节点:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &term);
        root = delete(root, term);
        inOrder(root); 
        printf("\n");
    }

    printf("请输入你要插入的节点个数:\n");
    scanf("%d",&k);
    printf("请输入你要插入的节点:\n");
    for (int i = 0; i < k; i++)
    {
        scanf("%d", &term);
        root = insert(root, term);
        inOrder(root); 
        printf("\n");
    }

    printf("请输入你要修改的元素是:\n");
        scanf("%d", &term);
        root = delete(root, term);
        printf("您要将其修改为:\n");
        scanf("%d", &term);
        root = insert(root, term);
        inOrder(root); 
        printf("\n");
    return 0;
}
