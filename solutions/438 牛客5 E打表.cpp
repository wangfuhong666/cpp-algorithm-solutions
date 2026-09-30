#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = 998244353;
const int N=1e7+10;
vector<ll>g(N,1);
vector<vector<int>>res;
vector<int>path;
void dfs(int x,int rest)
{
    if(x==1)
    {
        if(rest<=0)return;
        path.push_back(rest);
        res.push_back(path);
        path.pop_back(); 
       return;
    }
    for(int i=2;i<=rest;i*=2)
    {
        path.push_back(i);
        dfs(x-1,rest/i);
        path.pop_back();
    }
}
void sol()
{
    g[1]=1;
    g[2]=1;
    g[4]=2;
    g[8]=3;
    g[16]=5;
    g[32]=7;
    g[64]=11;
    g[128]=13;
    unordered_map<int,int>mp;
    for(int i=2;i<=7;i++)
    {
        dfs(i,256);
    }
    unordered_set<int>st;
    st.insert(0);
    for(auto e:res)
    {
        int tem=1;
        for(auto u:e)tem*=g[u];
        st.insert(tem);
    }
    for(int i=0;;i++)
    if(!st.count(i))
    {
        cout<<i;
        break;
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
