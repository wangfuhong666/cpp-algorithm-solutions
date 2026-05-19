#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 10;
vector<bool>isprime(N, true);
void getprime(int n)
{
    isprime[0] = isprime[1] = false;
    for (ll i = 2; i * i <= n; i++)
    {
        if (!isprime[i])continue;
        for (ll j = i * i; j <= n; j += i)isprime[j] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    getprime(n);

    return 0;
}
