#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
vector<vector<int>>adj(N);
int n;
vector<int>d(N);
const int LOG = 20;
int st[N][LOG + 1];
void dfs(int u,int fa)
{
  d[u] = d[fa] + 1;
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
int query(int u, int k)
{
  if(d[u]<=k)return -1;
  for (int i = LOG; i >= 0; i--)
  {
    if (k & (1 << i))
    {
      u = st[u][i];
    }
  }

  return u;
}
void sol()
{
  cin>>n;
  int m = n-1;

  int q;
  cin>>q;
  while(m--)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1,0);
  while(q--)
  {
    int u,k;
    cin>>u>>k;
    cout<<query(u,k)<<'\n';
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