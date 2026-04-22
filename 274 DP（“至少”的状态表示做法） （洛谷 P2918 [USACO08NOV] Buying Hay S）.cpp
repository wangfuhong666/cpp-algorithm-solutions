#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    long long n, h;
    cin >> n >> h;
    vector<int>arrp(n + 1, 0), arrc(n + 1, 0);
    for (int i = 1; i <= n; i++)cin >> arrp[i] >> arrc[i];
    vector<vector<long long>>dp(n + 1, vector<long long>(h + 1 , LLONG_MAX / 2));
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < h + 1 ; j++)
        {
            dp[i][j] = dp[i - 1][j];
            dp[i][j] = min(dp[i][j], arrc[i] + dp[i][max(0,j - arrp[i])]);
        }
    }
    cout << dp[n][h];
    return 0;
}
