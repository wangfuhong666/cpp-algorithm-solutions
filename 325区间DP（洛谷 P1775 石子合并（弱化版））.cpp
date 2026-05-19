#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    vector<int>arr(n + 1, 0);
   vector<long long>pre(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        pre[i] = pre[i - 1] + arr[i];
    }
    vector<vector<long long>>dp(n + 1, vector<long long>(n + 1, LLONG_MAX / 2));
    for (int i = 0; i <= n; i++)dp[i][i] = 0;
    for(int len=2;len<=n;len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            long long sum = pre[j] - pre[i - 1];
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][k] + dp[k + 1][j] + sum, dp[i][j]);
            }
        }
    }
    cout << dp[1][n];
    return 0;
}
