#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
vector<vector<int>>adj(N);
int n;
vector<int>d(N);
const int LOG = 20;
int st[N][LOG + 1];
//dp[i][j] = dp[dp[i][j - 1]][j-1]
//dp[i][j - 1]在 i 的上方
//填表顺序 up---->down left--------->right
//预处理 nlogn
void dfs(int u,int fa)
{
  d[u] = d[fa] + 1;//为了LCA服务的
  st[u][0] = fa;
  for (int j = 1; j <= LOG; j++)
  {
    st[u][j] = st[st[u][j - 1]][j - 1];
  }
  for(auto v:adj[u])
  {
    if(v==fa)continue;
    dfs(v,u);
  }
}
//查找 logn
int lca(int u, int v)
{
    if (d[u] < d[v]) swap(u, v);

    int k = d[u] - d[v];

    for (int i = LOG; i >= 0; i--)
    {
        if (k & (1 << i))
        {
            u = st[u][i];
        }
    }

    if (u == v) return u;

    for (int i = LOG; i >= 0; i--)
    {
        if (st[u][i] != st[v][i])
        {
            u = st[u][i];
            v = st[v][i];
        }
    }

    return st[u][0];
}
bool cmp(int a,int b)
{
    return d[a]>=d[b];
}
void sol()
{
    int m;
    cin>>n>>m;
    int t = n-1;
    while(t--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1,0);

    while(m--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        int a[3];
        a[0] = lca(x,y);
        a[1] = lca(y,z);
        a[2] = lca(x,z);
        sort(a,a+3,cmp);
        int d1 = d[x] - 1;
        int d2 = d[y] - 1;
        int d3 = d[z] - 1;
        int d4 = d[a[0]] - 1;
        int d5 = d[a[2]] - 1;
        cout<<a[0]<<" "<<d1 + d2 +d3 - d4 - 2*d5<<'\n';
    }
}
int main()
{

  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int t = 1;
  //cin>>t;
  while(t--)sol();
  return 0;
}