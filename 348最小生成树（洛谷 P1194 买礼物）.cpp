#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10;
int grid[N][N];
int n;
vector<bool>vis(N, false);
vector<int>dist(N, INT_MAX);
using PII = pair<int, int>;
int prim()
{
    int res = 0;
    priority_queue<PII, vector<PII>, greater<PII>>pq;
    //nlogm
    //mlogm
    pq.emplace(0, 0);
    while (!pq.empty())
    {
        auto [w, c] = pq.top();
        pq.pop();
        if (vis[c])continue;
        vis[c] = true;
        res += w;
        for (int j = 1; j <= n; j++)
        {
            if (vis[j])continue;
            if (!grid[c][j])continue;
            if (grid[c][j] < dist[j])
            {
                dist[j] = grid[c][j];
                pq.emplace(grid[c][j], j);
            }
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int m;
    cin >> m >> n;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == 0)grid[i][j] = m;
            else
            {
                int x;
                cin >> x;
                if (i == j)grid[i][j] = 0;
                else grid[i][j] = x;          
            }
        }
    }
    int res = prim();
    cout << res;
    return 0;
}
