#include<bits/stdc++.h>
vector<int>adj;
int vis[999];


///                         Articulation Graph
set<ll>ans;
void DFS(ll in,ll par)
{
    en[in]=mn[in]=cnt++;
    vis[in]=1;
    ll p=0,a,i,l=v[in].size();
    fr(i,l)
    {
        ll to=v[in][i];
        if(to==-1)continue;
        if(!vis[to])
        {
            DFS(to,in);
            p++;
            mn[in]=min(mn[in],mn[to]);
            if(par!=-1 && en[in]<=mn[to])
            ans.insert(in);
        }
        else
            mn[in]=min(mn[in],en[to]);
    }
    if(par==-1 && p>1)
        ans.insert(in);
}
    rep(i,n)
        {
            if(!vis[i])
                DFS(i,-1);
        }
///
void BFS(int s)
{
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(s);
    vis[s]=1;
    while(!q.empty())
    {
        int v=q.front();
        q.pop();
        for(int i=0;i<adj[v].size();i++)
        {
            int u=adj[v][i];
            if(vis[u]==0)
            {
                q.push(u);
                vis[u]=1;
            }
        }
    }
}

void DFS(int s)
{
    if(vis[s])return ;
    vis[s]=1;
    for(int i=0;i<adj[s].size();i++)
        DFS(adj[s][i]);
}
int main()
{

    return 0;
}
