#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=3e2+10;
vector<vector<int>>adj(N),dp(N,vector<int>(N,0));
vector<int>val(N),dfnval(N),sz(N);
int n,m;
int id=1;
int dfs(int root)
{
    int card=id++;
    dfnval[card] = val[root];
    int c=0;
    for(auto u:adj[root])
    {
        c+=dfs(u);
    }
    return sz[card] = c + 1;
}
void sol()
{
    cin>>n>>m;
    for(int i =1;i<=n;i++)
    {
        int s,k;
        cin>>k>>s;
        adj[k].push_back(i);
        val[i]=s;
    }
    m+=1;
    dfs(0);
    for(int i=id;i>=1;i--)
    {
        for(int j =1;j<=m;j++)
        {
            dp[i][j] = max(dp[i+sz[i]][j],dfnval[i] + dp[i+1][j-1]);
        }
    }
    cout<<dp[1][m];
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
