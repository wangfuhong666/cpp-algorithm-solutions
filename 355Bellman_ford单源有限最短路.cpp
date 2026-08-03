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
//本轮数组
vector<LL>dist(N, LLONG_MAX / 2);
//上一轮数组
vector<LL>distplus(N, LLONG_MAX / 2);
int n;
LL Bellman_ford()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.push_back({ u,v,w });
    }
    int x, y, k;
    cin >> x >> y >> k;
    dist[x] = 0;
    int tem = k + 1;
    while (tem--)
    {
        distplus = dist;
        for (auto p : edg)
        {
            int u = p.u, v = p.v, w = p.w;
            if (distplus[u] != LLONG_MAX / 2 && distplus[u] + w < dist[v])dist[v] = distplus[u] + w;
        }
    }
    return (dist[y] == LLONG_MAX / 2 ? LLONG_MAX : dist[y]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    LL res = Bellman_ford();
    if (res == LLONG_MAX)cout << "unreachable";
    else cout << res;
    return 0;
}
