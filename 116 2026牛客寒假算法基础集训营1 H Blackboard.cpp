#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>

using namespace std;
const long long mod = 998244353;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<long long>arr(n + 1);
        for (int i = 1; i <= n; i++)cin >> arr[i];
        vector<long long>dp(n + 1, 0), pre(n + 1, 0);
        dp[0] = 1LL;
        pre[0] = 1LL;
        int l = 1, r = 1;
        long long sumor = 0LL;
        while (r <= n)
        {
            while ((l <= r) && (sumor & arr[r]) != 0)sumor ^= arr[l++];
            sumor |= arr[r];
            long long tem = pre[r - 1];
            if (l >= 2)tem = (tem - pre[l - 2] + mod) % mod;
            dp[r] = tem; pre[r] = (pre[r - 1] + dp[r]) % mod;
            r++;
        }
        cout << dp[n] << endl;
    }
    return 0;
}