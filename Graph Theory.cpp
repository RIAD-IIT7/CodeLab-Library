///                             Bismillahi-r-Rahmani-r-Rahim
///                                     RhIeyAaD
///                                  IIT-7th Batch,JU
#include<bits/stdc++.h>
#define ll long long int
#define fr(i,n) ;for(i=0;i<n;i++)
#define rep(i,n) for(i=1;i<=n;i++)
#define mem(x,n) memset(x,n,sizeof(x))
#define V 5
#define INF INT_MAX
using namespace std;
ll graph[9999][9999],vis[9999],ad[9999],x[9999][9999],dist[9999],X[9999]={5,4,3,2,1};

vector<int>adj[99];

///                                     Graph
void DFS(int s)
{
    if(vis[s])return ;
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
        DFS(adj[s][i]);
}

void BFS(int s)
{
    int i;
    mem(vis,0);
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        fr(i,adj[u].size())
        {
            int v=adj[u][i];
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
}

void APSP(int x[V][V])
{
    int i,j,k;
    fr(k,V)
        fr(i,V)
            fr(j,V)
            {
                if(graph[i][j] > graph[i][k]+graph[k][j])
                   graph[i][j] = graph[i][k]+graph[k][j];
            }
}

ll minimum(ll dist[],ll tree[]) /// part of Dijkstra
{
    int i,min=INF,min_index;
    fr(i,V)
    {
        if(!tree[i] && dist[i]<min)
            min=dist[i],min_index=i;
    }
    return min_index;
}
void Dijkstra(int x[V][V],int s)
{
    int u,i,j,k;

    ///Initialization
    ll dist[999],tree[999];
    fr(i,V)
        dist[i]=INF,tree[i]=0;
    dist[s]=0;

    ///Find Minimum
    fr(i,V)
    {
        u=minimum(dist,tree);
        tree[u]=1;
     ///Relaxation
        fr(k,V)
        {
            if(!tree[k] && dist[k]!=INF && graph[u][k] && dist[k]>dist[u]+graph[u][k])
                dist[k] = dist[u]+graph[u][k];
        }
    }
   // print(graph);
}
struct edg
{
    int u,v,w;
};
vector<edg>edge;
edg e;
void BellFord(int graph[][V],int s)
{
    int i,j,k;
    fr(i,V)
        dist[i]=INF;
    dist[s]=0;
    ///Relaxation with Edges
    fr(j,V-1)
        fr(i,edge.size())
        {
            if(dist[edge[i].v] > dist[edge[i].u]+edge[i].w)
                edge[i].v = dist[edge[i].u]+edge[i].w;
        }
}
int printMST(int parent[], int n, int graph[V][V])
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}
void Prims(int graph[V][V])
{
    int i,j,u;
    ll tree[V],dist[V],parent[V];
    fr(i,V)
        dist[i]=INF,tree[i]=0;
    dist[0]=0,tree[0]=-1;
    for(j=0;j<V-1;j++)
    {
        u=minimum(dist,tree);
        tree[u]=1;
        fr(i,V)
        {
            if(!tree[i] && graph[u][i] && graph[u][i]<dist[i])
                dist[i]=graph[u][i],parent[i]=u;
        }
    }
  //  printMST(parent, V, graph);
}
int main()
{
    ll a,b,c,d,i,j,k,q,r,h,l,s;
    clock_t t1,t2;
//    ///Dijkstra
//    int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
//                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
//                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
//                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
//                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
//                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
//                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
//                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
//                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
//                     };
//    Dijkstra(graph, 0);
//
//    ///BellFord
//    cin>>n>>m;
//        fr(i,m)
//        {
//            cin>>a>>b>>c;
//            x.u=a,x.v=b,x.w=c;
//            edge.pb(x);
//            x.v=a,x.u=b,x.w=c;
//            edge.pb(x);
//        }
//        cin>>s;
//        BellFord(s);
//    int p[]={1,2,3,4};
//    cout<<MatMul(p,4);
//    t1=clock();
//    fr(i,9999)
//    X[i]=rand();
    //MergeSort(0,9998);
    //t2=clock();
//    Insertion(9999);
    CountSort(5,5)
    fr(i,5)cout<<X[i]<<endl;
//    double t=(t2-t1)/(CLOCKS_PER_SEC/1000);
//    cout<<"Time: "<<t<<endl;

    return 0;
}

