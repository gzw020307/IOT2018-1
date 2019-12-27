#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef long long LL;
const double eps=1e-8;
const int MAXN=1005;
const int INF=0x3f3f3f3f;
int pre[MAXN],dist[MAXN];
int cnt[MAXN],a[MAXN],peo[MAXN];
bool vis[MAXN];

struct Edge{
    int v,w;
    Edge(int _v=0,int _w=0):v(_v),w(_w){}
};
vector<Edge> g[MAXN];

struct QNode{
    int v,d;
    QNode(int _v=0,int _d=0):v(_v),d(_d){}
    bool operator < (const QNode &rhs) const{
        return d>rhs.d;
    }
};

void Init(int n){
    for(int i=0;i<=n;i++){
        g[i].clear();
        cnt[i]=0;peo[i]=0;
        pre[i]=-1;dist[i]=INF;
        vis[i]=false;
    }
}

int Dijkstra(int s){
    priority_queue<QNode> q;
    while(!q.empty()) q.pop();
    dist[s]=0;cnt[s]=1;peo[s]=a[s];
    q.push(QNode(s,0));
    QNode frt;
    while(!q.empty()){
        frt=q.top();
        q.pop();
        int u=frt.v;
        if(vis[u]) continue;
        vis[u]=true;
        int sz=g[u].size();
        for(int i=0;i<sz;i++){
            int v=g[u][i].v;
            int cost=g[u][i].w;
            if(dist[v]>dist[u]+cost){
                dist[v]=dist[u]+cost;
                pre[v]=u;
                cnt[v]=cnt[u];
                peo[v]=peo[u]+a[v];
                q.push(QNode(v,dist[v]));
            }else if(dist[v]==dist[u]+cost){
                if(peo[v]<peo[u]+a[v]){
                    pre[v]=u;
                    peo[v]=peo[u]+a[v];
                }
                cnt[v]+=cnt[u];
            }
        }
    }
}

void dfs(int s,int u){
    if(u==s) printf("%d",s);
    else{
        dfs(s,pre[u]);
        printf(" %d",u);
    }
}

int main(){
    int n,m,s,d;
    while(scanf("%d%d%d%d",&n,&m,&s,&d)!=EOF){
        Init(n);
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
        }
        int u,v,w;
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            g[u].push_back(Edge(v,w));
            g[v].push_back(Edge(u,w));
        }
        Dijkstra(s);
        printf("%d %d\n",cnt[d],peo[d]);
        dfs(s,d);
        printf("\n");
    }
    return 0;
}

