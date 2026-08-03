#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, v;
    cin >> n >> v;
    vector<int>arrv(n + 1, 0), arrw(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrv[i] >> arrw[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(v + 1, 0)), dpw(n + 1, vector<long long>(v + 1, LLONG_MIN));
    dpw[0][0] = 0LL;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            dp[i][j] = dp[i - 1][j];
            dpw[i][j] = dpw[i - 1][j];
            if (j >= arrv[i])
            {
                dp[i][j] = max(dp[i][j], dp[i][j - arrv[i]] + arrw[i]);
                dpw[i][j] = max(dpw[i][j], dpw[i][j - arrv[i]] + arrw[i]);

            }
        }
    }
    cout << dp[n][v] << '\n' << (dpw[n][v] < 0 ? 0 : dpw[n][v]);
    return 0;
}
