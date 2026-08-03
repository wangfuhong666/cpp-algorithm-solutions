#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=1e7+10;
vector<bool>ispr(N,true);
vector<int>pr;
vector<int>phi(N,0);
void getphi(ll n)
{
    ispr[0]=ispr[1]=false;
    phi[1]=1;
    for(ll i=2;i<=n;i++)
    {
        if(ispr[i])
        {
            pr.push_back(i);
            phi[i]=i-1;
        }
        for(int j=0;j<(int)pr.size();j++)
        {
            int p=pr[j];
            if(1LL*p*i>n)break;
            ispr[p*i]=false;
            if(i%p)
            {
                phi[i*p]=phi[i]*(p-1);
            }
            else
            {
                phi[i*p]=phi[i]*p;
                break;
            }
        }
    }
    
}
ll qpow(ll a,ll b,ll mod)
{
    a%=mod;
    ll res=1LL;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll dfs(ll p)
{
    if(p==1)return 0;
    return qpow(2,dfs(phi[p])+phi[p],p);
}
void sol()
{
    ll p;
    cin>>p;
    cout<<dfs(p)<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getphi(1e7+2);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
