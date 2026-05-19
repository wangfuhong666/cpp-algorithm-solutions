#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
using ll = long long;
using PII = pair<int, int>;
using PLI = pair<ll, int>;
vector<PII>adj[N];
vector<ll>dist(N, LLONG_MAX / 2);
vector<bool>vis(N, false);
int n;
void dig(int x)
{
    priority_queue<PLI, vector<PLI>, greater<PLI>>pq;
    pq.emplace(0, x);
    dist[x] = 0;
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
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
    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == LLONG_MAX / 2)cout << INT_MAX << ' ';
        else cout << dist[i] << ' ';
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    int x;
    cin >> n >> m >> x;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);

    }
    dig(x);
    return 0;
}
