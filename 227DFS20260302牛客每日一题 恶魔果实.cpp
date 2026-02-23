#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e4 + 7;
set<int> dist[10];
bool vis[10];
void dfs(int a)
{
    vis[a] = true;
    for (auto it = dist[a].begin(); it != dist[a].end(); it++)
    {
        if (!vis[*it])
        {
            vis[*it] = true;
            dfs(*it);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int x, n;
    cin >> x >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        dist[a].insert(b);
    }
    long long res = 1LL;
    while (x)
    {
        memset(vis, false, sizeof vis);
        dfs(x % 10);
        int cnt = 0;
        for (int i = 0; i < 10; i++) if (vis[i])cnt++;
        res = (res * cnt) % mod;
        x /= 10;
    }
    cout << res;
    return 0;
}
