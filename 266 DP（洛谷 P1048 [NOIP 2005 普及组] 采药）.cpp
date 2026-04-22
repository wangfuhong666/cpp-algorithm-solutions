#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t, n;
    cin >> t >> n;
    vector<int>arrt(n + 1, 0),arrw(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrt[i] >> arrw[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(t + 1, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= t; j++)
        {
            long long ret = dp[i - 1][j];
            if (j >= arrt[i])ret = max(ret, arrw[i] + dp[i - 1][j - arrt[i]]);
            dp[i][j] = ret;
        }
    }
    cout << dp[n][t];
    return 0;
}
