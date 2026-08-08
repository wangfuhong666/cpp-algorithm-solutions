#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=305;
int n,m;
vector<vector<int>>adj(N);
vector<int>score(N);
int dp[N][N][N];
void start()
{
    for(int i=0;i<N;i++)
        for(int j = 0;j<N;j++)
            for(int k = 0;k<N;k++)
                dp[i][j][k] = -1;
}
int dfs(int i,int j,int k)
{
    if(k==0)return dp[i][j][k] = 0;
    if(dp[i][j][k]!=-1)return dp[i][j][k];
    if(j==0||k==1)return dp[i][j][k] = score[i];
    int ans=dfs(i,j-1,k);
    int v=adj[i][j-1];
    for(int s = 1;s<k;s++)
        ans=max(ans,dfs(i,j-1,k-s)+dfs(v,adj[v].size(),s));
    return dp[i][j][k] = ans;
}
void sol()
{
    start();
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
    {
        int s,k;
        cin>>k>>s;
        adj[k].push_back(i);
        score[i]=s;
    }
    cout<<dfs(0,adj[0].size(),m+1);
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
