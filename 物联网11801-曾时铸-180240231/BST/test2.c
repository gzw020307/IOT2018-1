 #include<stdio.h>
 #include "bst.h"

 int main(int argc, char const *argv[])
 {
     struct node *root = NULL;
     int n, term, i;

    printf("Enter n:\n");
    scanf("%d", &n);

    printf("Enter node:\n");
     for (i = 0; i < n; i++)
     {
         scanf("%d", &term);
         root = insert (root, term);
     }

     inOrder(root);
     printf("\n");
     preOrder(root);

     return 0;     
 }