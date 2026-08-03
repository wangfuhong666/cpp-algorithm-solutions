#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;
ll qpow(ll a, ll b)
{
    ll res = 1LL;
    a %= mod;
    while (b)
    {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}
map<ll,int>mp;
void deprime(ll x)
{
    for (ll i = 2; i * i <= x; i++)
    {
        
        while (x % i == 0)
        {
            mp[i]++;
            x /= i;
        }
    }
    if (x > 1)mp[x]++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    ll x, y;
    cin >> x >> y;
    deprime(x);
    deprime(y);
    vector<ll>arr;
    arr.push_back(1);
    for (auto [a, b] : mp)
    {
        int s = arr.size();
        ll tmp = 1;
        for (int i = 1; i <= b; i++)
        {
            tmp = tmp * a;
            for (int j = 0; j < s; j++)
            {
                arr.push_back(arr[j] * tmp);
            }
        }
    }
    ll res = 0;
    for (auto a : arr)res = (res + qpow(a, a)) % mod;
    cout << res % mod;
    return 0;
}
