#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<int>arr(n + 1, 0);
    vector<vector<int>>dp(n + 1, vector<int>(n + 1, 0));
    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        dp[i][i] = arr[i];
        res = max(res, arr[i]);
    }
    for (int len = 2; len <= n; len++)
    {
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k < j; k++)
            {
                if (dp[i][k] && dp[i][k] == dp[k + 1][j])
                {
                    dp[i][j] = max(dp[i][j], dp[i][k] + 1);
                }
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res;
    return 0;
}
