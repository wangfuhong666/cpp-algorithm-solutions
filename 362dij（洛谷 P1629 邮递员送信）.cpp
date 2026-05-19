#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PII = pair<int, int>;
using PLI = pair<ll, int>;
vector<ll>dist;
vector<bool>vis;
int n;
ll dig(vector<vector<PII>>& adj, int x)
{
    dist.assign(n + 1, LLONG_MAX / 2);
    vis.assign(n + 1, false);
    priority_queue<PLI, vector<PLI>, greater<PLI>>pq;
    dist[x] = 0;
    pq.emplace(0, x);
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        for (auto& [a, b] : adj[c])
        {
            if (vis[a])continue;
            if (w + b < dist[a])
            {
                dist[a] = w + b;
                pq.emplace(dist[a], a);
            }
        }
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)res += dist[i];
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> n >> m;
    vector<vector<PII>>adj1(n + 1), adj2(n + 1);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj1[u].emplace_back(v, w);
        adj2[v].emplace_back(u, w);
    }
    ll res = 0LL;
    res += dig(adj1, 1);
    res += dig(adj2, 1);
    cout << res;
    return 0;
}
