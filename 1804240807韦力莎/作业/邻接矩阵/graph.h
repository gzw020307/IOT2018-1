#include<stdlib.h>
#include<stdio.h>
#define MaxertexNum 100
#define INFINITY 65535 
typedef int vertex; 
typedef int weighttype;
typedef char datatype;

// 图节点定义
typedef struct GNode *PtrToGnode;
struct GNode{
    int nv; //顶点数
    int ne; //边数
    weighttype G[MaxertexNum][MaxertexNum];  //邻接矩阵
    datatype Data[MaxertexNum]; //存顶点数据，若无数据，Data不出现
};
typedef PtrToGnode MGraph;  //指向图节点的指针

// 边的定义
typedef struct ENode
{
    vertex v1, v2; //有向边<v1,v2>
    weighttype weight;//权重
}*PtrToNode;
typedef PtrToNode Edge;

MGraph CreatGraph(int VertexNum);
void InsertEdge(MGraph Graph, Edge E);
MGraph BuildGraph();