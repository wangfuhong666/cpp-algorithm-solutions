#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long qpow(long long a, long long b)
{
    a %= mod;
    long long res = 1LL;
    while (b)
    {
        if (b & 1)res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
long long divimod(long long a, long long b)
{
    a %= mod;
    return a * qpow(b, mod - 2) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k, m, q;
    cin >> n >> k >> m >> q;
    cout << k * divimod(n - m, n) % mod;

    return 0;
}
