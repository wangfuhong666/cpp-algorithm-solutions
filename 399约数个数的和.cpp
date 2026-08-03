#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pii=pair<int,int>;
void sol()
{
    ll n;
    cin>>n;
    ll sum=0;
    for(ll i=1;i<=n/2;i++)sum+=n/i;
    sum+=n-n/2;
    cout<<sum;
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
