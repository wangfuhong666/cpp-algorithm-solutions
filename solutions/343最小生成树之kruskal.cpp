#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1E5 + 10;
int fa[N];
struct node
{
    int u, v, w;
    bool operator<(node a)
    {
        return this->w < a.w;
    }
};
void start(int n)
{
    for (int i = 0; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (x == fa[x])return x;
    return fa[x] = find(fa[x]);
}
bool un(int x, int y)
{
    int fx = find(x);
    int fy = find(y);
    if (fx == fy)return false;
    fa[fx] = fy;
    return true;
}
vector<node>edg;
int n;
int kruskal()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        edg.push_back({ u,v,w });
    }
    start(n);
    sort(edg.begin(), edg.end());
    int a = edg.size();
    int res = 0;
    for (int i = 0; i < a; i++)
    {
        node p = edg[i];
        int u = p.u, v = p.v, w = p.w;
        if(un(u,v))res += w;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cout << kruskal();

    return 0;
}
