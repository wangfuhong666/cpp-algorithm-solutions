#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
vector<vector<int>>adj(N);
vector<bool>vis(N, false);
vector<int>path;
bool ju = false;
int n;
void dfs(int u)
{
    if (vis[u])return;
    vis[u] = true;
    path.push_back(u);
    if (u == n)
    {
        ju = true;
        int m = path.size();
        for (int i = 0; i < m; i++)cout << path[i] << (i < m - 1 ? " " : "");
        cout << '\n';
    }
    for (auto e : adj[u])
    {
        if (vis[e])continue;
        dfs(e);
    }
    path.pop_back();
    vis[u] = false;
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
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1);
    if (!ju)cout << -1;
    return 0;
}