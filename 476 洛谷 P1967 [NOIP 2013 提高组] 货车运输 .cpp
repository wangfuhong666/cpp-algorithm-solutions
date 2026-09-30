#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
#define all(x) (x).begin(), (x).end()
const int N = 1e4 + 10;
vector<vector<pii>>adj(N);
vector<int>d(N);
const int LOG = 20;
int st[N][LOG + 1];
int stmin[N][LOG + 1];
int fa[N];
bool vis[N];
int n;
struct node
{
    int u,v,w;
};

//并查集（kruskual算法及LCA要用）
void start()
{
    for(int i = 0;i <= n;i++)fa[i] = i;
    for(int j = 0; j <= LOG; j++)stmin[0][j] = INT_MAX/2;
    
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
//dp[i][j] = dp[dp[i][j - 1]][j-1]
//dp[i][j - 1]在 i 的上方
//填表顺序 up---->down left--------->right
//预处理 nlogn
void dfs(int u,int fa,int w)
{
    vis[u] = true;
    d[u] = d[fa] + 1;//为了LCA服务的
    st[u][0] = fa;
    stmin[u][0] = (fa==0?INT_MAX/2:w);
    for (int j = 1; j <= LOG; j++)
    {
    st[u][j] = st[st[u][j - 1]][j - 1];
    stmin[u][j] = min(stmin[u][j-1],stmin[st[u][j-1]][j - 1]);
    }
  for(auto [v,wx]:adj[u])
  {
    if(vis[v])continue;
    dfs(v,u,wx);
  }
}
//查找 logn
int lca(int u, int v)
{
    if(find(u)!=find(v))return -1;
    if (d[u] < d[v]) swap(u, v);

    int k = d[u] - d[v];
    int ans = INT_MAX/2;
    for (int i = LOG; i >= 0; i--)
    {
        if (k & (1 << i))
        {         
            ans = min(ans,stmin[u][i]);
            u = st[u][i];
        }
    }

    if (u == v) return ans;

    for (int i = LOG; i >= 0; i--)
    {
        if (st[u][i] != st[v][i])
        {
            ans = min(ans,stmin[u][i]);
            ans = min(ans,stmin[v][i]);
            u = st[u][i];
            v = st[v][i];
        }
    }

    return min({stmin[u][0],ans,stmin[v][0]});
}
bool cmp(node a,node b)
{
    return a.w>=b.w;
}
void sol()
{
    int m;
    cin>>n>>m;
    vector<node>edg(m);
    for(int i = 0;i < m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        edg[i] = {u,v,w};
    }
    start();
    sort(all(edg),cmp);
    for(auto[u,v,w]:edg)
    {
        if(un(u,v))
        {
            adj[u].emplace_back(v,w);
            adj[v].emplace_back(u,w);
        }
    }
    for(int i = 1;i <= n;i++)
    {
        if(vis[i])continue;
        dfs(i,0,0);
    }
    int q;
    cin>>q;
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        cout<<lca(x,y)<<'\n';
    }
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
