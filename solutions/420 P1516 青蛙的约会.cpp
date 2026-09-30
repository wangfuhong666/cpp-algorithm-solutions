#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
ll exgcd(ll a,ll b,ll&x,ll &y)
{
    if(!b)
    {
        x=1;
        y=0;
        return a;
    }
    ll x1,y1;
    ll d=exgcd(b,a%b,x1,y1);
    x=y1;
    y=x1-a/b*y1;
    return d;
}
void sol()
{
    ll x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    ll a=n-m;
    ll b=x-y;
    if(a<0)
    {
        a=-a;
        b=-b;
    }
    ll t,k;
    ll d=exgcd(a,l,t,k);
    if(b%d)cout<<"Impossible";
    else
    {
        t = t * (b / d);
        t=(t+l/d)%(l / d);
        cout<<t;
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
