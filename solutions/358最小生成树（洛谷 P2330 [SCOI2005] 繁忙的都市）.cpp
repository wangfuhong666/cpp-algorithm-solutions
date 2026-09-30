#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 400;
using PII = pair<int, int>;
vector<PII>adj[N];
int n;
vector<int>dist(N, INT_MAX / 2);
vector<bool>vis(N, false);
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
    priority_queue<PII, vector<PII>, greater<PII>>pq;
    dist[1] = 0;
    pq.emplace(0, 1);
    int res = 0;
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        res = max(res, w);
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
    ;
    int res= prim();
    cout << n - 1 << ' ' << res;
    return 0;
}
