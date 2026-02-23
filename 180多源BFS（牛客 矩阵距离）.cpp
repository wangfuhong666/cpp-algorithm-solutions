#define _CRT_SECURE_NO_WARNINGS
#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
using PII = pair<int, int>;
vector<PII>path;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int arr[N][N];
int dist[N][N];
int n, m;
void bfs()
{
    queue<PII>q;
    for (int i = 0; i < path.size(); i++)
    {
        q.push(path[i]);
        dist[path[i].first][path[i].second] = 0;
    }
    while (!q.empty())
    {
        PII p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx<1 || nx>n || ny<1 || ny>m)continue;
            if (dist[nx][ny] != -1)continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.emplace(nx, ny);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fill((int*)dist, (int*)dist + N * N, -1);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            arr[i][j] = x - '0';
            if (x == '1')path.emplace_back(i, j);
        }
    }
    bfs();
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)cout << dist[i][j] << (j <= m - 1 ? " " : "");
        cout << '\n';
    }
    return 0;
}
