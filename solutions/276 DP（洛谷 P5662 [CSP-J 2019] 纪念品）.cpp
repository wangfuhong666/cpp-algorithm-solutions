#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T, n, m;
    cin >> T >> n >> m;
    vector<vector<int>>arr(T + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= T; i++) for (int j = 1; j <= n; j++)  cin >> arr[i][j];
    long long ans = m;
    for (int i = 1; i < T; i++)
    {
        vector<vector<long long>> dp(n + 1, vector<long long>(ans + 1, 0));
        for (int k = 0; k <= ans; k++) dp[0][k] = k;
        for (int j = 1; j <= n; j++)
        {
           
            for (int k = ans; k >= 0; k--)
            {
                dp[j][k] = dp[j - 1][k];
                if (k + arr[i][j] <=ans)dp[j][k] = max(dp[j][k], dp[j][k + arr[i][j]] + arr[i + 1][j] - arr[i][j]);
            }
        }
        long long tem = 0;
        for (int k = 0; k <= ans; k++)tem = max(tem, dp[n][k]);
        ans = tem;

    }
    cout << ans;
    return 0;
}
