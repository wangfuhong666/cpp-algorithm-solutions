#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
using LL = long long;
using PII = pair<int, int>;
vector<LL>dist(N, LLONG_MAX / 2), distplus(N, LLONG_MAX / 2);
vector<PII>adj[N];

int n;
LL Bellman_ford()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
    }
    int x, y, k;
    cin >> x >> y >> k;
    k += 1;
    queue<int>q;
    q.emplace(x);
    dist[x] = 0;
    while (k-- && !q.empty())
    {
        vector<bool>in(N, false);
        distplus = dist;
        int sz = q.size();
        while (sz--)
        {
            int c = q.front();
            q.pop();
            in[c] = false;
            for (auto [a, b] : adj[c])
            {
                if (distplus[c] + b < dist[a])
                {
                    dist[a] = distplus[c] + b;
                    if (in[a])continue;
                    q.push(a);
                    in[a] = true;
                }
            }
        }
    }
    return (dist[y] > LLONG_MAX / 4 ? LLONG_MAX : dist[y]);
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
