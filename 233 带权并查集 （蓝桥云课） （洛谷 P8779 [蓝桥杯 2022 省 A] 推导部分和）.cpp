#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int fa[N];
long long dist[N];
void start(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        dist[i] = 0;
    }
}
int find(int x)
{
    if (fa[x] == x)return x;
    int fx = fa[x];
    int root = find(fa[x]);
    dist[x] += dist[fx];
    return fa[x] = root;
}
void un(int x, int y, long long v)
{
    int fx = find(x);
    int fy = find(y);
    if (fx != fy)
    {
        dist[fx] = dist[y] - dist[x] + v;
        fa[fx] = fy;
    }
}
bool issameset(int x, int y)
{
    return find(x) == find(y);
}
long long querydist(int x, int y)
{
    if (!issameset(x, y))return 0x3f3f3f3f3f3f3f3fLL;
    return dist[x] - dist[y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, q;
    cin >> n >> m >> q;
    start(n + 2);
    for (int i = 0; i < m; i++)
    {
        long long x, y, v;
        cin >> x >> y >> v;
        un(x, y + 1, v);
    }
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        if (querydist(l, r + 1) == 0x3f3f3f3f3f3f3f3fLL)cout << "UNKNOWN" << '\n';
        else cout << querydist(l, r + 1) << '\n';
    }
    return 0;
}