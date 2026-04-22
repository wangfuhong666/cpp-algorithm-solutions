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
    long long maxn = LLONG_MIN;
    vector<vector<long long>>dp(n + 1, vector<long long>(n + 1, 0LL));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= i; j++)cin >> dp[i][j];
    if (n == 1)cout << dp[1][1];
    else
    {
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j <= i; j++)
            {
                dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]);
                maxn = max(maxn, dp[i][j]);
            }
        }
        cout << maxn;
    }
    
    return 0;
}
