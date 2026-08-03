#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
using ll = long long;
vector<vector<ll>>dp(N, vector<ll>(N, LLONG_MAX / 2));
vector<vector<int>>grid(N, vector<int>(N, INT_MAX / 2));
int n;
ll fd()
{
    ll res = LLONG_MAX / 2;
    //for (int i = 1; i <= n; i++)dp[i][i] = 0LL;
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
        {
            for (int j = i + 1; j < k; j++)
            {
                res = min(res, dp[i][j] + grid[i][k] + grid[j][k]);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
            }
        }

    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        grid[u][v] = grid[v][u] = dp[u][v] = dp[v][u] = min(dp[u][v], (ll)w);
    }
    ll res = fd();
    if (res >= INT_MAX / 2)cout << "No solution.";
    else cout << res;
    return 0;
}
