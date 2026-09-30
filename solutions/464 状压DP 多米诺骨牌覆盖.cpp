#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
int n, m;
int getinfo(int s, int j)
{
    return (s >> j) & 1;
}
int setinfo(int s, int j, int h)
{
    return h == 1 ? (s | (1 << j)) : (s & (~(1 << j)));
}
vector<vector<vector<ll>>> dp;
ll dfs(int i, int j, int mask)
{
    if (i == n)
        return 1;
    if (j == m)
        return dfs(i + 1, 0, mask);
    if (dp[i][j][mask] != -1)
        return dp[i][j][mask];
    ll ans = 0;
    if (getinfo(mask, j) == 1)
        ans += dfs(i, j + 1, setinfo(mask, j, 0));

    if (i < n - 1 && getinfo(mask, j) == 0)
    {
        ans += dfs(i, j + 1, setinfo(mask, j, 1));
    }
    if (j + 1 < m && getinfo(mask, j + 1) == 0 && getinfo(mask, j) == 0)
    {
        ans += dfs(i, j + 2, mask);
    }
    return dp[i][j][mask] = ans;
}
void sol()
{
    dp.assign(n, vector<vector<ll>>(m, vector<ll>((1 << m), -1)));
    cout << dfs(0, 0, 0) << '\n';
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t = 1;
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        sol();
    }
    return 0;
}
