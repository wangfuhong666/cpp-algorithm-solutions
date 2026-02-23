#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
using PII = pair<int, int>;
char arr[N][N];
vector<PII>path[4];
int dist[4][N][N];
int n, m;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
void bfs(int idx)
{
    deque<PII>q;
    for (int i = 0; i < path[idx].size(); i++)
    {
        auto [a, b] = path[idx][i];
        q.emplace_back(a, b);
        dist[idx][a][b] = 0;
    }
    while (!q.empty())
    {
        auto [a, b] = q.front();
        q.pop_front();
        for (int i = 0; i < 4; i++)
        {
            int nx = a + dx[i];
            int ny = b + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            if (arr[nx][ny] == '#')continue;
            if (arr[nx][ny] == '.' && dist[idx][a][b] + 1 < dist[idx][nx][ny])
            {
                dist[idx][nx][ny] = dist[idx][a][b] + 1;
                q.emplace_back(nx, ny);
            }
            if (arr[nx][ny] != '.' && dist[idx][a][b] < dist[idx][nx][ny])
            {
                dist[idx][nx][ny] = dist[idx][a][b];
                q.emplace_front(nx, ny);
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill((int*)dist, (int*)dist + 4 * N * N, 0x3f3f3f3f);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            arr[i][j] = x;
            if (x == '#' || x == '.')continue;
            int idx = x - '0';
            path[idx].emplace_back(i, j);
        }
    }
    for (int i = 1; i <= 3; i++)bfs(i);
    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (dist[1][i][j] == 0x3f3f3f3f || dist[2][i][j] == 0x3f3f3f3f || dist[3][i][j] == 0x3f3f3f3f) continue;         
            res = min(res, dist[1][i][j] + dist[2][i][j] + dist[3][i][j] + (arr[i][j] == '.' ? -2 : 0));
        }
    }
    if (res == 0x3f3f3f3f) cout << -1 << '\n'; 
    else  cout << res << '\n';
    
    return 0;
}
