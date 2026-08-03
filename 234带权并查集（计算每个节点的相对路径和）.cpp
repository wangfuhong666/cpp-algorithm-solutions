#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int fa[N];
int dist[N];
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
void un(int x, int y,int v)
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
int querydist(int x, int y)
{
    if (!issameset(x, y))return 0x3f3f3f3f;
    return dist[x] - dist[y];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    start(n);
    for (int i = 0; i < m; i++)
    {
        int x, y, v;
        cin >> x >> y >> v;
        un(x, y, v);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << "节点" << i << "与节点" << j << "的距离";
            int pos = querydist(i, j);
            if (pos == 0x3f3f3f3f)cout << "不存在\n";
            else cout << "为：" << pos << '\n';

        }
    }
    return 0;
}