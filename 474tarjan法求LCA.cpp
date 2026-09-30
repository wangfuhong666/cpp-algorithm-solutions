#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N = 1e6 + 10;
int fa[N];
bool vis[N];
vector<vector<int>>adj(N);
vector<vector<pii>>Q(N);
int ans[N];
int n;
void start()
{
    for(int i = 0;i <= n;i++)fa[i] = i;
}
int find(int x)
{
    if(fa[x]==x)return x;
    return fa[x] = find(fa[x]);
}
bool un(int x,int y)
{
    int fx = find(x);
    int fy = find(y);
    if(fx==fy)return false;
    fa[fx] = fy;
    return true;
}
void targin(int u)
{
    for(auto[v,id]:Q[u])
    {
        if(vis[v])
        {
            ans[id] = find(v);
        }
    }
}
void dfs(int u)
{
    vis[u] = true;
    for(auto v:adj[u])
    {
        if(vis[v])continue;
        dfs(v);
        un(v,u);
    }
    targin(u);
}
void sol()
{
    int m,s;
    cin>>n>>m>>s;
    int t = n-1;
    while(t--)
    {
        int u ,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(int i = 1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        Q[u].emplace_back(v,i);
        Q[v].emplace_back(u,i);
    }
    start();
    dfs(s);
    for(int i = 1;i<=m;i++)cout<<ans[i]<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    while(t--)sol();
    return 0;
}
