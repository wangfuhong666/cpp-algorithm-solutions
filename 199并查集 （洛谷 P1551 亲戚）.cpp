#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
int fa[N];
void start(int n)
{
    for (int i = 1; i <= n; i++)fa[i] = i;
}
int find(int x)
{
    if (fa[x] == x)return x;
    return fa[x] = find(fa[x]);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m, p;
    cin >> n >> m >> p;
    start(n);
    while (m--)
    {
        int m1, m2;
        cin >> m1 >> m2;
        int fx, fy;
        if ((fx = find(m1)) != (fy = find(m2)))fa[fx] = fy;
    }
    while (p--)
    {
        int p1, p2;
        cin >> p1 >> p2;
        if (find(p1) == find(p2))cout << "Yes" << '\n';
        else cout << "No" << '\n';
    }
    return 0;
}
