#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
using PII = pair<int, int>;
vector<PII>adj[N];
vector<bool>vis(N, false);
vector<int>dist(N, INT_MAX);
int n;
int dij(int x)
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    priority_queue<PII, vector<PII>, greater<PII>>pq;
    pq.emplace(0, x);
    dist[x] = 0;
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        if (c == n)break;
        for (auto [a, b] : adj[c])
        {
            if (vis[a])continue;
            if (w + b < dist[a])
            {
                dist[a] = w + b;
                pq.emplace(dist[a], a);
            }
        }
    }

    return (dist[n] == INT_MAX ? -1 : dist[n]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << dij(1);
    return 0;
}
