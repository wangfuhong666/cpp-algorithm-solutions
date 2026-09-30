#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
using PII = pair<int, int>;
int n, m;
int p[N][N];
bool memo[N][N];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

bool bfs(int mid)
{
    queue<PII>q;
    for (int i = 1; i <= m; i++)
    {
        q.emplace(1, i);
        memo[1][i] = true;
    }
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        if (a == n)return true;
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            if (memo[nx][ny])continue;
            if (p[nx][ny] > mid)continue;
            memo[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
            cin >> p[i][j];
            r = max(r, p[i][j]);
        }
    }
    while (l < r)
    {
        int mid = (l + r) >> 1;
        fill((bool*)memo, (bool*)memo + N * N, false);
        if (bfs(mid))r = mid;
        else l = mid + 1;
    }
    cout << l;
    return 0;
}
