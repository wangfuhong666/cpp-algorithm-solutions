#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

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
        vector<long long>arr(n);
        long long ret = LLONG_MAX;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            ret = min(ret, x);
            arr[i] = ret;
        }
        vector<long long>dp(n);
        dp[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--)
        {
            if (dp[i + 1] <= arr[i])dp[i] = dp[i + 1] + 1;
            else dp[i] = dp[i + 1];
        }
        cout << dp[0] << '\n';
    }

    return 0;
}
