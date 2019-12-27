#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<map>
#include<cstring>
#include<string>
#include<set>
#include<queue>
#include<fstream>
using namespace std;
typedef pair<int,int> PII;
const int MAXN=1e4+5;
const int INF=0x3f3f3f3f;
bool vis[MAXN];
int dist[MAXN],head[MAXN],tot;
int pre[MAXN];

struct Edge
{
    int from,to,cost,nxt;
    Edge(){}
    Edge(int _from,int _to,int _cost):from(_from),to(_to),cost(_cost){}
}e[MAXN*2];

void addedge(int u,int v,int w)
{
    e[tot].from=u;e[tot].to=v;e[tot].cost=w;
    e[tot].nxt=head[u];head[u]=tot++;
}

struct qnode
{
    int c,v;
    qnode(int _c=0,int _v=0):c(_c),v(_v){}
    bool operator < (const qnode &rhs) const {return c>rhs.c;}
};

void Dijkstra(int n,int st)//点的编号从1开始
{
    memset(vis,false,sizeof(vis));
    for(int i=0;i<=n;i++) dist[i]=INF;
    priority_queue<qnode> pq;
    while(!pq.empty()) pq.pop();
    dist[st]=0;
    pq.push(qnode(0,st));
    qnode frt;
    while(!pq.empty())
    {
        frt=pq.top(); pq.pop();
        int u=frt.v;
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=head[u];i!=-1;i=e[i].nxt)
        {
            int to=e[i].to;
            int cost=e[i].cost;
            if(dist[to]>dist[u]+cost)
            {
                dist[to]=dist[u]+cost;
                pre[to]=u;
                pq.push(qnode(dist[to],to));
            }
        }
    }
}

int main()
{
    int vN,eN;
    while(scanf("%d%d",&vN,&eN)!=EOF)
    {
        if(vN==0&&eN==0) break;
        tot=0;memset(head,-1,sizeof(head));
        int u,v,w;
        for(int i=1;i<=eN;i++)
        {
            scanf("%d%d%d",&u,&v,&w);
            addedge(u,v,w);addedge(v,u,w);
        }
        int st,ed;
        scanf("%d%d",&st,&ed);
        //if(st==ed) {printf("0\n");continue;}
        Dijkstra(vN,st);
//        for(int i=0;i<=vN-1;i++)
//            printf("%d ",dist[i]);
//        printf("\n");
//        for(int i=0;i<=vN-1;i++)
//            printf("%d ",pre[i]);
//        printf("\n");
        if(dist[ed]!=INF)  printf("%d\n",dist[ed]);
        else printf("-1\n");
    }
    return 0;
}

