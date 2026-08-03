#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod =998244353;
const int N =2000000+10;
ll qpow(ll a,ll b)
{
    ll res=1LL;
    a%=mod;
    while(b)
    {
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1;
    }
    return res%mod;
}
ll divimod(ll a,ll b)
{
    return a%mod*qpow(b,mod-2)%mod;
}
vector<ll>f(N),inv(N);
void start()
{
    f[0] = 1;
    for(int i = 1; i <N; i++)
    {
        f[i] = f[i - 1] * i % mod;
    }
    inv[N-1] = qpow(f[N-1], mod - 2);
    for(int i = N - 2; i >= 0; i--)
    {
        inv[i] = (i + 1) * inv[i + 1] % mod;
    }
}

ll C(ll n, ll m)
{
    if(n < m) return 0;
    return f[n] * inv[n - m] % mod* inv[m] % mod;
}

void sol()
{
    ll n,m,c,a,b;
    cin>>n>>m>>c>>a>>b;
    if(m-n<0||(m-n)%c!=0)
    {
        cout<<"0\n";
        return;
    }
    ll k=(m-n)/c;
    cout<<(divimod(n,m)%mod*C(m,k)%mod*qpow(divimod(a,b),k)%mod*qpow(divimod(b-a,b),m-k))%mod<<'\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    start();
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
