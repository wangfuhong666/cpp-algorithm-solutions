#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
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
    int n, m;
    cin >> n >> m;
    start(n);
    while (m--)
    {
        int z, x, y;
        cin >> z >> x >> y;
        if (z == 1)fa[find(x)] = find(y);
        else cout << (find(x) == find(y) ? "Y" : "N") << '\n';
    }
    return 0;
}
