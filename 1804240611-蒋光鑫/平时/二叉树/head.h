#include <iostream>
#include<cstdio>
#include<cstdlib>

using namespace std;

typedef int TelemType;

typedef struct BinaryTreeNode
{
	TelemType data;
	struct BinaryTreeNode* Left;
	struct BinaryTreeNode* Right;
}Node; 

Node* createBinaryTree();
void preOrderTraverse(Node* root);
void inOrderTraverse(Node* root);
void lastOrderTraverse(Node* root);
