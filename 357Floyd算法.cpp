#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
using LL = long long;
vector<vector<LL>>dp(N, vector<LL>(N, LLONG_MAX / 2));
void Floyd()
{
    int n, m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = w;
        dp[v][u] = w;
    }
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
    int q;
    cin >> q;
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        if (dp[u][v] == LLONG_MAX / 2)cout << -1 << '\n';
        else cout << dp[u][v] << '\n';
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
