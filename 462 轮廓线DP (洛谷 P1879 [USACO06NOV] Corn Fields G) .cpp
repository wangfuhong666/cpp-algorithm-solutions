#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const ll mod = 1e8;
int n, m;
vector<vector<int>> a(13, vector<int>(13, 0));
// 返回s中第j列的信息
int getinfo(int s, int j)
{
    return (s >> j) & 1;
}

vector<vector<vector<ll>>> dp;
ll dfs(int i, int j, int mask)
{

    if (i == n)
        return 1;
    if (j == m)
        return dfs(i + 1, 0, mask) % mod;
    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];
    ll ans = dfs(i, j + 1, mask & ~(1 << j)) % mod;
    if ((j == 0 || getinfo(mask, j - 1) == 0) && (getinfo(mask, j) == 0) && (a[i][j] == 1))
        ans = (ans + dfs(i, j + 1, mask | (1 << j)));
    return dp[i][j][mask] = ans % mod;
}

void sol()
{
    cin >> n >> m;
    dp.assign(n, vector<vector<ll>>(m, vector<ll>((1 << m), -1)));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << dfs(0, 0, 0) % mod;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--)
        sol();
    return 0;
}
