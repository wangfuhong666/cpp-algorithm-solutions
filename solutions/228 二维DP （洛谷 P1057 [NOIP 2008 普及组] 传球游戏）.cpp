#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    //状态：dp[i][j]表示传i次球，球落到第j号人的方案数
    //状态转移方程：处理环要把第1号人与第n号人单独讨论
    //j = 1 dp[i][1]=dp[i-1][2]+dp[i-1][n]
    //j>2&&j<n dp[i][j]=dp[i-1][j-1]+dp[i-1][j+1]
    //j=n dp[i][n]=dp[i-1][n-1]+dp[i-1][1]
    //
    vector<vector<int>>dp(m + 1, vector<int>(n + 1, 0));
    dp[0][1] = 1;
    for (int i = 1; i <= m; i++)
    {
        dp[i][1] = dp[i - 1][2] + dp[i - 1][n];
        for (int j = 2; j < n; j++)dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        dp[i][n] = dp[i - 1][n - 1] + dp[i - 1][1];
    }
    cout << dp[m][1];
    return 0;
}
