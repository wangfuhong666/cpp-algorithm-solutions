#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=1e6+10;
vector<int>inv(N,0);
void getinv(int n,int p)
{
    inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        inv[i]=p-(p/i)*inv[p%i]%p;
    }
}
void sol()
{
    
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
