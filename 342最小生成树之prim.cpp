#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using PII = pair<int, int>;
int n;
vector<PII>adj[N];
vector<bool>vis(N, false);
vector<int>dist(N, INT_MAX);
int prim()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int res = 0;
    dist[1] = 0;
    for (int i = 0; i < n; i++)
    {
        int idx = -1;
        int mindist = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && mindist > dist[j])
            {
                idx = j;
                mindist = dist[j];
            }
        }
        vis[idx] = true;
        res += mindist;
        for (auto& [a, b] : adj[idx])
        {
            if (vis[a])continue;
            dist[a] = min(dist[a], b);
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << prim();
    return 0;
}