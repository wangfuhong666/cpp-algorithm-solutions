#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ull=unsigned long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const long long mod =1e9+7;
vector<vector<int>>adj(2026);
int gcd(int a,int b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
int lcm(int a,int b)
{
    return a/gcd(a,b)*b;
}
void start()
{
    for(int i=1;i<=2025;i++)
    {
        for(int j=1;j<=2025;j++)
        {
            if(lcm(i,j)==2025)adj[i].push_back(j);
        }
    }
}
vector<vector<ll>>mp(2026,vector<ll>(2026,-1));
//dfs（pos填上num有多少种不同的方案）
ll dfs(int pos,int num)
{
    if(mp[pos][num]!=-1)return mp[pos][num];
    if(pos==2025)return 1;
    ll res=0LL;
    for(auto e:adj[num])
    {

        res=res+dfs(pos+1,e)%mod;
    }
    return mp[pos][num]=res%mod;
}
void sol()
{
    start();
    ll res=0LL;
    for(int i=1;i<=2025;i++)res=res+dfs(1,i)%mod;
    cout<<res%mod<<endl;
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
