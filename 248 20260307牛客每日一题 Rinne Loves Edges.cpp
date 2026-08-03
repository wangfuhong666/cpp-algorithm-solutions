#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using PIL = pair<int, long long>;
vector<long long>dp(N);
vector<vector<PIL>>adj(N);
int n, m, s;
void dfs(int x, int fa)
{
    int num = adj[x].size();
    bool judge = true;
    for (int i = 0; i < num; i++)
    {
        int y = adj[x][i].first;
        long long w = adj[x][i].second;
        if (y == fa)continue;
        judge = false;
        dfs(y, x);
        dp[x] += min(dp[y], w);
    }
    if (judge)dp[x] = LLONG_MAX;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    dfs(s, 0);
    cout << dp[s];
    return 0;
}
