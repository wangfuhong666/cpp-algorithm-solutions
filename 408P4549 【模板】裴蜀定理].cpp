#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
ll gcd(ll a,ll b)
{
    a=llabs(a);
    b=llabs(b);
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}
void sol()
{
    int n;
    cin>>n;
    n--;
    ll res;
    cin>>res;
    while(n--)
    {
        ll x;
        cin>>x;
        res=gcd(res,x);
    }
    cout<<res<<'\n';
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
