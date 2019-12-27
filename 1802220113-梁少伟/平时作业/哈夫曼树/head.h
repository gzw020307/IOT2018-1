#include"stdio.h"
#include"malloc.h"
#include"iostream"
using namespace std;


typedef int Elemtype;
typedef struct BiTNode{
	Elemtype data;
	struct BiTNode* Lchild, * Rchild;
}BiTNode ,*BiTree;



void NewTree(BiTree& T, Elemtype n);/////初始化
void InsertTree(BiTree& T, Elemtype n);//////树的元素输入
void ShowTree(BiTree& T);///////树中元素的打印
void cengci(BiTree& Root);


typedef struct node {
	BiTree data;
	struct node* next;
}node, * QueuePtr;

typedef struct {
	QueuePtr front;
	QueuePtr rear;
	int length;
}Queue;
void InitQueue(Queue& Q);//////初始化
void EnQueue(Queue& Q, BiTree e);/////入队操作
void DeQueue(Queue& Q, BiTree& e);//////出队操作
int QueueEmpty(Queue& Q);




typedef char Elemtype1;
typedef enum PointerType{Link,THread};
typedef struct BiThrNode {
	Elemtype1 data;
	struct BiThrNode* Lchild, * Rchild; 
	PointerType LTag, RTag;
}BiThrNode,*BiThrTree;
BiThrTree Insert_BiTHrTree(BiThrTree Root);//初始化
void Print_BiTHrTree(BiThrTree Root);///打印

void InThreading(BiThrTree p, BiThrTree& pre);
void InOrderThreading(BiThrTree& head, BiThrTree Root);
void read(BiThrTree t);



typedef struct {
	int weight;
	int Parent;
	int Lchild;
	int Rchild;
}THNode,*HuffmanTree;

typedef char** HuffmanNode;
void Compare(HuffmanTree ht, int n, int* p, int* q);//////比较出两个最小值
void CreateHuffmanTree(HuffmanTree ht,  int n, int* w);///////哈夫曼树的建立及编码实现