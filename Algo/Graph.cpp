#include<bits/stdc++.h>
vector<int>adj;
int vis[999];
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
