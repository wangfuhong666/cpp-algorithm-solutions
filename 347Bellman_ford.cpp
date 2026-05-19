#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
using LL = long long;
const int N = 1e3 + 10;
struct node
{
    int u, v, w;
};
vector<node>edg;
vector<LL>dist(N, LLONG_MAX / 2);
int n;
LL Bellman_ford(int x)
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.push_back({ u,v,w });
    }
    dist[x] = 0;
    int tem = n - 1;
    while (tem--)
    {
        for (auto p : edg)
        {
            int u = p.u, v = p.v, w = p.w;
            if (dist[u] != LLONG_MAX / 2&&dist[u] + w < dist[v])dist[v] = dist[u] + w;
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
