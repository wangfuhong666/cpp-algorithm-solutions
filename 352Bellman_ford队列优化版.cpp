#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
using PII = pair<int, int>;
vector<PII>adj[N];
vector<LL>dist(N, LLONG_MAX / 2);
int n;
vector<bool>in(N, false);
LL Bellman_ford(int x)
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    queue<int>q;
    q.push(x);
    dist[x] = 0;
    while (!q.empty())
    {
        int p = q.front();
        q.pop();
        in[p] = false;
        for (auto [a, b] : adj[p])
        {
            if (dist[p] + b < dist[a])
            {
                dist[a] = dist[p] + b;
                if (!in[a])
                {
                    q.push(a);
                    in[a] = true;
                }
            }
        }
    }
    return (dist[n] == LLONG_MAX / 2 ? -1 : dist[n]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    LL res = Bellman_ford(1);
    if (res == -1)cout << "unconnected";
    else cout << res;
    return 0;
}
