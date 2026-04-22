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
    vector<vector<long long>>dp(n + 1, vector<long long>(v + 1, 0)), dpv(n + 1, vector<long long>(v + 1, LLONG_MIN));
    dpv[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= v; j++)
        {
            long long ret = dp[i - 1][j];
            long long res = dpv[i - 1][j];
            if (j >= arrv[i])
            {
                ret = max(ret, arrw[i] + dp[i - 1][j - arrv[i]]);
                res = max(res, arrw[i] + dpv[i - 1][j - arrv[i]]);
            }
            dp[i][j] = ret;
            dpv[i][j] = res;
        }
    }
    cout << dp[n][v] << '\n' << (dpv[n][v] < 0 ? 0 : dpv[n][v]);
    return 0;
}
