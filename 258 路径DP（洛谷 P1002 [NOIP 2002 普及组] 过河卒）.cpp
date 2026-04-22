#include <bits/stdc++.h>
using namespace std;
const int N = 50;
long long dp[N][N];
bool vis[N][N];
int dx[] = { -2, -1,  1,  2,  2,  1, -1, -2 };
int dy[] = { 1,  2,  2,  1, -1, -2, -2, -1 };
int n, m;
void bfs(int x,int y)
{
    vis[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 1 || nx >=n || ny < 1 || ny > m)continue;
        vis[nx][ny] = true;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    memset(vis, false, sizeof vis);
    int x, y;
    cin >> n >> m >> x >> y;
    n += 1;
    m += 1;
    dp[1][1] = 1;
    bfs(x+1, y+1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (i == 1 && j == 1)continue;
            if (vis[i][j])dp[i][j] = 0;
            else dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    cout << dp[n][m];
}
