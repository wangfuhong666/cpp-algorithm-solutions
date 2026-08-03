#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
const int N=3e6+10;
int p;
vector<int>inv(N);
void getinv(int n)
{
    inv[1]=1;
    for(int i=2;i<=n;i++)
    {
        inv[i]=p-1LL*(p/i)*inv[p%i]%p;
    }
}
void sol()
{
    int n;
    cin>>n>>p;
    getinv(n);
    for(int i=1;i<=n;i++)cout<<inv[i]<<'\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    sol();

    return 0;
}