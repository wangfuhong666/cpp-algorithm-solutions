#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u, v, w;
};
//const int N = 2e3 + 10;
vector<node>edg;
using ll = long long;
int n;
vector<ll>dist;
bool Bellman_ford()
{
    int m = n;
    dist[1] = 0;
    while (m--)
    {
        if (m > 1)
        {
            for (auto p : edg)
            {
                int u = p.u;
                int v = p.v;
                int w = p.w;
                if (dist[u] != LLONG_MAX / 2 && dist[u] + w < dist[v])dist[v] = dist[u] + w;
                
            }
        }
        else
        {
            for (auto p : edg)
            {
                int u = p.u;
                int v = p.v;
                int w = p.w;
                if (dist[u] != LLONG_MAX / 2 && dist[u] + w < dist[v])
                {
                    return true;
                }

            }
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--)
    {
        edg.clear();
        int m;
        cin >> n >> m;
        dist.resize(n + 1, LLONG_MAX / 2);
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            edg.push_back({ u,v,w });
            if (w >= 0)edg.push_back({ v,u,w });
        }
        if (Bellman_ford())cout << "YES" << '\n';
        else cout << "NO" << '\n';
    }
    return 0;
}
