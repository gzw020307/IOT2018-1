#ifndef BST_H
#define BST_H

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int n);
struct node *insert(struct node *root, int n);
void inOrder(struct node *root);

#endif