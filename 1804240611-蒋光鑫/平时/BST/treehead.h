#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int n);
struct node *insert(struct node *root, int n);
void inOrder(struct node *root);
void preOrder(struct node *root);
struct node *deletet(struct node *root, int n);
struct node *maxValue(struct node *root);
