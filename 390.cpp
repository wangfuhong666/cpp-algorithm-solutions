#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define rep(x,a,b) for(int x=(a);x<(b);x++)
#define per(x,a,b) for(int x=(a);x>=(b);x--)
using vi=vector<int>;
using vl=vector<ll>;
using vb=vector<bool>;
#define pb push_back
#define eb emplace_back
const int N=1e5+10;
vi path;
vi adj[N];
int n;
vb vis(N,false);
bool fl=false;
void dfs(int u)
{
    if(vis[u])return;
    path.pb(u);
    vis[u]=true;
    if(u==n)
    {
        fl=true;
        int m=path.size();
        rep(i,0,m)cout<<path[i]<<" \n"[i==m-1];
    }
    for(auto e:adj[u])
    {
        if(vis[e])continue;
        dfs(e);
    }
    vis[u]=false;
    path.pop_back();

}
void sol()
{
    int m;
    cin>>n>>m;
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].pb(v);
    }
    dfs(1);
    if(!fl)cout<<"-1\n";
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
