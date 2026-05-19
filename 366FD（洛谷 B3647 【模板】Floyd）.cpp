#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
using LL = long long;
vector<vector<LL>>dp(N, vector<LL>(N, LLONG_MAX / 2));
void Floyd()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        LL u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = min(w, dp[u][v]);
        dp[v][u] = min(w, dp[v][u]);
    }
    for (int i = 1; i <= n; i++)dp[i][i] = 0;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)cout << 0 << ' ';
            else cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    Floyd();
    return 0;
}
