#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
using PII = pair<int, int>;
using ll = long long;
vector<PII>adj[N];
vector<ll>dist(N, LLONG_MAX / 2);
vector<bool>vis(N, false);
int n;
vector<int>h(N, 0);
struct node
{
    int w, c;
    bool operator<(const  node& a)const
    {
        int w = this->w;
        int c = this->c;
        if (h[c] != h[a.c])return h[c] < h[a.c];
        return w > a.w;
    }
};
vector<ll> prim()
{
    
    int m;
    cin >> n >> m;
    
    for (int i = 1; i <= n; i++)cin >> h[i];
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        if (h[u] >= h[v])adj[u].emplace_back(v, w);
        if (h[v] >= h[u])adj[v].emplace_back(u, w);
    }
    priority_queue<node, vector<node>>pq;
    ll cnt = 0, res = 0;
    pq.emplace(0, 1);
    dist[1] = 0;
    while (!pq.empty())
    {
        auto p = pq.top();
        int w = p.w;
        int c = p.c;
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        cnt++;
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
    return { cnt,res };
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<ll>res = prim();
    cout << res[0] << ' ' << res[1];
    return 0;
}
