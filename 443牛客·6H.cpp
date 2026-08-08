#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
bool ispr(int x)
{
    if(x<2)return false;
    for(int i=2;(ll)i*i<=x;i++)if(x%i==0)return false;
    return true;
}
void sol()
{
    int n;
    cin>>n;
    if(!ispr(n-1))
    {
        for(int i = 1;i<=n;i++)cout<<i<<' ';
        cout<<'\n';
        return;
    }
    if(n<8)
    {
        cout<<"-1\n";
        return;
    }
    for(int i = 1;i<=n-4;i++)cout<<i<<' ';
    for(int i = n;i>=n-3;i--)cout<<i<<' ';
    cout<<'\n';

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
