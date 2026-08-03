#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
void sol()
{
    ll n, m;
    cin >> n >> m;
    ll k = min(n, m + 1);
    ll ans = k * (k - 1) / 2 - m;
    cout << ans << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)sol();
    return 0;
}
