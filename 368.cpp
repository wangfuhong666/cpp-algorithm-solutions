#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 300;
using ll = long long;
vector<vector<ll>>dp(N, vector <ll>(N, LLONG_MAX / 2));
int n;
void fd(int k)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)dp[i][i] = 0;
    vector<int>t(n);
    for (auto& num : t)cin >> num;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dp[u][v] = dp[v][u] = w;
    }
    int q;
    cin >> q;
    int pos = 0;
    while (q--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        while (pos < n && t[pos] <= c)fd(pos++);
        if (t[a] > c || t[b] > c || dp[a][b] == LLONG_MAX / 2)cout << -1 << '\n';
        else cout << dp[a][b] << '\n';
    }
    return 0;
}
