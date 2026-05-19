#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 200;
using PII = pair<int, int>;
using PID = pair<int, double>;
using PDI = pair<double, int>;
double d(PII a, PII b)
{
    int x1 = a.first;
    int y1 = a.second;
    int x2 = b.first;
    int y2 = b.second;
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
int n;
vector<PII>arr(N);
vector<PID>adj[N];
vector<bool>vis(N, false);
vector<double>dist(N, LLONG_MAX / 2);
double dig(int s, int t)
{
    priority_queue<PDI, vector<PDI>, greater<PDI>>pq;
    dist[s] = 0.0;
    pq.emplace(0.0, s);
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        if (c == t)break;
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
    return dist[t];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        cin >> x >> y;
        arr[i] = { x,y };
    }
    int m;
    cin >> m;
    while (m--)
    {
        int u, v;
        cin >> u >> v;
        double w = d(arr[u], arr[v]);
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    int s,t;
    cin >> s >> t;
    printf("%.2lf", dig(s, t));
    return 0;
}
