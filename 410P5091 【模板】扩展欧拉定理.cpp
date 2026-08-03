#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
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
ll phi(ll n)
{
    if(n==1)return 1;
    ll ans=n;
    for(ll i=2;i<=n/i;i++)
    {
        if(n%i==0)
        {
            ans-=ans/i;
            while(n%i==0)n/=i;
        }
    }
    if(n>1)ans-=ans/n;
    return ans;
}

void sol()
{
    ll a,m;
    string b;
    cin>>a>>m>>b;
    bool fl=false;
    ll ans=0;
    ll ph=phi(m);
    for(auto &e:b)
    {
        ans=ans*10+e-'0';
        if(ans>=ph)
        {
            fl=true;
            ans%=ph;
        }
    }
    if(fl)cout<<qpow(a,ans%ph+ph,m);
    else cout<<qpow(a,ans,m);
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
