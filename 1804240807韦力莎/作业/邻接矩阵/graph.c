#include"graph.h"


MGraph CreatGraph(int VertexNum)
{//初始化一个有VertexNum个顶点但没有边的图
    vertex V,W;
    MGraph Graph;

    Graph=(MGraph)malloc(sizeof(struct GNode)); //建立图
    Graph->nv = VertexNum;
    Graph->ne = 0;;

    /*初始化邻接矩阵 默认顶点编号从0开始到 Graph->nv-1*/
    for(V=0; V<Graph->nv; V++)
        for ( W = 0; W < Graph->nv; W++)
        {
            Graph->G[V][W] = INFINITY;
        }        
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    //插入边
    Graph->ne[E->v1][E->v2] = E->weight;
    //若为无向图，还要插入边<v2,v1>
    Graph->ne[E->v2][E->v1] = E->weight;
}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    vertex V;
    int Nv,i;
    scanf("%d",&Nv);//读入顶点个数
    Graph=CreatGraph(Nv);  //初始化有Nv个顶点但无边的图

    scanf("%d",&Graph->ne); //读入边
    if(Graph->ne!=0){
        E=(Edge)malloc(sizeof(struct ENode)); //建立边结点
        for(i=0;i<Graph->ne;i++){
            scanf("%d%d%d",&E->v1,&E->v2,&E->weight);
            InsertEdge(Graph, E);
        }
    }
    //若顶点有数据，读入数据
    for(V=0;V=Graph->nv;V++){
        scanf("%c",&(Graph->Data[V]));
    }

    return Graph;
}



