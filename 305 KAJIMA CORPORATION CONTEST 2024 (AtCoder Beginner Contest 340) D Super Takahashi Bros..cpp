#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using PLL = pair<ll, ll>;
const int N = 2e5 + 10;
vector<vector<PLL>>adj(N);
vector<bool>vis(N, false);
vector<ll>dist(N, LLONG_MAX/2);
int n;
ll dij(int u)
{
    priority_queue<PLL, vector<PLL>, greater<PLL>>pq;
    dist[u] = 0;
    pq.emplace(0, u);
    while (!pq.empty())
    {
        auto [a, b] = pq.top();
        pq.pop();
        if (vis[b])continue;
        vis[b] = true;
        for (auto [x, y] : adj[b])
        {
            if (dist[b] + y < dist[x])
            {
                dist[x] = dist[b] + y;
                pq.emplace(dist[x], x);
            }
        }
    }
    return dist[n];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        ll a, b, x;
        cin >> a >> b >> x;
        adj[i].push_back({ i + 1,a });
        adj[i].push_back({ x,b });
    }
    cout << dij(1);
    return 0;
}
