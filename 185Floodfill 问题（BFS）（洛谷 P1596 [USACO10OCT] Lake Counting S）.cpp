#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e2 + 10;
bool memo[N][N];
char arr[N][N];
using PII = pair<int, int>;
int n, m;
int res = 0;
int dx[] = { 0,0,1,1,1,-1,-1,-1 };
int dy[] = { 1,-1, -1,0,1,-1,0,1 };
void bfs(int x, int y)
{
    queue<PII>q;
    q.emplace(x, y);
    memo[x][y] = true;
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            if (memo[nx][ny])continue;
            if (arr[nx][ny] == '.')continue;
            memo[nx][ny] = true;
            q.emplace(nx, ny);

        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill((bool*)memo, (bool*)memo + N * N, false);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)for (int j = 1; j <= m; j++)cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (arr[i][j] == 'W' && memo[i][j] == false)
            {
                res++;
                bfs(i, j);
            }
        }
    }
    cout << res;
    return 0;
}

