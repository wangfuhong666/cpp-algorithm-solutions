#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int n;
using PII = pair<int, int>;
//prim
vector<PII>adj[N];
vector<bool>vis(N, false);
vector<int>dist(N,INT_MAX);
bool ju = true;
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
    pq.emplace(0, 1);
    dist[1] = 0;
    int res = 0;
    int cnt = 0;
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        res += w;
        cnt++;
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
    if (cnt != n)ju = false;
    return res;
}
//kruskal
struct node
{
    int u, v, w;
    bool operator<(const node& a)const
    {
        return this->w < a.w;
    }
};
vector<node>edg;
int fa[N];
int setnum[N];
void start(int n)
{
    for (int i = 0; i <= n; i++)
    {
        fa[i] = i;
        setnum[i] = 1;
    }
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
bool un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)return false;
    fa[fx] = fy;
    setnum[fy] += setnum[fx];
    return true;
}
int kruskal()
{
    int m;
    cin >> n >> m;
    start(n);
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.push_back({ u,v,w });
    }
    sort(edg.begin(), edg.end());
    int res = 0;
    int cnt = 0;
    for (auto p : edg)
    {
        int u = p.u, v = p.v, w = p.w;
        if (un(u, v))res += w;     
    }
    for (int i = 1; i <= n; i++)
    if (fa[i]==i)
    {
        ju = (setnum[i] == n);
        break;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int res = kruskal();
    if (ju)cout << res;
    else cout << "orz";
    return 0;
}
