#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
#define rep(x,a,b) for(int x=(a);x<(b);x++)
#define per(x,a,b) for(int x=(a);x>=(b);x--)
using vi=vector<int>;
using vl=vector<ll>;
using vb=vector<bool>;
#define pb push_back
#define eb emplace_back
#define all(x) (x).begin(),(x).end()
const int N=1e6+10;
vb isprime(N,true);
vi prime;
void getprime(int n)
{
    isprime[0]=isprime[1]=false;
    for(ll i=2;i<=n;i++)
    {
        if(isprime[i])prime.pb(i);
        for(int j=0;j<prime.size();j++)
        {
            if(prime[j]*i>n)break;
            isprime[prime[j]*i]=false;
            if(i%prime[j]==0)break;
        }
    }
}
void sol(ll n)
{
    
    rep(i,0,prime.size())
    {
        ll a=prime[i];
        if(a%2)
        {
            if(a>n)break;
            if(isprime[n-a])
            {
                cout<<n<<" = "<<a<<" + "<<n-a<<'\n';
                return;
            }
        }
    }
    cout<<"Goldbach's conjecture is wrong.\n";
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    getprime(1e6+1);
    while(1)
    {
        ll n;
        cin>>n;
        if(!n)break;
        sol(n);
    }
    return 0;
}
