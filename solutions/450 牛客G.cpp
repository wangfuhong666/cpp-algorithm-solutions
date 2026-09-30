#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    int n;
    int m,k;
    cin>>n>>m>>k;
    vector<vector<int>>adj(n+1);
    while(m--)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool>issp(n+1,false);
    queue<int>q;
    vector<bool>score(n+1);
    vector<int>cnt(n+1,0);
    while(k--)
    {
        int a;
        cin>>a;
        issp[a] = true;
        score[a] = true;
        q.push(a);
    }
    while(!q.empty())
    {
        int p = q.front();
        q.pop();
        for(auto u:adj[p])
        {
            if(score[u])continue;
            cnt[u]++;
            if(cnt[u]>=2)
            {
                score[u] = true;
                q.push(u);
            }
        }       
    }
    vector<int>ans;
    for(int i=1;i<=n;i++)
    {
        if(issp[i])continue;
        for(auto u:adj[i])
        {
            if(score[u])
            {
                ans.push_back(i);
                break;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto u:ans)cout<<u<<' ';
    cout<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
