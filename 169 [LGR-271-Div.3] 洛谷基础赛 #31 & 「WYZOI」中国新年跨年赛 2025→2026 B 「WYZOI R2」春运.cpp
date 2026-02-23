#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long maxsize = 9e6 + 10;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<long long>pre(maxsize, 0LL);
    int n, m;
    long long d, t;
    cin >> d >> n >> m >> t;
    vector<long long>arr(n);
    for (auto& num : arr)cin >> num;
    pre[0] = 0LL;
    for (long long i = 0; i < n * m; i++)pre[i + 1] = (pre[i] + arr[(i % n - (i / m + 1) % n + n) % n]) % d;
    long long tem1 = t / (n * m);
    long long tem2 = t % (n * m);
    long long sum = pre[n * m];
    long long ans = (tem1 % d) * (sum % d) % d;
    ans = (ans + pre[tem2]) % d;
    cout << ans;
    return 0;
}
