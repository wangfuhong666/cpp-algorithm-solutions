#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
unordered_map<ll, ll>mp;
ll dfs(ll x)
{
    if (x < 2)return mp[x] = 0;
    if (mp.count(x))return mp[x];
    return mp[x] = x + dfs(x / 2) + dfs((x + 1) / 2);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll n;
    cin >> n;
    cout << dfs(n);

    return 0;
}
