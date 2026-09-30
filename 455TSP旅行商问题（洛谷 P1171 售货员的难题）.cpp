#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int N = 30;
int n;
int adj[N][N];
ll dp[(1<<20)][N];
//来到last这个点，以前走过的点的集合为mask，
//返回从该点开始回到起点1的最小权值和
ll dfs(int mask, int last)
{
    if(dp[mask][last])return dp[mask][last];
    if(mask == (1 << n) - 1)
        return dp[mask][last] = adj[last][0];
    ll ans = LLONG_MAX / 2;
    for (int i = 0; i < n; i++)
    {
        if (i == last)
            continue;
        if (mask & (1 << i))
            continue;
        ans = min(ans, dfs(mask | (1 << i), i)+adj[last][i]);
    }
    return dp[mask][last] = ans;
}
void sol()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> adj[i][j];
        }
    }
    cout << dfs(1, 0);
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
