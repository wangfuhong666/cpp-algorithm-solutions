#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, w;
    cin >> n >> w;
    vector<int>arrw(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrw[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(w + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= w; j++)
        {
            dp[i][j] = dp[i - 1][j];
            if (j >= arrw[i])dp[i][j] += dp[i - 1][j - arrw[i]];
        }
    }
    if (dp[n][w] < 0)cout << 0;
    else cout << dp[n][w];
    return 0;
}
