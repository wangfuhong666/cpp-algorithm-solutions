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
    vector<int>arrx(n + 1, 0), arrw(n + 1, 0), arrv(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrx[i] >> arrw[i] >> arrv[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(w + 1));
    for (int i = 1; i <= n; i++)for (int j = 0; j <= w; j++)for (int k = 0; k <= arrx[i] && j - k * arrw[i] >= 0; k++)dp[i][j] = max(dp[i][j], dp[i - 1][j - k * arrw[i]] + k * arrv[i]);
    cout << dp[n][w];
    return 0;
}
