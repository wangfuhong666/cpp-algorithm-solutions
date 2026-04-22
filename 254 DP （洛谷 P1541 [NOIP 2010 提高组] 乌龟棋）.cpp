#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N  = 50;
long long dp[N][N][N][N];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<long long>arr(n + 1, 0LL);
    for (int i = 1; i <= n; i++)cin >> arr[i];
    vector<int>mp(5, 0);
    while (m--)
    {
        int x;
        cin >> x;
        mp[x]++;
    }
    memset(dp, 0, sizeof dp);
    dp[0][0][0][0] = arr[1];
    for (int i = 0; i <= mp[1]; i++)
    {
        for (int j = 0; j <= mp[2]; j++)
        {
            for (int k = 0; k <= mp[3]; k++)
            {
                for (int t = 0; t <= mp[4]; t++)
                {
                    long long dist = 1 + i + 2 * j + 3 * k + 4 * t;
                    long long maxn = LLONG_MIN;
                    if (i)maxn = max(maxn, dp[i - 1][j][k][t]);
                    if (j)maxn = max(maxn, dp[i][j - 1][k][t]);
                    if (k)maxn = max(maxn, dp[i][j][k - 1][t]);
                    if (t)maxn = max(maxn, dp[i][j][k][t - 1]);
                    if (i == 0 && j == 0 && k == 0 && t == 0)continue;
                    dp[i][j][k][t] = maxn + arr[dist];
                }
            }
        }
    }
    cout << dp[mp[1]][mp[2]][mp[3]][mp[4]];
    return 0;
}
