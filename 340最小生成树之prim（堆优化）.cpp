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
    priority_queue<PII, vector<PII>, greater<PII>>pq;
    pq.emplace(0, 1);
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        dist[c] = w;
        res += w;
        for (auto& [a, b] : adj[c])
        {
            if (vis[a])continue;
            if (b < dist[a])
            {
                dist[a] = b;
                pq.emplace(b, a);
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

    cout << prim();
    return 0;
}