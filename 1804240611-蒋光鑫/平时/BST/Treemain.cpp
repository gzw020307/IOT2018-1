#include"treehead.h"
int main()
{
	int i;
    struct node *root = NULL;
    int term, n;
    
    printf("Enter n:\n");
    scanf("%d", &n);

    printf("Enter node:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &term);
        root = insert(root, term);
    }


    inOrder(root);
    printf("\n");
   for (i = 0; i < n; i++)
    {
        scanf("%d", &term);
        root = deletet(root, term);
        inOrder(root); 
        printf("\n");
    }
    return 0;
}