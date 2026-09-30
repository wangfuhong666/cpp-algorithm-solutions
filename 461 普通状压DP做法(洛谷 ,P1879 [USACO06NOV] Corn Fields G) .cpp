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

ll dfs(int i, int j, int mask, int s);
ll dfsval(int id, int mask);

// dfs含义:
// 现在来到第i行第j列，上一行的状态为mask，更新当前行状态s并返回种草方法数

ll dfs(int i, int j, int mask, int s)
{
    if (j == m)
    {
        return dfsval(i + 1, s) % mod;
    }
    ll ans = dfs(i, j + 1, mask, s);
    if ((j == 0 || getinfo(s, j - 1) == 0) && (getinfo(mask, j) == 0) && (a[i][j] == 1))
        ans = (ans + dfs(i, j + 1, mask, s | (1 << j))) % mod;
    return ans % mod;
}
// dfsval含义：
// 来到第id行，上一行的种草情况为mask，返回在不违反规则的情况下，返回种草方法数
vector<vector<ll>> dp;
ll dfsval(int id, int mask)
{

    if (id == n)
        return 1;
    if (dp[id][mask] != -1)
        return dp[id][mask];
    return dp[id][mask] = dfs(id, 0, mask, 0);
}

void sol()
{
    cin >> n >> m;
    dp.assign(n, vector<ll>((1 << m), -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cout << dfsval(0, 0) % mod;
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
