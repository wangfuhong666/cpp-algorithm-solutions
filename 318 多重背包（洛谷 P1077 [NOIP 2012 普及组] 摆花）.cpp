#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const long long mod = 1e6 + 7;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int>arrc(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrc[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(m + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= arrc[i]&&j-k>=0; k++)dp[i][j] = (dp[i][j] + dp[i - 1][j - k]) % mod;
        }
    }
    cout << dp[n][m];
    return 0;
}
