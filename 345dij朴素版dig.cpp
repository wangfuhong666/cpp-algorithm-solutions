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
    dist[x] = 0;
    for (int i = 1; i <= n; i++)
    {
        int cur = -1;
        int minn = INT_MAX;
        for (int j = 1; j <= n; j++)
        {
            if (!vis[j] && minn > dist[j])
            {
                minn = dist[j];
                cur = j;
            }
        }
        if (cur == -1)break;
        vis[cur] = true;
        for (auto [a, b] : adj[cur])
        {
            if (vis[a])continue;
            if (minn + b < dist[a]) dist[a] = minn + b;      
        }

    }
    return (dist[n] == INT_MAX ? -1 : dist[n]);
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
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    cout<<dij(1);
    return 0;
}
