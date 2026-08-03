#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const ll mod = 998244353;
const int N=1e7+10;
vector<bool>isprime(N,true);
vector<int>prime;
vector<int>f(N,0);
void start()
{
    isprime[0]=isprime[1]=false;
    f[1]=1;
    for(ll i=2;i<N;i++)
    {
        if(isprime[i])
        {
            prime.push_back(i);
            f[i]=1;
        }
        for(int j=0;j<(int)prime.size();j++)
        {
            if(i*prime[j]>=N)break;
            isprime[i*prime[j]]=false;
            f[i*prime[j]]=f[i]+1;
            if(i%prime[j]==0)break;
        }
    }
}
void sol()
{
    int n,c;
    cin>>n>>c;
    ll tem=1;
    ll sum=0;
    for(int i=1;i<=n;i++)
    {
        tem=tem*c%mod;
        if(i==1||isprime[i])
        {
            sum=(sum+tem)%mod;
        }
        else sum=(sum+prime[f[i]-2]%mod*tem%mod)%mod;
    }
    cout<<sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    //cin>>t;
    start();
    while(t--)sol();
    return 0;
}
