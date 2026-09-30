#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = 1e9+7;
ll qpow(ll a,ll b)
{
    ll res=1LL;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res;
}
ll divimod(ll a,ll b)
{
    return a*qpow(b,mod-2)%mod;
}
void sol(ll n)
{
    n%=mod;
    ll p=n*(n+1)%mod*(2*n+1)%mod;
    cout<<divimod(p%mod,6)<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;  
    while(cin>>n)sol(n);
    return 0;
}
